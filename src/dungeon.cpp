//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <string.h>

#include "my_dungeon.hpp"
#include "my_main.hpp"
#include "my_room.hpp"

void add_dungeon(const char *dungeon)
{
  TRACE_NO_INDENT();

  auto expected_len = ROOM_WIDTH * ROOM_HEIGHT * ROOMS_ACROSS * ROOMS_DOWN;
  expected_len += (ROOMS_ACROSS - 1) * ROOMS_DOWN * ROOM_HEIGHT;

  if (strlen(dungeon) != expected_len) {
    DIE("bad room size, expected %d, got %d", (int) strlen(dungeon), (int) expected_len);
  }

  room_new(dungeon);
}
