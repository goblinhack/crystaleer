//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_H_
#define _MY_LEVEL_H_

#include <inttypes.h>

#include "my_fwd.hpp"
#include "my_level_data.hpp"

class Level
{
public:
  Level();
  ~Level();

  LevelDatap data {};

  TpId is_oob(uint8_t x, uint8_t y);

  bool        set_tpid(uint8_t x, uint8_t y, uint8_t z, TpId);
  inline void set_tpid_nocheck(uint8_t x, uint8_t y, uint8_t z, TpId tpid) { data->tpid[ x ][ y ][ z ] = tpid; }

  TpId        get_tpid(uint8_t x, uint8_t y, uint8_t z);
  inline TpId get_tpid_nocheck(uint8_t x, uint8_t y, uint8_t z) { return data->tpid[ x ][ y ][ z ]; }

  void display(void);
};

#endif // _MY_LEVEL_H_
