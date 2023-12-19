//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_H_
#define _MY_LEVEL_H_

#include <inttypes.h>

#include "my_fwd.hpp"
#include "my_level_data.hpp"
#include "my_point.hpp"

class Level
{
public:
  Level();
  ~Level();

  LevelDatap data {};

  //
  // Map scroll offset
  //
  point pixel_map_at;

  bool is_oob(uint8_t x, uint8_t y);

  bool set_tp_id(uint8_t x, uint8_t y, uint8_t z, TpId);
  void set_tp_id_no_check(uint8_t x, uint8_t y, uint8_t z, TpId);
  TpId get_tp_id(uint8_t x, uint8_t y, uint8_t z);
  TpId get_tp_id_no_check(uint8_t x, uint8_t y, uint8_t z);

  bool  set_tp_tile(uint8_t x, uint8_t y, uint8_t z, Tilep);
  void  set_tp_tile_no_check(uint8_t x, uint8_t y, uint8_t z, Tilep);
  Tilep get_tp_tile(uint8_t x, uint8_t y, uint8_t z);
  Tilep get_tp_tile_no_check(uint8_t x, uint8_t y, uint8_t z);

  void display(void);
};

#endif // _MY_LEVEL_H_
