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
  //
  // The thing template index
  //
  uint16_t tp_id;
  //
  // Layers of tiles, used in walls. Only layer 0 is animated.
  //
  uint16_t tile;
  uint16_t tile_top;
  uint16_t tile_bot;
  uint16_t tile_left;
  uint16_t tile_right;
  uint16_t tile_tl;
  uint16_t tile_tr;
  uint16_t tile_bl;
  uint16_t tile_br;
  //
  // The current tiles[] index for this template
  //
  uint16_t anim_index;
  //
  // When the next animation frame should start
  //
  uint32_t anim_ts;
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
