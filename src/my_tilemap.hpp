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

class Tilemap
{
private:
public:
  static Tilemaps all_tilemaps;

  Tilemap(void) {}
  ~Tilemap(void) {}

  uint16_t             pattern_bitmap[ LAYER_MAX ] {};
  std::vector< Tilep > replace_with;
  std::vector< Tilep > filler[ LAYER_MAX ][ FILLER_MAX ];
  ;
};

void tilemap_add(int layer, const char *, const char *, const char *, ...);
void tilemap_add_filler(int layer, int filler, const char *, const char *, ...);
void tilemap_add(int layer, const char *);

#endif
