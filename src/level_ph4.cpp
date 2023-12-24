//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_dice.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph3.hpp"
#include "my_level_ph4.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_random.hpp"
#include "my_template.hpp"

void LevelPh4::dump(void)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH4_WIDTH;
  const auto h = LEVEL_PH4_HEIGHT;

  for (auto y = 0; y < h; y++) {
    std::string s;
    for (auto x = 0; x < w; x++) {
      auto c = get(data, x, y);
      if (c) {
        s += c;
      } else {
        s += ' ';
      }
    }
    LOG("Phase4: [%s]", s.c_str());
  }
}

static bool is_oob(int x, int y)
{
  if (x < 0) {
    return true;
  }
  if (y < 0) {
    return true;
  }
  if (x >= LEVEL_PH3_WIDTH) {
    return true;
  }
  if (y >= LEVEL_PH3_HEIGHT) {
    return true;
  }
  return false;
}

void LevelPh4::add_blocks(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      std::string match_str;

      std::array< std::array< char, LEVEL_PH4_BLOCK_HEIGHT >, LEVEL_PH4_BLOCK_WIDTH > pattern {};

      for (auto bx = 0; bx < LEVEL_PH4_BLOCK_WIDTH; bx++) {
        for (auto by = 0; by < LEVEL_PH4_BLOCK_HEIGHT; by++) {
          auto ph3_x = x + bx - 1;
          auto ph3_y = y + by - 1;
          if (is_oob(ph3_x, ph3_y)) {
            set(pattern, bx, by, ' ');
            match_str += '.';
          } else {
            auto c = get(ph3.data, ph3_x, ph3_y);
            set(pattern, bx, by, c);
            match_str += c;
          }
        }
      }

      std::vector< LevelPh4Block * > cands;

      for (auto b : LevelPh4Block::all_blocks_of_type[ BLOCK_TYPE_NORMAL ]) {
        bool matched = true;
        for (auto bx = 0; bx < LEVEL_PH4_BLOCK_WIDTH; bx++) {
          for (auto by = 0; by < LEVEL_PH4_BLOCK_HEIGHT; by++) {
            auto c = get(b->match_with, bx, by);
            if (c == '*') {
              continue;
            }
            auto d = get(pattern, bx, by);
            if (c != d) {
              matched = false;
              break;
            }
          }
          if (! matched) {
            break;
          }
        }

        if (matched) {
          cands.push_back(b);
        }
      }

      if (cands.size()) {
        auto cand = one_of(cands);
        for (auto bx = 0; bx < LEVEL_PH4_BLOCK_WIDTH; bx++) {
          for (auto by = 0; by < LEVEL_PH4_BLOCK_HEIGHT; by++) {
            auto c  = get(cand->replace_with, bx, by);
            auto nx = (x * LEVEL_PH4_BLOCK_WIDTH) + bx;
            auto ny = (y * LEVEL_PH4_BLOCK_HEIGHT) + by;
            set(data, nx, ny, c);
          }
        }
      }
    }
  }
}

bool LevelPh4::expand(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      point at(x, y);
      auto  c = get(ph3.data, x, y);

      auto nx = (x * LEVEL_PH4_BLOCK_WIDTH) + 0;
      auto ny = (y * LEVEL_PH4_BLOCK_HEIGHT) + 2;
      set(data, nx, ny, c);
    }
  }

  return true;
}

LevelPh4::LevelPh4(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  LOG("Initial layout:");
  expand(ph3);
  add_blocks(ph3);
  dump();

  ok = true;
}

LevelPh4 level_ph4(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  LevelPh4 ph4(ph3);

  return ph4;
}
