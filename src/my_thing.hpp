//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_THING_HPP_
#define _MY_THING_HPP_

#include "my_sys.hpp"
#include "my_thing_id.hpp"

using Thing = struct Thing_ {
public:
  ThingId id {};
  constexpr Thing_() = default;
  uint16_t tp_id;
  uint16_t pix_x;
  uint16_t pix_y;
  int8_t   dx;
  int8_t   dy;
};

using Thingp = Thing *;

#endif
