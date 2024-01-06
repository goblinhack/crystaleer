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
        Tpp  tp;
        auto t = thing_get(x, y, slot, &tp);
        if (! tp) {
          continue;
        }

        auto obj        = &data->obj[ x ][ y ][ slot ];
        auto tile_index = obj->tile;
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

        if (ts < obj->anim_ts) {
          continue;
        }

        obj->anim_index++;
        if (obj->anim_index >= tp->tiles.size()) {
          obj->anim_index = 0;
        }

        tile         = tp->tiles[ obj->anim_index ];
        obj->tile    = tile->global_index;
        obj->anim_ts = ts + tile->delay_ms;
      }
    }
  }
}
