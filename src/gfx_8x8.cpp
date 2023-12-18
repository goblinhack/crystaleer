//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"
#include "my_tilemap.hpp"
#include "my_ui.hpp"

void gfx_init_8x8(void)
{
  std::initializer_list< std::string > tiles = {
      // clang-format off
        "t1.0.0",  "t1.0.1",  "t1.0.2",  "t1.0.3",  "t1.0.4",  "t1.0.5",  "t1.0.6",  "",
        "t1.1.0",  "t1.1.1",  "t1.1.2",  "t1.1.3",  "t1.1.4",  "t1.1.5",  "t1.1.6",  "",
        "t1.2.0",  "t1.2.1",  "t1.2.2",  "t1.2.3",  "t1.2.4",  "t1.2.5",  "t1.2.6",  "",
        "t1.3.0",  "t1.3.1",  "t1.3.2",  "t1.3.3",  "t1.3.4",  "t1.3.5",  "t1.3.6",  "",
        "t1.4.0",  "t1.4.1",  "t1.4.2",  "t1.4.3",  "t1.4.4",  "t1.4.5",  "t1.4.6",  "",
        "t1.5.0",  "t1.5.1",  "t1.5.2",  "t1.5.3",  "t1.5.4",  "t1.5.5",  "t1.5.6",  "",
        "t1.6.0",  "t1.6.1",  "t1.6.2",  "t1.6.3",  "t1.6.4",  "t1.6.5",  "t1.6.6",  "",
        "t1.7.0",  "t1.7.1",  "t1.7.2",  "t1.7.3",  "t1.7.4",  "t1.7.5",  "t1.7.6",  "",
        "t1.8.0",  "t1.8.1",  "t1.8.2",  "t1.8.3",  "t1.8.4",  "t1.8.5",  "t1.8.6",  "",
        "t1.9.0",  "t1.9.1",  "t1.9.2",  "t1.9.3",  "t1.9.4",  "t1.9.5",  "t1.9.6",  "",
        "t1.10.0", "t1.10.1", "t1.10.2", "t1.10.3", "t1.10.4", "t1.10.5", "t1.10.6", "",
        "t1.11.0", "t1.11.1", "t1.11.2", "t1.11.3", "t1.11.4", "t1.11.5", "t1.11.6", "",
        "t1.12.0", "t1.12.1", "t1.12.2", "t1.12.3", "t1.12.4", "t1.12.5", "t1.12.6", "",
        "t1.13.0", "t1.13.1", "t1.13.2", "t1.13.3", "t1.13.4", "t1.13.5", "t1.13.6", "",
      // clang-format on
  };
  const std::vector< std::string > arr(tiles);
  tile_load_arr("data/gfx/tiles_8x8.tga", "tiles_8x8", UI_TILE_WIDTH, UI_TILE_HEIGHT, arr);

  // clang-format off
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              ".x."
              "...",
              "t1.3.10", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              ".xx"
              "...",
              "t1.0.7", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              "xx."
              "...",
              "t1.5.7", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              ".x."
              "...",
              "t1.0.13", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              ".x."
              ".x.",
              "t1.0.8", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              "xx."
              "...",
              "t1.4.13", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              ".xx"
              "...",
              "t1.3.13", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              ".xx"
              ".x.",
              "t1.1.13", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              "xx."
              ".x.",
              "t1.2.13", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              "xxx"
              ".x.",
              "t1.6.7", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              "xx."
              ".x.",
              "t1.6.10", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              "xxx"
              "...",
              "t1.6.9", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              ".xx"
              ".x.",
              "t1.6.8", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              "xxx"
              ".x.",
              "t1.6.11", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              "xxx"
              "...",
              "t1.1.7", "t1.2.7", "t1.3.7", "t1.4.7", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".x."
              ".x."
              ".x.",
              "t1.0.9", "t1.0.10", "t1.0.11", "t1.0.12", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              ".xx"
              ".xx",
              "t1.0.0", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xx."
              "xx."
              "...",
              "t1.6.6", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".xx"
              ".xx"
              "...",
              "t1.0.6", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              "xx."
              "xx.",
              "t1.6.0", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "..."
              "xxx"
              "xxx",
              "t1.1.0", "t1.2.0", "t1.3.0", "t1.4.0", "t1.5.0", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xx."
              "xx."
              "xx.",
              "t1.6.1", "t1.6.2", "t1.6.3", "t1.6.4", "t1.6.1", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xxx"
              "xxx"
              "...",
              "t1.1.6", "t1.2.6", "t1.3.6", "t1.4.6", "t1.5.6", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              ".xx"
              ".xx"
              ".xx",
              "t1.0.1", "t1.0.2", "t1.0.3", "t1.0.4", "t1.0.5", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xxx"
              "xxx"
              "xxx",
              "t1.3.3", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xxx"
              "xx."
              "xxx",
              "t1.2.10", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xxx"
              ".xx"
              "xxx",
              "t1.4.10", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "x.x"
              "xxx"
              "xxx",
              "t1.3.11", nullptr);
  tilemap_add(TILEMAP_TYPE_NORMAL,
              "xxx"
              "xxx"
              "x.x",
              "t1.4.9", nullptr);
  // clang-format on
}
