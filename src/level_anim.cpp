//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_level.hpp"
#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_thing_template.hpp"

void Level::anim(void)
{
  TRACE_NO_INDENT();

  auto ts = time_ms();

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    for (auto y = miny; y < maxy; y++) {
      for (auto x = minx; x < maxx; x++) {
        auto t = &data->thing_or_tp[ x ][ y ][ slot ];
        if (! t->tp_id) {
          continue;
        }

        auto tp = tp_find(t->tp_id);
        if (! tp) {
          continue;
        }

        auto tile_index = t->tile;
        if (! tile_index) {
          continue;
        }

        auto tile = tile_index_to_tile(tile_index);
        if (! tile) {
          continue;
        }

        if (! tile->delay_ms) {
          continue;
        }

        if (ts < t->anim_ts) {
          continue;
        }

        t->anim_index++;
        if (t->anim_index >= tp->tiles.size()) {
          t->anim_index = 0;
        }

        tile       = tp->tiles[ t->anim_index ];
        t->tile    = tile->global_index;
        t->anim_ts = ts + tile->delay_ms;
      }
    }
  }
}
