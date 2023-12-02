//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_dungeon.hpp"
#include "my_dungeons.hpp"
#include "my_main.hpp"

void dungeons_init(void)
{
  TRACE_NO_INDENT();
  add_dungeon(
      /* [    v  *    * v     ] */
      /* [   1---S1---K1----1 ] */
      /* [   |>  < >  <|>  <  ] */
      /* [   |         |      ] */
      /* [   |         |      ] */
      /* [   |        *|v    v] */
      /* [   1----1   D2----2 ] */
      /* [  ^ >  <    ^|>  <| ] */
      /* [             |    | ] */
      /* [             |    | ] */
      /* [         v  *|   *|v] */
      /* [   2----2----2----2 ] */
      /* [    >  <|>  < >  ^| ] */
      /* [        |         | ] */
      /* [        |         | ] */
      /* [        |        *| ] */
      /* [  s.    2   s1???E2 ] */
      /* [       ^            ] */
      "                                             "
      " 1111111111 1111111111 1111111111 1111111111 "
      " 1........1 111....111 1111...111 1........1 "
      " .........1 11......11 11...kH..1 1........1 "
      " .........1 1...S....1 111111H..1 1111H111.1 "
      " .......... ...1111... ......H... ....H....1 "
      " 1..H111... ..111111.. .1111111.. ..11H111.1 "
      " 11.H....1.#..11......#..........#....H....1 "
      " 11111.1111 1111.....1 11..111.11 1111111111 "
      "      #                       #              "
      " .....H1111 1111111111 1.......11 .....1.111 "
      " .....H..11 1........1 1........1 .........1 "
      " .H11111..1 1........1 1.....1111 .......111 "
      " .H.......1 1........1 1........1 .......... "
      " .111H....1 1........1 1..1111111 .......... "
      " ....H..... .........1 1..1...... ...1111... "
      " ....H.....#.........1 1..D......#.......... "
      " 1111111111 1111111111 11111111.1 1111..1111 "
      "                               #      #      "
      " 1111111111 1111111111 .......1.1 ......1111 "
      " 1.......11 .......... ......11.. ...1111..1 "
      " 1........1 .......... .......... ......1H11 "
      " 1..111.... .......... ...H111111 111H..1H.. "
      " 1.....11.1 1..111111H ...H...... ...H...H.. "
      " 1......... .........H .H111..... ...H...H.. "
      " 1.........#.........H#.H........#...H...H.1 "
      " 1111111111 11...11111 1111111111 111111.111 "
      "              #                         #    "
      " 1111111111 11..H..111 1111111111 111111.111 "
      " 1........1 1...H....1 1........1 1......111 "
      " 1..11111.1 1..1H....1 1........1 1......... "
      " 1........1 1...H...11 1.11111111 11111..... "
      " 1........1 1..111...1 1..1111111 ......H111 "
      " 1........1 1........1 1....11111 ......H... "
      " 1........s 111...1111 1........s#.E....H... "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             ");

  TRACE_NO_INDENT();
  add_dungeon(
      "                                             "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..........#..........#..........#.......... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..........#..........#..........#.......... "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " #           #           #           #       "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..........#..........#..........#.......... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..........#..........#..........#.......... "
      " .111111111 1.11111111 11.1111111 111.111111 "
      "                                             ");

  TRACE_NO_INDENT();
  add_dungeon(
      "                                             "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..S.......#..S.......#..S.......#..S....... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ......S...#......S...#.....S....#..S....... "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " #           #           #           #       "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .S........#...S......#...S......#...S...... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .....S....#....S.....#.....S....#.......S.. "
      " .111111111 1.11111111 11.1111111 111.111111 "
      "                                             ");

  TRACE_NO_INDENT();
  add_dungeon(
      "                                             "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..E.......#..E.......#..E.......#..E....... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ......E...#......E...#.....E....#..E....... "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " #           #           #           #       "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .E........#...E......#...E......#...E...... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .....E....#....E.....#.....E....#.......E.. "
      " .111111111 1.11111111 11.1111111 111.111111 "
      "                                             ");

  TRACE_NO_INDENT();
  add_dungeon(
      "                                             "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..k.......#..k.......#..k.......#..k....... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ......k...#......k...#.....k....#..k....... "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " #           #           #           #       "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .k........#...k......#...k......#...k...... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .....k....#....k.....#.....k....#.......k.. "
      " .111111111 1.11111111 11.1111111 111.111111 "
      "                                             ");

  TRACE_NO_INDENT();
  add_dungeon(
      "                                             "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ..D.......#..D.......#..D.......#..D....... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " ......D...#......D...#.....D....#..D....... "
      " .111111111 1.11111111 11.1111111 111.111111 "
      " #           #           #           #       "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .D........#...D......#...D......#...D...... "
      " 111111.111 1111111.11 11111111.1 111111111. "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .....D....#....D.....#.....D....#.......D.. "
      " .111111111 1.11111111 11.1111111 111.111111 "
      "                                             ");

  TRACE_NO_INDENT();
  add_dungeon(
      "                                             "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .........s#s........s#s........s#s......... "
      " 111111s111 1111111.11 11111111s1 111111111s "
      "       #           #           #           # "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .........s#s........s#s........s#s......... "
      " s111111111 1s11111111 11s1111111 111s111111 "
      " #           #           #           #       "
      " s......... .s........ ..s....... ...s...... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .........s#s........s#s........s#s......... "
      " 111111s111 1111111s11 11111111s1 111111111s "
      "       #           #           #           # "
      " ......s... .......s.. ........s. .........s "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .......... .......... .......... .......... "
      " .........s#s........s#s........s#s......... "
      " 1111111111 1111111111 1111111111 1111111111 "
      "                                             ");
}
