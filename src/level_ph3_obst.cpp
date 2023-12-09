//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_charmap.hpp"
#include "my_level_ph3.hpp"

void level_ph3_obst_init(void)
{
  //
  // Ground
  //
  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "11111"
                     "....."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "1111."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     ".1111"
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "....."
                     "11111");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "2.2.."
                     "17177");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     ".2.2."
                     "71717");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "..2.2"
                     "77171");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "222.."
                     "111..");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     ".222."
                     ".111.");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "..222"
                     "..111");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "111.."
                     "222.."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     ".111."
                     ".222."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "..111"
                     "..222"
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     ".222."
                     "21112");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "2.1.."
                     "77117");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_GROUND,
                     "....."
                     "..1.2"
                     "71177");

  //
  // Air
  //
  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "11111"
                     "....."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "22222"
                     "....."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "111.."
                     "222.."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     ".111."
                     ".222."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "..111"
                     "..222"
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "....."
                     ".111."
                     ".....");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "....."
                     ".111."
                     ".222.");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "....."
                     ".222."
                     ".111.");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "....."
                     "..22."
                     ".1111");

  TRACE_NO_INDENT();
  level_ph3_obst_add(CHAR_OBSTACLE_AIR,
                     "....."
                     "222.."
                     "111..");
}
