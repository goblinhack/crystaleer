//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_TILEMAP_HPP_
#define _MY_LEVEL_TILEMAP_HPP_

#include <array>
#include <list>
#include <string>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

#define LEVEL_TILEMAP_WIDTH  3 // Max obstacle dimensions
#define LEVEL_TILEMAP_HEIGHT 3 // Max obstacle dimensions

using Tilemaps = std::vector< Tilemapp >;

using TilemapType = enum {
  TILEMAP_TYPE_NORMAL,
  TILEMAP_TYPE_MAX,
};

class Tilemap
{
private:
public:
  static Tilemaps all_tilemaps_of_type[ TILEMAP_TYPE_MAX ];
  static Tilemaps all_tilemaps;

  Tilemap(void);
  ~Tilemap(void);

  //
  // Unique per tilemap.
  //
  uint32_t    unique_id {0};
  TilemapType type;
  uint8_t     width {LEVEL_TILEMAP_WIDTH};
  uint8_t     height {LEVEL_TILEMAP_HEIGHT};

  std::array< std::array< char, LEVEL_TILEMAP_HEIGHT >, LEVEL_TILEMAP_WIDTH > match_with {};
  std::list< std::string >                                                    replace_with;
};

void tilemap_init(void);
void tilemap_fini(void);

Tilemapp tilemap_new(void);

void tilemap_init(void);
void tilemap_add(TilemapType, const char *, const char *, ...);

#endif
