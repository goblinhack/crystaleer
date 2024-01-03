//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level_ph2.hpp"

void level_ph2_norm_init(void)
{
  //
  // Single exit left or right rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         "                                             "
                         " 1......... 2.....2..2 12........ H........$ "
                         " .........$ .......... 2....P...$ H12.....21 "
                         " H1..112211 .6****...$ 1H1..11111 H..6****.. "
                         " H......... .*****.211 .H........ H..*****.. "
                         " H......... .*****.... .H.5****.. H..*****.. "
                         " H5****...H>.m........>111*****..>H..5****..>"
                         " H*****...H 111....111 111*****.1 1..*****.1 "
                         " H*****1111 111||||111 1111111111 11|*****|1 "
                         "                                             "
                         " ....2..... ...22..... .......... H........$ "
                         " m.......$. .........$ Hm.6****.$ H122112211 "
                         " 1121.1211. H......P.1 H11*****11 H......... "
                         " H......... H1122111.. H..*****.. 112211H... "
                         " H......... H......... H......... ......H... "
                         " H.........>5*****....>..212..|..>11....H...>"
                         " 1|||22|||1 ******||11 ......11|. 11||2|||.1 "
                         " 1111111111 1111111111 1|||||1211 1111111111 "
                         "                                             "
                         " .........$ 112....... ......P... HP.......$ "
                         " H...||.... 12.......$ Hm....P..$ H1....H211 "
                         " H111111111 H......P.1 H112121.11 H....mH... "
                         " H......... H1122111.. H......... H122111... "
                         " H..H22H... H......... H......... H......... "
                         " H..H||H...>5*****...P>..212.....>H.........>"
                         " 111111H..1 ******m..1 .|||||11|. 11||2|||.1 "
                         " 1111111..1 1111111111 1111111111 1111111111 "
                         "                                             "
                         " 11........ ...212.... .......... 11..111..2 "
                         " 1.......$. .........$ Hm.......$ 1....2.... "
                         " .....1211. H......P.1 H112121.11 .........$ "
                         " Hm..112... H1122111.. H......... H12211..21 "
                         " H11112.... H......... H..m...... H......... "
                         " H.........>5*****....>.21112....>H.........>"
                         " 1........1 1*****1111 .......1.1 H......... "
                         " 1|||22|||1 ******||11 1|||||11|1 11||2|||.1 "
                         "                                             ");

  //
  // Top left corner rooms with a right and down exit
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         "                                             "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " ....11.... ....11.... ....11.... ....11.... "
                         " ....11.... ....11.... ....11.... ....11.... "
                         " .......... .......... .......... .......... "
                         " ..........>..........>..........>..........>"
                         " ....111111 ....111111 ..1..11111 ..11..1111 "
                         " ...1111111 ..1.111111 ..11.11111 ..111.1111 "
                         "   v           v           v           v     "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " ..........>..........>..........>..........>"
                         " ..11..1111 ..11..1111 ...1111111 ...1111111 "
                         " ..111.1111 ..111.1111 ..11111111 ..11111111 "
                         "      v          v     v           v         "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " .......... .......... .......... .......... "
                         " ..........>..........>..........>..........>"
                         " ..11..1111 ..11..1111 ..11..1111 ..11..1111 "
                         " ..111.1111 ..111.1111 ..111.1111 ..111.1111 "
                         "      v          v          v          v     "
                         " 1$........ 2..22..... 2..H.....$ 1$........ "
                         " 111....... .........$ ..1H111111 112212111H "
                         " 11....2... H....m..21 H..H...... .........H "
                         " 1....1122. H112211... H..Hm..... H11221...H "
                         " ...2111... H11..11... H211112... H.....222. "
                         " 1.........>H.........>H.........>H5****....>"
                         " 11........ H..||....1 H..m...... 1*****.... "
                         " 111||2||1. H.111111.1 1111111.11 1*****.1|1 "
                         "          v         v         v         v    ");

  //
  // Corner L shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
                         " 1111111111 1111111111 1111111111 1........1 "
                         " 1..P..P... 1......m.2 1........1 1H..m.P..1 "
                         " 1.22..1H11 1.....1111 1....m...1 1H11111..1 "
                         " .......H.1 1.5****..1 1..1111111 1H.......1 "
                         " .5****.H.1 1.*****..1 1........1 1..5****.1 "
                         "#.*****....#..*****2..#..5****...#...*****..#"
                         " 1*****m..1 1111111111 11*****111 1.2*****21 "
                         " 11111111.1 1111111111 11*****111 1111111111 "
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         " ^           ^           ^           ^       "
                         " H.11111111 .H11111111 1.H1111111 111H111111 "
                         " H........1 .H.......1 1.H......1 1..H....11 "
                         " 1111H....1 .111H....1 1.H......1 1..H....11 "
                         " 1...H....1 ....H..111 1111..1111 11111...11 "
                         " 1.1111H..1 11..H....1 1........1 11111..111 "
                         " 1.....H..1 1...111..1 1..1111..1 11111...11 "
                         " 1.....H..1 1........1 1........1 1.......11 "
                         " 1111111111 1111111111 1111111111 1111111111 "
                         "          ^         ^         ^         ^    "
                         " 11111111.H 11111111H1 1111111H11 111111H111 "
                         " 1........H 11111...H1 1.111..H.1 1111..H.11 "
                         " 1.H11..111 11......H1 11.....H.1 1.....H.11 "
                         " 1.H.....11 11......H1 1....11111 1.....H.11 "
                         " 1.H.....11 1111H...H1 1H11111111 11...11111 "
                         " 1.H.....11 11..H...H1 1H.......1 1.......11 "
                         " 1.11111111 1...H...H1 1H.......1 1111....11 "
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
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
