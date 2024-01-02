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

  //
  // Level display bounds
  //
  int minx = {};
  int miny = {};
  int maxx = {};
  int maxy = {};

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
  void assign_tiles(void);
  void display_tile(Tpp, uint16_t, point tl, point br, point offset, bool shadow);
  void display_tile(Tpp, Tilep, point tl, point br, point offset, bool shadow);
  void anim(void);
  void display_z_layer(int z, bool shadow, bool deco);

  bool is_wall(const uint8_t x, const uint8_t y);
  bool is_wall(const point p);

  bool is_rock(const uint8_t x, const uint8_t y);
  bool is_rock(const point p);

  bool is_ladder(const uint8_t x, const uint8_t y);
  bool is_ladder(const point p);

  bool is_block(const uint8_t x, const uint8_t y);
  bool is_block(const point p);

  Thingp thing_find_optional(ThingId id);
  Thingp thing_find(ThingId id);
  Thingp thing_new(Tpp, uint8_t x, uint8_t y);
  void   thing_free(Thingp);
  void   thing_push(Thingp);
  void   thing_pop(Thingp);
};

#endif // _MY_LEVEL_H_
