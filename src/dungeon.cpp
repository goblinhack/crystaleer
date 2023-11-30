//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <string.h>

#include "my_charmap.hpp"
#include "my_dungeon.hpp"
#include "my_main.hpp"
#include "my_room.hpp"

void add_dungeon(const char *data)
{
  TRACE_NO_INDENT();

  auto expected_len = ROOM_WIDTH * ROOM_HEIGHT * ROOMS_ACROSS * ROOMS_DOWN;
  expected_len += (ROOMS_ACROSS - 1) * ROOMS_DOWN * ROOM_HEIGHT;

  if (strlen(data) != expected_len) {
    DIE("bad room size, expected %d, got %d", (int) strlen(data), (int) expected_len);
  }

  //
  // Break the grid of rooms up into individual rooms
  //
  const auto row_len = (((ROOM_WIDTH + 1) * ROOMS_ACROSS) - 1);
  for (auto room_across = 0; room_across < ROOMS_ACROSS; room_across++) {
    for (auto room_down = 0; room_down < ROOMS_DOWN; room_down++) {
      auto r = room_new();

      for (auto ry = 0; ry < ROOM_HEIGHT; ry++) {
        for (auto rx = 0; rx < ROOM_WIDTH; rx++) {
          auto offset = (row_len * ROOM_HEIGHT * room_down) + (row_len * ry) + (room_across * (ROOM_WIDTH + 1)) + rx;
          auto c      = data[ offset ];

          switch (c) {
            case CHAR_ROCK : break;
            case CHAR_WALL : break;
            case CHAR_LADDER : break;
            case CHAR_ENTRANCE : r->type = ROOM_TYPE_ENTRANCE; break;
            case CHAR_EXIT : r->type = ROOM_TYPE_EXIT; break;
            case CHAR_DOOR : r->type = ROOM_TYPE_DOOR; break;
            case CHAR_KEY : r->type = ROOM_TYPE_KEY; break;
            case CHAR_SECRET : r->type = ROOM_TYPE_SECRET; break;
          }
          r->data[ rx ][ ry ] = c;
        }
      }
    }
  }
}
