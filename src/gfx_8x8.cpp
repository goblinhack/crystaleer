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
      "t1.0.0",   "t1.1.0",   "t1.2.0",   "t1.3.0",   "t1.4.0",   "t1.5.0",   "t1.6.0",   "",
      "t1.0.1",   "t1.1.1",   "t1.2.1",   "t1.3.1",   "t1.4.1",   "t1.5.1",   "t1.6.1",   "",
      "t1.0.2",   "t1.1.2",   "t1.2.2",   "t1.3.2",   "t1.4.2",   "t1.5.2",   "t1.6.2",   "",
      "t1.0.3",   "t1.1.3",   "t1.2.3",   "t1.3.3",   "t1.4.3",   "t1.5.3",   "t1.6.3",   "",
      "t1.0.4",   "t1.1.4",   "t1.2.4",   "t1.3.4",   "t1.4.4",   "t1.5.4",   "t1.6.4",   "",
      "t1.0.5",   "t1.1.5",   "t1.2.5",   "t1.3.5",   "t1.4.5",   "t1.5.5",   "t1.6.5",   "",
      "t1.0.6",   "t1.1.6",   "t1.2.6",   "t1.3.6",   "t1.4.6",   "t1.5.6",   "t1.6.6",   "",
      "t1.0.7",   "t1.1.7",   "t1.2.7",   "t1.3.7",   "t1.4.7",   "t1.5.7",   "t1.6.7",   "",
      "t1.0.8",   "t1.1.8",   "t1.2.8",   "t1.3.8",   "t1.4.8",   "t1.5.8",   "t1.6.8",   "",
      "t1.0.9",   "t1.1.9",   "t1.2.9",   "t1.3.9",   "t1.4.9",   "t1.5.9",   "t1.6.9",   "",
      "t1.0.10",  "t1.1.10",  "t1.2.10",  "t1.3.10",  "t1.4.10",  "t1.5.10",  "t1.6.10",  "",
      "t1.0.11",  "t1.1.11",  "t1.2.11",  "t1.3.11",  "t1.4.11",  "t1.5.11",  "t1.6.11",  "",
      "t1.0.12",  "t1.1.12",  "t1.2.12",  "t1.3.12",  "t1.4.12",  "t1.5.12",  "t1.6.12",  "",
      "t1.0.13",  "t1.1.13",  "t1.2.13",  "t1.3.13",  "t1.4.13",  "t1.5.13",  "t1.6.13",  "",
      // clang-format on
  };
  const std::vector< std::string > arr(tiles);
  tile_load_arr("data/gfx/tiles_8x8.tga", "tiles_8x8", UI_TILE_WIDTH, UI_TILE_HEIGHT, arr);

  // clang-format off
  tilemap_add("wall",
              "xxx"
              "xxx"
              ".xx",
              "t1.4.9", nullptr);
  tilemap_add("wall",
              "xxx"
              "xxx"
              "xx.",
              "t1.2.9", nullptr);
  tilemap_add("wall",
              "xx."
              "xxx"
              "xxx",
              "t1.2.11", nullptr);
  tilemap_add("wall",
              ".xx"
              "xxx"
              "xxx",
              "t1.4.11", nullptr);

  tilemap_add("wall",
              "..."
              "xxx"
              "xxx",
              "t1.1.0", "t1.2.0", "t1.3.0", "t1.4.0", "t1.5.0", nullptr);
  tilemap_add("wall",
              "xx."
              "xx."
              "xx.",
              "t1.6.1", "t1.6.2", "t1.6.3", "t1.6.4", "t1.6.1", nullptr);
  tilemap_add("wall",
              "xxx"
              "xxx"
              "...",
              "t1.1.6", "t1.2.6", "t1.3.6", "t1.4.6", "t1.5.6", nullptr);
  tilemap_add("wall",
              ".xx"
              ".xx"
              ".xx",
              "t1.0.1", "t1.0.2", "t1.0.3", "t1.0.4", "t1.0.5", nullptr);

  tilemap_add("wall",
              ".x."
              "xxx"
              "xxx",
              "t1.3.12", nullptr);
  tilemap_add("wall",
              "xx."
              "xxx"
              "xx.",
              "t1.4.12", nullptr);
  tilemap_add("wall",
              "xxx"
              "xxx"
              ".x.",
              "t1.1.12", nullptr);
  tilemap_add("wall",
              ".xx"
              "xxx"
              ".xx",
              "t1.2.12", nullptr);

  tilemap_add("wall",
              "..x"
              "xxx"
              "xxx",
              "t1.1.0", "t1.2.0", "t1.3.0", "t1.4.0", "t1.5.0", nullptr);
  tilemap_add("wall",
              "xxx"
              "xx."
              "xx.",
              "t1.6.1", "t1.6.2", "t1.6.3", "t1.6.4", "t1.6.1", nullptr);
  tilemap_add("wall",
              "xxx"
              "xxx"
              "..x",
              "t1.1.6", "t1.2.6", "t1.3.6", "t1.4.6", "t1.5.6", nullptr);
  tilemap_add("wall",
              "xxx"
              ".xx"
              ".xx",
              "t1.0.1", "t1.0.2", "t1.0.3", "t1.0.4", "t1.0.5", nullptr);

  tilemap_add("wall",
              "x.."
              "xxx"
              "xxx",
              "t1.1.0", "t1.2.0", "t1.3.0", "t1.4.0", "t1.5.0", nullptr);
  tilemap_add("wall",
              "xx."
              "xx."
              "xxx",
              "t1.6.1", "t1.6.2", "t1.6.3", "t1.6.4", "t1.6.1", nullptr);
  tilemap_add("wall",
              "xxx"
              "xxx"
              "x..",
              "t1.1.6", "t1.2.6", "t1.3.6", "t1.4.6", "t1.5.6", nullptr);
  tilemap_add("wall",
              ".xx"
              ".xx"
              "xxx",
              "t1.0.1", "t1.0.2", "t1.0.3", "t1.0.4", "t1.0.5", nullptr);


  tilemap_add("wall",
              ".xx"
              ".xx"
              "..x",
              "t1.0.6", nullptr);
  tilemap_add("wall",
              "xx."
              "xx."
              "x..",
              "t1.6.6", nullptr);
  tilemap_add("wall",
              "..x"
              ".xx"
              ".xx",
              "t1.0.0", nullptr);
  tilemap_add("wall",
              "x.."
              "xx."
              "xx.",
              "t1.6.0", nullptr);

  tilemap_add("wall",
              "xxx"
              ".xx"
              "...",
              "t1.0.6", nullptr);
  tilemap_add("wall",
              "xxx"
              "xx."
              "...",
              "t1.6.6", nullptr);
  tilemap_add("wall",
              "..."
              ".xx"
              "xxx",
              "t1.0.0", nullptr);
  tilemap_add("wall",
              "..."
              "xx."
              "xxx",
              "t1.6.0", nullptr);
  if (0) {
  tilemap_add("wall",
              "xxx"
              "xxx"
              "xxx",
              "t1.3.3", nullptr);
  }
  tilemap_add("wall",
              "xxx"
              "xx."
              "xxx",
              "t1.2.10", nullptr);
  tilemap_add("wall",
              "xxx"
              ".xx"
              "xxx",
              "t1.4.10", nullptr);
  tilemap_add("wall",
              "x.x"
              "xxx"
              "xxx",
              "t1.3.11", nullptr);
  tilemap_add("wall",
              "xxx"
              "xxx"
              "x.x",
              "t1.4.9", nullptr);

  tilemap_add("wall",
              "..."
              ".xx"
              ".xx",
              "t1.0.0", nullptr);
  tilemap_add("wall",
              "xx."
              "xx."
              "...",
              "t1.6.6", nullptr);
  tilemap_add("wall",
              ".xx"
              ".xx"
              "...",
              "t1.0.6", nullptr);
  tilemap_add("wall",
              "..."
              "xx."
              "xx.",
              "t1.6.0", nullptr);

  tilemap_add("wall",
              ".x."
              "xxx"
              ".x.",
              "t1.6.11", nullptr);

  tilemap_add("wall",
              "..."
              "xxx"
              ".x.",
              "t1.6.7", nullptr);
  tilemap_add("wall",
              ".x."
              "xx."
              ".x.",
              "t1.6.10", nullptr);
  tilemap_add("wall",
              ".x."
              "xxx"
              "...",
              "t1.6.9", nullptr);
  tilemap_add("wall",
              ".x."
              ".xx"
              ".x.",
              "t1.6.8", nullptr);

  tilemap_add("wall",
              "xxx"
              ".x."
              "...",
              "t1.0.13", nullptr);
  tilemap_add("wall",
              "..x"
              ".xx"
              "..x",
              "t1.0.7", nullptr);
  tilemap_add("wall",
              "..."
              ".x."
              "xxx",
              "t1.0.8", nullptr);
  tilemap_add("wall",
              "x.."
              "xx."
              "x..",
              "t1.5.7", nullptr);

  tilemap_add("wall",
              ".x."
              "xx."
              "...",
              "t1.4.13", nullptr);
  tilemap_add("wall",
              ".x."
              ".xx"
              "...",
              "t1.3.13", nullptr);
  tilemap_add("wall",
              "..."
              ".xx"
              ".x.",
              "t1.1.13", nullptr);
  tilemap_add("wall",
              "..."
              "xx."
              ".x.",
              "t1.2.13", nullptr);

  tilemap_add("wall",
              "..."
              "xxx"
              "...",
              "t1.1.7", "t1.2.7", "t1.3.7", "t1.4.7", nullptr);
  tilemap_add("wall",
              ".x."
              ".x."
              ".x.",
              "t1.0.9", "t1.0.10", "t1.0.11", "t1.0.12", nullptr);

  tilemap_add("wall",
              "..."
              ".xx"
              "...",
              "t1.0.7", nullptr);
  tilemap_add("wall",
              "..."
              "xx."
              "...",
              "t1.5.7", nullptr);
  tilemap_add("wall",
              ".x."
              ".x."
              "...",
              "t1.0.13", nullptr);
  tilemap_add("wall",
              "..."
              ".x."
              ".x.",
              "t1.0.8", nullptr);

  tilemap_add("wall",
              "..."
              ".x."
              "...",
              "t1.3.10", nullptr);

  tilemap_add_filler(FILLER_0, "wall",
                     "t1.1.1", "t1.2.1", "t1.3.1", "t1.4.1", "t1.5.1",
                     "t1.1.2", "t1.5.2",
                     "t1.1.3", "t1.5.3",
                     "t1.1.4", "t1.5.4",
                     "t1.1.5", "t1.2.5", "t1.3.5", "t1.4.5", "t1.5.5", nullptr);

  tilemap_add_filler(FILLER_1, "wall",
                     "t1.2.2", "t1.3.2", "t1.4.2", "t1.2.3", "t1.3.3", "t1.4.3", "t1.2.4", "t1.3.4", "t1.4.4",
                     "t1.3.8", "t1.4.8", "t1.5.8",
                     "t1.5.9", "t1.5.10", "t1.5.11", "t1.5.12", "t1.5.12", nullptr);

  tilemap_add_filler(FILLER_2, "wall",
                     "t1.1.8", "t1.2.8",
                     "t1.1.9", "t1.1.10", "t1.1.11", nullptr);

  // clang-format on
}
