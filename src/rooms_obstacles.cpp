//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_main.hpp"
#include "my_room_solver.hpp"
#include "my_rooms.hpp"

void rooms_obstacles_init(void)
{
  //
  // Ground
  //
  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "11111"
                    "....."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "1111."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".1111"
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "....."
                    "11111");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "2.2.."
                    "17177");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".2.2."
                    "71717");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "..2.2"
                    "77171");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "222.."
                    "111..");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".222."
                    ".111.");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "..222"
                    "..111");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "111.."
                    "222.."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    ".111."
                    ".222."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "..111"
                    "..222"
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".222."
                    "21112");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "2.1.."
                    "77117");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "..1.2"
                    "71177");

  //
  // Air
  //
  TRACE_NO_INDENT();
  room_obstacle_add("6",
                    "11111"
                    "....."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "22222"
                    "....."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "111.."
                    "222.."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    ".111."
                    ".222."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "..111"
                    "..222"
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".111."
                    ".....");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".111."
                    ".222.");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    ".222."
                    ".111.");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "..22."
                    ".1111");

  TRACE_NO_INDENT();
  room_obstacle_add("5",
                    "....."
                    "222.."
                    "111..");
}
