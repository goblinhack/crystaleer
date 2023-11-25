//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"
#include "my_ui.hpp"

void gfx_init1(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.1,0,0",   "ui.pixelart.1,1,0",   "ui.pixelart.1,2,0",   "ui.pixelart.1,3,0",
        "ui.pixelart.1,4,0",   "ui.pixelart.1,5,0",   "ui.pixelart.1,6,0",   "ui.pixelart.1,7,0",
        "ui.pixelart.1,8,0",   "ui.pixelart.1,9,0",   "ui.pixelart.1,10,0",  "ui.pixelart.1,11,0",
        "ui.pixelart.1,12,0",  "ui.pixelart.1,13,0",  "ui.pixelart.1,14,0",  "ui.pixelart.1,15,0",
        "ui.pixelart.1,0,1",   "ui.pixelart.1,1,1",   "ui.pixelart.1,2,1",   "ui.pixelart.1,3,1",
        "ui.pixelart.1,4,1",   "ui.pixelart.1,5,1",   "ui.pixelart.1,6,1",   "ui.pixelart.1,7,1",
        "ui.pixelart.1,8,1",   "ui.pixelart.1,9,1",   "ui.pixelart.1,10,1",  "ui.pixelart.1,11,1",
        "ui.pixelart.1,12,1",  "ui.pixelart.1,13,1",  "ui.pixelart.1,14,1",  "ui.pixelart.1,15,1",
        "ui.pixelart.1,0,2",   "ui.pixelart.1,1,2",   "ui.pixelart.1,2,2",   "ui.pixelart.1,3,2",
        "ui.pixelart.1,4,2",   "ui.pixelart.1,5,2",   "ui.pixelart.1,6,2",   "ui.pixelart.1,7,2",
        "ui.pixelart.1,8,2",   "ui.pixelart.1,9,2",   "ui.pixelart.1,10,2",  "ui.pixelart.1,11,2",
        "ui.pixelart.1,12,2",  "ui.pixelart.1,13,2",  "ui.pixelart.1,14,2",  "ui.pixelart.1,15,2",
        "ui.pixelart.1,0,3",   "ui.pixelart.1,1,3",   "ui.pixelart.1,2,3",   "ui.pixelart.1,3,3",
        "ui.pixelart.1,4,3",   "ui.pixelart.1,5,3",   "ui.pixelart.1,6,3",   "ui.pixelart.1,7,3",
        "ui.pixelart.1,8,3",   "ui.pixelart.1,9,3",   "ui.pixelart.1,10,3",  "ui.pixelart.1,11,3",
        "ui.pixelart.1,12,3",  "ui.pixelart.1,13,3",  "ui.pixelart.1,14,3",  "ui.pixelart.1,15,3",
        "ui.pixelart.1,0,4",   "ui.pixelart.1,1,4",   "ui.pixelart.1,2,4",   "ui.pixelart.1,3,4",
        "ui.pixelart.1,4,4",   "ui.pixelart.1,5,4",   "ui.pixelart.1,6,4",   "ui.pixelart.1,7,4",
        "ui.pixelart.1,8,4",   "ui.pixelart.1,9,4",   "ui.pixelart.1,10,4",  "ui.pixelart.1,11,4",
        "ui.pixelart.1,12,4",  "ui.pixelart.1,13,4",  "ui.pixelart.1,14,4",  "ui.pixelart.1,15,4",
        "ui.pixelart.1,0,5",   "ui.pixelart.1,1,5",   "ui.pixelart.1,2,5",   "ui.pixelart.1,3,5",
        "ui.pixelart.1,4,5",   "ui.pixelart.1,5,5",   "ui.pixelart.1,6,5",   "ui.pixelart.1,7,5",
        "ui.pixelart.1,8,5",   "ui.pixelart.1,9,5",   "ui.pixelart.1,10,5",  "ui.pixelart.1,11,5",
        "ui.pixelart.1,12,5",  "ui.pixelart.1,13,5",  "ui.pixelart.1,14,5",  "ui.pixelart.1,15,5",
        "ui.pixelart.1,0,6",   "ui.pixelart.1,1,6",   "ui.pixelart.1,2,6",   "ui.pixelart.1,3,6",
        "ui.pixelart.1,4,6",   "ui.pixelart.1,5,6",   "ui.pixelart.1,6,6",   "ui.pixelart.1,7,6",
        "ui.pixelart.1,8,6",   "ui.pixelart.1,9,6",   "ui.pixelart.1,10,6",  "ui.pixelart.1,11,6",
        "ui.pixelart.1,12,6",  "ui.pixelart.1,13,6",  "ui.pixelart.1,14,6",  "ui.pixelart.1,15,6",
        "ui.pixelart.1,0,7",   "ui.pixelart.1,1,7",   "ui.pixelart.1,2,7",   "ui.pixelart.1,3,7",
        "ui.pixelart.1,4,7",   "ui.pixelart.1,5,7",   "ui.pixelart.1,6,7",   "ui.pixelart.1,7,7",
        "ui.pixelart.1,8,7",   "ui.pixelart.1,9,7",   "ui.pixelart.1,10,7",  "ui.pixelart.1,11,7",
        "ui.pixelart.1,12,7",  "ui.pixelart.1,13,7",  "ui.pixelart.1,14,7",  "ui.pixelart.1,15,7",
        "ui.pixelart.1,0,8",   "ui.pixelart.1,1,8",   "ui.pixelart.1,2,8",   "ui.pixelart.1,3,8",
        "ui.pixelart.1,4,8",   "ui.pixelart.1,5,8",   "ui.pixelart.1,6,8",   "ui.pixelart.1,7,8",
        "ui.pixelart.1,8,8",   "ui.pixelart.1,9,8",   "ui.pixelart.1,10,8",  "ui.pixelart.1,11,8",
        "ui.pixelart.1,12,8",  "ui.pixelart.1,13,8",  "ui.pixelart.1,14,8",  "ui.pixelart.1,15,8",
        "ui.pixelart.1,0,9",   "ui.pixelart.1,1,9",   "ui.pixelart.1,2,9",   "ui.pixelart.1,3,9",
        "ui.pixelart.1,4,9",   "ui.pixelart.1,5,9",   "ui.pixelart.1,6,9",   "ui.pixelart.1,7,9",
        "ui.pixelart.1,8,9",   "ui.pixelart.1,9,9",   "ui.pixelart.1,10,9",  "ui.pixelart.1,11,9",
        "ui.pixelart.1,12,9",  "ui.pixelart.1,13,9",  "ui.pixelart.1,14,9",  "ui.pixelart.1,15,9",
        "ui.pixelart.1,0,10",  "ui.pixelart.1,1,10",  "ui.pixelart.1,2,10",  "ui.pixelart.1,3,10",
        "ui.pixelart.1,4,10",  "ui.pixelart.1,5,10",  "ui.pixelart.1,6,10",  "ui.pixelart.1,7,10",
        "ui.pixelart.1,8,10",  "ui.pixelart.1,9,10",  "ui.pixelart.1,10,10", "ui.pixelart.1,11,10",
        "ui.pixelart.1,12,10", "ui.pixelart.1,13,10", "ui.pixelart.1,14,10", "ui.pixelart.1,15,10",
        "ui.pixelart.1,0,11",  "ui.pixelart.1,1,11",  "ui.pixelart.1,2,11",  "ui.pixelart.1,3,11",
        "ui.pixelart.1,4,11",  "ui.pixelart.1,5,11",  "ui.pixelart.1,6,11",  "ui.pixelart.1,7,11",
        "ui.pixelart.1,8,11",  "ui.pixelart.1,9,11",  "ui.pixelart.1,10,11", "ui.pixelart.1,11,11",
        "ui.pixelart.1,12,11", "ui.pixelart.1,13,11", "ui.pixelart.1,14,11", "ui.pixelart.1,15,11",
        "ui.pixelart.1,0,12",  "ui.pixelart.1,1,12",  "ui.pixelart.1,2,12",  "ui.pixelart.1,3,12",
        "ui.pixelart.1,4,12",  "ui.pixelart.1,5,12",  "ui.pixelart.1,6,12",  "ui.pixelart.1,7,12",
        "ui.pixelart.1,8,12",  "ui.pixelart.1,9,12",  "ui.pixelart.1,10,12", "ui.pixelart.1,11,12",
        "ui.pixelart.1,12,12", "ui.pixelart.1,13,12", "ui.pixelart.1,14,12", "ui.pixelart.1,15,12",
        "ui.pixelart.1,0,13",  "ui.pixelart.1,1,13",  "ui.pixelart.1,2,13",  "ui.pixelart.1,3,13",
        "ui.pixelart.1,4,13",  "ui.pixelart.1,5,13",  "ui.pixelart.1,6,13",  "ui.pixelart.1,7,13",
        "ui.pixelart.1,8,13",  "ui.pixelart.1,9,13",  "ui.pixelart.1,10,13", "ui.pixelart.1,11,13",
        "ui.pixelart.1,12,13", "ui.pixelart.1,13,13", "ui.pixelart.1,14,13", "ui.pixelart.1,15,13",
        "ui.pixelart.1,0,14",  "ui.pixelart.1,1,14",  "ui.pixelart.1,2,14",  "ui.pixelart.1,3,14",
        "ui.pixelart.1,4,14",  "ui.pixelart.1,5,14",  "ui.pixelart.1,6,14",  "ui.pixelart.1,7,14",
        "ui.pixelart.1,8,14",  "ui.pixelart.1,9,14",  "ui.pixelart.1,10,14", "ui.pixelart.1,11,14",
        "ui.pixelart.1,12,14", "ui.pixelart.1,13,14", "ui.pixelart.1,14,14", "ui.pixelart.1,15,14",
        "ui.pixelart.1,0,15",  "ui.pixelart.1,1,15",  "ui.pixelart.1,2,15",  "ui.pixelart.1,3,15",
        "ui.pixelart.1,4,15",  "ui.pixelart.1,5,15",  "ui.pixelart.1,6,15",  "ui.pixelart.1,7,15",
        "ui.pixelart.1,8,15",  "ui.pixelart.1,9,15",  "ui.pixelart.1,10,15", "ui.pixelart.1,11,15",
        "ui.pixelart.1,12,15", "ui.pixelart.1,13,15", "ui.pixelart.1,14,15", "ui.pixelart.1,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/pixelart_ui_box1.tga", "ui_pixelart_box", UI_TILE_PIXELART_WIDTH,
                  UI_TILE_PIXELART_HEIGHT, arr);
  }
}
