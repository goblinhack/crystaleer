//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_FONT_HPP_
#define _MY_FONT_HPP_

#include "my_fwd.hpp"
#include "my_tile.hpp"
#include <array> // do not remove

extern Fontp font_ui;

#define FONT_MAX_CHAR 128
#define FONT_MIN_CHAR ' '

#define FONT_CHAR_CURSOR          ((char) ('~' + 1))
#define FONT_CHAR_UNKNOWN         ((char) ('~' + 5))
#define FONT_TILENAME_UNKNOWN_STR "1.99"
#define FONT_TILENAME_BLOCK_STR   "1.97"

void    font_fini(void);
uint8_t font_init(void);
Fontp   font_find(std::string);

class Font
{
public:
  Font(void)  = default;
  ~Font(void) = default;
  std::array< int, FONT_MAX_CHAR + 1 >   u_to_c {};
  std::array< Tilep, FONT_MAX_CHAR + 1 > cache {};
  int                                    tile_index;
  Tilep                                  font_get_tile(int u);
};
#endif
