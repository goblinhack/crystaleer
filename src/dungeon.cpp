//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_dungeon.hpp"
#include "my_dungeon_grid.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_room.hpp"
#include "my_template.hpp"

class Dungeon
{
private:
public:
  Dungeon(void) {}
  ~Dungeon(void) {}

  std::array< std::array< Roomp, ROOMS_DOWN >, ROOMS_ACROSS > rooms {};
};

void add_dungeon(const char *data)
{
  TRACE_NO_INDENT();
  const auto row_len      = (((ROOM_WIDTH + 1) * ROOMS_ACROSS) + 1);
  auto       expected_len = (row_len) * (((ROOM_HEIGHT + 1) * ROOMS_DOWN) + 1);

  if (strlen(data) != expected_len) {
    DIE("bad room size, expected %d, got %d", (int) strlen(data), (int) expected_len);
  }

  //
  // Break the grid of rooms up into individual rooms
  //
  for (auto room_across = 0; room_across < ROOMS_ACROSS; room_across++) {
    for (auto room_down = 0; room_down < ROOMS_DOWN; room_down++) {
      auto r  = room_new();
      r->type = ROOM_TYPE_NORMAL;

      for (auto ry = 0; ry < ROOM_HEIGHT; ry++) {
        for (auto rx = 0; rx < ROOM_WIDTH; rx++) {
          auto offset = row_len + (((ROOM_HEIGHT + 1) * room_down) * row_len) + (row_len * ry)
                      + (room_across * (ROOM_WIDTH + 1)) + rx + 1;
          auto c = data[ offset ];

          switch (c) {
            case CHAR_ROCK : break;
            case CHAR_WALL : break;
            case CHAR_LADDER : break;
            case CHAR_ENTRANCE :
              if (r->type != ROOM_TYPE_NORMAL) {
                DIE("room type already set when trying to set entrance");
              }
              r->type = ROOM_TYPE_ENTRANCE;
              break;
            case CHAR_EXIT :
              if (r->type != ROOM_TYPE_NORMAL) {
                DIE("room type already set when trying to set as exit");
              }
              r->type = ROOM_TYPE_EXIT;
              break;
            case CHAR_LOCK :
              if ((r->type != ROOM_TYPE_NORMAL) && (r->type != ROOM_TYPE_LOCK)) {
                DIE("room type already set when trying to set as lock");
              }
              r->type = ROOM_TYPE_LOCK;
              break;
            case CHAR_KEY :
              if ((r->type != ROOM_TYPE_NORMAL) && (r->type != ROOM_TYPE_KEY)) {
                DIE("room type already set when trying to set as key");
              }
              r->type = ROOM_TYPE_KEY;
              break;
            case CHAR_SECRET :
              if ((r->type != ROOM_TYPE_NORMAL) && (r->type != ROOM_TYPE_SECRET)) {
                DIE("room type already set when trying to set as secret");
              }
              r->type = ROOM_TYPE_SECRET;
              break;
            case CHAR_EMPTY : break;
            default : DIE("unexpected room char '%c'", c);
          }

          r->data[ rx ][ ry ] = c;

          if (rx == 0) {
            auto c = data[ offset - 1 ];
            if (c == CHAR_CONNECTOR) {
              r->exits_left |= 1U << (ROOM_HEIGHT - ry - 1);
            }
          } else if (rx == ROOM_WIDTH - 1) {
            auto c = data[ offset + 1 ];
            if (c == CHAR_CONNECTOR) {
              r->exits_right |= 1U << (ROOM_HEIGHT - ry - 1);
            }
          }

          if (ry == 0) {
            auto c = data[ offset - row_len ];
            if (c == CHAR_CONNECTOR) {
              r->exits_up |= 1U << (ROOM_WIDTH - rx - 1);
            }
          } else if (ry == ROOM_HEIGHT - 1) {
            auto c = data[ offset + row_len ];
            if (c == CHAR_CONNECTOR) {
              r->exits_down |= 1U << (ROOM_WIDTH - rx - 1);
            }
          }
        }
      }

      if (r->type != ROOM_TYPE_SECRET) {
        if (! r->exits_left && ! r->exits_right && ! r->exits_up && ! r->exits_down) {
          DIE("room %u has no exits", r->roomno);
        }
      }

      Room::all_rooms_of_type[ r->type ].push_back(r);
      // auto f = r->flip();
      // Room::all_rooms_of_type[ f->type ].push_back(f);
    }
  }
}

static Roomp get_fitted_room_type(DungeonNode *node, Roomp room_left, Roomp room_right, Roomp room_up,
                                  Roomp room_down)
{
  TRACE_NO_INDENT();

  auto required_room_type = ROOM_TYPE_NORMAL;

  if (node->is_entrance) {
    required_room_type = ROOM_TYPE_ENTRANCE;
  }
  if (node->is_exit) {
    required_room_type = ROOM_TYPE_EXIT;
  }
  if (node->is_key) {
    required_room_type = ROOM_TYPE_KEY;
  }
  if (node->is_lock) {
    required_room_type = ROOM_TYPE_LOCK;
  }
  if (node->is_secret) {
    required_room_type = ROOM_TYPE_SECRET;
  }

  int  max_elems = Room::all_rooms_of_type[ required_room_type ].size();
  auto tries     = max_elems * 4;

  while (tries-- > 0) {
    auto r = pcg_one_of(Room::all_rooms_of_type[ required_room_type ]);
    if (! r) {
      return nullptr;
    }

    if (node->dir_left) {
      if (! r->exits_left) {
        continue;
      }
    }

    if (node->dir_right) {
      if (! r->exits_right) {
        continue;
      }
    }

    if (node->dir_up) {
      if (! r->exits_up) {
        continue;
      }
    }

    if (node->dir_down) {
      if (! r->exits_down) {
        continue;
      }
    }

    if (room_left && room_left->exits_right) {
      if (! (room_left->exits_right & r->exits_left)) {
        continue;
      }
    }

    if (room_right && room_right->exits_left) {
      if (! (room_right->exits_left & r->exits_right)) {
        continue;
      }
    }

    if (room_up && room_up->exits_down) {
      if (! (room_up->exits_down & r->exits_up)) {
        continue;
      }
    }

    if (room_down && room_down->exits_up) {
      if (! (room_down->exits_up & r->exits_down)) {
        continue;
      }
    }

    return r;
  }
  return nullptr;
}

static void dump_dungeon(Dungeon d)
{
  TRACE_NO_INDENT();

  std::array< std::array< char, MAP_HEIGHT + ROOMS_ACROSS >, MAP_WIDTH + ROOMS_DOWN > out {};

  for (auto room_across = 0; room_across < ROOMS_ACROSS; room_across++) {
    for (auto room_down = 0; room_down < ROOMS_DOWN; room_down++) {
      auto r = get(d.rooms, room_across, room_down);
      if (r) {
        for (auto ry = 0; ry < ROOM_HEIGHT; ry++) {
          for (auto rx = 0; rx < ROOM_WIDTH; rx++) {
            auto c = get(r->data, rx, ry);
            auto x = (room_across * (ROOM_WIDTH + 1)) + rx;
            auto y = (room_down * (ROOM_HEIGHT + 1)) + ry;
            set(out, x, y, c);
          }
        }
      }
    }
  }

  for (auto y = 0; y < MAP_HEIGHT + ROOMS_DOWN; y++) {
    std::string s;
    for (auto x = 0; x < MAP_WIDTH + ROOMS_ACROSS; x++) {
      auto c = get(out, x, y);
      if (c) {
        s += c;
      } else {
        s += ' ';
      }
    }
    CON("%s", s.c_str());
  }

  CON("-");
}

static bool solve_dungeon(Nodes &n, Dungeon &d, point at)
{
  TRACE_NO_INDENT();

  auto x    = at.x;
  auto y    = at.y;
  auto r    = get(d.rooms, x, y);
  auto node = n.getn(x, y);

  if (! node->on_critical_path && ! node->is_entrance) {
    // return true;
  }

  if (! r) {
    //
    // Place a room that fits
    //
    Roomp left_room;
    Roomp right_room;
    Roomp up_room;
    Roomp down_room;

    if (x > 0) {
      left_room = get(d.rooms, x - 1, y);
    } else {
      left_room = nullptr;
    }
    if (x < ROOMS_ACROSS - 1) {
      right_room = get(d.rooms, x + 1, y);
    } else {
      right_room = nullptr;
    }
    if (y > 0) {
      up_room = get(d.rooms, x, y - 1);
    } else {
      up_room = nullptr;
    }
    if (y < ROOMS_DOWN - 1) {
      down_room = get(d.rooms, x, y + 1);
    } else {
      down_room = nullptr;
    }

    //
    // Place the room
    //
    r = get_fitted_room_type(node, left_room, right_room, up_room, down_room);
    if (! r) {
      dump_dungeon(d);
      CON("COULD NOT FIT at %d,%d", x, y);
      return false;
    }
    set(d.rooms, x, y, r);
  }

  if (x > 0) {
    if (! get(d.rooms, x - 1, y)) {
      if (! solve_dungeon(n, d, point(x - 1, y))) {
        return false;
      }
    }
  }

  if (x < ROOMS_ACROSS - 1) {
    if (! get(d.rooms, x + 1, y)) {
      if (! solve_dungeon(n, d, point(x + 1, y))) {
        return false;
      }
    }
  }

  if (y > 0) {
    if (! get(d.rooms, x, y - 1)) {
      if (! solve_dungeon(n, d, point(x, y - 1))) {
        return false;
      }
    }
  }

  if (y < ROOMS_DOWN - 1) {
    if (! get(d.rooms, x, y + 1)) {
      if (! solve_dungeon(n, d, point(x, y + 1))) {
        return false;
      }
    }
  }

  return true;
}

void make_dungeon(void)
{
  TRACE_NO_INDENT();

  for (;;) {
    Dungeon d;
    Nodes   n(ROOMS_ACROSS, ROOMS_DOWN);
    point   entrance_at;
    n.dump();

    //
    // Find the starting point, the entrance
    //
    for (auto y = 0; y < n.grid_height; y++) {
      for (auto x = 0; x < n.grid_width; x++) {
        auto node = n.getn(x, y);
        if (node->is_entrance) {
          entrance_at = point(x, y);
          goto got_entrance;
        }
      }
    }

    continue;

  got_entrance:
    //
    // Create all the rooms
    //
    if (solve_dungeon(n, d, entrance_at)) {
      dump_dungeon(d);
      CON("ALL GOOD");
      exit(1);
      return;
    }
    exit(1);
  }

//
// Place the exit and entrance
//
#if 0
  Roomp entrance = get_random_room_type(ROOM_TYPE_ENTRANCE);
  point entrance_at(pcg_random_range(1, ROOMS_ACROSS - 2), 0);
  set(d.rooms, entrance_at.x, entrance_at.y, entrance);

  Roomp exit = get_random_room_type(ROOM_TYPE_ENTRANCE);
  point exit_at(pcg_random_range(1, ROOMS_ACROSS - 2), ROOMS_DOWN - 1);
  set(d.rooms, exit_at.x, exit_at.y, exit);
#endif
}
