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

void tilemap_add(int layer, const char *what, const char *match_with, const char *args...)
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
        case 'x' : o.pattern_bitmap[ layer ] |= (1U << index); break;
        case '.' : break;
        default : DIE("unknown tilemap char [%c]", c); break;
      }
      index++;
    }
  }

  Tilemap::all_tilemaps[ std::string(what) ].push_back(o);
}

void tilemap_add_filler(int layer, int filler_type, const char *what, const char *args...)
{
  TRACE_NO_INDENT();

  va_list ptr;
  va_start(ptr, args);

  auto tile = tile_find(args);
  if (! tile) {
    DIE("tilemap tile [%s] not found", args);
  }

  auto o = Tilemap();

  o.filler[ layer ][ filler_type ].push_back(tile);

  for (;;) {
    const char *s = va_arg(ptr, char *);
    if (! s) {
      break;
    }

    auto tile = tile_find(s);
    if (! tile) {
      DIE("tilemap tile [%s] not found", s);
    }

    o.filler[ layer ][ filler_type ].push_back(tile);
  }

  Tilemap::all_tilemaps[ std::string(what) ].push_back(o);
}

void tilemap_add(int layer, const char *what)
{
  std::string tile_name = std::string(what) + std::to_string(layer) + ".";

  // clang-format off
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              ".xx",
              (tile_name + "4.9").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              "xx.",
              (tile_name + "2.9").c_str(), nullptr);
  tilemap_add(layer, what,
              "xx."
              "xxx"
              "xxx",
              (tile_name + "2.11").c_str(), nullptr);
  tilemap_add(layer, what,
              ".xx"
              "xxx"
              "xxx",
              (tile_name + "4.11").c_str(), nullptr);

  tilemap_add(layer, what,
              "..."
              "xxx"
              "xxx",
              (tile_name + "1.0").c_str(),
              (tile_name + "2.0").c_str(),
              (tile_name + "3.0").c_str(),
              (tile_name + "4.0").c_str(),
              (tile_name + "5.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "xx."
              "xx."
              "xx.",
              (tile_name + "6.1").c_str(),
              (tile_name + "6.2").c_str(),
              (tile_name + "6.3").c_str(),
              (tile_name + "6.4").c_str(),
              (tile_name + "6.1").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              "...",
              (tile_name + "1.6").c_str(),
              (tile_name + "2.6").c_str(),
              (tile_name + "3.6").c_str(),
              (tile_name + "4.6").c_str(),
              (tile_name + "5.6").c_str(), nullptr);
  tilemap_add(layer, what,
              ".xx"
              ".xx"
              ".xx",
              (tile_name + "0.1").c_str(),
              (tile_name + "0.2").c_str(),
              (tile_name + "0.3").c_str(),
              (tile_name + "0.4").c_str(),
              (tile_name + "0.5").c_str(), nullptr);

  tilemap_add(layer, what,
              ".x."
              "xxx"
              "xxx",
              (tile_name + "2.8").c_str(), nullptr);
  tilemap_add(layer, what,
              "xx."
              "xxx"
              "xx.",
              (tile_name + "3.8").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              ".x.",
              (tile_name + "0.8").c_str(), nullptr);
  tilemap_add(layer, what,
              ".xx"
              "xxx"
              ".xx",
              (tile_name + "1.8").c_str(), nullptr);

  tilemap_add(layer, what,
              "..x"
              "xxx"
              "xxx",
              (tile_name + "1.0").c_str(),
              (tile_name + "2.0").c_str(),
              (tile_name + "3.0").c_str(),
              (tile_name + "4.0").c_str(),
              (tile_name + "5.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xx."
              "xx.",
              (tile_name + "6.1").c_str(),
              (tile_name + "6.2").c_str(),
              (tile_name + "6.3").c_str(),
              (tile_name + "6.4").c_str(),
              (tile_name + "6.1").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              "..x",
              (tile_name + "1.6").c_str(),
              (tile_name + "2.6").c_str(),
              (tile_name + "3.6").c_str(),
              (tile_name + "4.6").c_str(),
              (tile_name + "5.6").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              ".xx"
              ".xx",
              (tile_name + "0.1").c_str(),
              (tile_name + "0.2").c_str(),
              (tile_name + "0.3").c_str(),
              (tile_name + "0.4").c_str(),
              (tile_name + "0.5").c_str(), nullptr);

  tilemap_add(layer, what,
              "x.."
              "xxx"
              "xxx",
              (tile_name + "1.0").c_str(),
              (tile_name + "2.0").c_str(),
              (tile_name + "3.0").c_str(),
              (tile_name + "4.0").c_str(),
              (tile_name + "5.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "xx."
              "xx."
              "xxx",
              (tile_name + "6.1").c_str(),
              (tile_name + "6.2").c_str(),
              (tile_name + "6.3").c_str(),
              (tile_name + "6.4").c_str(),
              (tile_name + "6.1").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              "x..",
              (tile_name + "1.6").c_str(),
              (tile_name + "2.6").c_str(),
              (tile_name + "3.6").c_str(),
              (tile_name + "4.6").c_str(),
              (tile_name + "5.6").c_str(), nullptr);
  tilemap_add(layer, what,
              ".xx"
              ".xx"
              "xxx",
              (tile_name + "0.1").c_str(),
              (tile_name + "0.2").c_str(),
              (tile_name + "0.3").c_str(),
              (tile_name + "0.4").c_str(),
              (tile_name + "0.5").c_str(), nullptr);


  tilemap_add(layer, what,
              ".xx"
              ".xx"
              "..x",
              (tile_name + "0.6").c_str(), nullptr);
  tilemap_add(layer, what,
              "xx."
              "xx."
              "x..",
              (tile_name + "6.6").c_str(), nullptr);
  tilemap_add(layer, what,
              "..x"
              ".xx"
              ".xx",
              (tile_name + "0.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "x.."
              "xx."
              "xx.",
              (tile_name + "6.0").c_str(), nullptr);

  tilemap_add(layer, what,
              "xxx"
              ".xx"
              "...",
              (tile_name + "0.6").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xx."
              "...",
              (tile_name + "6.6").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              ".xx"
              "xxx",
              (tile_name + "0.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              "xx."
              "xxx",
              (tile_name + "6.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xx."
              "xxx",
              (tile_name + "2.10").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              ".xx"
              "xxx",
              (tile_name + "4.10").c_str(), nullptr);
  tilemap_add(layer, what,
              "x.x"
              "xxx"
              "xxx",
              (tile_name + "3.11").c_str(), nullptr);
  tilemap_add(layer, what,
              "xxx"
              "xxx"
              "x.x",
              (tile_name + "4.9").c_str(), nullptr);

  tilemap_add(layer, what,
              "..."
              ".xx"
              ".xx",
              (tile_name + "0.0").c_str(), nullptr);
  tilemap_add(layer, what,
              "xx."
              "xx."
              "...",
              (tile_name + "6.6").c_str(), nullptr);
  tilemap_add(layer, what,
              ".xx"
              ".xx"
              "...",
              (tile_name + "0.6").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              "xx."
              "xx.",
              (tile_name + "6.0").c_str(), nullptr);

  tilemap_add(layer, what,
              ".x."
              "xxx"
              ".x.",
              (tile_name + "4.8").c_str(), nullptr);

  tilemap_add(layer, what,
              "..."
              "xxx"
              ".x.",
              (tile_name + "5.8").c_str(), nullptr);
  tilemap_add(layer, what,
              ".x."
              ".xx"
              ".x.",
              (tile_name + "5.9").c_str(), nullptr);
  tilemap_add(layer, what,
              ".x."
              "xxx"
              "...",
              (tile_name + "5.10").c_str(), nullptr);
  tilemap_add(layer, what,
              ".x."
              "xx."
              ".x.",
              (tile_name + "5.11").c_str(), nullptr);

  tilemap_add(layer, what,
              "xxx"
              ".x."
              "...",
              (tile_name + "1.11").c_str(), nullptr);
  tilemap_add(layer, what,
              "..x"
              ".xx"
              "..x",
              (tile_name + "6.7").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              ".x."
              "xxx",
              (tile_name + "6.7").c_str(), nullptr);
  tilemap_add(layer, what,
              "x.."
              "xx."
              "x..",
              (tile_name + "5.7").c_str(), nullptr);

  tilemap_add(layer, what,
              ".x."
              "xx."
              "...",
              (tile_name + "1.10").c_str(), nullptr);
  tilemap_add(layer, what,
              ".x."
              ".xx"
              "...",
              (tile_name + "0.10").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              ".xx"
              ".x.",
              (tile_name + "0.9").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              "xx."
              ".x.",
              (tile_name + "1.9").c_str(), nullptr);

  tilemap_add(layer, what,
              "..."
              "xxx"
              "...",
              (tile_name + "1.7").c_str(),
              (tile_name + "2.7").c_str(),
              (tile_name + "3.7").c_str(),
              (tile_name + "4.7").c_str(), nullptr);
  tilemap_add(layer, what,
              ".x."
              ".x."
              ".x.",
              (tile_name + "6.8").c_str(),
              (tile_name + "6.9").c_str(),
              (tile_name + "6.10").c_str(),
              (tile_name + "6.11").c_str(), nullptr);

  tilemap_add(layer, what,
              "..."
              ".xx"
              "...",
              (tile_name + "6.7").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              "xx."
              "...",
              (tile_name + "5.7").c_str(), nullptr);
  tilemap_add(layer, what,
              ".x."
              ".x."
              "...",
              (tile_name + "1.11").c_str(), nullptr);
  tilemap_add(layer, what,
              "..."
              ".x."
              ".x.",
              (tile_name + "6.7").c_str(), nullptr);

  tilemap_add(layer, what,
              "..."
              ".x."
              "...",
              (tile_name + "0.11").c_str(), nullptr);

  tilemap_add_filler(layer, FILLER_0, what,
                     (tile_name + "1.1").c_str(),
                     (tile_name + "2.1").c_str(),
                     (tile_name + "3.1").c_str(),
                     (tile_name + "4.1").c_str(),
                     (tile_name + "5.1").c_str(),
                     (tile_name + "1.2").c_str(),
                     (tile_name + "5.2").c_str(),
                     (tile_name + "1.3").c_str(),
                     (tile_name + "5.3").c_str(),
                     (tile_name + "1.4").c_str(),
                     (tile_name + "5.4").c_str(),
                     (tile_name + "1.5").c_str(),
                     (tile_name + "2.5").c_str(),
                     (tile_name + "3.5").c_str(),
                     (tile_name + "4.5").c_str(),
                     (tile_name + "5.5").c_str(),
                     nullptr);

  tilemap_add_filler(layer, FILLER_1, what,
                     (tile_name + "2.2").c_str(),
                     (tile_name + "3.2").c_str(),
                     (tile_name + "4.2").c_str(),
                     (tile_name + "2.3").c_str(),
                     (tile_name + "3.3").c_str(),
                     (tile_name + "4.3").c_str(),
                     (tile_name + "2.4").c_str(),
                     (tile_name + "3.4").c_str(),
                     (tile_name + "4.4").c_str(),
                     nullptr);
}
