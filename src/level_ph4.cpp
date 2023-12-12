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

bool LevelPh4::expand(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      point at(x, y);
      auto  c = get(ph3.data, x, y);

      auto nx = (x * LEVEL_PH4_BLOCK_WIDTH) + 1;
      auto ny = (y * LEVEL_PH4_BLOCK_HEIGHT) + 1;
      set(data, nx, ny, c);

      if (0) {
        for (auto bx = 0; bx < LEVEL_PH4_BLOCK_WIDTH; bx++) {
          for (auto by = 0; by < LEVEL_PH4_BLOCK_HEIGHT; by++) {
            auto nx = (x * LEVEL_PH4_BLOCK_WIDTH) + bx;
            auto ny = (y * LEVEL_PH4_BLOCK_HEIGHT) + by;
            set(data, nx, ny, c);
          }
        }
      }
    }
  }

  return true;
}

LevelPh4::LevelPh4(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  LOG("Initial layout:");
  expand(ph3);
  dump();

  ok = true;
}

LevelPh4 level_ph4(const LevelPh3 &ph3)
{
  TRACE_NO_INDENT();

  LevelPh4 ph4(ph3);

  return ph4;
}
