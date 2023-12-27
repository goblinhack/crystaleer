//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_bits.hpp"
#include "my_charmap.hpp"
#include "my_dice.hpp"
#include "my_level_ph4.hpp"
#include "my_level_ph5.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_random.hpp"
#include "my_template.hpp"
#include "my_thing_template.hpp"
#include "my_tilemap.hpp"

static Tilep auto_tile_tmp[ LEVEL_PH5_WIDTH ][ LEVEL_PH5_HEIGHT ][ LAYER_MAX ];

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

      auto it = data.tp[ tx ][ ty ][ tp->z_depth ].tp_id;
      if (it) {
        auto tpit = tp_find(it);
        if (tpit) {
          if (tpit->is_tiled) {
            bitmap |= 1U << index;
          }
        }
      }
      index++;
    }
  }

  //
  // Exact match
  //
  for (auto layer = 0; layer < LAYER_MAX; layer++) {
    std::vector< Tilep > cands;

    for (const auto &tilemap : Tilemap::all_tilemaps[ tp->name ]) {
      if (tilemap.pattern_bitmap[ layer ] == bitmap) {
        auto r = tilemap.replace_with;
        for (auto c : r) {
          cands.push_back(c);
        }
      }
    }
    if (cands.size()) {
      auto_tile_tmp[ x ][ y ][ layer ] = one_of(cands);
    }
  }
}

//
// Returns true if an auto fill tile was placed
//
bool LevelPh5::auto_fill_at(Tpp tp, int layer, int filler_type, int x, int y)
{
  const auto w = LEVEL_PH5_WIDTH;
  const auto h = LEVEL_PH5_HEIGHT;

  //
  // Edge tiles are always filler
  //
  if ((x == 0) || (y == 0) || (x == w - 1) || (y == h - 1)) {
    if (filler_type == FILLER_MAX - 1) {
      for (const auto &tilemap : Tilemap::all_tilemaps[ tp->name ]) {
        if (tilemap.filler[ layer ][ filler_type ].size()) {
          auto r                           = tilemap.filler[ layer ][ filler_type ];
          auto_tile_tmp[ x ][ y ][ layer ] = one_of(r);
          return true;
        }
      }
    } else {
      return false;
    }
  }

  auto tp_A = &data.tp[ x - 1 ][ y ][ tp->z_depth ];
  if (! tp_A->tile[ layer ]) {
    tp_A = nullptr;
  }

  auto tp_B = &data.tp[ x + 1 ][ y ][ tp->z_depth ];
  if (! tp_B->tile[ layer ]) {
    tp_B = nullptr;
  }

  auto tp_C = &data.tp[ x ][ y - 1 ][ tp->z_depth ];
  if (! tp_C->tile[ layer ]) {
    tp_C = nullptr;
  }

  auto tp_D = &data.tp[ x ][ y + 1 ][ tp->z_depth ];
  if (! tp_D->tile[ layer ]) {
    tp_D = nullptr;
  }

  auto tp_E = &data.tp[ x - 1 ][ y - 1 ][ tp->z_depth ];
  if (! tp_E->tile[ layer ]) {
    tp_E = nullptr;
  }

  auto tp_F = &data.tp[ x + 1 ][ y - 1 ][ tp->z_depth ];
  if (! tp_F->tile[ layer ]) {
    tp_F = nullptr;
  }

  auto tp_G = &data.tp[ x - 1 ][ y + 1 ][ tp->z_depth ];
  if (! tp_G->tile[ layer ]) {
    tp_G = nullptr;
  }

  auto tp_H = &data.tp[ x + 1 ][ y + 1 ][ tp->z_depth ];
  if (! tp_H->tile[ layer ]) {
    tp_H = nullptr;
  }

  if (
      // clang-format off
      (tp_A && (tp_A->tp_id == tp->id)) ||
      (tp_B && (tp_B->tp_id == tp->id)) ||
      (tp_C && (tp_C->tp_id == tp->id)) ||
      (tp_D && (tp_D->tp_id == tp->id)) ||
      (tp_E && (tp_E->tp_id == tp->id)) ||
      (tp_F && (tp_F->tp_id == tp->id)) ||
      (tp_G && (tp_G->tp_id == tp->id)) ||
      (tp_H && (tp_H->tp_id == tp->id))
      // clang-format on
  ) {
    for (const auto &tilemap : Tilemap::all_tilemaps[ tp->name ]) {
      if (tilemap.filler[ layer ][ filler_type ].size()) {
        auto r                           = tilemap.filler[ layer ][ filler_type ];
        auto_tile_tmp[ x ][ y ][ layer ] = one_of(r);
        return true;
      }
    }
  }
  return false;
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

  for (auto y = 1; y < h - 1; y++) {
    for (auto x = 1; x < w - 1; x++) {
      if (data.tp[ x ][ y ][ tp->z_depth ].tp_id == tp->id) {
        auto_tile_at(tp, x, y);
      }
    }
  }

  //
  // Join tiles together
  //
  for (auto y = 1; y < h - 1; y++) {
    for (auto x = 1; x < w - 1; x++) {
      for (auto layer = 0; layer < LAYER_MAX; layer++) {
        Tilep t = auto_tile_tmp[ x ][ y ][ layer ];
        if (t) {
          data.tp[ x ][ y ][ tp->z_depth ].tile[ layer ] = t->global_index;
        }
      }
    }
  }

  //
  // Fill in empty blocks repeatedly
  //
  for (auto layer = 0; layer < LAYER_MAX; layer++) {
    for (auto filler = 0; filler < FILLER_MAX; filler++) {
      memset(auto_tile_tmp, 0, sizeof(auto_tile_tmp));

      for (auto y = 0; y < h; y++) {
        for (auto x = 0; x < w; x++) {
          auto *otp = &data.tp[ x ][ y ][ tp->z_depth ];
          if (otp->tp_id != tp->id) {
            continue;
          }
          if (otp->tile[ layer ]) {
            continue;
          }

          (void) auto_fill_at(tp, layer, filler, x, y);
        }
      }

      for (auto y = 0; y < h; y++) {
        for (auto x = 0; x < w; x++) {
          Tilep t = auto_tile_tmp[ x ][ y ][ layer ];
          if (t) {
            data.tp[ x ][ y ][ tp->z_depth ].tile[ layer ] = t->global_index;
          }
        }
      }
    }
  }

  //
  // Fill in any remaining empty blocks
  //
  for (auto layer = 0; layer < LAYER_MAX; layer++) {
    for (;;) {
      auto filler = FILLER_MAX - 1;
      auto got    = 0;
      memset(auto_tile_tmp, 0, sizeof(auto_tile_tmp));

      for (auto y = 0; y < h; y++) {
        for (auto x = 0; x < w; x++) {
          auto *otp = &data.tp[ x ][ y ][ tp->z_depth ];
          if (otp->tp_id != tp->id) {
            continue;
          }
          if (otp->tile[ layer ]) {
            continue;
          }
          got += auto_fill_at(tp, layer, filler, x, y) ? 1 : 0;
        }
      }

      for (auto y = 0; y < h; y++) {
        for (auto x = 0; x < w; x++) {
          for (auto layer = 0; layer < LAYER_MAX; layer++) {
            Tilep t = auto_tile_tmp[ x ][ y ][ layer ];
            if (t) {
              data.tp[ x ][ y ][ tp->z_depth ].tile[ layer ] = t->global_index;
            }
          }
        }
      }

      if (! got) {
        break;
      }
    }
  }
}

//
// Flag the remaining non tiled elements
//
void LevelPh5::auto_tile_final(void)
{
  const auto w        = LEVEL_PH5_WIDTH;
  const auto h        = LEVEL_PH5_HEIGHT;
  auto       bad_tile = tile_find_mand("bad_tile");

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      for (auto z = 0; z < MAP_DEPTH; z++) {
        SimpleThing *t = &data.tp[ x ][ y ][ z ];
        if (t->tp_id == NoTpId) {
          continue;
        }

        Tpp tp = tp_find(t->tp_id);
        if (! tp) {
          continue;
        }

        if (! tp->is_tiled) {
          continue;
        }

        bool tile_exists_here = false;
        for (auto layer = 0; layer < LAYER_MAX; layer++) {
          if (t->tile[ layer ]) {
            tile_exists_here = true;
          }
        }

        if (tile_exists_here) {
          continue;
        }

        //
        // Tp and no tile
        //
        data.tp[ x ][ y ][ z ].tile[ LAYER_0 ] = bad_tile->global_index;
      }
    }
  }
}

void LevelPh5::add_object_ids(const LevelPh4 &ph4)
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
        case PH2_CHAR_ENTRANCE : tp = tp_random_entrance(); break;
        case PH2_CHAR_EXIT : tp = tp_random_exit(); break;
        case PH2_CHAR_KEY : tp = tp_random_key(); break;
        case PH2_CHAR_LADDER : tp = tp_random_ladder(); break;
        case PH2_CHAR_ROCK_GOLD : tp = tp_random_rock_gold(); break;
        case PH2_CHAR_BLOCK : tp = tp_random_block(); break;
        case PH2_CHAR_LEFT : break;
        case PH2_CHAR_LOCK : break;
        case PH2_CHAR_OBSTACLE_AIR : break;
        case PH2_CHAR_OBSTACLE_GROUND : break;
        case PH2_CHAR_RIGHT : break;
        case PH2_CHAR_ROCK : tp = tp_random_rock(); break;
        case PH2_CHAR_SECRET_DOOR : break;
        case PH2_CHAR_SPIKE_33_PERCENT : tp = tp_random_spike(); break;
        case PH2_CHAR_UP : break;
        case PH2_CHAR_WALL_100_PERCENT :
          tp = tp_random_wall();

          //
          // Occasional gold
          //
          if (((x % LEVEL_PH4_BLOCK_WIDTH) == 1) && ((y % LEVEL_PH4_BLOCK_HEIGHT) == 1)) {
            //
            // If surrounded by rock
            //
            if ((get(ph4.data, x - LEVEL_PH4_BLOCK_WIDTH, y) == PH2_CHAR_WALL_100_PERCENT)
                && (get(ph4.data, x + LEVEL_PH4_BLOCK_WIDTH, y) == PH2_CHAR_WALL_100_PERCENT)
                && (get(ph4.data, x, y - LEVEL_PH4_BLOCK_HEIGHT) == PH2_CHAR_WALL_100_PERCENT)
                && (get(ph4.data, x, y + LEVEL_PH4_BLOCK_HEIGHT) == PH2_CHAR_WALL_100_PERCENT)) {
              if (d100() < 20) {
                auto tp = tp_random_rock_gold();
                if (tp) {
                  data.tp[ x ][ y ][ tp->z_depth ].tp_id = tp->id;
                }
              }
            }
          }
          break;
        case PH2_CHAR_WALL_50_PERCENT : tp = tp_random_wall(); break;
        case PH2_CHAR_WILDCARD : break;
      }

      if (tp) {
        data.tp[ x ][ y ][ tp->z_depth ].tp_id = tp->id;
      }
    }
  }
}

LevelPh5::LevelPh5(const LevelPh4 &ph4)
{
  TRACE_NO_INDENT();

  add_object_ids(ph4);
  auto_tile("rock");
  auto_tile("wall");
  auto_tile_final();

  ok = true;
}

LevelPh5 level_ph5(const LevelPh4 &ph4)
{
  TRACE_NO_INDENT();

  LevelPh5 ph5(ph4);

  return ph5;
}
