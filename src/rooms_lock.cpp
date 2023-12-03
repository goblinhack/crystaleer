//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_main.hpp"
#include "my_room_solver.hpp"
#include "my_rooms.hpp"

void rooms_lock_init(void)
{
  //
  // Single exit left or right rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             ");

  //
  // Corner rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 11111111.. 1111111..1 111111..11 11111..111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      "          v         v         v         v    "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1..1111111 11..111111 111..11111 1111..1111 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      "   v           v           v           v     "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>1.........>11........>"
      " 1111..1111 1111..1111 ...1111111 1..1111111 "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      "      v          v     v           v         "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111..1111 1111..1111 1111..1111 1111..1111 "
      " 11111.1111 11111.1111 11111.1111 11111.1111 "
      "      v          v          v          v     ");

  //
  // Corner L shaped rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      "          ^          ^          ^          ^ "
      " 111111111. 111111111. 111111111. 111111111. "
      " 111111111. 111111111. 111111111. 111111111. "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "          ^         ^         ^         ^    "
      " 111111111. 11111111.. 1111111.11 111111.111 "
      " 111111111. 11111111.. 1111111.11 111111.111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "   ^           ^           ^           ^     "
      " 11.111111. 111.11111. 1111.11111 11111.1111 "
      " 11.111111. 111.11111. 1111.11111 11111.1111 "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "      ^          ^     ^           ^         "
      " 11111.111. 11111.1111 ..1111111. ..11111111 "
      " 11111.111. 11111.1111 ...111111. ...1111111 "
      " 11........ 11........ 1......... 1......... "
      " 11........ 11........ 11........ 11........ "
      " 11........ 11........ 11........ 11........ "
      " 11........>11........>11........>11........>"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             ");

  //
  // T shaped rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 11111111.. 1111111..1 111111..11 11111..111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      "          v         v         v         v    "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1..1111111 11..111111 111..11111 1111..1111 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      "   v           v           v           v     "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111..1111 1111..1111 ..11111111 1..1111111 "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      "      v          v     v           v         "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111..1111 1111..1111 1111..1111 1111..1111 "
      " 11111.1111 11111.1111 11111.1111 11111.1111 "
      "      v          v          v          v     ");

  //
  // Left/right shaped rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             ");

  //
  // T shape, sideways rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      " #           #           #           #       "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " ...1111111 1.11111111 11.1111111 111.111111 "
      " 11......11 1.......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 1111......>11........>11........>11........>"
      " 11111111.. 1111111..1 111111..11 11111..111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      "          #         #         #         #    "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      " 11........ 11.......1 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11........>11........>11........>11........>"
      " 11.1111111 11..111111 111..11111 1111..1111 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      "   #           #           #           #     "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      " 1..1111111 111.111111 1111.11111 11111.1111 "
      " 1.......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11........>11........>11........>11........>"
      " 1111..1111 1111..1111 ...1111111 1..1111111 "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      "      #          #     #           #         "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      " 11111.1111 11111.1111 ...1111111 1.11111111 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11........>11........>11........>11........>"
      " 11111.1111 11111.1111 11111.1111 11111.1111 "
      " 11111.1111 11111.1111 11111.1111 11111.1111 "
      "      #          #          #          #     ");

  //
  // Four way rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      " #           #           #           #       "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " ...1111111 1.11111111 11.1111111 111.111111 "
      " 11......11 1.......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 11111111.. 1111111..1 111111..11 11111..111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      "          #         #         #         #    "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      " 11........ 11.......1 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1..1111111 11..111111 111..11111 1111..1111 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      "   #           #           #           #     "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      " 1..1111111 111.111111 1111.11111 11111.1111 "
      " 1.......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111..1111 1111..1111 ..11111111 1.11111111 "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      "      #          #     #           #         "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      " 11111.1111 11111.1111 ...1111111 1.11111111 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 11111.1111 11111.1111 11111.1111 11111.1111 "
      " 11111.1111 11111.1111 11111.1111 11111.1111 "
      "      #          #          #          #     ");

  //
  // T shape, upside down rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      " ^           ^           ^           ^       "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " ...1111111 1.11111111 11.1111111 111.111111 "
      " 11......11 1.......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "          ^         ^         ^         ^    "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      " 11........ 11.......1 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "   ^           ^           ^           ^     "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      " 1..1111111 111.111111 1111.11111 11111.1111 "
      " 1.......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "      ^          ^     ^           ^         "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      " 11111.1111 11111.1111 ...1111111 1.11111111 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      "#..........#..........#..........#..........#"
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             ");

  //
  // Up rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      " ^           ^           ^           ^       "
      " ..11111111 ..11111111 11.1111111 111.111111 "
      " ....111111 1...111111 11..111111 11..111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "          ^         ^         ^         ^    "
      " 11111111.. 11111111.1 1111111.11 111111.111 "
      " 11111....1 11111....1 11111...11 1111....11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "   ^           ^           ^           ^     "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      " 11.1111.11 11..111111 11......11 1111....11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1111111111 1111111111 1111111111 1111111111 "
      "      ^          ^     ^           ^         "
      " 11111.1111 11111.1111 ..11111111 1.11111111 "
      " 1111....11 1111....11 ....111111 1...111111 "
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
  room_set_add(
      " #           #           #           #       "
      " ..11111111 ..11111111 11.1111111 111.111111 "
      " ....111111 1...111111 11..111111 11..111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11.......1 11.......1 11......11 11......11 "
      " 11111111.. 1111111..1 111111..11 11111..111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      "          #         #         #         #    "
      " 11111111.. 11111111.1 1111111.11 111111.111 "
      " 11111....1 11111....1 11111...11 1111....11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11..111111 111..11111 1111..1111 1111...111 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      "   #           #           #           #     "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      " 11.1111.11 11..111111 11......11 1111....11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 11......11 1.......11 "
      " 11......11 11......11 1.......11 1.......11 "
      " 1111...111 1111...111 ...1111111 1..1111111 "
      " 11111.1111 11111.1111 ..11111111 1.11111111 "
      "      #          #     #           #         "
      " 11111.1111 11111.1111 ..11111111 1.11111111 "
      " 1111....11 1111....11 ....111111 1...111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 1111..1111 1111..1111 1111..1111 1111..1111 "
      " 11111.1111 1111.11111 1111.11111 11111.1111 "
      "      #         #          #           #     ");

  //
  // Down rooms
  //
  TRACE_NO_INDENT();
  room_set_add(
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 1........1 1........1 1........1 1........1 "
      " 11111111.. 11111111.1 1111111.11 111111.111 "
      " 111111111. 11111111.1 1111111.11 111111.111 "
      "          v         v         v         v    "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 1........1 1........1 1........1 1........1 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      " 11.1111111 111.111111 1111.11111 11111.1111 "
      "   v           v           v           v     "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......1. 11......11 "
      " 11......11 11......11 11......1. 11......11 "
      " 11......11 11......11 11......1. 11......11 "
      " 11......11 11......11 11......1. 11......11 "
      " 1........1 1........1 1......... 1........1 "
      " 11111.1111 11111.1111 ..11111111 1.11111111 "
      " 11111.1111 11111.1111 .111111111 1.11111111 "
      "      v          v     v           v         "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 11......11 11......11 11......11 11......11 "
      " 1........1 1........1 1........1 1........1 "
      " 1111.11111 1111.11111 1111.11111 1111.11111 "
      " 1111.11111 1111.11111 1111.11111 1111.11111 "
      "     v          v          v          v      ");
}
