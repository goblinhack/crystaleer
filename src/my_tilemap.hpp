//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_TILEMAP_HPP_
#define _MY_LEVEL_TILEMAP_HPP_

#include <array>
#include <list>
#include <map>
#include <string>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

#define LEVEL_TILEMAP_WIDTH  3 // Max obstacle dimensions
#define LEVEL_TILEMAP_HEIGHT 3 // Max obstacle dimensions

using Tilemaps = std::map< std::string, std::vector< Tilemap > >;

class Tilemap
{
private:
public:
  static Tilemaps all_tilemaps;

  Tilemap(void) {}
  ~Tilemap(void) {}

  std::array< std::array< char, LEVEL_TILEMAP_HEIGHT >, LEVEL_TILEMAP_WIDTH > match_with {};
  std::list< std::string >                                                    replace_with;
};

void tilemap_add(const char *, const char *, const char *, ...);

#endif
