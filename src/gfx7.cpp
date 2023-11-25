//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"
#include "my_ui.hpp"

void gfx_init7(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.7,0,0",   "ui.pixelart.7,1,0",   "ui.pixelart.7,2,0",   "ui.pixelart.7,3,0",
        "ui.pixelart.7,4,0",   "ui.pixelart.7,5,0",   "ui.pixelart.7,6,0",   "ui.pixelart.7,7,0",
        "ui.pixelart.7,8,0",   "ui.pixelart.7,9,0",   "ui.pixelart.7,10,0",  "ui.pixelart.7,11,0",
        "ui.pixelart.7,12,0",  "ui.pixelart.7,13,0",  "ui.pixelart.7,14,0",  "ui.pixelart.7,15,0",
        "ui.pixelart.7,0,1",   "ui.pixelart.7,1,1",   "ui.pixelart.7,2,1",   "ui.pixelart.7,3,1",
        "ui.pixelart.7,4,1",   "ui.pixelart.7,5,1",   "ui.pixelart.7,6,1",   "ui.pixelart.7,7,1",
        "ui.pixelart.7,8,1",   "ui.pixelart.7,9,1",   "ui.pixelart.7,10,1",  "ui.pixelart.7,11,1",
        "ui.pixelart.7,12,1",  "ui.pixelart.7,13,1",  "ui.pixelart.7,14,1",  "ui.pixelart.7,15,1",
        "ui.pixelart.7,0,2",   "ui.pixelart.7,1,2",   "ui.pixelart.7,2,2",   "ui.pixelart.7,3,2",
        "ui.pixelart.7,4,2",   "ui.pixelart.7,5,2",   "ui.pixelart.7,6,2",   "ui.pixelart.7,7,2",
        "ui.pixelart.7,8,2",   "ui.pixelart.7,9,2",   "ui.pixelart.7,10,2",  "ui.pixelart.7,11,2",
        "ui.pixelart.7,12,2",  "ui.pixelart.7,13,2",  "ui.pixelart.7,14,2",  "ui.pixelart.7,15,2",
        "ui.pixelart.7,0,3",   "ui.pixelart.7,1,3",   "ui.pixelart.7,2,3",   "ui.pixelart.7,3,3",
        "ui.pixelart.7,4,3",   "ui.pixelart.7,5,3",   "ui.pixelart.7,6,3",   "ui.pixelart.7,7,3",
        "ui.pixelart.7,8,3",   "ui.pixelart.7,9,3",   "ui.pixelart.7,10,3",  "ui.pixelart.7,11,3",
        "ui.pixelart.7,12,3",  "ui.pixelart.7,13,3",  "ui.pixelart.7,14,3",  "ui.pixelart.7,15,3",
        "ui.pixelart.7,0,4",   "ui.pixelart.7,1,4",   "ui.pixelart.7,2,4",   "ui.pixelart.7,3,4",
        "ui.pixelart.7,4,4",   "ui.pixelart.7,5,4",   "ui.pixelart.7,6,4",   "ui.pixelart.7,7,4",
        "ui.pixelart.7,8,4",   "ui.pixelart.7,9,4",   "ui.pixelart.7,10,4",  "ui.pixelart.7,11,4",
        "ui.pixelart.7,12,4",  "ui.pixelart.7,13,4",  "ui.pixelart.7,14,4",  "ui.pixelart.7,15,4",
        "ui.pixelart.7,0,5",   "ui.pixelart.7,1,5",   "ui.pixelart.7,2,5",   "ui.pixelart.7,3,5",
        "ui.pixelart.7,4,5",   "ui.pixelart.7,5,5",   "ui.pixelart.7,6,5",   "ui.pixelart.7,7,5",
        "ui.pixelart.7,8,5",   "ui.pixelart.7,9,5",   "ui.pixelart.7,10,5",  "ui.pixelart.7,11,5",
        "ui.pixelart.7,12,5",  "ui.pixelart.7,13,5",  "ui.pixelart.7,14,5",  "ui.pixelart.7,15,5",
        "ui.pixelart.7,0,6",   "ui.pixelart.7,1,6",   "ui.pixelart.7,2,6",   "ui.pixelart.7,3,6",
        "ui.pixelart.7,4,6",   "ui.pixelart.7,5,6",   "ui.pixelart.7,6,6",   "ui.pixelart.7,7,6",
        "ui.pixelart.7,8,6",   "ui.pixelart.7,9,6",   "ui.pixelart.7,10,6",  "ui.pixelart.7,11,6",
        "ui.pixelart.7,12,6",  "ui.pixelart.7,13,6",  "ui.pixelart.7,14,6",  "ui.pixelart.7,15,6",
        "ui.pixelart.7,0,7",   "ui.pixelart.7,1,7",   "ui.pixelart.7,2,7",   "ui.pixelart.7,3,7",
        "ui.pixelart.7,4,7",   "ui.pixelart.7,5,7",   "ui.pixelart.7,6,7",   "ui.pixelart.7,7,7",
        "ui.pixelart.7,8,7",   "ui.pixelart.7,9,7",   "ui.pixelart.7,10,7",  "ui.pixelart.7,11,7",
        "ui.pixelart.7,12,7",  "ui.pixelart.7,13,7",  "ui.pixelart.7,14,7",  "ui.pixelart.7,15,7",
        "ui.pixelart.7,0,8",   "ui.pixelart.7,1,8",   "ui.pixelart.7,2,8",   "ui.pixelart.7,3,8",
        "ui.pixelart.7,4,8",   "ui.pixelart.7,5,8",   "ui.pixelart.7,6,8",   "ui.pixelart.7,7,8",
        "ui.pixelart.7,8,8",   "ui.pixelart.7,9,8",   "ui.pixelart.7,10,8",  "ui.pixelart.7,11,8",
        "ui.pixelart.7,12,8",  "ui.pixelart.7,13,8",  "ui.pixelart.7,14,8",  "ui.pixelart.7,15,8",
        "ui.pixelart.7,0,9",   "ui.pixelart.7,1,9",   "ui.pixelart.7,2,9",   "ui.pixelart.7,3,9",
        "ui.pixelart.7,4,9",   "ui.pixelart.7,5,9",   "ui.pixelart.7,6,9",   "ui.pixelart.7,7,9",
        "ui.pixelart.7,8,9",   "ui.pixelart.7,9,9",   "ui.pixelart.7,10,9",  "ui.pixelart.7,11,9",
        "ui.pixelart.7,12,9",  "ui.pixelart.7,13,9",  "ui.pixelart.7,14,9",  "ui.pixelart.7,15,9",
        "ui.pixelart.7,0,10",  "ui.pixelart.7,1,10",  "ui.pixelart.7,2,10",  "ui.pixelart.7,3,10",
        "ui.pixelart.7,4,10",  "ui.pixelart.7,5,10",  "ui.pixelart.7,6,10",  "ui.pixelart.7,7,10",
        "ui.pixelart.7,8,10",  "ui.pixelart.7,9,10",  "ui.pixelart.7,10,10", "ui.pixelart.7,11,10",
        "ui.pixelart.7,12,10", "ui.pixelart.7,13,10", "ui.pixelart.7,14,10", "ui.pixelart.7,15,10",
        "ui.pixelart.7,0,11",  "ui.pixelart.7,1,11",  "ui.pixelart.7,2,11",  "ui.pixelart.7,3,11",
        "ui.pixelart.7,4,11",  "ui.pixelart.7,5,11",  "ui.pixelart.7,6,11",  "ui.pixelart.7,7,11",
        "ui.pixelart.7,8,11",  "ui.pixelart.7,9,11",  "ui.pixelart.7,10,11", "ui.pixelart.7,11,11",
        "ui.pixelart.7,12,11", "ui.pixelart.7,13,11", "ui.pixelart.7,14,11", "ui.pixelart.7,15,11",
        "ui.pixelart.7,0,12",  "ui.pixelart.7,1,12",  "ui.pixelart.7,2,12",  "ui.pixelart.7,3,12",
        "ui.pixelart.7,4,12",  "ui.pixelart.7,5,12",  "ui.pixelart.7,6,12",  "ui.pixelart.7,7,12",
        "ui.pixelart.7,8,12",  "ui.pixelart.7,9,12",  "ui.pixelart.7,10,12", "ui.pixelart.7,11,12",
        "ui.pixelart.7,12,12", "ui.pixelart.7,13,12", "ui.pixelart.7,14,12", "ui.pixelart.7,15,12",
        "ui.pixelart.7,0,13",  "ui.pixelart.7,1,13",  "ui.pixelart.7,2,13",  "ui.pixelart.7,3,13",
        "ui.pixelart.7,4,13",  "ui.pixelart.7,5,13",  "ui.pixelart.7,6,13",  "ui.pixelart.7,7,13",
        "ui.pixelart.7,8,13",  "ui.pixelart.7,9,13",  "ui.pixelart.7,10,13", "ui.pixelart.7,11,13",
        "ui.pixelart.7,12,13", "ui.pixelart.7,13,13", "ui.pixelart.7,14,13", "ui.pixelart.7,15,13",
        "ui.pixelart.7,0,14",  "ui.pixelart.7,1,14",  "ui.pixelart.7,2,14",  "ui.pixelart.7,3,14",
        "ui.pixelart.7,4,14",  "ui.pixelart.7,5,14",  "ui.pixelart.7,6,14",  "ui.pixelart.7,7,14",
        "ui.pixelart.7,8,14",  "ui.pixelart.7,9,14",  "ui.pixelart.7,10,14", "ui.pixelart.7,11,14",
        "ui.pixelart.7,12,14", "ui.pixelart.7,13,14", "ui.pixelart.7,14,14", "ui.pixelart.7,15,14",
        "ui.pixelart.7,0,15",  "ui.pixelart.7,1,15",  "ui.pixelart.7,2,15",  "ui.pixelart.7,3,15",
        "ui.pixelart.7,4,15",  "ui.pixelart.7,5,15",  "ui.pixelart.7,6,15",  "ui.pixelart.7,7,15",
        "ui.pixelart.7,8,15",  "ui.pixelart.7,9,15",  "ui.pixelart.7,10,15", "ui.pixelart.7,11,15",
        "ui.pixelart.7,12,15", "ui.pixelart.7,13,15", "ui.pixelart.7,14,15", "ui.pixelart.7,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/pixelart_ui_box7.tga", "ui_pixelart_box7", UI_TILE_PIXELART_WIDTH,
                  UI_TILE_PIXELART_HEIGHT, arr);
  }
}
