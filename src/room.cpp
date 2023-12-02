//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_ptrcheck.hpp"
#include "my_room.hpp"
#include "my_vector_bounds_check.hpp"

std::vector< Roomp > Room::all_rooms;
std::vector< Roomp > Room::all_rooms_of_type[ ROOM_TYPE_MAX ];

void rooms_init(void) { TRACE_NO_INDENT(); }

void rooms_fini(void)
{
  TRACE_NO_INDENT();
  for (auto &r : Room::all_rooms) {
    delete r;
  }
}

Room::Room(void)
{
  TRACE_NO_INDENT();
  this->roomno = all_rooms.size();
  newptr(MTYPE_ROOM, this, "room");
}

Room::~Room(void)
{
  TRACE_NO_INDENT();
  oldptr(MTYPE_ROOM, this);
}

Roomp Room::flip(void)
{
  TRACE_NO_INDENT();
  auto f = new Room();

  f->type        = type;
  f->exits_up    = 0;
  f->exits_down  = 0;
  f->exits_left  = exits_right;
  f->exits_right = exits_left;

  //
  // Bit reverse
  //
  for (auto x = 0; x < ROOM_WIDTH; x++) {
    if (exits_up & (1 << x)) {
      f->exits_up |= 1 << (ROOM_WIDTH - x - 1);
    }
    if (exits_down & (1 << x)) {
      f->exits_down |= 1 << (ROOM_WIDTH - x - 1);
    }
  }

  for (auto x = 0; x < ROOM_WIDTH; x++) {
    for (auto y = 0; y < ROOM_HEIGHT; y++) {
      auto c = get(data, x, y);
      set(f->data, ROOM_WIDTH - x - 1, y, c);
    }
  }

  return f;
}

Roomp room_new(void)
{
  TRACE_NO_INDENT();
  auto r = new Room();
  Room::all_rooms.push_back(r);
  return r;
}
