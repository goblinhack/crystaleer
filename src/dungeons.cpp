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
      /* [    v       *    * v] */
      /* [   1----1---S1----1 ] */
      /* [   |>  < >  < >  <| ] */
      /* [   |              | ] */
      /* [   |              | ] */
      /* [   |   * v  *    *| ] */
      /* [   1   D2---K1----1 ] */
      /* [  ^     |>  < >  <  ] */
      /* [        |           ] */
      /* [        |           ] */
      /* [    v  *|   * v  * v] */
      /* [   2----2----2----2 ] */
      /* [   |>  <?>   |>   | ] */
      /* [   |    ?    |    | ] */
      /* [   |    ?    |    | ] */
      /* [   |    ?    |   *| ] */
      /* [   2???s1    2   E2 ] */
      /* [  ^         ^       ] */
      ".........1 1111111111 1111111111 1111111111"
      ".........1 111....111 1111...111 1........."
      ".........1 11......11 11.......1 1........."
      ".........1 1........1 11...S...1 111......."
      ".......... .......... ....111... .........."
      ".........1 1111111111 1111111111 1111......"
      "11......11 1111....11 1........1 1111111..."
      "111....111 1111.....1 .......... .....11..."

      "111H..1111 11........ .......... .....111.1"
      "...H....11 1......... ...k..H... .....11..1"
      "...H.....1 1......... 111111H... ....111.11"
      "..1111...1 1......... ......H... ....111..."
      "1.....11.1 1111111... .....11111 .........."
      "11.......1 1.....1... .......... 1111111111"
      "1111111111 11....D... 1111111111 1111111111"
      "1111111111 1111..1111 1111111111 1111111111"

      "111.111111 11........ .......... .....11..1"
      "........11 1..1111... .......... .....11..1"
      ".........1 .......... .......... ....111.11"
      "...111...1 .......... .......... ....111..."
      "......11.1 ......1111 .......... .........."
      ".......... .......... .......... .........."
      ".........1 11........ 1........1 111111.111"
      "111....111 1111s11111 1111..1111 111111.111"

      "111.111111 11..H..111 111..H1111 111......."
      "..1.1.H..1 1...H....1 11...H.111 1.....1111"
      "..1.1.H..1 1...H....1 11...H.111 1........."
      "..1.1.H..1 1...H...11 1111111111 11111....."
      "......11.1 1..111...1 1111111111 1......111"
      "11.......s s........1 1111111111 1........."
      "1111111111 111...1111 1111111111 1....E...."
      "1111111111 11111....1 1111111111 1...111...");

  TRACE_NO_INDENT();
  add_dungeon(
      /* [                 * v] */
      /* [   1----1----1---S1 ] */
      /* [    >  < >  < >  <| ] */
      /* [                  | ] */
      /* [                  | ] */
      /* [    v    v    v  *|v] */
      /* [   2----2    1---K1 ] */
      /* [   |>  <|    ?>  <| ] */
      /* [   |    |    ?    | ] */
      /* [   |    |    ?    | ] */
      /* [  *|v  *|   *?   *| ] */
      /* [   2----2----2---D2 ] */
      /* [  ^|   <?   <    <? ] */
      /* [   |    ?         ? ] */
      /* [   |    ?         ? ] */
      /* [  *|    ?         ? ] */
      /* [  E2   s1---s1---s1 ] */
      /* [         >  < >  <  ] */
      "111.....11 1111111111 1111111111 1111111111"
      "11.......1 111....111 1111...111 1........."
      "1........1 11......11 11.......1 1.....S..."
      ".........1 1........1 11.......1 111..111.."
      ".......... .......... .......... .........."
      ".........1 1111111111 1111111111 1.......11"
      "11......11 1111....11 1........1 1.......11"
      "1111111111 1111.....1 .......... 111111..11"

      "......1111 11........ 1......... .....1.111"
      "........11 1......... 1......... ..k......1"
      ".........1 1......... 1......... 1111H..111"
      ".........1 1......... 1......... ....H....."
      ".........1 1......... 1......... ....H....."
      ".........1 1......... 1......... ....H....."
      ".......... .......... 1......... ....H....."
      "111.111111 1111..1111 1111s11111 11111111.1"

      "111.111111 11..H..... .......... .....11..1"
      "........11 1...H..... .......... .....11..1"
      ".........1 ....H..... .......... ....111.11"
      "...111...1 ....H..... .......... ....111..."
      "......11.1 ...111111. .......... ....1....."
      ".......... .......... .......... ....1....."
      ".........1 11........ 1........1 ....D....1"
      "111....111 1111s11111 1111111111 111111s111"

      "111.....11 11..H..111 1111111111 111111H111"
      ".........1 1...H....1 1111111111 1.....H111"
      "...11111.1 1...H....1 1111111111 1.....H..."
      ".........1 1...H...11 1111111111 11111.H..."
      ".........1 1..111...1 1111111111 1.....H111"
      ".........1 s........1 1111111111 1........."
      ".E.......1 111...1111 1111111111 1........."
      "1111111111 11111..... .......... ..........");
}
