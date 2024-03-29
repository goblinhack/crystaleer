//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level_ph2.hpp"

void level_ph2_key_init(void)
{
  //
  // Single exit left or right rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // Top left corner rooms with a right and down exit
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          v         v         v         v    "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1..1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1.......kP 1111111111 1111111111 "
                         " 1111111111 ...H..1111 1111111111 1111111111 "
                         " 11........ 6**H*6**** 11........ 11........ "
                         " 11........ ***H****** 11........ 11........ "
                         " 11........ ***H*****. 11........ 11........ "
                         " 11.......k>..1115***.>1........k>11.......k>"
                         " 1111..1111 1....***** ...1111111 1..1111111 "
                         " 11111.1111 1111..**** .111111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111..1111 1111..1111 1111..1111 1111..1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      v          v          v          v     ");

  //
  // Corner L shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         "          ^          ^          ^          ^ "
                         " 111111111. 111111111. 111111111. 111111111. "
                         " 111111111. 111111111. 111111111. 111111111. "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 111111111. 11111111.. 1111111.11 111111.111 "
                         " 111111111. 11111111.. 1111111.11 111111.111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11.111111. 111.11111. 1111.11111 11111.1111 "
                         " 11.111111. 111.11111. 1111.11111 11111.1111 "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111.111. 11111.1111 ..1111111. ..11111111 "
                         " 11111.111. 11111.1111 ...111111. ...1111111 "
                         " 11........ 11........ 1......... 1......... "
                         " 11........ 11........ 11........ 11........ "
                         " 11........ 11........ 11........ 11........ "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // T shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          v         v         v         v    "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1..1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111..1111 1111..1111 ..11111111 1..1111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111..1111 1111..1111 1111..1111 1111..1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      v          v          v          v     ");

  //
  // Left/right shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // T shape, sideways rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         " #           #           #           #       "
                         " .111111111 1.11111111 11.1111111 111.111111 "
                         " ...1111111 1.11111111 11.1111111 111.111111 "
                         " 11......11 1.......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1111.....k>11.......k>11.......k>11.......k>"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 11........ 11.......1 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 11.1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   #           #           #           #     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 1..1111111 111.111111 1111.11111 11111.1111 "
                         " 1.......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 1111..1111 1111..1111 ...1111111 1..1111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         " 11111.1111 11111.1111 ...1111111 1.11111111 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.......k>11.......k>11.......k>11.......k>"
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      #          #          #          #     ");

  //
  // Four way rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         " #           #           #           #       "
                         " .111111111 1.11111111 11.1111111 111.111111 "
                         " ...1111111 1.11111111 11.1111111 111.111111 "
                         " 11......11 1.......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 11........ 11.......1 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1..1111111 11..111111 111..11111 1111..1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   #           #           #           #     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 1..1111111 111.111111 1111.11111 11111.1111 "
                         " 1.......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111..1111 1111..1111 ..11111111 1.11111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         " 11111.1111 11111.1111 ...1111111 1.11111111 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      #          #          #          #     ");

  //
  // T shape, upside down rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         " ^           ^           ^           ^       "
                         " .111111111 1.11111111 11.1111111 111.111111 "
                         " ...1111111 1.11111111 11.1111111 111.111111 "
                         " 11......11 1.......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         " 11........ 11.......1 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 1..1111111 111.111111 1111.11111 11111.1111 "
                         " 1.......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         " 11111.1111 11111.1111 ...1111111 1.11111111 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         "#.........k#.........k#.........k#.........k#"
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // Up rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         " ^           ^           ^           ^       "
                         " ..11111111 ..11111111 11.1111111 111.111111 "
                         " ....111111 1...111111 11..111111 11..111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11..k...11 11...k..11 11...k..11 11..k...11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 11111111.. 11111111.1 1111111.11 111111.111 "
                         " 11111....1 11111....1 11111...11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11..k...11 11...k..11 11...k..11 1...k...11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 11.1111.11 11..111111 11......11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11..k...11 11...k..11 11...k..11 1....k..11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         " 1111....11 1111....11 ....111111 1...111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11..k...11 11..k...11 11...k..11 11...k..11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "                                             ");

  //
  // Up/down rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         " #           #           #           #       "
                         " ..11111111 ..11111111 11.1111111 111.111111 "
                         " ....111111 1...111111 11..111111 11..111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11k......1 11..k....1 11.k....11 11..k...11 "
                         " 11111111.. 1111111..1 111111..11 11111..111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 11111111.. 11111111.1 1111111.11 111111.111 "
                         " 11111....1 11111....1 11111...11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11..k...11 11....k.11 11.k....11 1..k....11 "
                         " 11..111111 111..11111 1111..1111 1111...111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   #           #           #           #     "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 11.1111.11 11..111111 11......11 1111....11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11......11 11......11 11......11 1.......11 "
                         " 11.k....11 11.k....11 1.....k.11 1..k....11 "
                         " 1111...111 1111...111 ...1111111 1..1111111 "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         " 1111....11 1111....11 ....111111 1...111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11.k....11 11.k....11 11....k.11 11.k....11 "
                         " 1111..1111 1111..1111 1111..1111 1111..1111 "
                         " 11111.1111 1111.11111 1111.11111 11111.1111 "
                         "      #         #          #           #     ");

  //
  // Down rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_KEY,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1...k....1 1.....k..1 1.k......1 1..k.....1 "
                         " 11111111.. 11111111.1 1111111.11 111111.111 "
                         " 111111111. 11111111.1 1111111.11 111111.111 "
                         "          v         v         v         v    "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1...k....1 1....k...1 1.....k..1 1.k......1 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 11......11 11......11 11......1. 11......11 "
                         " 1...k....1 1..k.....1 1......k.. 1..k.....1 "
                         " 11111.1111 11111.1111 ..11111111 1.11111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 11......11 11......11 11......11 11......11 "
                         " 1..k.....1 1.k......1 1k.......1 1k.......1 "
                         " 1111.11111 1111.11111 1111.11111 1111.11111 "
                         " 1111.11111 1111.11111 1111.11111 1111.11111 "
                         "     v          v          v          v      ");
}
