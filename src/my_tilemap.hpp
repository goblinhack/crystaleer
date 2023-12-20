//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_TILEMAP_HPP_
#define _MY_LEVEL_TILEMAP_HPP_

#include <array>
#include <map>
#include <string>
#include <vector>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

#define LEVEL_TILEMAP_WIDTH  3 // Max obstacle dimensions
#define LEVEL_TILEMAP_HEIGHT 3 // Max obstacle dimensions

using Tilemaps = std::map< std::string, std::vector< Tilemap > >;

enum {
  FILLER_0,
  FILLER_1,
  FILLER_2,
  FILLER_MAX,
};

class Tilemap
{
private:
public:
  static Tilemaps all_tilemaps;

  Tilemap(void) {}
  ~Tilemap(void) {}

  uint16_t             pattern_bitmap {};
  std::vector< Tilep > replace_with;
  std::vector< Tilep > filler[ FILLER_MAX ];
  ;
};

void tilemap_add(const char *, const char *, const char *, ...);
void tilemap_add_filler(int filler, const char *, const char *, ...);

#endif
