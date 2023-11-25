//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"

void gfx_init13(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.13,0,0",   "ui.pixelart.13,1,0",   "ui.pixelart.13,2,0",   "ui.pixelart.13,3,0",
        "ui.pixelart.13,4,0",   "ui.pixelart.13,5,0",   "ui.pixelart.13,6,0",   "ui.pixelart.13,7,0",
        "ui.pixelart.13,8,0",   "ui.pixelart.13,9,0",   "ui.pixelart.13,10,0",  "ui.pixelart.13,11,0",
        "ui.pixelart.13,12,0",  "ui.pixelart.13,13,0",  "ui.pixelart.13,14,0",  "ui.pixelart.13,15,0",
        "ui.pixelart.13,0,1",   "ui.pixelart.13,1,1",   "ui.pixelart.13,2,1",   "ui.pixelart.13,3,1",
        "ui.pixelart.13,4,1",   "ui.pixelart.13,5,1",   "ui.pixelart.13,6,1",   "ui.pixelart.13,7,1",
        "ui.pixelart.13,8,1",   "ui.pixelart.13,9,1",   "ui.pixelart.13,10,1",  "ui.pixelart.13,11,1",
        "ui.pixelart.13,12,1",  "ui.pixelart.13,13,1",  "ui.pixelart.13,14,1",  "ui.pixelart.13,15,1",
        "ui.pixelart.13,0,2",   "ui.pixelart.13,1,2",   "ui.pixelart.13,2,2",   "ui.pixelart.13,3,2",
        "ui.pixelart.13,4,2",   "ui.pixelart.13,5,2",   "ui.pixelart.13,6,2",   "ui.pixelart.13,7,2",
        "ui.pixelart.13,8,2",   "ui.pixelart.13,9,2",   "ui.pixelart.13,10,2",  "ui.pixelart.13,11,2",
        "ui.pixelart.13,12,2",  "ui.pixelart.13,13,2",  "ui.pixelart.13,14,2",  "ui.pixelart.13,15,2",
        "ui.pixelart.13,0,3",   "ui.pixelart.13,1,3",   "ui.pixelart.13,2,3",   "ui.pixelart.13,3,3",
        "ui.pixelart.13,4,3",   "ui.pixelart.13,5,3",   "ui.pixelart.13,6,3",   "ui.pixelart.13,7,3",
        "ui.pixelart.13,8,3",   "ui.pixelart.13,9,3",   "ui.pixelart.13,10,3",  "ui.pixelart.13,11,3",
        "ui.pixelart.13,12,3",  "ui.pixelart.13,13,3",  "ui.pixelart.13,14,3",  "ui.pixelart.13,15,3",
        "ui.pixelart.13,0,4",   "ui.pixelart.13,1,4",   "ui.pixelart.13,2,4",   "ui.pixelart.13,3,4",
        "ui.pixelart.13,4,4",   "ui.pixelart.13,5,4",   "ui.pixelart.13,6,4",   "ui.pixelart.13,7,4",
        "ui.pixelart.13,8,4",   "ui.pixelart.13,9,4",   "ui.pixelart.13,10,4",  "ui.pixelart.13,11,4",
        "ui.pixelart.13,12,4",  "ui.pixelart.13,13,4",  "ui.pixelart.13,14,4",  "ui.pixelart.13,15,4",
        "ui.pixelart.13,0,5",   "ui.pixelart.13,1,5",   "ui.pixelart.13,2,5",   "ui.pixelart.13,3,5",
        "ui.pixelart.13,4,5",   "ui.pixelart.13,5,5",   "ui.pixelart.13,6,5",   "ui.pixelart.13,7,5",
        "ui.pixelart.13,8,5",   "ui.pixelart.13,9,5",   "ui.pixelart.13,10,5",  "ui.pixelart.13,11,5",
        "ui.pixelart.13,12,5",  "ui.pixelart.13,13,5",  "ui.pixelart.13,14,5",  "ui.pixelart.13,15,5",
        "ui.pixelart.13,0,6",   "ui.pixelart.13,1,6",   "ui.pixelart.13,2,6",   "ui.pixelart.13,3,6",
        "ui.pixelart.13,4,6",   "ui.pixelart.13,5,6",   "ui.pixelart.13,6,6",   "ui.pixelart.13,7,6",
        "ui.pixelart.13,8,6",   "ui.pixelart.13,9,6",   "ui.pixelart.13,10,6",  "ui.pixelart.13,11,6",
        "ui.pixelart.13,12,6",  "ui.pixelart.13,13,6",  "ui.pixelart.13,14,6",  "ui.pixelart.13,15,6",
        "ui.pixelart.13,0,7",   "ui.pixelart.13,1,7",   "ui.pixelart.13,2,7",   "ui.pixelart.13,3,7",
        "ui.pixelart.13,4,7",   "ui.pixelart.13,5,7",   "ui.pixelart.13,6,7",   "ui.pixelart.13,7,7",
        "ui.pixelart.13,8,7",   "ui.pixelart.13,9,7",   "ui.pixelart.13,10,7",  "ui.pixelart.13,11,7",
        "ui.pixelart.13,12,7",  "ui.pixelart.13,13,7",  "ui.pixelart.13,14,7",  "ui.pixelart.13,15,7",
        "ui.pixelart.13,0,8",   "ui.pixelart.13,1,8",   "ui.pixelart.13,2,8",   "ui.pixelart.13,3,8",
        "ui.pixelart.13,4,8",   "ui.pixelart.13,5,8",   "ui.pixelart.13,6,8",   "ui.pixelart.13,7,8",
        "ui.pixelart.13,8,8",   "ui.pixelart.13,9,8",   "ui.pixelart.13,10,8",  "ui.pixelart.13,11,8",
        "ui.pixelart.13,12,8",  "ui.pixelart.13,13,8",  "ui.pixelart.13,14,8",  "ui.pixelart.13,15,8",
        "ui.pixelart.13,0,9",   "ui.pixelart.13,1,9",   "ui.pixelart.13,2,9",   "ui.pixelart.13,3,9",
        "ui.pixelart.13,4,9",   "ui.pixelart.13,5,9",   "ui.pixelart.13,6,9",   "ui.pixelart.13,7,9",
        "ui.pixelart.13,8,9",   "ui.pixelart.13,9,9",   "ui.pixelart.13,10,9",  "ui.pixelart.13,11,9",
        "ui.pixelart.13,12,9",  "ui.pixelart.13,13,9",  "ui.pixelart.13,14,9",  "ui.pixelart.13,15,9",
        "ui.pixelart.13,0,10",  "ui.pixelart.13,1,10",  "ui.pixelart.13,2,10",  "ui.pixelart.13,3,10",
        "ui.pixelart.13,4,10",  "ui.pixelart.13,5,10",  "ui.pixelart.13,6,10",  "ui.pixelart.13,7,10",
        "ui.pixelart.13,8,10",  "ui.pixelart.13,9,10",  "ui.pixelart.13,10,10", "ui.pixelart.13,11,10",
        "ui.pixelart.13,12,10", "ui.pixelart.13,13,10", "ui.pixelart.13,14,10", "ui.pixelart.13,15,10",
        "ui.pixelart.13,0,11",  "ui.pixelart.13,1,11",  "ui.pixelart.13,2,11",  "ui.pixelart.13,3,11",
        "ui.pixelart.13,4,11",  "ui.pixelart.13,5,11",  "ui.pixelart.13,6,11",  "ui.pixelart.13,7,11",
        "ui.pixelart.13,8,11",  "ui.pixelart.13,9,11",  "ui.pixelart.13,10,11", "ui.pixelart.13,11,11",
        "ui.pixelart.13,12,11", "ui.pixelart.13,13,11", "ui.pixelart.13,14,11", "ui.pixelart.13,15,11",
        "ui.pixelart.13,0,12",  "ui.pixelart.13,1,12",  "ui.pixelart.13,2,12",  "ui.pixelart.13,3,12",
        "ui.pixelart.13,4,12",  "ui.pixelart.13,5,12",  "ui.pixelart.13,6,12",  "ui.pixelart.13,7,12",
        "ui.pixelart.13,8,12",  "ui.pixelart.13,9,12",  "ui.pixelart.13,10,12", "ui.pixelart.13,11,12",
        "ui.pixelart.13,12,12", "ui.pixelart.13,13,12", "ui.pixelart.13,14,12", "ui.pixelart.13,15,12",
        "ui.pixelart.13,0,13",  "ui.pixelart.13,1,13",  "ui.pixelart.13,2,13",  "ui.pixelart.13,3,13",
        "ui.pixelart.13,4,13",  "ui.pixelart.13,5,13",  "ui.pixelart.13,6,13",  "ui.pixelart.13,7,13",
        "ui.pixelart.13,8,13",  "ui.pixelart.13,9,13",  "ui.pixelart.13,10,13", "ui.pixelart.13,11,13",
        "ui.pixelart.13,12,13", "ui.pixelart.13,13,13", "ui.pixelart.13,14,13", "ui.pixelart.13,15,13",
        "ui.pixelart.13,0,14",  "ui.pixelart.13,1,14",  "ui.pixelart.13,2,14",  "ui.pixelart.13,3,14",
        "ui.pixelart.13,4,14",  "ui.pixelart.13,5,14",  "ui.pixelart.13,6,14",  "ui.pixelart.13,7,14",
        "ui.pixelart.13,8,14",  "ui.pixelart.13,9,14",  "ui.pixelart.13,10,14", "ui.pixelart.13,11,14",
        "ui.pixelart.13,12,14", "ui.pixelart.13,13,14", "ui.pixelart.13,14,14", "ui.pixelart.13,15,14",
        "ui.pixelart.13,0,15",  "ui.pixelart.13,1,15",  "ui.pixelart.13,2,15",  "ui.pixelart.13,3,15",
        "ui.pixelart.13,4,15",  "ui.pixelart.13,5,15",  "ui.pixelart.13,6,15",  "ui.pixelart.13,7,15",
        "ui.pixelart.13,8,15",  "ui.pixelart.13,9,15",  "ui.pixelart.13,10,15", "ui.pixelart.13,11,15",
        "ui.pixelart.13,12,15", "ui.pixelart.13,13,15", "ui.pixelart.13,14,15", "ui.pixelart.13,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/pixelart_ui_vert_scroll2.tga", "ui_pixelart_box13", 8, 8, arr);
  }
}