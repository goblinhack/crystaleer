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

void tilemap_add(int layer, int tile_variant, const char *tp_name, const char *tile_name)
{
  std::string tile_name_layer_variant
      = std::string(tile_name) + "." + std::to_string(layer) + "." + std::to_string(tile_variant) + ".";

  // clang-format off
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              ".xx",
              (tile_name_layer_variant + "4.9").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              "xx.",
              (tile_name_layer_variant + "2.9").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xx."
              "xxx"
              "xxx",
              (tile_name_layer_variant + "2.11").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".xx"
              "xxx"
              "xxx",
              (tile_name_layer_variant + "4.11").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..."
              "xxx"
              "xxx",
              (tile_name_layer_variant + "1.0").c_str(),
              (tile_name_layer_variant + "2.0").c_str(),
              (tile_name_layer_variant + "3.0").c_str(),
              (tile_name_layer_variant + "4.0").c_str(),
              (tile_name_layer_variant + "5.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xx."
              "xx."
              "xx.",
              (tile_name_layer_variant + "6.1").c_str(),
              (tile_name_layer_variant + "6.2").c_str(),
              (tile_name_layer_variant + "6.3").c_str(),
              (tile_name_layer_variant + "6.4").c_str(),
              (tile_name_layer_variant + "6.1").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              "...",
              (tile_name_layer_variant + "1.6").c_str(),
              (tile_name_layer_variant + "2.6").c_str(),
              (tile_name_layer_variant + "3.6").c_str(),
              (tile_name_layer_variant + "4.6").c_str(),
              (tile_name_layer_variant + "5.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".xx"
              ".xx"
              ".xx",
              (tile_name_layer_variant + "0.1").c_str(),
              (tile_name_layer_variant + "0.2").c_str(),
              (tile_name_layer_variant + "0.3").c_str(),
              (tile_name_layer_variant + "0.4").c_str(),
              (tile_name_layer_variant + "0.5").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              ".x."
              "xxx"
              "xxx",
              (tile_name_layer_variant + "2.8").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xx."
              "xxx"
              "xx.",
              (tile_name_layer_variant + "3.8").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              ".x.",
              (tile_name_layer_variant + "0.8").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".xx"
              "xxx"
              ".xx",
              (tile_name_layer_variant + "1.8").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..x"
              "xxx"
              "xxx",
              (tile_name_layer_variant + "1.0").c_str(),
              (tile_name_layer_variant + "2.0").c_str(),
              (tile_name_layer_variant + "3.0").c_str(),
              (tile_name_layer_variant + "4.0").c_str(),
              (tile_name_layer_variant + "5.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xx."
              "xx.",
              (tile_name_layer_variant + "6.1").c_str(),
              (tile_name_layer_variant + "6.2").c_str(),
              (tile_name_layer_variant + "6.3").c_str(),
              (tile_name_layer_variant + "6.4").c_str(),
              (tile_name_layer_variant + "6.1").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              "..x",
              (tile_name_layer_variant + "1.6").c_str(),
              (tile_name_layer_variant + "2.6").c_str(),
              (tile_name_layer_variant + "3.6").c_str(),
              (tile_name_layer_variant + "4.6").c_str(),
              (tile_name_layer_variant + "5.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              ".xx"
              ".xx",
              (tile_name_layer_variant + "0.1").c_str(),
              (tile_name_layer_variant + "0.2").c_str(),
              (tile_name_layer_variant + "0.3").c_str(),
              (tile_name_layer_variant + "0.4").c_str(),
              (tile_name_layer_variant + "0.5").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "x.."
              "xxx"
              "xxx",
              (tile_name_layer_variant + "1.0").c_str(),
              (tile_name_layer_variant + "2.0").c_str(),
              (tile_name_layer_variant + "3.0").c_str(),
              (tile_name_layer_variant + "4.0").c_str(),
              (tile_name_layer_variant + "5.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xx."
              "xx."
              "xxx",
              (tile_name_layer_variant + "6.1").c_str(),
              (tile_name_layer_variant + "6.2").c_str(),
              (tile_name_layer_variant + "6.3").c_str(),
              (tile_name_layer_variant + "6.4").c_str(),
              (tile_name_layer_variant + "6.1").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              "x..",
              (tile_name_layer_variant + "1.6").c_str(),
              (tile_name_layer_variant + "2.6").c_str(),
              (tile_name_layer_variant + "3.6").c_str(),
              (tile_name_layer_variant + "4.6").c_str(),
              (tile_name_layer_variant + "5.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".xx"
              ".xx"
              "xxx",
              (tile_name_layer_variant + "0.1").c_str(),
              (tile_name_layer_variant + "0.2").c_str(),
              (tile_name_layer_variant + "0.3").c_str(),
              (tile_name_layer_variant + "0.4").c_str(),
              (tile_name_layer_variant + "0.5").c_str(), nullptr);


  tilemap_add(layer, tp_name,
              ".xx"
              ".xx"
              "..x",
              (tile_name_layer_variant + "0.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xx."
              "xx."
              "x..",
              (tile_name_layer_variant + "6.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..x"
              ".xx"
              ".xx",
              (tile_name_layer_variant + "0.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "x.."
              "xx."
              "xx.",
              (tile_name_layer_variant + "6.0").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "xxx"
              ".xx"
              "...",
              (tile_name_layer_variant + "0.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xx."
              "...",
              (tile_name_layer_variant + "6.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              ".xx"
              "xxx",
              (tile_name_layer_variant + "0.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              "xx."
              "xxx",
              (tile_name_layer_variant + "6.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xx."
              "xxx",
              (tile_name_layer_variant + "2.10").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              ".xx"
              "xxx",
              (tile_name_layer_variant + "4.10").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "x.x"
              "xxx"
              "xxx",
              (tile_name_layer_variant + "3.11").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xxx"
              "xxx"
              "x.x",
              (tile_name_layer_variant + "4.9").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..."
              ".xx"
              ".xx",
              (tile_name_layer_variant + "0.0").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "xx."
              "xx."
              "...",
              (tile_name_layer_variant + "6.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".xx"
              ".xx"
              "...",
              (tile_name_layer_variant + "0.6").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              "xx."
              "xx.",
              (tile_name_layer_variant + "6.0").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              ".x."
              "xxx"
              ".x.",
              (tile_name_layer_variant + "4.8").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..."
              "xxx"
              ".x.",
              (tile_name_layer_variant + "5.8").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".x."
              ".xx"
              ".x.",
              (tile_name_layer_variant + "5.9").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".x."
              "xxx"
              "...",
              (tile_name_layer_variant + "5.10").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".x."
              "xx."
              ".x.",
              (tile_name_layer_variant + "5.11").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "xxx"
              ".x."
              "...",
              (tile_name_layer_variant + "1.11").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..x"
              ".xx"
              "..x",
              (tile_name_layer_variant + "6.7").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              ".x."
              "xxx",
              (tile_name_layer_variant + "6.7").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "x.."
              "xx."
              "x..",
              (tile_name_layer_variant + "5.7").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              ".x."
              "xx."
              "...",
              (tile_name_layer_variant + "1.10").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".x."
              ".xx"
              "...",
              (tile_name_layer_variant + "0.10").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              ".xx"
              ".x.",
              (tile_name_layer_variant + "0.9").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              "xx."
              ".x.",
              (tile_name_layer_variant + "1.9").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..."
              "xxx"
              "...",
              (tile_name_layer_variant + "1.7").c_str(),
              (tile_name_layer_variant + "2.7").c_str(),
              (tile_name_layer_variant + "3.7").c_str(),
              (tile_name_layer_variant + "4.7").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".x."
              ".x."
              ".x.",
              (tile_name_layer_variant + "6.8").c_str(),
              (tile_name_layer_variant + "6.9").c_str(),
              (tile_name_layer_variant + "6.10").c_str(),
              (tile_name_layer_variant + "6.11").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..."
              ".xx"
              "...",
              (tile_name_layer_variant + "6.7").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              "xx."
              "...",
              (tile_name_layer_variant + "5.7").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              ".x."
              ".x."
              "...",
              (tile_name_layer_variant + "1.11").c_str(), nullptr);
  tilemap_add(layer, tp_name,
              "..."
              ".x."
              ".x.",
              (tile_name_layer_variant + "6.7").c_str(), nullptr);

  tilemap_add(layer, tp_name,
              "..."
              ".x."
              "...",
              (tile_name_layer_variant + "0.11").c_str(), nullptr);

  tilemap_add_filler(layer, FILLER_0, tp_name,
                     (tile_name_layer_variant + "1.1").c_str(),
                     (tile_name_layer_variant + "2.1").c_str(),
                     (tile_name_layer_variant + "3.1").c_str(),
                     (tile_name_layer_variant + "4.1").c_str(),
                     (tile_name_layer_variant + "5.1").c_str(),
                     (tile_name_layer_variant + "1.2").c_str(),
                     (tile_name_layer_variant + "5.2").c_str(),
                     (tile_name_layer_variant + "1.3").c_str(),
                     (tile_name_layer_variant + "5.3").c_str(),
                     (tile_name_layer_variant + "1.4").c_str(),
                     (tile_name_layer_variant + "5.4").c_str(),
                     (tile_name_layer_variant + "1.5").c_str(),
                     (tile_name_layer_variant + "2.5").c_str(),
                     (tile_name_layer_variant + "3.5").c_str(),
                     (tile_name_layer_variant + "4.5").c_str(),
                     (tile_name_layer_variant + "5.5").c_str(),
                     nullptr);

  tilemap_add_filler(layer, FILLER_1, tp_name,
                     (tile_name_layer_variant + "2.2").c_str(),
                     (tile_name_layer_variant + "3.2").c_str(),
                     (tile_name_layer_variant + "4.2").c_str(),
                     (tile_name_layer_variant + "2.3").c_str(),
                     (tile_name_layer_variant + "3.3").c_str(),
                     (tile_name_layer_variant + "4.3").c_str(),
                     (tile_name_layer_variant + "2.4").c_str(),
                     (tile_name_layer_variant + "3.4").c_str(),
                     (tile_name_layer_variant + "4.4").c_str(),
                     nullptr);
}

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
