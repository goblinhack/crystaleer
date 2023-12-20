//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_bits.hpp"
#include "my_charmap.hpp"
#include "my_level_ph4.hpp"
#include "my_level_ph5.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_random.hpp"
#include "my_template.hpp"
#include "my_thing_template.hpp"
#include "my_tilemap.hpp"

static Tilep auto_tile_tmp[ LEVEL_PH5_WIDTH ][ LEVEL_PH5_HEIGHT ];

static bool is_oob(int x, int y)
{
  if (x < 0) {
    return true;
  }
  if (y < 0) {
    return true;
  }
  if (x >= LEVEL_PH5_WIDTH) {
    return true;
  }
  if (y >= LEVEL_PH5_HEIGHT) {
    return true;
  }
  return false;
}

void LevelPh5::auto_tile_at(Tpp tp, int x, int y)
{
  uint16_t bitmap = 0;

  auto index = 0;
  for (auto dy = -1; dy <= 1; dy++) {
    for (auto dx = -1; dx <= 1; dx++) {
      auto tx = x + dx;
      auto ty = y + dy;

      if (is_oob(tx, ty)) {
        continue;
      }

      if (data.tp[ tx ][ ty ][ tp->z_depth ].id == tp->id) {
        bitmap |= 1U << index;
      }
      index++;
    }
  }

  //
  // Exact match
  //
  for (const auto &tilemap : Tilemap::all_tilemaps[ tp->name ]) {
    if (tilemap.pattern_bitmap == bitmap) {
      auto r                  = tilemap.replace_with;
      auto_tile_tmp[ x ][ y ] = one_of(r);
      return;
    }
  }

  if (0) {
    Tilemap  best {};
    uint16_t best_match = 0;

    for (const auto &tilemap : Tilemap::all_tilemaps[ tp->name ]) {
      auto intersection = tilemap.pattern_bitmap & bitmap;
      if (intersection) {
        uint16_t this_match = bitcount(intersection);
        if (! best_match || (this_match > best_match)) {
          best       = tilemap;
          best_match = this_match;
        }
      }
    }

    if (best_match) {
      auto_tile_tmp[ x ][ y ] = one_of(best.replace_with);
    }
  }
}

void LevelPh5::auto_tile(std::string what)
{
  auto tp = tp_find(what);
  if (! tp) {
    return;
  }

  memset(auto_tile_tmp, 0, sizeof(auto_tile_tmp));

  const auto w = LEVEL_PH5_WIDTH;
  const auto h = LEVEL_PH5_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      if (data.tp[ x ][ y ][ tp->z_depth ].id == tp->id) {
        auto_tile_at(tp, x, y);
      }
    }
  }

  auto bad_tile = tile_find("t1.6.13");
  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      Tilep t = auto_tile_tmp[ x ][ y ];
      if (t) {
        data.tp[ x ][ y ][ tp->z_depth ].tile = t->global_index;
      } else if (data.tp[ x ][ y ][ tp->z_depth ].id == tp->id) {
        data.tp[ x ][ y ][ tp->z_depth ].tile = bad_tile->global_index;
      }
    }
  }
}

void LevelPh5::add_objects(const LevelPh4 &ph4)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH5_WIDTH;
  const auto h = LEVEL_PH5_HEIGHT;

  memset(data.tp, 0, sizeof(data.tp));

  for (auto y = 0; y < h; y++) {
    std::string s;
    for (auto x = 0; x < w; x++) {
      auto c  = get(ph4.data, x, y);
      Tpp  tp = nullptr;
      switch (c) {
        case PH2_CHAR_CONNECTOR : break;
        case PH2_CHAR_DOWN : break;
        case PH2_CHAR_EMPTY : break;
        case PH2_CHAR_ENTRANCE : break;
        case PH2_CHAR_EXIT : break;
        case PH2_CHAR_KEY : break;
        case PH2_CHAR_LADDER : break;
        case PH2_CHAR_LEFT : break;
        case PH2_CHAR_LOCK : break;
        case PH2_CHAR_OBSTACLE_AIR : break;
        case PH2_CHAR_OBSTACLE_GROUND : break;
        case PH2_CHAR_RIGHT : break;
        case PH2_CHAR_ROCK : tp = tp_random_rock(); break;
        case PH2_CHAR_SECRET_DOOR : break;
        case PH2_CHAR_SPIKE_33_PERCENT : break;
        case PH2_CHAR_UP : break;
        case PH2_CHAR_WALL_100_PERCENT :
        case PH2_CHAR_WALL_50_PERCENT : tp = tp_random_wall(); break;
        case PH2_CHAR_WILDCARD : break;
      }

      if (tp) {
        data.tp[ x ][ y ][ tp->z_depth ].id = tp->id;
      }
    }
  }
}

LevelPh5::LevelPh5(const LevelPh4 &ph4)
{
  TRACE_NO_INDENT();

  add_objects(ph4);

  // auto_tile("rock");
  auto_tile("wall");

  ok = true;
}

LevelPh5 level_ph5(const LevelPh4 &ph4)
{
  TRACE_NO_INDENT();

  LevelPh5 ph5(ph4);

  return ph5;
}
