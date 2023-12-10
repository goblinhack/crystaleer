//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_PH3_OBST_HPP_
#define _MY_LEVEL_PH3_OBST_HPP_

#include <array>
#include <string>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

using LevelPh3Obsts = std::vector< LevelPh3Obstp >;

using ObsType = enum {
  OBST_TYPE_AIR,
  OBST_TYPE_GROUND,
  OBST_TYPE_MAX,
};

class LevelPh3Obst
{
private:
public:
  static LevelPh3Obsts all_obsts_of_type[ OBST_TYPE_MAX ];
  static LevelPh3Obsts all_obsts;

  LevelPh3Obst(void);
  ~LevelPh3Obst(void);

  //
  // Unique per obst.
  //
  uint32_t obstno {0};
  ObsType  type;
  uint8_t  width {LEVEL_PH3_OBST_WIDTH};
  uint8_t  height {LEVEL_PH3_OBST_HEIGHT};

  std::array< std::array< char, LEVEL_PH3_OBST_HEIGHT >, LEVEL_PH3_OBST_WIDTH > data {};

  LevelPh3Obstp flip(void);
  void          dump(void);
};

void level_ph3_init(void);
void level_ph3_fini(void);

LevelPh3Obstp obst_new(void);

#endif
