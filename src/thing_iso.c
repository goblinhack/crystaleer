/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 *
 * Code is based heavily on https://github.com/shaunlebron/IsometricBlocks 
 * with some bug fixes
 */

#include "main.h"
#include "tile.h"
#include "thing_tile.h"
#include "python.h"
#include "config.h"
#include "math_util.h"
#include "time_util.h"

static thingp things_all_blocks[MAX_THINGS_SCRATCH];
static size_t things_all_blocks_count;

thingp things_draw_list[MAX_THINGS_SCRATCH];
size_t things_draw_list_count;

/*
 * Convert xyz 3d space to flattened 2d iso space with h and v
 * planes to describe horizontal and vertical planes for calculating
 * on screen overlaps.
 */
static void
thing_xyz_to_iso (ipoint *p) 
{
    double z = p->z;
    double x = p->x - z;
    double y = p->y - z;

    p->x = x;
    p->y = y;
    p->h = (x-y)*sqrt(3)/2; // Math.cos(Math.PI/6)
    p->v = (x+y)/2;         // Math.sin(Math.PI/6)
}

/*
 * Get the extents of this block in 2d space.
 */
static void 
thing_get_iso_verts (thingp t)
{
    fpoint3d s = { 1.0, 1.0, t->height };
    fpoint3d p = { t->at.x, t->at.y, t->at.z };

    ipoint backDown  = { p.x,     p.y,     p.z };
    ipoint frontDown = { p.x+s.x, p.y+s.y, p.z };

    ipoint frontUp   = { p.x+s.x, p.y+s.y, p.z+s.z };
    ipoint backUp    = { p.x,     p.y,     p.z+s.z };

    ipoint rightDown = { p.x+s.x, p.y,     p.z };
    ipoint leftDown  = { p.x,     p.y+s.y, p.z };

    ipoint rightUp   = { p.x+s.x, p.y,     p.z+s.z };
    ipoint leftUp    = { p.x,     p.y+s.y, p.z+s.z };

    thing_xyz_to_iso(&rightDown);
    thing_xyz_to_iso(&leftDown);
    thing_xyz_to_iso(&backDown);
    thing_xyz_to_iso(&frontDown);
    thing_xyz_to_iso(&rightUp);
    thing_xyz_to_iso(&leftUp);
    thing_xyz_to_iso(&backUp);
    thing_xyz_to_iso(&frontUp);

    t->rightDown = rightDown;
    t->leftDown  = leftDown;
    t->backDown  = backDown;
    t->frontDown = frontDown;
    t->rightUp   = rightUp;
    t->leftUp    = leftUp;
    t->backUp    = backUp;
    t->frontUp   = frontUp;
}

/*
 * Get just the bounds we care about for checking for on screen overlap.
 */
static void 
thing_get_iso_bounds (thingp t)
{
    thing_get_iso_verts(t);

    /*
     *        ...... h ......
     *         .           .
     *          .         .
     *           x       y
     *            .     .
     *             .   .
     *
     */

    t->xmin = t->backUp.x;
    t->xmax = t->frontDown.x;

    t->ymin = t->backUp.y;
    t->ymax = t->frontDown.y;

    t->hmin = t->leftDown.h;
    t->hmax = t->rightDown.h;
}

/*
 * Get the bounds in xyz form.
 */
static void 
thing_get_xyz_bounds (thingp t)
{
    t->xmin = t->at.x;
    t->xmax = t->at.x + 1.0;
    t->ymin = t->at.y;
    t->ymax = t->at.y + 1.0;
    t->zmin = t->at.z;
    t->zmax = t->at.z + t->height;
}

/*
 * Determine if the given ranges are disjoint (i.e. do not overlap).
 * For determining drawing order, this camera considers two
 * ranges to be disjoint even if they share an endpoint.
 * Thus, we use less-or-equal (<=) instead of strictly less (<).
 */
static int
ranges_do_not_overlap (double amin, double amax, double bmin, double bmax)
{
    if ((amin == bmin) && (amax == bmax)) {
	return (false);
    }

    /*
     * amin ...... amax
     *                   bmin ...... bmax
     */
    if (amax <= bmin) {
	return (true);
    }

    /*
     *                  amin ...... amax
     * bmin ...... bmax
     */
    if (bmax <= amin) {
	return (true);
    }

    return (false);
}

/*
 * As above.
 */
static int
ranges_overlap (double amin, double amax, double bmin, double bmax)
{
    if ((amin == bmin) && (amax == bmax)) {
	return (true);
    }

    /*
     * amin ...... amax
     *                   bmin ...... bmax
     */
    if (amax <= bmin) {
	return (false);
    }

    /*
     *                  amin ...... amax
     * bmin ...... bmax
     */
    if (bmax <= amin) {
	return (false);
    }

    return (true);
}

/*
 * Try to find an axis in 2D isometric that separates the two given blocks.
 * This helps identify if the the two blocks are overlap on the screen.
 *
 * Only if we have a collision in all three bounds is there an overlap;
 * this allows us to trim the number of blocks that we need to put in the
 * 'in front of list'
 */
int
things_iso_overlap (thingp a, thingp b)
{
    if (ranges_overlap(a->xmin, a->xmax, b->xmin, b->xmax) &&
        ranges_overlap(a->ymin, a->ymax, b->ymin, b->ymax) &&
        ranges_overlap(a->hmin, a->hmax, b->hmin, b->hmax)) {
	return (true);
    }

    return (false);
}

static char
thing_get_space_sep_axis (thingp a, thingp b)
{
    char sepAxis = '\0';;

    if (ranges_do_not_overlap(a->xmin, a->xmax, b->xmin, b->xmax)) {
	sepAxis = 'x';
    } else if (ranges_do_not_overlap(a->ymin, a->ymax, b->ymin, b->ymax)) {
	sepAxis = 'y';
    } else if (ranges_do_not_overlap(a->zmin, a->zmax, b->zmin, b->zmax)) {
	sepAxis = 'z';
    }

    return (sepAxis);
}

/*
 * Try to find an axis in 2D isometric that separates the two given blocks.
 * This helps identify if the the two blocks are overlap on the screen.
 *
 * Only if we have a collision in all three bounds is there an overlap;
 * this allows us to trim the number of blocks that we need to put in the
 * 'in front of list'
 */
int
things_iso_intersect (thingp a, thingp b)
{
    thing_get_xyz_bounds(a);
    thing_get_xyz_bounds(b);

    if (ranges_overlap(a->xmin, a->xmax, b->xmin, b->xmax) &&
        ranges_overlap(a->ymin, a->ymax, b->ymin, b->ymax) &&
        ranges_overlap(a->zmin, a->zmax, b->zmin, b->zmax)) {

        ERR("Intersecting things, %s %s",
            thing_logname(a),
            thing_logname(b));

	return (true);
    }

    return (false);
}

int
things_iso_collision_check (thingp a, thingp b, fpoint3d at)
{
    int rc = false;

    fpoint3d old = a->at;
    a->at = at;

    thing_get_xyz_bounds(a);
    thing_get_xyz_bounds(b);

    if (ranges_overlap(a->xmin, a->xmax, b->xmin, b->xmax) &&
        ranges_overlap(a->ymin, a->ymax, b->ymin, b->ymax) &&
        ranges_overlap(a->zmin, a->zmax, b->zmin, b->zmax)) {

#if 0
        CON("Intersecting things, %s %s",
            thing_logname(a),
            thing_logname(b));

        CON("  x %f<->%f y %f<->%f z %f<->%f ", a->xmin, a->xmax, a->ymin, a->ymax, a->zmin, a->zmax);
        CON("  x %f<->%f y %f<->%f z %f<->%f ", b->xmin, b->xmax, b->ymin, b->ymax, b->zmin, b->zmax);

    a->at = old;
    thing_get_xyz_bounds(a);
        CON("  x %f<->%f y %f<->%f z %f<->%f ", a->xmin, a->xmax, a->ymin, a->ymax, a->zmin, a->zmax);
        CON(" ");
#endif

        rc = true;
    }

    a->at = old;
    thing_get_xyz_bounds(a);

    return (rc);
}

/*
 * In an isometric perspective of the two given blocks, determine
 * if they will overlap each other on the screen. If they do, then return
 * the block that will appear in front.
 */
static thingp 
getFrontBlock (thingp a, thingp b) 
{
    /*
     * There's some problem here where sometimes a character at the front
     * will wind up at the back. Gave up for now.
     */
    thing_get_iso_bounds(a);
    thing_get_iso_bounds(b);

    /*
     * If no isometric separation axis is found, then the two 
     * blocks do not overlap on the screen. This means there 
     * is no "front" block to identify.
     */
    if (!things_iso_overlap(a, b)) {
#if 0
CON("%s and %s do not overlap", thing_logname(a), thing_logname(b));
CON("  %15s x %5.2f %5.2f y %5.2f %5.2f h %5.2f %5.2f", thing_logname(a), a->xmin, a->xmax, a->ymin, a->ymax, a->hmin, a->hmax);
CON("  %15s x %5.2f %5.2f y %5.2f %5.2f h %5.2f %5.2f", thing_logname(b), b->xmin, b->xmax, b->ymin, b->ymax, b->hmin, b->hmax);
#endif
        return (0);
    }

    if (things_iso_intersect(a, b)) {
    }

    switch (thing_get_space_sep_axis(a, b)) {
	case 'x': return (a->xmin < b->xmin) ? a : b;
	case 'y': return (a->ymin < b->ymin) ? a : b;
	case 'z': return (a->zmin < b->zmin) ? a : b;
    }

    return (0);
}

static void
things_init_sort (void)
{
    thingp t;

    things_all_blocks_count = 0;
    things_draw_list_count = 0;

    FOR_ALL_THINGS(t) {
        if (!t->is_on_map) {
            continue;
        }

        if (things_all_blocks_count >= ARRAY_SIZE(things_all_blocks)) {
            ERR("scratch pad overflow");
            return;
        }

	things_all_blocks[things_all_blocks_count++] = t;

	t->infront_count = 0;
	t->behind_count = 0;
    } FOR_ALL_THINGS_END
}

static void
things_push_infront (thingp t, thingp o)
{
    if (t->infront_count >= ARRAY_SIZE(t->infront)) {
	ERR("overflow thing infront array");
	return;
    }

    size_t j;

    for (j = 0; j < o->infront_count; j++) {
        if (o->infront[j] == t) {
            ERR("cycle");
            return;
        }
    }

    t->infront[t->infront_count++] = o;

    // LOG("%f %f is in front of %f %f [%u]\n", o->at.x, o->at.y, t->at.x, t->at.y, (int)t->infront_count);
}

static void
things_push_behind (thingp t, thingp o)
{
    t->behind_count++;
}

static void
things_push_todraw (thingp t)
{
    if (unlikely(things_draw_list_count >= 
                 ARRAY_SIZE(things_draw_list))) {
	ERR("overflow todraw array");
	return;
    }

    things_draw_list[things_draw_list_count++] = t;
}

static void
things_make_behind_and_infront_list (void)
{
    size_t i, j;

    for (i = 0; i < things_all_blocks_count; i++) {
	for (j = i + 1; j < things_all_blocks_count; j++) {
	    thingp a = things_all_blocks[i];
	    thingp b = things_all_blocks[j];

	    thingp f = getFrontBlock(a, b);
	    if (f) {
		if (f == b) {
		    things_push_behind(a, b);
		    things_push_infront(b, a);
		} else {
		    things_push_behind(b, a);
		    things_push_infront(a, b);
		}
            }
	}
    }
}

void
things_iso_sort (void)
{
    things_init_sort();
    things_make_behind_and_infront_list();

    size_t i, j;

    for (i = 0; i < things_all_blocks_count; i++) {
	thingp a = things_all_blocks[i];
	if (a->behind_count == 0) {
	    things_push_todraw(a);
	}
    }

    for (i = 0; i < things_draw_list_count; i++) {
	thingp a = things_draw_list[i];
	for (j = 0; j < a->infront_count; j++) {
	    thingp f = a->infront[j];

	    f->behind_count--;
	    if (!f->behind_count) {
		things_push_todraw(f);
	    }
	}
    }
}
