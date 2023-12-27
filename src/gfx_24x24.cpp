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
      "ladder.0", "block.0", "rock_gold.0", "", "", "", "", "",
      "ladder.1", "block.1", "rock_gold.1", "", "", "", "", "",
      "ladder.2", "block.2", "rock_gold.2", "", "", "", "", "",
      "ladder.3", "block.3", "rock_gold.3", "", "", "", "", "",
      "ladder.4", "block.4", "rock_gold.4", "", "", "", "", "",
      // clang-format on
  };
  const std::vector< std::string > arr(tiles);
  tile_load_arr("data/gfx/tiles_24x24.tga", "tiles_24x24", 24, 24, arr);
}
