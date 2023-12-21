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
      "wall0.0.0",   "wall0.1.0",   "wall0.2.0",   "wall0.3.0",   "wall0.4.0",   "wall0.5.0",   "wall0.6.0",   "",
      "wall0.0.1",   "wall0.1.1",   "wall0.2.1",   "wall0.3.1",   "wall0.4.1",   "wall0.5.1",   "wall0.6.1",   "",
      "wall0.0.2",   "wall0.1.2",   "wall0.2.2",   "wall0.3.2",   "wall0.4.2",   "wall0.5.2",   "wall0.6.2",   "",
      "wall0.0.3",   "wall0.1.3",   "wall0.2.3",   "wall0.3.3",   "wall0.4.3",   "wall0.5.3",   "wall0.6.3",   "",
      "wall0.0.4",   "wall0.1.4",   "wall0.2.4",   "wall0.3.4",   "wall0.4.4",   "wall0.5.4",   "wall0.6.4",   "",
      "wall0.0.5",   "wall0.1.5",   "wall0.2.5",   "wall0.3.5",   "wall0.4.5",   "wall0.5.5",   "wall0.6.5",   "",
      "wall0.0.6",   "wall0.1.6",   "wall0.2.6",   "wall0.3.6",   "wall0.4.6",   "wall0.5.6",   "wall0.6.6",   "",
      "wall0.0.7",   "wall0.1.7",   "wall0.2.7",   "wall0.3.7",   "wall0.4.7",   "wall0.5.7",   "wall0.6.7",   "",
      "wall0.0.8",   "wall0.1.8",   "wall0.2.8",   "wall0.3.8",   "wall0.4.8",   "wall0.5.8",   "wall0.6.8",   "",
      "wall0.0.9",   "wall0.1.9",   "wall0.2.9",   "wall0.3.9",   "wall0.4.9",   "wall0.5.9",   "wall0.6.9",   "",
      "wall0.0.10",  "wall0.1.10",  "wall0.2.10",  "wall0.3.10",  "wall0.4.10",  "wall0.5.10",  "wall0.6.10",  "",
      "wall0.0.11",  "wall0.1.11",  "wall0.2.11",  "wall0.3.11",  "wall0.4.11",  "wall0.5.11",  "wall0.6.11",  "",
      "",            "",            "",            "",            "",            "",            "",            "bad_tile",
      "wall1.0.0",   "wall1.1.0",   "wall1.2.0",   "wall1.3.0",   "wall1.4.0",   "wall1.5.0",   "wall1.6.0",   "",
      "wall1.0.1",   "wall1.1.1",   "wall1.2.1",   "wall1.3.1",   "wall1.4.1",   "wall1.5.1",   "wall1.6.1",   "",
      "wall1.0.2",   "wall1.1.2",   "wall1.2.2",   "wall1.3.2",   "wall1.4.2",   "wall1.5.2",   "wall1.6.2",   "",
      "wall1.0.3",   "wall1.1.3",   "wall1.2.3",   "wall1.3.3",   "wall1.4.3",   "wall1.5.3",   "wall1.6.3",   "",
      "wall1.0.4",   "wall1.1.4",   "wall1.2.4",   "wall1.3.4",   "wall1.4.4",   "wall1.5.4",   "wall1.6.4",   "",
      "wall1.0.5",   "wall1.1.5",   "wall1.2.5",   "wall1.3.5",   "wall1.4.5",   "wall1.5.5",   "wall1.6.5",   "",
      "wall1.0.6",   "wall1.1.6",   "wall1.2.6",   "wall1.3.6",   "wall1.4.6",   "wall1.5.6",   "wall1.6.6",   "",
      "wall1.0.7",   "wall1.1.7",   "wall1.2.7",   "wall1.3.7",   "wall1.4.7",   "wall1.5.7",   "wall1.6.7",   "",
      "wall1.0.8",   "wall1.1.8",   "wall1.2.8",   "wall1.3.8",   "wall1.4.8",   "wall1.5.8",   "wall1.6.8",   "",
      "wall1.0.9",   "wall1.1.9",   "wall1.2.9",   "wall1.3.9",   "wall1.4.9",   "wall1.5.9",   "wall1.6.9",   "",
      "wall1.0.10",  "wall1.1.10",  "wall1.2.10",  "wall1.3.10",  "wall1.4.10",  "wall1.5.10",  "wall1.6.10",  "",
      "wall1.0.11",  "wall1.1.11",  "wall1.2.11",  "wall1.3.11",  "wall1.4.11",  "wall1.5.11",  "wall1.6.11",  "",
      "",            "",            "",            "",            "",            "",            "",            "",
      "wall2.0.0",   "wall2.1.0",   "wall2.2.0",   "wall2.3.0",   "wall2.4.0",   "wall2.5.0",   "wall2.6.0",   "",
      "wall2.0.1",   "wall2.1.1",   "wall2.2.1",   "wall2.3.1",   "wall2.4.1",   "wall2.5.1",   "wall2.6.1",   "",
      "wall2.0.2",   "wall2.1.2",   "wall2.2.2",   "wall2.3.2",   "wall2.4.2",   "wall2.5.2",   "wall2.6.2",   "",
      "wall2.0.3",   "wall2.1.3",   "wall2.2.3",   "wall2.3.3",   "wall2.4.3",   "wall2.5.3",   "wall2.6.3",   "",
      "wall2.0.4",   "wall2.1.4",   "wall2.2.4",   "wall2.3.4",   "wall2.4.4",   "wall2.5.4",   "wall2.6.4",   "",
      "wall2.0.5",   "wall2.1.5",   "wall2.2.5",   "wall2.3.5",   "wall2.4.5",   "wall2.5.5",   "wall2.6.5",   "",
      "wall2.0.6",   "wall2.1.6",   "wall2.2.6",   "wall2.3.6",   "wall2.4.6",   "wall2.5.6",   "wall2.6.6",   "",
      "wall2.0.7",   "wall2.1.7",   "wall2.2.7",   "wall2.3.7",   "wall2.4.7",   "wall2.5.7",   "wall2.6.7",   "",
      "wall2.0.8",   "wall2.1.8",   "wall2.2.8",   "wall2.3.8",   "wall2.4.8",   "wall2.5.8",   "wall2.6.8",   "",
      "wall2.0.9",   "wall2.1.9",   "wall2.2.9",   "wall2.3.9",   "wall2.4.9",   "wall2.5.9",   "wall2.6.9",   "",
      "wall2.0.10",  "wall2.1.10",  "wall2.2.10",  "wall2.3.10",  "wall2.4.10",  "wall2.5.10",  "wall2.6.10",  "",
      "wall2.0.11",  "wall2.1.11",  "wall2.2.11",  "wall2.3.11",  "wall2.4.11",  "wall2.5.11",  "wall2.6.11",  "",
      "",            "",            "",            "",            "",            "",            "",            "",
      // clang-format on
  };
  const std::vector< std::string > arr(tiles);
  tile_load_arr("data/gfx/tiles_8x8.tga", "tiles_8x8", UI_TILE_WIDTH, UI_TILE_HEIGHT, arr);

  tilemap_add(LAYER_0, "wall");
  tilemap_add(LAYER_1, "wall");
  tilemap_add(LAYER_2, "wall");
  // clang-format on
}
