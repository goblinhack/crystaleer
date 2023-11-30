//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_ROOM_HPP_
#define _MY_ROOM_HPP_

#include <array>

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

  Room(const std::string &data);
  ~Room(void);

  //
  // Unique per room.
  //
  uint32_t    roomno {0};
  room_type_t type;
  uint8_t     width {MAP_ROOM_WIDTH};
  uint8_t     height {MAP_ROOM_HEIGHT};

  std::array< std::array< char, MAP_ROOM_HEIGHT >, MAP_ROOM_WIDTH > data {};

  uint16_t exits_up {};
  uint16_t exits_down {};
  uint16_t exits_left {};
  uint16_t exits_right {};

  Roomp rooms_new(const std::string &data);
};

void rooms_init(void);
void rooms_fini(void);

#endif
