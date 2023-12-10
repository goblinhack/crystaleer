//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_PH3_OBSTACLE_HPP_
#define _MY_LEVEL_PH3_OBSTACLE_HPP_

#include <array>
#include <string>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

using LevelPh3Obstaclets = std::vector< LevelPh3Obstacletp >;

using ObstacleType = enum {
  OBSTACLE_TYPE_AIR,
  OBSTACLE_TYPE_GROUND,
  OBSTACLE_TYPE_MAX,
};

class LevelPh3Obstaclet
{
private:
public:
  static LevelPh3Obstaclets all_obsts_of_type[ OBSTACLE_TYPE_MAX ];
  static LevelPh3Obstaclets all_obsts;

  LevelPh3Obstaclet(void);
  ~LevelPh3Obstaclet(void);

  //
  // Unique per obst.
  //
  uint32_t     obstno {0};
  ObstacleType type;
  uint8_t      width {LEVEL_PH3_OBSTACLE_WIDTH};
  uint8_t      height {LEVEL_PH3_OBSTACLE_HEIGHT};

  std::array< std::array< char, LEVEL_PH3_OBSTACLE_HEIGHT >, LEVEL_PH3_OBSTACLE_WIDTH > data {};

  LevelPh3Obstacletp flip(void);
  void               dump(void);
};

void level_ph3_init(void);
void level_ph3_fini(void);

LevelPh3Obstacletp obstacle_new(void);

void level_ph3_obstacle_init(void);
void level_ph3_obstacle_add(ObstacleType, const char *);

#endif
