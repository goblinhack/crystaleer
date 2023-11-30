//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_ROOM_HPP_
#define _MY_ROOM_HPP_

#include <array>
#include <string>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

using Rooms = std::vector< Roomp >;

using room_type_t = enum {
  ROOM_TYPE_NORMAL,
  ROOM_TYPE_ENTRANCE,
  ROOM_TYPE_EXIT,
  ROOM_TYPE_KEY,
  ROOM_TYPE_DOOR,
  ROOM_TYPE_SECRET,
};

class Room
{
private:
public:
  static Rooms all_rooms;

  Room(void);
  ~Room(void);

  //
  // Unique per room.
  //
  uint32_t    roomno {0};
  room_type_t type;
  uint8_t     width {ROOM_WIDTH};
  uint8_t     height {ROOM_HEIGHT};

  std::array< std::array< char, ROOM_HEIGHT >, ROOM_WIDTH > data {};

  uint16_t exits_up {};
  uint16_t exits_down {};
  uint16_t exits_left {};
  uint16_t exits_right {};
};

void  rooms_init(void);
void  rooms_fini(void);
Roomp room_new(void);

#endif
