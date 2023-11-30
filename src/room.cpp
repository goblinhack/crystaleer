//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_ptrcheck.hpp"
#include "my_room.hpp"
#include "my_vector_bounds_check.hpp"

std::vector< Roomp > Room::all_rooms;

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
  this->roomno = all_rooms.size();
  newptr(MTYPE_ROOM, this, "room");
}

Room::~Room(void) { oldptr(MTYPE_ROOM, this); }

Roomp room_new(void)
{
  TRACE_NO_INDENT();

  auto r = new Room();
  Room::all_rooms.push_back(r);
  return r;
}
