//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"
#include "my_ui.hpp"

void gfx_init6(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.6,0,0",   "ui.pixelart.6,1,0",   "ui.pixelart.6,2,0",   "ui.pixelart.6,3,0",
        "ui.pixelart.6,4,0",   "ui.pixelart.6,5,0",   "ui.pixelart.6,6,0",   "ui.pixelart.6,7,0",
        "ui.pixelart.6,8,0",   "ui.pixelart.6,9,0",   "ui.pixelart.6,10,0",  "ui.pixelart.6,11,0",
        "ui.pixelart.6,12,0",  "ui.pixelart.6,13,0",  "ui.pixelart.6,14,0",  "ui.pixelart.6,15,0",
        "ui.pixelart.6,0,1",   "ui.pixelart.6,1,1",   "ui.pixelart.6,2,1",   "ui.pixelart.6,3,1",
        "ui.pixelart.6,4,1",   "ui.pixelart.6,5,1",   "ui.pixelart.6,6,1",   "ui.pixelart.6,7,1",
        "ui.pixelart.6,8,1",   "ui.pixelart.6,9,1",   "ui.pixelart.6,10,1",  "ui.pixelart.6,11,1",
        "ui.pixelart.6,12,1",  "ui.pixelart.6,13,1",  "ui.pixelart.6,14,1",  "ui.pixelart.6,15,1",
        "ui.pixelart.6,0,2",   "ui.pixelart.6,1,2",   "ui.pixelart.6,2,2",   "ui.pixelart.6,3,2",
        "ui.pixelart.6,4,2",   "ui.pixelart.6,5,2",   "ui.pixelart.6,6,2",   "ui.pixelart.6,7,2",
        "ui.pixelart.6,8,2",   "ui.pixelart.6,9,2",   "ui.pixelart.6,10,2",  "ui.pixelart.6,11,2",
        "ui.pixelart.6,12,2",  "ui.pixelart.6,13,2",  "ui.pixelart.6,14,2",  "ui.pixelart.6,15,2",
        "ui.pixelart.6,0,3",   "ui.pixelart.6,1,3",   "ui.pixelart.6,2,3",   "ui.pixelart.6,3,3",
        "ui.pixelart.6,4,3",   "ui.pixelart.6,5,3",   "ui.pixelart.6,6,3",   "ui.pixelart.6,7,3",
        "ui.pixelart.6,8,3",   "ui.pixelart.6,9,3",   "ui.pixelart.6,10,3",  "ui.pixelart.6,11,3",
        "ui.pixelart.6,12,3",  "ui.pixelart.6,13,3",  "ui.pixelart.6,14,3",  "ui.pixelart.6,15,3",
        "ui.pixelart.6,0,4",   "ui.pixelart.6,1,4",   "ui.pixelart.6,2,4",   "ui.pixelart.6,3,4",
        "ui.pixelart.6,4,4",   "ui.pixelart.6,5,4",   "ui.pixelart.6,6,4",   "ui.pixelart.6,7,4",
        "ui.pixelart.6,8,4",   "ui.pixelart.6,9,4",   "ui.pixelart.6,10,4",  "ui.pixelart.6,11,4",
        "ui.pixelart.6,12,4",  "ui.pixelart.6,13,4",  "ui.pixelart.6,14,4",  "ui.pixelart.6,15,4",
        "ui.pixelart.6,0,5",   "ui.pixelart.6,1,5",   "ui.pixelart.6,2,5",   "ui.pixelart.6,3,5",
        "ui.pixelart.6,4,5",   "ui.pixelart.6,5,5",   "ui.pixelart.6,6,5",   "ui.pixelart.6,7,5",
        "ui.pixelart.6,8,5",   "ui.pixelart.6,9,5",   "ui.pixelart.6,10,5",  "ui.pixelart.6,11,5",
        "ui.pixelart.6,12,5",  "ui.pixelart.6,13,5",  "ui.pixelart.6,14,5",  "ui.pixelart.6,15,5",
        "ui.pixelart.6,0,6",   "ui.pixelart.6,1,6",   "ui.pixelart.6,2,6",   "ui.pixelart.6,3,6",
        "ui.pixelart.6,4,6",   "ui.pixelart.6,5,6",   "ui.pixelart.6,6,6",   "ui.pixelart.6,7,6",
        "ui.pixelart.6,8,6",   "ui.pixelart.6,9,6",   "ui.pixelart.6,10,6",  "ui.pixelart.6,11,6",
        "ui.pixelart.6,12,6",  "ui.pixelart.6,13,6",  "ui.pixelart.6,14,6",  "ui.pixelart.6,15,6",
        "ui.pixelart.6,0,7",   "ui.pixelart.6,1,7",   "ui.pixelart.6,2,7",   "ui.pixelart.6,3,7",
        "ui.pixelart.6,4,7",   "ui.pixelart.6,5,7",   "ui.pixelart.6,6,7",   "ui.pixelart.6,7,7",
        "ui.pixelart.6,8,7",   "ui.pixelart.6,9,7",   "ui.pixelart.6,10,7",  "ui.pixelart.6,11,7",
        "ui.pixelart.6,12,7",  "ui.pixelart.6,13,7",  "ui.pixelart.6,14,7",  "ui.pixelart.6,15,7",
        "ui.pixelart.6,0,8",   "ui.pixelart.6,1,8",   "ui.pixelart.6,2,8",   "ui.pixelart.6,3,8",
        "ui.pixelart.6,4,8",   "ui.pixelart.6,5,8",   "ui.pixelart.6,6,8",   "ui.pixelart.6,7,8",
        "ui.pixelart.6,8,8",   "ui.pixelart.6,9,8",   "ui.pixelart.6,10,8",  "ui.pixelart.6,11,8",
        "ui.pixelart.6,12,8",  "ui.pixelart.6,13,8",  "ui.pixelart.6,14,8",  "ui.pixelart.6,15,8",
        "ui.pixelart.6,0,9",   "ui.pixelart.6,1,9",   "ui.pixelart.6,2,9",   "ui.pixelart.6,3,9",
        "ui.pixelart.6,4,9",   "ui.pixelart.6,5,9",   "ui.pixelart.6,6,9",   "ui.pixelart.6,7,9",
        "ui.pixelart.6,8,9",   "ui.pixelart.6,9,9",   "ui.pixelart.6,10,9",  "ui.pixelart.6,11,9",
        "ui.pixelart.6,12,9",  "ui.pixelart.6,13,9",  "ui.pixelart.6,14,9",  "ui.pixelart.6,15,9",
        "ui.pixelart.6,0,10",  "ui.pixelart.6,1,10",  "ui.pixelart.6,2,10",  "ui.pixelart.6,3,10",
        "ui.pixelart.6,4,10",  "ui.pixelart.6,5,10",  "ui.pixelart.6,6,10",  "ui.pixelart.6,7,10",
        "ui.pixelart.6,8,10",  "ui.pixelart.6,9,10",  "ui.pixelart.6,10,10", "ui.pixelart.6,11,10",
        "ui.pixelart.6,12,10", "ui.pixelart.6,13,10", "ui.pixelart.6,14,10", "ui.pixelart.6,15,10",
        "ui.pixelart.6,0,11",  "ui.pixelart.6,1,11",  "ui.pixelart.6,2,11",  "ui.pixelart.6,3,11",
        "ui.pixelart.6,4,11",  "ui.pixelart.6,5,11",  "ui.pixelart.6,6,11",  "ui.pixelart.6,7,11",
        "ui.pixelart.6,8,11",  "ui.pixelart.6,9,11",  "ui.pixelart.6,10,11", "ui.pixelart.6,11,11",
        "ui.pixelart.6,12,11", "ui.pixelart.6,13,11", "ui.pixelart.6,14,11", "ui.pixelart.6,15,11",
        "ui.pixelart.6,0,12",  "ui.pixelart.6,1,12",  "ui.pixelart.6,2,12",  "ui.pixelart.6,3,12",
        "ui.pixelart.6,4,12",  "ui.pixelart.6,5,12",  "ui.pixelart.6,6,12",  "ui.pixelart.6,7,12",
        "ui.pixelart.6,8,12",  "ui.pixelart.6,9,12",  "ui.pixelart.6,10,12", "ui.pixelart.6,11,12",
        "ui.pixelart.6,12,12", "ui.pixelart.6,13,12", "ui.pixelart.6,14,12", "ui.pixelart.6,15,12",
        "ui.pixelart.6,0,13",  "ui.pixelart.6,1,13",  "ui.pixelart.6,2,13",  "ui.pixelart.6,3,13",
        "ui.pixelart.6,4,13",  "ui.pixelart.6,5,13",  "ui.pixelart.6,6,13",  "ui.pixelart.6,7,13",
        "ui.pixelart.6,8,13",  "ui.pixelart.6,9,13",  "ui.pixelart.6,10,13", "ui.pixelart.6,11,13",
        "ui.pixelart.6,12,13", "ui.pixelart.6,13,13", "ui.pixelart.6,14,13", "ui.pixelart.6,15,13",
        "ui.pixelart.6,0,14",  "ui.pixelart.6,1,14",  "ui.pixelart.6,2,14",  "ui.pixelart.6,3,14",
        "ui.pixelart.6,4,14",  "ui.pixelart.6,5,14",  "ui.pixelart.6,6,14",  "ui.pixelart.6,7,14",
        "ui.pixelart.6,8,14",  "ui.pixelart.6,9,14",  "ui.pixelart.6,10,14", "ui.pixelart.6,11,14",
        "ui.pixelart.6,12,14", "ui.pixelart.6,13,14", "ui.pixelart.6,14,14", "ui.pixelart.6,15,14",
        "ui.pixelart.6,0,15",  "ui.pixelart.6,1,15",  "ui.pixelart.6,2,15",  "ui.pixelart.6,3,15",
        "ui.pixelart.6,4,15",  "ui.pixelart.6,5,15",  "ui.pixelart.6,6,15",  "ui.pixelart.6,7,15",
        "ui.pixelart.6,8,15",  "ui.pixelart.6,9,15",  "ui.pixelart.6,10,15", "ui.pixelart.6,11,15",
        "ui.pixelart.6,12,15", "ui.pixelart.6,13,15", "ui.pixelart.6,14,15", "ui.pixelart.6,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/pixelart_ui_box6.tga", "ui_pixelart_box6", UI_TILE_PIXELART_WIDTH,
                  UI_TILE_PIXELART_HEIGHT, arr);
  }
}
