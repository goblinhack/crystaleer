//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_dice.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph3.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_random.hpp"
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
    LOG("Phase3: [%s]", s.c_str());
  }
}

bool LevelPh3::expand(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      set(data, x, y, (char) PH2_CHAR_ROCK);
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

void LevelPh3::add_obstacle_at(const LevelPh2 &ph2, point at, LevelPh3Obstacletp o)
{
  TRACE_NO_INDENT();

  for (auto y = 0; y < LEVEL_PH3_OBSTACLE_HEIGHT; y++) {
    for (auto x = 0; x < LEVEL_PH3_OBSTACLE_WIDTH; x++) {
      //
      // For each obst char, check there is a wildcard char on the level
      //
      auto c = get(o->data, x, y);
      switch (get(data, at.x + x, at.y + y)) {
        default : break;
        case PH2_CHAR_WILDCARD :
        case PH2_CHAR_OBSTACLE_AIR :
        case PH2_CHAR_OBSTACLE_GROUND : set(data, at.x + x, at.y + y, c); break;
      }
    }
  }
}

void LevelPh3::add_obstacles(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      point at(x, y);
      switch (get(data, x, y)) {
        case PH2_CHAR_OBSTACLE_AIR :
          add_obstacle_at(ph2, at, pcg_one_of(LevelPh3Obstaclet::all_obsts_of_type[ OBSTACLE_TYPE_AIR ]));
          break;
        case PH2_CHAR_OBSTACLE_GROUND :
          add_obstacle_at(ph2, at, pcg_one_of(LevelPh3Obstaclet::all_obsts_of_type[ OBSTACLE_TYPE_GROUND ]));
          break;
      }
    }
  }
}

void LevelPh3::fix_obstacles(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  const auto w = LEVEL_PH3_WIDTH;
  const auto h = LEVEL_PH3_HEIGHT;

  for (auto y = 0; y < h; y++) {
    for (auto x = 0; x < w; x++) {
      point at(x, y);
      switch (get(data, x, y)) {
        case PH2_CHAR_SPIKE_33_PERCENT :
          if (d100() > 33) {
            set(data, x, y, (char) PH2_CHAR_EMPTY);
          }
          break;
        case PH2_CHAR_WALL_100_PERCENT : break;
        case PH2_CHAR_WALL_50_PERCENT :
          if (d100() > 50) {
            set(data, x, y, (char) PH2_CHAR_EMPTY);
          } else {
            set(data, x, y, (char) PH2_CHAR_WALL_100_PERCENT);
          }
      }
    }
  }
}

LevelPh3::LevelPh3(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  LOG("Initial layout:");
  expand(ph2);
  dump();

  LOG("Add obstacles:");
  add_obstacles(ph2);
  dump();

  LOG("Fix obstacles with a chance of appearing:");
  fix_obstacles(ph2);
  dump();

  ok = true;
}

LevelPh3 level_ph3(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  LevelPh3 ph3(ph2);

  return ph3;
}