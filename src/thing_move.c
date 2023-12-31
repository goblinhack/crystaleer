/*
 * Copyright (C) 2011-2015 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */


#include "main.h"
#include "thing.h"
#include "tile.h"
#include "math_util.h"

#if 0
/*
 * Try to fall down
 */
int thing_fall (thingp t)
{
    double x = t->x;
    double y = t->y + 0.015;

    if (t->jump_speed) {
        t->fall_speed = 0;
        return (false);
    }

    if (thing_hit_solid_obstacle(level, t, x, y)) {
        t->fall_speed = 0;
        return (false);
    }

    t->fall_speed += 0.010;

    if (t->fall_speed > 1) {
        t->fall_speed = 1;
    }

    y = t->y + t->fall_speed;
    if (thing_hit_solid_obstacle(level, t, x, y)) {
        t->fall_speed /= 2;

        y = t->y + t->fall_speed;
        if (thing_hit_solid_obstacle(level, t, x, y)) {
            t->fall_speed /= 2;

            y = t->y + t->fall_speed;
            if (thing_hit_solid_obstacle(level, t, x, y)) {
                t->fall_speed /= 2;

                y = t->y + t->fall_speed;
                if (thing_hit_solid_obstacle(level, t, x, y)) {
                    t->fall_speed = 0;
                    return (false);
                }
            }
        }
    }

    thing_wid_update(level, t, x, y, true, false /* is new */);

    thing_handle_collisions(level, t);

    return (true);
}

/*
 * Try to fall down
 */
int thing_jump (levelp level, thingp t)
{
    double x = t->x;
    double y;

    y = t->y - t->jump_speed;

    if (thing_hit_solid_obstacle(level, t, x, y)) {
        t->jump_speed = 0;
        return (false);
    }

    thing_wid_update(level, t, x, y, true, false /* is new */);

    t->jump_speed *= 0.90;
    if (fabs(t->jump_speed) < 0.01) {
        t->jump_speed = 0;
        return (true);
    }

    thing_handle_collisions(level, t);

    return (true);
}

/*
 * Try to keep moving with velocity
 */
int thing_slide (levelp level, thingp t)
{
    double x;
    double y = t->y;

    if (fabs(t->velocity) < 0.008) {
        t->velocity = 0;
        return (false);
    }

    x = t->x + t->velocity;
    if (thing_hit_solid_obstacle(level, t, x, y)) {
        t->velocity /= 2;

        x = t->x + t->velocity;
        if (thing_hit_solid_obstacle(level, t, x, y)) {
            t->velocity /= 2;

            x = t->x + t->velocity;
            if (thing_hit_solid_obstacle(level, t, x, y)) {
                t->velocity /= 2;

                x = t->x + t->velocity;
                if (thing_hit_solid_obstacle(level, t, x, y)) {
                    t->velocity = 0;
                    return (false);
                }
            }
        }
    }

    t->velocity *= 0.90;

    thing_wid_update(level, t, x, y, true, false /* is new */);

    thing_handle_collisions(level, t);

    return (true);
}

static void thing_wid_move (levelp level,
                            thingp t, 
                            double x, 
                            double y, 
                            uint8_t smooth)
{
    double dist = DISTANCE(t->x, t->y, x, y);

    if (smooth) {
        if (dist == 0.0) {
            return;
        }
    }

    widp w = t->wid;

    thing_move_to(t, x, y);

    x *= game.tile_width;
    y *= game.tile_height;
    x += game.tile_width / 2;
    y += game.tile_height / 2;

    fpoint tl = { x, y };
    fpoint br = { x, y };

    if (!w) {
        /*
         * Player has left the level?
         */
        THING_LOG(t, "Trying to move but has no widget");
        return;
    }

    tilep tile = wid_get_tile(w);
    double tw = tile_get_width(tile);
    double th = tile_get_height(tile);
    double scale_x = tw / TILE_WIDTH; 
    double scale_y = th / TILE_HEIGHT; 

    double tile_width = game.tile_width;
    double tile_height = game.tile_height;

    if (scale_x > 1) {
        tile_width *= scale_x;
        tile_height *= scale_y;
    }

    br.x += tile_width / 2.0;
    br.y += tile_height / 2.0;
    tl.x -= tile_width / 2.0;
    tl.y -= tile_height / 2.0;

    /*
     * Now the tile itself has a shadow that is 1/4 of the pixels.
     * The center is 24x24 and with shadow it is 32x32. We need to
     * stretch the tile so it overlaps so the inner 24x24 if seamless.
     */
#if 0
    double tile_width = ((br.x - tl.x) / 
                         (double)TILE_PIX_WIDTH) * 
                            (double)TILE_PIX_WITH_SHADOW_WIDTH;

    double tile_height = ((br.y - tl.y) / 
                         (double)TILE_PIX_HEIGHT) * 
                            (double)TILE_PIX_WITH_SHADOW_HEIGHT;
    double tile_width = (br.x - tl.x);
    double tile_height = (br.y - tl.y);

    tile_width *= 0.50;
    tile_height *= 0.50;
#endif

#if 0
    double tile_width = (br.x - tl.x);
    double tile_height = (br.y - tl.y);
#endif

#if 0
    if (thing_is_wall(t) || thing_is_door(t)) {
        tl.y -= game.tile_height / 3.0;
        br.x += game.tile_width / 3.0;
    }
#endif

#if 0
    if (scale_x == 1) {
        tl.y -= tile_height / 4.0;
        br.x += tile_width / 4.0;
    }
#endif

#if 0
    /*
     * Stretch vertically a bit and then recented. Don't do this. Overlapping 
     * wall pixels with shadows mess up.
     */
    tl.y -= tile_height / 8.0;
    tl.y += tile_height / 16.0;
    br.y += tile_height / 16.0;
#endif

    /*
     * Off the map? Perhaps between levels.
     */
    if (!w) {
        return;
    }

    /*
     * For teleporting things, no smooth move!
     */
    if (dist > 2.0) {
        wid_move_end(w);
        smooth = false;
    }

    /*
     * Player moves better in small increments.
     */
    smooth = false;

    double ms = 1000;
    ms = ms / (1.0 / dist);

    if (smooth) {
        if (t->is_jumping) {
            if (wid_is_moving(w)) {
                wid_move_end(w);
            }
        }

        wid_move_to_abs_poffset_in(w, tl, ms);
    } else {
        wid_set_tl_br(w, tl, br);
    }

    double bounce_ms = 300;

    /*
     * Make the player bounce about as they walk
     */
    if (thing_is_player(t) || 
        (thing_is_monst(t) && (t->scale == 1.0))) {

        if (!t->fall_speed && !t->jump_speed) {
            if (!w->bouncing) {
                wid_bounce_to_pct_in(w, 0.1, 0.9, bounce_ms, 0);
            }

            /*
             * And their little weapon too.
             */
            widp weapon_wid = thing_get_weapon_carry_anim_wid(level, t);
            if (weapon_wid) {
                wid_bounce_to_pct_in(weapon_wid, 0.15, 0.9, bounce_ms, 0);
            }
        }
    }
}

void thing_wid_update (levelp level,
                       thingp t, 
                       double x, double y, 
                       uint8_t smooth,
                       uint8_t is_new)
{
    verify(t);

    thing_wid_move(level, t, x, y, smooth);

    widp w = t->wid;

    /*
     * Update the weapon being carried.
     */
    thingp weapon_carry_anim = thing_weapon_carry_anim(level, t);
    if (weapon_carry_anim) {
        weapon_carry_anim->dir = t->dir;
        thing_wid_move(level, weapon_carry_anim, x, y, smooth);
        wid_set_blit_y_offset(weapon_carry_anim->wid, w->blit_y_offset);
    }

    /*
     * Update the weapon being swung.
     */
    thingp weapon_swing_anim = thing_weapon_swing_anim(level, t);
    if (weapon_swing_anim) {
        double dx = 0;
        double dy = 0;

        weapon_swing_anim->dir = t->dir;
        thing_weapon_swing_offset(level, t, &dx, &dy);
        thing_wid_move(level, weapon_swing_anim, x + dx, y + dy, smooth);
        wid_set_blit_y_offset(weapon_swing_anim->wid, w->blit_y_offset);
    }
}
#endif
