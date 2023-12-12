//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level_ph2.hpp"

void level_ph2_lock_init(void)
{
  //
  // Single exit left or right rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // Top left corner rooms with a right and down exit
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          v         v         v         v    "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1..1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>1........D>11.......D>"
                         " 1111..1111 1111..1111 ...1111111 1..1111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111..1111 1111..1111 1111..1111 1111..1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      v          v          v          v     ");

  //
  // Corner L shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         "          ^          ^          ^          ^ "
                         " 111111111. 111111111. 111111111. 111111111. "
                         " 111111111. 111111111. 111111111. 111111111. "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 111111111. 11111111.. 1111111.11 111111.111 "
                         " 111111111. 11111111.. 1111111.11 111111.111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11.111111. 111.11111. 1111.11111 11111.1111 "
                         " 11.111111. 111.11111. 1111.11111 11111.1111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111.111. 11111.1111 ..1111111. ..11111111 "
                         " 11111.111. 11111.1111 ...111111. ...1111111 "
                         " 11........ 11........ 1......... 1......... "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // T shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          v         v         v         v    "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1..1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111..1111 1111..1111 ..11111111 1..1111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111..1111 1111..1111 1111..1111 1111..1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      v          v          v          v     ");

  //
  // Left/right shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // T shape, sideways rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         " #           #           #           #       "
                         " .111111111 1.11111111 11.1111111 111.111111 "
                         " ...1111111 1.11111111 11.1111111 111.111111 "
                         " 11...1..11 1.......11 11......11 11......11 "
                         " 11...1..11 11..1...11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1111.....D>11.......D>11.......D>11.......D>"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 11........ 11.......1 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 11.1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   #           #           #           #     "
                         " 11.1111111 111.111111 1111.11111 1......H.. "
                         " 1..1111111 111.111111 1111.11111 111...1H11 "
                         " 1.......11 11......11 11......11 1......H.. "
                         " 11......11 11......11 11......11 11111..H.. "
                         " 11......11 11......11 11......11 1...1..H.. "
                         " 11.......D>11.......D>11.......D>1...D..H..>"
                         " 1111..1111 1111..1111 ...1111111 1..1111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         " 11111.1111 11111.1111 ...1111111 1.11111111 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.......D>11.......D>11.......D>11.......D>"
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      #          #          #          #     ");

  //
  // Four way rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         " #           #           #           #       "
                         " .111111111 1.11111111 11.1111111 111.111111 "
                         " ...1111111 1.11111111 11.1111111 111.111111 "
                         " 11......11 1.......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 11........ 11.......1 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1..1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   #           #           #           #     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 1..1111111 111.111111 1111.11111 11111.1111 "
                         " 1.......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111..1111 1111..1111 ..11111111 1.11111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         " 11111.1111 11111.1111 ...1111111 1.11111111 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      #          #          #          #     ");

  //
  // T shape, upside down rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         " ^           ^           ^           ^       "
                         " .111111111 1.11111111 11.1111111 111.111111 "
                         " ...1111111 1.11111111 11.1111111 111.111111 "
                         " 11......11 1.......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 11........ 11.......1 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 1..1111111 111.111111 1111.11111 11111.1111 "
                         " 1.......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         " 11111.1111 11111.1111 ...1111111 1.11111111 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........D#.........D#.........D#.........D#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // Up rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         " ^           ^           ^           ^       "
                         " ..11111111 ..11111111 11D1111111 111D111111 "
                         " .D..111111 1D..111111 11..111111 11..111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 111111111D 11111111D1 1111111D11 111111D111 "
                         " 11111..... 11111....1 11111...11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11D1111111 111D111111 1111D11111 11111D1111 "
                         " 11.1111.11 11..111111 11......11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111D1111 11111D1111 D111111111 1D11111111 "
                         " 1111....11 1111....11 1...111111 1...111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // Up/down rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         " #           #           #           #       "
                         " ..11111111 ..11111111 11.1111111 111.111111 "
                         " ....111111 1...111111 11..111111 11..111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.....D.1 11.....D.1 11...D..11 11..D...11 "
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 11111111.. 11111111.1 1111111.11 111111.111 "
                         " 11111....1 11111....1 11111...11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11..D...11 11...D..11 11....D.11 1..D....11 "
                         " 11..111111 111..11111 1111..1111 1111...111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   #           #           #           #     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 11.1111.11 11..111111 11......11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11.D....11 11.D....11 1..D....11 1...D...11 "
                         " 1111...111 1111...111 ...1111111 1..1111111 "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         " 1111....11 1111....11 ....111111 1...111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11....D.11 11....D.11 11.D....11 11.D....11 "
                         " 1111..1111 1111..1111 1111..1111 1111..1111 "
                         " 11111.1111 1111.11111 1111.11111 11111.1111 "
                         "      #         #          #           #     ");

  //
  // Down rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_LOCK,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1.....D..1 1....D...1 1...D....1 1...D....1 "
                         " 11111111.. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          v         v         v         v    "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1....D...1 1.....D..1 1....D...1 1..D.....1 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 1..D.....1 1.....D..1 1......D.. 1.....D..1 "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1....D...1 1......D.1 1....D...1 1.....D..1 "
                         " 1111.11111 1111.11111 1111.11111 1111.11111 "
                         " 1111.11111 1111.11111 1111.11111 1111.11111 "
                         "     v          v          v          v      ");
}
