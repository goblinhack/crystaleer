//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"
#include "my_tilemap.hpp"
#include "my_ui.hpp"

void gfx_init_24x24(void)
{
  std::initializer_list< std::string > tiles = {
      // clang-format off
      "ladder.0", "pushblock.0", "", "", "", "", "", "",
      "ladder.1", "pushblock.1", "", "", "", "", "", "",
      "ladder.2", "pushblock.2", "", "", "", "", "", "",
      "ladder.3", "pushblock.3", "", "", "", "", "", "",
      "ladder.4", "pushblock.4", "", "", "", "", "", "",
      // clang-format on
  };
  const std::vector< std::string > arr(tiles);
  tile_load_arr("data/gfx/tiles_24x24.tga", "tiles_24x24", 24, 24, arr);
}
