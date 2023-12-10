//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph3.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_template.hpp"

void LevelPh3::dump(void)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

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
    CON("Phase3: [%s]", s.c_str());
  }
}

bool LevelPh3::expand(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      set(data, x, y, (char) CHAR_ROCK);
    }
  }

  for (auto room_across = 0; room_across < LEVEL_PH1_WIDTH; room_across++) {
    for (auto room_down = 0; room_down < LEVEL_PH1_HEIGHT; room_down++) {
      LevelPh2Roomp r = get(ph2.rooms, room_across, room_down);
      if (r) {
        for (auto ry = 0; ry < LEVEL_PH2_ROOM_HEIGHT; ry++) {
          for (auto rx = 0; rx < LEVEL_PH2_ROOM_WIDTH; rx++) {
            auto c = get(r->data, rx, ry);
            auto x = (room_across * LEVEL_PH2_ROOM_WIDTH) + rx;
            auto y = (room_down * LEVEL_PH2_ROOM_HEIGHT) + ry;
            set(data, x + LEVEL_PH3_MAP_BORDER, y + LEVEL_PH3_MAP_BORDER, c);
          }
        }
      }
    }
  }

  return true;
}

LevelPh3::LevelPh3(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  expand(ph2);

  ok = true;
}

LevelPh3 level_ph3(const LevelPh2 &ph2)
{
  TRACE_AND_INDENT();

  LevelPh3 ph3(ph2);

  return ph3;
}
