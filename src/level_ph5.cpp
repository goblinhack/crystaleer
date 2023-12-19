//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_dice.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph4.hpp"
#include "my_level_ph5.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_random.hpp"
#include "my_template.hpp"
#include "my_thing_template.hpp"

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

  ok = true;
}

LevelPh5 level_ph5(const LevelPh4 &ph4)
{
  TRACE_NO_INDENT();

  LevelPh5 ph5(ph4);

  return ph5;
}
