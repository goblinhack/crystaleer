/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include "main.h"
#include "tile.h"
#include "thing_tile.h"
#include "python.h"
#include "config.h"

int thing_tile_count = 1;
thing_tile thing_tile_arr[TILES_ANIM_MAX];

void thing_tile_free (thing_tile *t)
{
    myfree(t->tilename);

    oldptr(t);
}

const char *thing_tile_name (thing_tile *t)
{
    return (t->tilename);
}

uint32_t thing_tile_delay_ms (thing_tile *t)
{
    return (t->delay_ms);
}

uint8_t thing_tile_is_moving (thing_tilep t)
{
    return (t->is_moving);
}

uint8_t thing_tile_is_dir_down (thing_tilep t)
{
    return (t->dir == THING_DIR_DOWN);
}

uint8_t thing_tile_is_dir_up (thing_tilep t)
{
    return (t->dir == THING_DIR_UP);
}

uint8_t thing_tile_is_dir_left (thing_tilep t)
{
    return (t->dir == THING_DIR_LEFT);
}

uint8_t thing_tile_is_dir_right (thing_tilep t)
{
    return (t->dir == THING_DIR_RIGHT);
}

uint8_t thing_tile_is_dir_none (thing_tilep t)
{
    return (t->dir == THING_DIR_NONE);
}

uint8_t thing_tile_is_dir_tl (thing_tilep t)
{
    return (t->dir == THING_DIR_TL);
}

uint8_t thing_tile_is_dir_bl (thing_tilep t)
{
    return (t->dir == THING_DIR_BL);
}

uint8_t thing_tile_is_dir_tr (thing_tilep t)
{
    return (t->dir == THING_DIR_TR);
}

uint8_t thing_tile_is_dir_br (thing_tilep t)
{
    return (t->dir == THING_DIR_BR);
}

uint8_t thing_tile_is_yyy5 (thing_tilep t)
{
    return (t->is_yyy5);
}

uint8_t thing_tile_is_yyy6 (thing_tilep t)
{
    return (t->is_yyy6);
}

uint8_t thing_tile_is_yyy7 (thing_tilep t)
{
    return (t->is_yyy7);
}

uint8_t thing_tile_is_yyy8 (thing_tilep t)
{
    return (t->is_yyy8);
}

uint8_t thing_tile_is_yyy9 (thing_tilep t)
{
    return (t->is_yyy9);
}

uint8_t thing_tile_is_yyy10 (thing_tilep t)
{
    return (t->is_yyy10);
}

uint8_t thing_tile_is_yyy11 (thing_tilep t)
{
    return (t->is_yyy11);
}

uint8_t thing_tile_is_yyy12 (thing_tilep t)
{
    return (t->is_yyy12);
}

uint8_t thing_tile_is_yyy13 (thing_tilep t)
{
    return (t->is_yyy13);
}

uint8_t thing_tile_is_yyy14 (thing_tilep t)
{
    return (t->is_yyy14);
}

uint8_t thing_tile_is_sleeping (thing_tilep t)
{
    return (t->is_sleeping);
}

uint8_t thing_tile_is_open (thing_tilep t)
{
    return (t->is_open);
}

uint8_t thing_tile_is_dead (thing_tilep t)
{
    return (t->is_dead);
}

uint8_t thing_tile_is_end_of_anim (thing_tilep t)
{
    return (t->is_end_of_anim);
}

uint8_t thing_tile_is_dead_on_end_of_anim (thing_tilep t)
{
    return (t->is_dead_on_end_of_anim);
}

thing_tilep thing_tile_random (tree_rootp root)
{
    thing_tilep thing_tile;

    do {

        thing_tile = (TYPEOF(thing_tile)) tree_root_get_random(root);

        /*
         * Filter out terminal state tiles.
         */
        if (thing_tile->is_dead) {
            continue;
        }

    } while (0);

    if (thing_tile) {
        verify(thing_tile);
    }

    return (thing_tile);
}

thing_tilep thing_tile_first (tree_rootp root)
{
    thing_tilep thing_tile;

    thing_tile = (TYPEOF(thing_tile)) tree_root_first(root);

    if (thing_tile) {
        verify(thing_tile);
    }

    return (thing_tile);
}

thing_tilep thing_tile_next (tree_rootp root, thing_tilep in)
{
    thing_tile cursor;
    thing_tilep next;

    verify(in);

    memset(&cursor, 0, sizeof(cursor));
    cursor.tree.key = in->tree.key;

    next = (TYPEOF(next)) tree_get_next(root,
                                        tree_root_top(root),
                                        &cursor.tree.node);
    if (next) {
        verify(next);
    }

    return (next);
}

thing_tilep thing_tile_get_xy (tree_root *root, int x, int y)
{
#define R 128
    static int rands[R][R];
    static int done;

    if (!done) {
        int ix, iy;
        for (ix = 0; ix < R; ix++) {
            for (iy = 0; iy < R; iy++) {
                rands[ix][iy] = myrand();
            }
        }

        done = true;
    }

    tree_node *top;
    uint32_t size;
    uint32_t r;

    top = root->node;
    if (!top) {
        return (0);
    }

    size = tree_size(top);
    if (!size) {
        return (0);
    }

    r = (rands[x % R][y % R]) % size;

    return ((thing_tilep) tree_root_get_nth(root, r));
}
