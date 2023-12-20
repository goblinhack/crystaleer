//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <stdarg.h>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_ptrcheck.hpp"
#include "my_tile.hpp"
#include "my_tilemap.hpp"

Tilemaps Tilemap::all_tilemaps;

void tilemap_add(const char *what, const char *match_with, const char *args...)
{
  TRACE_NO_INDENT();

  const auto row_len      = LEVEL_TILEMAP_WIDTH;
  auto       expected_len = row_len * LEVEL_TILEMAP_HEIGHT;

  if (strlen(match_with) != expected_len) {
    DIE("bad match with tilemap size, expected %d, got %d", (int) strlen(match_with), (int) expected_len);
  }

  va_list ptr;
  va_start(ptr, args);

  auto tile = tile_find(args);
  if (! tile) {
    DIE("tilemap tile [%s] not found", args);
  }

  auto o = Tilemap();

  o.replace_with.push_back(tile);

  for (;;) {
    const char *s = va_arg(ptr, char *);
    if (! s) {
      break;
    }

    auto tile = tile_find(s);
    if (! tile) {
      DIE("tilemap tile [%s] not found", s);
    }

    o.replace_with.push_back(tile);
  }

  auto index = 0;
  for (auto ry = 0; ry < LEVEL_TILEMAP_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_TILEMAP_WIDTH; rx++) {
      auto offset = (row_len * ry) + rx;

      //
      // Match with...
      //
      auto c = match_with[ offset ];
      switch (c) {
        case 'x' : o.pattern_bitmap |= (1U << index); break;
        case '.' : break;
        default : DIE("unknown tilemap char [%c]", c); break;
      }
      index++;
    }
  }

  Tilemap::all_tilemaps[ std::string(what) ].push_back(o);
}
