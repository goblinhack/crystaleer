//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_level_ph2_room.hpp"
#include "my_ptrcheck.hpp"
#include "my_vector_bounds_check.hpp"

LevelPh2Rooms LevelPh2Room::all_rooms_of_type[ ROOM_TYPE_MAX ];
LevelPh2Rooms LevelPh2Room::all_rooms;

void level_ph2_init(void) { TRACE_NO_INDENT(); }

void level_ph2_fini(void)
{
  TRACE_NO_INDENT();
  for (auto &r : LevelPh2Room::all_rooms) {
    delete r;
  }
}

LevelPh2Room::LevelPh2Room(void)
{
  TRACE_NO_INDENT();
  this->roomno = all_rooms.size();
  newptr(MTYPE_ROOM, this, "room");
}

LevelPh2Room::~LevelPh2Room(void)
{
  TRACE_NO_INDENT();
  oldptr(MTYPE_ROOM, this);
}

LevelPh2Roomp LevelPh2Room::flip(void)
{
  TRACE_NO_INDENT();
  auto f = new LevelPh2Room();

  f->type        = type;
  f->exits_up    = 0;
  f->exits_down  = 0;
  f->exits_left  = exits_right;
  f->exits_right = exits_left;

  //
  // Bit reverse
  //
  for (auto x = 0; x < LEVEL_PH2_ROOM_WIDTH; x++) {
    if (exits_up & (1 << x)) {
      f->exits_up |= 1 << (LEVEL_PH2_ROOM_WIDTH - x - 1);
    }
    if (exits_down & (1 << x)) {
      f->exits_down |= 1 << (LEVEL_PH2_ROOM_WIDTH - x - 1);
    }
  }

  for (auto x = 0; x < LEVEL_PH2_ROOM_WIDTH; x++) {
    for (auto y = 0; y < LEVEL_PH2_ROOM_HEIGHT; y++) {
      auto c = get(data, x, y);
      set(f->data, LEVEL_PH2_ROOM_WIDTH - x - 1, y, c);
    }
  }

  return f;
}

void LevelPh2Room::dump(void)
{
  TRACE_NO_INDENT();

  CON("LevelPh2Roomno: %u", roomno);

  std::array< std::array< char, LEVEL_PH2_ROOM_WIDTH >, LEVEL_PH2_ROOM_HEIGHT > out {};

  for (auto ry = 0; ry < LEVEL_PH2_ROOM_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_PH2_ROOM_WIDTH; rx++) {
      auto c = get(data, rx, ry);
      set(out, rx, ry, c);
    }
  }

  for (auto y = 0; y < LEVEL_PH2_ROOM_HEIGHT; y++) {
    std::string s;
    for (auto x = 0; x < LEVEL_PH2_ROOM_WIDTH; x++) {
      auto c = get(out, x, y);
      if (c) {
        s += c;
      } else {
        s += ' ';
      }
    }
    CON("%s", s.c_str());
  }

  CON("Exits left %x right %x up %x down %x", exits_left, exits_right, exits_up, exits_down);
  CON("-");
}

LevelPh2Roomp room_new(void)
{
  TRACE_NO_INDENT();
  auto r = new LevelPh2Room();
  LevelPh2Room::all_rooms.push_back(r);
  return r;
}
