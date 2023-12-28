
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
          if (is_ladder(x, y - 1) && is_ladder(x, y + 1)) {
            auto tile = tile_n(&tp->tiles, pcg_random_range_inclusive(1, tp->tiles.size() - 2));
            if (tile) {
              set_tp_tile(x, y, z, tile);
            }
          } else if (! is_ladder(x, y - 1)) {
            auto tile = tile_n(&tp->tiles, 0);
            if (tile) {
              set_tp_tile(x, y, z, tile);
            }
          } else if (! is_ladder(x, y + 1)) {
            auto tile = tile_n(&tp->tiles, tp->tiles.size() - 1);
            if (tile) {
              set_tp_tile(x, y, z, tile);
            }
          }
        } else if (tp->is_wall) {
          auto tile = tile_find("wall." + std::to_string(x % 6) + "." + std::to_string(y % 6));
          if (tile) {
            set_tp_tile(x, y, z, tile);
          }

          if (! is_wall(x, y - 1)) {
            if (tp->tiles_top.size()) {
              auto tile = one_of(tp->tiles_top);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_top = tile->global_index;
              }
            }
          }

          if (! is_wall(x, y + 1)) {
            if (tp->tiles_bot.size()) {
              auto tile = one_of(tp->tiles_bot);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_bot = tile->global_index;
              }
            }
          }

          if (! is_wall(x - 1, y)) {
            if (tp->tiles_left.size()) {
              auto tile = one_of(tp->tiles_left);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_left = tile->global_index;
              }
            }
          }

          if (! is_wall(x + 1, y)) {
            if (tp->tiles_right.size()) {
              auto tile = one_of(tp->tiles_right);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_right = tile->global_index;
              }
            }
          }

          if (! is_wall(x - 1, y - 1) && ! is_wall(x - 1, y) && ! is_wall(x, y - 1)) {
            if (tp->tiles_tl.size()) {
              auto tile = one_of(tp->tiles_tl);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_tl = tile->global_index;
              }
            }
          }

          if (! is_wall(x + 1, y - 1) && ! is_wall(x + 1, y) && ! is_wall(x, y - 1)) {
            if (tp->tiles_tr.size()) {
              auto tile = one_of(tp->tiles_tr);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_tr = tile->global_index;
              }
            }
          }

          if (! is_wall(x - 1, y + 1) && ! is_wall(x - 1, y) && ! is_wall(x, y + 1)) {
            if (tp->tiles_bl.size()) {
              auto tile = one_of(tp->tiles_bl);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_bl = tile->global_index;
              }
            }
          }

          if (! is_wall(x + 1, y + 1) && ! is_wall(x + 1, y) && ! is_wall(x, y + 1)) {
            if (tp->tiles_br.size()) {
              auto tile = one_of(tp->tiles_br);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_br = tile->global_index;
              }
            }
          }

        } else if (tp->is_rock) {
          auto tile = tile_find("rock." + std::to_string(x % 6) + "." + std::to_string(y % 6));
          if (tile) {
            set_tp_tile(x, y, z, tile);
          }

          if (y > 0) {
            if (! is_rock(x, y - 1)) {
              if (tp->tiles_top.size()) {
                auto tile = one_of(tp->tiles_top);
                if (tile) {
                  data->tp[ x ][ y ][ z ].tile_top = tile->global_index;
                }
              }
            }
          }

          if (y < MAP_HEIGHT - 1) {
            if (! is_rock(x, y + 1)) {
              if (tp->tiles_bot.size()) {
                auto tile = one_of(tp->tiles_bot);
                if (tile) {
                  data->tp[ x ][ y ][ z ].tile_bot = tile->global_index;
                }
              }
            }
          }

          if (x > 0) {
            if (! is_rock(x - 1, y)) {
              if (tp->tiles_left.size()) {
                auto tile = one_of(tp->tiles_left);
                if (tile) {
                  data->tp[ x ][ y ][ z ].tile_left = tile->global_index;
                }
              }
            }
          }

          if (x < MAP_WIDTH - 1) {
            if (! is_rock(x + 1, y)) {
              if (tp->tiles_right.size()) {
                auto tile = one_of(tp->tiles_right);
                if (tile) {
                  data->tp[ x ][ y ][ z ].tile_right = tile->global_index;
                }
              }
            }
          }

          if ((x == 0) && (y == 0)) {
            if (tp->tiles_br.size()) {
              auto tile = one_of(tp->tiles_br);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_br = tile->global_index;
              }
            }
          }

          if ((x == MAP_WIDTH - 1) && (y == 0)) {
            if (tp->tiles_bl.size()) {
              auto tile = one_of(tp->tiles_bl);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_bl = tile->global_index;
              }
            }
          }

          if ((x == 0) && (y == MAP_HEIGHT - 1)) {
            if (tp->tiles_tr.size()) {
              auto tile = one_of(tp->tiles_tr);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_tr = tile->global_index;
              }
            }
          }

          if ((x == MAP_WIDTH - 1) && (y == MAP_HEIGHT - 1)) {
            if (tp->tiles_tl.size()) {
              auto tile = one_of(tp->tiles_tl);
              if (tile) {
                data->tp[ x ][ y ][ z ].tile_tl = tile->global_index;
              }
            }
          }

        } else {
          auto tile = one_of(tp->tiles);
          if (tile) {
            set_tp_tile(x, y, z, tile);
          }
        }
      }
    }
  }
}
