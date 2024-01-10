//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_THING_HPP_
#define _MY_THING_HPP_

#include "my_sys.hpp"
#include "my_thing_id.hpp"

struct Thing {
  ThingId  id;
  uint16_t tp_id;
  uint16_t tick;
  int16_t  pix_x; /* Scaled up by PIX_SCALE */
  int16_t  pix_y; /* Scaled up by PIX_SCALE */
  int8_t   dx;
  int8_t   dy;
};

using Thingp = struct Thing *;

#endif
