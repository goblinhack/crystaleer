//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <stdarg.h>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_ptrcheck.hpp"
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

  std::list< std::string > replace_with;

  va_list ptr;
  va_start(ptr, args);

  replace_with.push_back(std::string(args));

  for (;;) {
    const char *s = va_arg(ptr, char *);
    if (! s) {
      break;
    }
    replace_with.push_back(std::string(s));
  }

  auto o = Tilemap();

  for (auto ry = 0; ry < LEVEL_TILEMAP_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_TILEMAP_WIDTH; rx++) {
      auto offset = (row_len * ry) + rx;

      //
      // Match with...
      //
      auto c                   = match_with[ offset ];
      o.match_with[ rx ][ ry ] = c;
    }
  }

  Tilemap::all_tilemaps[ std::string(what) ].push_back(o);
}
