
//
// Copyright Neil McGill, goblinhack@gmail.com
//
#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_level.hpp"
#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_random.hpp"
#include "my_template.hpp"
#include "my_thing_template.hpp"
#include "my_tile.hpp"

void Level::assign_tiles(void)
{
  TRACE_NO_INDENT();

  for (auto y = 0; y < MAP_HEIGHT; y++) {
    for (auto x = 0; x < MAP_WIDTH; x++) {
      for (auto z = 0; z < MAP_DEPTH; z++) {
        auto tp_id = get_tp_id(x, y, z);
        if (! tp_id) {
          continue;
        }

        auto tp = tp_find(tp_id);
        if (! tp) {
          continue;
        }

        if (! tp->tiles.size()) {
          continue;
        }

        if (tp->is_ladder) {
          if (is_ladder(x, y - LEVEL_PH4_BLOCK_HEIGHT) && is_ladder(x, y + LEVEL_PH4_BLOCK_HEIGHT)) {
            auto tile = tile_n(&tp->tiles, pcg_random_range_inclusive(1, tp->tiles.size() - 2));
            if (tile) {
              set_tp_tile(x, y, z, LAYER_0, tile);
            }
          } else if (! is_ladder(x, y - LEVEL_PH4_BLOCK_HEIGHT)) {
            auto tile = tile_n(&tp->tiles, 0);
            if (tile) {
              set_tp_tile(x, y, z, LAYER_0, tile);
            }
          } else if (! is_ladder(x, y + LEVEL_PH4_BLOCK_HEIGHT)) {
            auto tile = tile_n(&tp->tiles, tp->tiles.size() - 1);
            if (tile) {
              set_tp_tile(x, y, z, LAYER_0, tile);
            }
          }
        } else {
          auto tile = one_of(tp->tiles);
          if (tile) {
            set_tp_tile(x, y, z, LAYER_0, tile);
          }
        }
      }
    }
  }
}
