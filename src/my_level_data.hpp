//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_DATA_H_
#define _MY_LEVEL_DATA_H_

#include <array>
#include <inttypes.h>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

enum {
  MAP_DEPTH_WALL,
  MAP_DEPTH_OBJ,
  MAP_DEPTH,
};

//
// Simple things like walls that do not change much
//
typedef struct SimpleThing_ {
  uint16_t id;
  uint16_t tile[ LAYER_MAX ];
} SimpleThing;

typedef struct LevelData_ {
  //////////////////////////////////////////////////////////////
  // No c++ types can be used here, to allow easy level replay
  //////////////////////////////////////////////////////////////

  SimpleThing tp[ MAP_WIDTH ][ MAP_HEIGHT ][ MAP_DEPTH ];

  //////////////////////////////////////////////////////////////
  // No c++ types can be used here, to allow easy level replay
  //////////////////////////////////////////////////////////////
} LevelData;

LevelDatap level_data_constructor(void);
void       level_data_destructor(LevelDatap);

#endif // _MY_LEVEL_DATA_H_
