//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph2_room.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_template.hpp"

class LevelPh2RoomSolver
{
private:
public:
  LevelPh2RoomSolver(void) {}
  ~LevelPh2RoomSolver(void) {}

  std::array< std::array< LevelPh2Roomp, LEVEL_PH1_DOWN >, LEVEL_PH1_ACROSS > rooms {};
};

void level_ph2_room_set_add(const char *data)
{
  TRACE_NO_INDENT();
  const auto row_len      = (((LEVEL_PH2_ROOM_WIDTH + 1) * LEVEL_PH1_ACROSS) + 1);
  auto       expected_len = (row_len) * (((LEVEL_PH2_ROOM_HEIGHT + 1) * LEVEL_PH1_DOWN) + 1);

  if (strlen(data) != expected_len) {
    DIE("bad room size, expected %d, got %d", (int) strlen(data), (int) expected_len);
  }

  //
  // Break the grid of rooms up into individual rooms
  //
  for (auto room_across = 0; room_across < LEVEL_PH1_ACROSS; room_across++) {
    for (auto room_down = 0; room_down < LEVEL_PH1_DOWN; room_down++) {
      auto r  = room_new();
      r->type = ROOM_TYPE_NORMAL;

      for (auto ry = 0; ry < LEVEL_PH2_ROOM_HEIGHT; ry++) {
        for (auto rx = 0; rx < LEVEL_PH2_ROOM_WIDTH; rx++) {
          auto offset = row_len + (((LEVEL_PH2_ROOM_HEIGHT + 1) * room_down) * row_len) + (row_len * ry)
                      + (room_across * (LEVEL_PH2_ROOM_WIDTH + 1)) + rx + 1;
          auto c = data[ offset ];

          switch (c) {
            case CHAR_ROCK : break;
            case CHAR_WILDCARD : break;
            case CHAR_WALL_100_PERCENT : break;
            case CHAR_WALL_50_PERCENT : break;
            case CHAR_SPIKE_33_PERCENT : break;
            case CHAR_OBSTACLE_GROUND : break;
            case CHAR_OBSTACLE_AIR : break;
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
            if ((c == CHAR_CONNECTOR) || (c == CHAR_LEFT)) {
              r->exits_left |= 1U << (LEVEL_PH2_ROOM_HEIGHT - ry - 1);
            }
          } else if (rx == LEVEL_PH2_ROOM_WIDTH - 1) {
            auto c = data[ offset + 1 ];
            if ((c == CHAR_CONNECTOR) || (c == CHAR_RIGHT)) {
              r->exits_right |= 1U << (LEVEL_PH2_ROOM_HEIGHT - ry - 1);
            }
          }

          if (ry == 0) {
            auto c = data[ offset - row_len ];
            if ((c == CHAR_CONNECTOR) || (c == CHAR_UP)) {
              r->exits_up |= 1U << (LEVEL_PH2_ROOM_WIDTH - rx - 1);
            }
          } else if (ry == LEVEL_PH2_ROOM_HEIGHT - 1) {
            auto c = data[ offset + row_len ];
            if ((c == CHAR_CONNECTOR) || (c == CHAR_DOWN)) {
              r->exits_down |= 1U << (LEVEL_PH2_ROOM_WIDTH - rx - 1);
            }
          }
        }
      }

      if (r->type != ROOM_TYPE_SECRET) {
        if (! r->exits_left && ! r->exits_right && ! r->exits_up && ! r->exits_down) {
          DIE("room %u has no exits", r->roomno);
        }
      }

      if (r->type == ROOM_TYPE_ENTRANCE) {
        r->exits_up = 0;
      }

      if (r->type == ROOM_TYPE_EXIT) {
        r->exits_down = 0;
      }

      // TODO
      if (r->type == ROOM_TYPE_SECRET) {
        // ok
      } else if (r->type == ROOM_TYPE_ENTRANCE) {
        // ok
      } else if (r->type == ROOM_TYPE_EXIT) {
        // ok
      } else {
        r->type = ROOM_TYPE_NORMAL;
      }
      LevelPh2Room::all_rooms_of_type[ r->type ].push_back(r);
      // r->dump();

      auto f = r->flip();
      LevelPh2Room::all_rooms_of_type[ f->type ].push_back(f);
      // f->dump();
    }
  }
}

void level_ph3_obst_add(const char key, const char *data) { TRACE_NO_INDENT(); }

static LevelPh2Roomp get_fitted_room_type(const Level1Node *node, const LevelPh2Roomp room_left,
                                          const LevelPh2Roomp room_right, const LevelPh2Roomp room_up,
                                          const LevelPh2Roomp room_down)
{
  TRACE_NO_INDENT();

  auto required_room_type = ROOM_TYPE_NORMAL;

  // TODO
  if (node->is_entrance) {
    required_room_type = ROOM_TYPE_ENTRANCE;
  }
  if (node->is_exit) {
    required_room_type = ROOM_TYPE_EXIT;
  }
  if (node->is_key) {
    required_room_type = ROOM_TYPE_KEY;
    required_room_type = ROOM_TYPE_NORMAL;
  }
  if (node->is_lock) {
    required_room_type = ROOM_TYPE_LOCK;
    required_room_type = ROOM_TYPE_NORMAL;
  }
  if (node->is_secret) {
    required_room_type = ROOM_TYPE_SECRET;
  }

  int  max_elems = LevelPh2Room::all_rooms_of_type[ required_room_type ].size();
  auto tries     = max_elems * 4;

  while (tries-- > 0) {
    auto r = pcg_one_of(LevelPh2Room::all_rooms_of_type[ required_room_type ]);
    if (! r) {
      return nullptr;
    }

    int wanted = (((node->has_door_left || node->has_secret_exit_left) ? 1 : 0) << 3)
               | (((node->has_door_right || node->has_secret_exit_right) ? 1 : 0) << 2)
               | (((node->has_door_up || node->has_secret_exit_up) ? 1 : 0) << 1)
               | ((node->has_door_down || node->has_secret_exit_down) ? 1 : 0);

    int candidate = ((r->exits_left) ? 1 : 0) << 3 | ((r->exits_right) ? 1 : 0) << 2 | ((r->exits_up) ? 1 : 0) << 1
                  | ((r->exits_down) ? 1 : 0);

    if (wanted != candidate) {
      continue;
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

static void level_dump(LevelPh2RoomSolver ph2_solver)
{
  TRACE_NO_INDENT();

  std::array< std::array< char, LEVEL_PH2_HEIGHT + LEVEL_PH1_DOWN >, LEVEL_PH2_WIDTH + LEVEL_PH1_ACROSS > out {};

  for (auto room_across = 0; room_across < LEVEL_PH1_ACROSS; room_across++) {
    for (auto room_down = 0; room_down < LEVEL_PH1_DOWN; room_down++) {
      LevelPh2Roomp r = get(ph2_solver.rooms, room_across, room_down);
      if (r) {
        for (auto ry = 0; ry < LEVEL_PH2_ROOM_HEIGHT; ry++) {
          for (auto rx = 0; rx < LEVEL_PH2_ROOM_WIDTH; rx++) {
            auto c = get(r->data, rx, ry);
            auto x = (room_across * (LEVEL_PH2_ROOM_WIDTH + 1)) + rx;
            auto y = (room_down * (LEVEL_PH2_ROOM_HEIGHT + 1)) + ry;
            set(out, x, y, c);
          }
        }
      }
    }
  }

  for (auto y = 0; y < LEVEL_PH2_HEIGHT + LEVEL_PH1_DOWN; y++) {
    std::string s;
    for (auto x = 0; x < LEVEL_PH2_WIDTH + LEVEL_PH1_ACROSS; x++) {
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

void LevelPh2::dump(void) { TRACE_NO_INDENT(); }

static bool level_recursive(const LevelPh1 &ph1, LevelPh2RoomSolver &ph2_solver, point at)
{
  TRACE_NO_INDENT();

  auto x    = at.x;
  auto y    = at.y;
  auto r    = get(ph2_solver.rooms, x, y);
  auto node = ph1.get_node_ptr_const(x, y);

  if (node->on_critical_path) {
    if (node->dir_up && ! node->dir_down && node->dir_left && node->dir_right && ! node->is_exit) {
      return false;
    }
  }

  if (! r) {
    //
    // Place a room that fits
    //
    LevelPh2Roomp left_room;
    LevelPh2Roomp right_room;
    LevelPh2Roomp up_room;
    LevelPh2Roomp down_room;

    if (x > 0) {
      left_room = get(ph2_solver.rooms, x - 1, y);
    } else {
      left_room = nullptr;
    }
    if (x < LEVEL_PH1_ACROSS - 1) {
      right_room = get(ph2_solver.rooms, x + 1, y);
    } else {
      right_room = nullptr;
    }
    if (y > 0) {
      up_room = get(ph2_solver.rooms, x, y - 1);
    } else {
      up_room = nullptr;
    }
    if (y < LEVEL_PH1_DOWN - 1) {
      down_room = get(ph2_solver.rooms, x, y + 1);
    } else {
      down_room = nullptr;
    }

    //
    // Place the room
    //
    r = get_fitted_room_type(node, left_room, right_room, up_room, down_room);
    if (! r) {
      CON("COULD NOT FIT at %d,%d", x, y);
      exit(1);
      return false;
    }
    set(ph2_solver.rooms, x, y, r);
  }

  if (x > 0) {
    if (! get(ph2_solver.rooms, x - 1, y)) {
      if (! level_recursive(ph1, ph2_solver, point(x - 1, y))) {
        return false;
      }
    }
  }

  if (x < LEVEL_PH1_ACROSS - 1) {
    if (! get(ph2_solver.rooms, x + 1, y)) {
      if (! level_recursive(ph1, ph2_solver, point(x + 1, y))) {
        return false;
      }
    }
  }

  if (y > 0) {
    if (! get(ph2_solver.rooms, x, y - 1)) {
      if (! level_recursive(ph1, ph2_solver, point(x, y - 1))) {
        return false;
      }
    }
  }

  if (y < LEVEL_PH1_DOWN - 1) {
    if (! get(ph2_solver.rooms, x, y + 1)) {
      if (! level_recursive(ph1, ph2_solver, point(x, y + 1))) {
        return false;
      }
    }
  }

  return true;
}

LevelPh2::LevelPh2(const LevelPh1 &ph1)
{
  TRACE_NO_INDENT();

  LevelPh2RoomSolver ph2_solver;
  point              entrance_at;

  //
  // Find the starting point, the entrance
  //
  for (auto y = 0; y < ph1.grid_height; y++) {
    for (auto x = 0; x < ph1.grid_width; x++) {
      auto node = ph1.get_node_ptr_const(x, y);
      if (node->is_entrance) {
        entrance_at = point(x, y);
        goto got_entrance;
      }
    }
  }

  //
  // No entrance
  //
  return;

got_entrance:
  //
  // Create all the rooms
  //
  if (level_recursive(ph1, ph2_solver, entrance_at)) {
    level_dump(ph2_solver);
    CON("ALL GOOD");
    ok = true;
    return;
  }
}

LevelPh2 level_ph2(const LevelPh1 &ph1)
{
  TRACE_AND_INDENT();

  LevelPh2 ph2(ph1);
  return ph2;
}
