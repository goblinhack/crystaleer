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
                         " .......... .......... .......... ........11 "
                         " .....m...$ ....m.H..$ H.m......$ ......m.1$ "
                         " .1H1111211 .11111H211 H111112111 .2H2111111 "
                         " ..H.11...1 ....11H... H...11.... ..H.111111 "
                         " ..H....... 1...11H... 11..11.... ..H....... "
                         " 1....m....>11...mHP..>.....P..m.>..P...Pm..>"
                         " 11..111111 1...111111 ..1..11111 ..11..1111 "
                         " 11.1111111 ..1.111111 ..11.11111 ..111.1111 "
                         "   v           v           v           v     "
                         " .......... 22........ .......... .......... "
                         " .11....11. 2........$ .......... 2.....m..$ "
                         " .1...$.m1. .....m...1 111.112... .2....1111 "
                         " .11111111. ...21112.. 1...12...1 ..2....... "
                         " .......... 1...111... $..m1...1. ........2. "
                         " 1.........>11........>11111..1..>..2..11...>"
                         " 11....m... 111....... 1.............||111m.."
                         " 11111.1111 11111.1111 1.11111111 ..11111111 "
                         "      v          v     v           v         "
                         " H.......P. 22........ ..1....... .....1.... "
                         " H11111111. 2......11$ $.1..P.... 2....1m..$ "
                         " H1$....... ........11 111.112... .2...11111 "
                         " H111...m.. ....m..... ....12...1 ..2....... "
                         " H..1111111 1..1111..2 .m..1...1. ...2...... "
                         " H.........>11....1.2.>111.1..1..>..........>"
                         " H.m....... 111...1... 1...1......|..||..1m.."
                         " 1111|.|111 11111.1111 1.11111111 1.11111111 "
                         "      v          v     v           v         "
                         " 1$........ 2..22..... 2..H.....$ 1$........ "
                         " 111....... .........$ ..1H111111 112212111H "
                         " 11....2... H....m..21 H..H...... ...m.....H "
                         " 1...m1122. H112211... H..Hm..... H11221...H "
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
                         " 11111111.H 111111111H 111111111H 111...111H "
                         " 11.......H 11..P....H 11.....11H 1........H "
                         " 1.....P... 1..1111..H 11.......H 1..P...111 "
                         " 1..11211.| 1......... ...m.....H 1.212..... "
                         " 12.....111 ...1111111 ..111.2111 .......... "
                         " ..........>..........>..........>11.....2..>"
                         " .....m...1 ..m....... .........1 ....m..111 "
                         " 11|11111|1 1111111111 11111||111 11111||111 "
                         "          ^         ^         ^         ^    "
                         " 111111111H 11111111H. 1111111H11 111111H111 "
                         " 11......1H 111....1H. 1111...H.1 11....H... "
                         " ..m......H 11......H. 111....H.. 1.....H... "
                         " 21112....H 1...m...H. 11.....H.. ..P...H... "
                         " .......111 122111.111 1....1111. 111...111. "
                         " ..........>1.........>1........P>1.......P.>"
                         " 11|...|111 1......111 1..m...P.1 1...m...1. "
                         " 111|||1111 11|111|111 1111|11111 1111111111 "
                         "   ^           ^           ^           ^     "
                         " 11H1111111 111H111111 1111H11111 11111H1111 "
                         " 1.H..11111 1.1H.1..11 1..1H1...1 11...H...1 "
                         " 1.H......1 1..H...... 1...H..... 1....H.... "
                         " 1.H....P.. 1..H....P. 1...H....m ..11.H.11. "
                         " 11111.212. 111112..11 1.21112.11 .....P.... "
                         " 1.........>1.........>1.........>....111...>"
                         " 1.....m... 1......m.. 1||...||11 |.m....m.| "
                         " 1111111111 11111||111 1111111111 1111111111 "
                         "      ^          ^     ^           ^         "
                         " 11111H1111 11111H1111 H.1111111. .H11111111 "
                         " .....H.... 111..H...1 H..111111. .H.1111111 "
                         " .....H.... 1....H.... H......... .H........ "
                         " .....H.... 1....111.. H........H ...m...m.. "
                         " 2...111..2 1|........ 11212.211H ..111.111. "
                         " 1....m....>11|.......>.........H>..........>"
                         " 1|||111||| 111|.m...1 .m...|...1 |.....|..1 "
                         " 1111111111 11111111|1 1111|1|111 1|111|1|11 "
                         "                                             ");

  //
  // T shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         "                                             "
                         " 1111111111 1111111111 1111111111 1.1.111111 "
                         " 1.......11 1.H......1 1.....P..1 1.P...1..1 "
                         " 1$.1.....1 1.H...P..1 1..m..1.$1 1.1.$.P..1 "
                         " 11112..P.1 1.H..11..1 11111.1111 1.11111..1 "
                         " .......11. 111..11..1 ..221P1..1 .......... "
                         "#..........#.....11...#..........#.......m..#"
                         " 1...|..m.. 1.m...1..1 11...m.... 1.m..1.111 "
                         " 111|||111. 11111111.1 11|||11.11 111111.111 "
                         "          v         v         v         v    "
                         " 11111111.1 1111111111 1111111111 1111111..1 "
                         " 1...11...1 12......21 12.......1 11....P.$1 "
                         " 1....P...1 1........1 1...P....1 1.....1.11 "
                         " 1....1.$.P 1.111...11 111.11..11 1........1 "
                         " ...1.11111 1...11.... 2....1.... ...P..P..2 "
                         "#...1......#.m..11....#.m...1....#...1..1...#"
                         " 1..1...m.1 11..11|..1 111..11111 1..1m.1|11 "
                         " 11.1111111 111.111111 1111.11111 11111.1111 "
                         "   v           v           v           v     "
                         " 1111111111 1111111111 1111111111 111.111111 "
                         " 11.......1 111.....11 1111.....1 1$.....m.1 "
                         " 1...m...H1 11.......1 11....P.$1 1111111111 "
                         " 1..11111H1 1........1 1.....1111 1.......21 "
                         " ........H. ......1... 1..1...... 12........ "
                         "#..........#..1|..1|..#...1|||m..#.....2....#"
                         " 1..|...|.1 1111|.1111 ..11111111 1..1....11 "
                         " 1111|.|111 11111.1111 .111111111 1.11||||11 "
                         "      v          v     v           v         "
                         " 1111111111 1.11111111 1111111111 1111111111 "
                         " 1.H......1 1$1.....11 1..m.H..$1 1..m..m..1 "
                         " 1.H1....m1 111.m..H.1 11111H1111 11111H1111 "
                         " 1.H1111111 1..1111H.1 1....H...1 1....H...1 "
                         " ..H....... 1......H.. 1...22.... ....22.... "
                         "#..........#..........#..........#..........#"
                         " 1111|.|111 11||..|111 1||1..1111 1||1..1||1 "
                         " 11111.1111 1111|.1111 11111.1111 11111.1111 "
                         "      v          v          v          v     ");

  //
  // Left/right shaped rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         "                                             "
                         " 1111111111 $.......m. 11..22..11 $......... "
                         " ..1111111. 111111H111 1........1 11m.....P. "
                         " ....111... ......H... .......... 111111H112 "
                         " .......... ......H... ....11.... H...m.H... "
                         " .....m.... .......... ...111.... H11111112. "
                         "#...2212...#....m.....#..1111..1.#H1m.......#"
                         " 12......21 11..111..1 111111..11 1111111..1 "
                         " 11||||||11 11||111||1 111111||11 1111111||1 "
                         "                                             "
                         " .......... .......... .......... HP........ "
                         " .......... .......... .....P.... H122...... "
                         " 111....... .......P.. 1H1111..11 H.....m... "
                         " .......... 22H1111122 .H........ H111111122 "
                         " ....211... ..H....... .H....2... H......... "
                         "#........m.#..H.m.....#.H...m....#H...m.....#"
                         " 11|||11111 1111111111 |111111111 111111..|1 "
                         " 1111111111 1111111111 1111111111 111111||11 "
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
                         " 1111111111 1H....1111 1111111111 1........1 "
                         " 11..111.11 1H..P..111 1111...111 .....m.... "
                         " 1........1 1H111...11 116****..1 .H211112H. "
                         " 1.....2... 1H...m...1 1.*****... .H......H. "
                         " ....2..... .H.2112... ..*****... .H......H. "
                         "#..........#.H........#..........#.H..||..H.#"
                         " 1||.||.||1 111||||111 111|..|111 11.|11|.H1 "
                         " 1111111111 1111111111 1111||1111 11|1111|11 "
                         "                                             ");

  //
  // T shape, sideways rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         " #           #           #           #       "
                         " H111111111 1H11111111 11H1111111 111H111111 "
                         " H..1111111 1H11111111 1.H......1 1.1H....11 "
                         " H.......11 1H......11 1.H......1 1..HP...11 "
                         " H.......11 1H..m...11 1.H....211 1.1112..11 "
                         " H.......11 111.111.11 1211...... 1.......11 "
                         " H..m......>11........>1.........>11..m..P..>"
                         " 11111111.. 1......m.1 1..m.....1 11111|.111 "
                         " 111111111. 11|||111.1 1|1111|.11 111111.111 "
                         "          #         #         #         #    "
                         " 111111111H 11111111H1 1111111H11 111111H111 "
                         " 1........H 1.......H1 1.....PH11 11....H111 "
                         " 1...m....H 1..m...mH1 1....21111 1.....H.11 "
                         " 12..111111 11112..111 1...m...11 12...11111 "
                         " 1...1..... 1......... 1.1111.... 1..m...... "
                         " 1......m..>1.........>1.........>1.111.....>"
                         " 1|.|111111 1||.1||111 1|...|||.1 1.111.1111 "
                         " 11.1111111 111.111111 1111.11111 1|111.1111 "
                         "   #           #           #           #     "
                         " 11H1111111 111H111111 1111H11111 11111H1111 "
                         " 1.H......1 1..H.....1 1...H....1 1....H...1 "
                         " 1.H..m...1 1..H....11 1...H....1 1...m....1 "
                         " 1....11111 111|11...1 1...H...21 1...111..1 "
                         " 1.....2... 111111.... 12..H....1 1..m.....1 "
                         " 11.11.m...>11........>1......m..>1111......>"
                         " 11.11.1111 1111..1111 ...|||1111 1......111 "
                         " 11|11.1111 11111.1111 .111111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111H1111 11111H1111 H111111111 1H11111111 "
                         " 1....H...1 1....H...1 H........1 1H.......1 "
                         " 6****....1 1.6****..1 12.......1 1....6**** "
                         " *****....1 1.*****..1 1.6****..1 1....6**** "
                         " *****..211 1.*****..1 1.*****..1 1....****. "
                         " 1.........>1.........>1.*****...>1.........>"
                         " 1m....||.1 1.......m1 1.m....|.1 1.m.|....1 "
                         " 11111.1111 11111.1111 11111.1111 11111.1111 "
                         "      #          #          #          #     ");

  //
  // Four way rooms
  //
  TRACE_NO_INDENT();
  level_ph2_room_set_add(ROOM_TYPE_NORMAL,
                         " #           #           #           #       "
                         " H11.....11 1H11111111 11H1111111 111H111111 "
                         " H....2...1 1H.......1 1.H......1 1..H.....1 "
                         " 12.......1 16****...1 1..6****.1 1........1 "
                         " 1.....m..1 1*****...1 1..*****.1 12.6****.1 "
                         " 1.111111.1 1*****...1 12.*****.1 1..*****.1 "
                         "#..P....1..#..........#..........#...*****..#"
                         " 1.1.m..P.. 1....1...1 1....1...1 1........1 "
                         " 1|1111111. 11111111.1 1111111.11 111111.111 "
                         "          #         #         #         #    "
                         " 111111111H 11111111H1 1111111H11 1...11H111 "
                         " 1........H 1...2...H1 1......H.1 1.m...H..1 "
                         " 1.m......H 1.......H1 1......H.1 1.11111121 "
                         " 11111.1111 1.m....m.1 1...2..H.1 1....m...1 "
                         " .......... 11111.1111 112....... 11111111.. "
                         "#.....|....#....1.1...#.....2....#..........#"
                         " 1....1...1 1........1 1..m.....1 1......... "
                         " 11.1111111 111.1|1111 1111.1|||1 11111.1||1 "
                         "   #           #           #           #     "
                         " 11H1111111 111H111111 1111H11111 11111H1111 "
                         " 1.H1111111 11.H.....1 1111H11111 11111H1111 "
                         " 1.H.111111 1.....1..1 11..H...11 11...H.111 "
                         " 11..m...11 1...m.1..1 11.111..11 1...m..111 "
                         " 1111111.1. 1111111... 11......11 111.111111 "
                         "#..........#..........#..........#..........#"
                         " 1111..1||1 11|1..1||1 ..1|1|||11 1.11111111 "
                         " 11111.1111 11111.1111 .111111111 1.11111111 "
                         "      #          #     #           #         "
                         " 11111H1111 11111H1111 H111111111 1H11111111 "
                         " 1111...111 111..H...1 H..1111111 1H......11 "
                         " 11...m..11 11...H...1 H...m...11 1....2..11 "
                         " 11..111.11 1........1 111111..11 1..m....11 "
                         " 11........ 111...1111 .11111.... 11111..211 "
                         "#...m......#....m.....#..........#..........#"
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
