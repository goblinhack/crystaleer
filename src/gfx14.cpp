//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"

void gfx_init14(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.14,0,0",   "ui.pixelart.14,1,0",   "ui.pixelart.14,2,0",   "ui.pixelart.14,3,0",
        "ui.pixelart.14,4,0",   "ui.pixelart.14,5,0",   "ui.pixelart.14,6,0",   "ui.pixelart.14,7,0",
        "ui.pixelart.14,8,0",   "ui.pixelart.14,9,0",   "ui.pixelart.14,10,0",  "ui.pixelart.14,11,0",
        "ui.pixelart.14,12,0",  "ui.pixelart.14,13,0",  "ui.pixelart.14,14,0",  "ui.pixelart.14,15,0",
        "ui.pixelart.14,0,1",   "ui.pixelart.14,1,1",   "ui.pixelart.14,2,1",   "ui.pixelart.14,3,1",
        "ui.pixelart.14,4,1",   "ui.pixelart.14,5,1",   "ui.pixelart.14,6,1",   "ui.pixelart.14,7,1",
        "ui.pixelart.14,8,1",   "ui.pixelart.14,9,1",   "ui.pixelart.14,10,1",  "ui.pixelart.14,11,1",
        "ui.pixelart.14,12,1",  "ui.pixelart.14,13,1",  "ui.pixelart.14,14,1",  "ui.pixelart.14,15,1",
        "ui.pixelart.14,0,2",   "ui.pixelart.14,1,2",   "ui.pixelart.14,2,2",   "ui.pixelart.14,3,2",
        "ui.pixelart.14,4,2",   "ui.pixelart.14,5,2",   "ui.pixelart.14,6,2",   "ui.pixelart.14,7,2",
        "ui.pixelart.14,8,2",   "ui.pixelart.14,9,2",   "ui.pixelart.14,10,2",  "ui.pixelart.14,11,2",
        "ui.pixelart.14,12,2",  "ui.pixelart.14,13,2",  "ui.pixelart.14,14,2",  "ui.pixelart.14,15,2",
        "ui.pixelart.14,0,3",   "ui.pixelart.14,1,3",   "ui.pixelart.14,2,3",   "ui.pixelart.14,3,3",
        "ui.pixelart.14,4,3",   "ui.pixelart.14,5,3",   "ui.pixelart.14,6,3",   "ui.pixelart.14,7,3",
        "ui.pixelart.14,8,3",   "ui.pixelart.14,9,3",   "ui.pixelart.14,10,3",  "ui.pixelart.14,11,3",
        "ui.pixelart.14,12,3",  "ui.pixelart.14,13,3",  "ui.pixelart.14,14,3",  "ui.pixelart.14,15,3",
        "ui.pixelart.14,0,4",   "ui.pixelart.14,1,4",   "ui.pixelart.14,2,4",   "ui.pixelart.14,3,4",
        "ui.pixelart.14,4,4",   "ui.pixelart.14,5,4",   "ui.pixelart.14,6,4",   "ui.pixelart.14,7,4",
        "ui.pixelart.14,8,4",   "ui.pixelart.14,9,4",   "ui.pixelart.14,10,4",  "ui.pixelart.14,11,4",
        "ui.pixelart.14,12,4",  "ui.pixelart.14,13,4",  "ui.pixelart.14,14,4",  "ui.pixelart.14,15,4",
        "ui.pixelart.14,0,5",   "ui.pixelart.14,1,5",   "ui.pixelart.14,2,5",   "ui.pixelart.14,3,5",
        "ui.pixelart.14,4,5",   "ui.pixelart.14,5,5",   "ui.pixelart.14,6,5",   "ui.pixelart.14,7,5",
        "ui.pixelart.14,8,5",   "ui.pixelart.14,9,5",   "ui.pixelart.14,10,5",  "ui.pixelart.14,11,5",
        "ui.pixelart.14,12,5",  "ui.pixelart.14,13,5",  "ui.pixelart.14,14,5",  "ui.pixelart.14,15,5",
        "ui.pixelart.14,0,6",   "ui.pixelart.14,1,6",   "ui.pixelart.14,2,6",   "ui.pixelart.14,3,6",
        "ui.pixelart.14,4,6",   "ui.pixelart.14,5,6",   "ui.pixelart.14,6,6",   "ui.pixelart.14,7,6",
        "ui.pixelart.14,8,6",   "ui.pixelart.14,9,6",   "ui.pixelart.14,10,6",  "ui.pixelart.14,11,6",
        "ui.pixelart.14,12,6",  "ui.pixelart.14,13,6",  "ui.pixelart.14,14,6",  "ui.pixelart.14,15,6",
        "ui.pixelart.14,0,7",   "ui.pixelart.14,1,7",   "ui.pixelart.14,2,7",   "ui.pixelart.14,3,7",
        "ui.pixelart.14,4,7",   "ui.pixelart.14,5,7",   "ui.pixelart.14,6,7",   "ui.pixelart.14,7,7",
        "ui.pixelart.14,8,7",   "ui.pixelart.14,9,7",   "ui.pixelart.14,10,7",  "ui.pixelart.14,11,7",
        "ui.pixelart.14,12,7",  "ui.pixelart.14,13,7",  "ui.pixelart.14,14,7",  "ui.pixelart.14,15,7",
        "ui.pixelart.14,0,8",   "ui.pixelart.14,1,8",   "ui.pixelart.14,2,8",   "ui.pixelart.14,3,8",
        "ui.pixelart.14,4,8",   "ui.pixelart.14,5,8",   "ui.pixelart.14,6,8",   "ui.pixelart.14,7,8",
        "ui.pixelart.14,8,8",   "ui.pixelart.14,9,8",   "ui.pixelart.14,10,8",  "ui.pixelart.14,11,8",
        "ui.pixelart.14,12,8",  "ui.pixelart.14,13,8",  "ui.pixelart.14,14,8",  "ui.pixelart.14,15,8",
        "ui.pixelart.14,0,9",   "ui.pixelart.14,1,9",   "ui.pixelart.14,2,9",   "ui.pixelart.14,3,9",
        "ui.pixelart.14,4,9",   "ui.pixelart.14,5,9",   "ui.pixelart.14,6,9",   "ui.pixelart.14,7,9",
        "ui.pixelart.14,8,9",   "ui.pixelart.14,9,9",   "ui.pixelart.14,10,9",  "ui.pixelart.14,11,9",
        "ui.pixelart.14,12,9",  "ui.pixelart.14,13,9",  "ui.pixelart.14,14,9",  "ui.pixelart.14,15,9",
        "ui.pixelart.14,0,10",  "ui.pixelart.14,1,10",  "ui.pixelart.14,2,10",  "ui.pixelart.14,3,10",
        "ui.pixelart.14,4,10",  "ui.pixelart.14,5,10",  "ui.pixelart.14,6,10",  "ui.pixelart.14,7,10",
        "ui.pixelart.14,8,10",  "ui.pixelart.14,9,10",  "ui.pixelart.14,10,10", "ui.pixelart.14,11,10",
        "ui.pixelart.14,12,10", "ui.pixelart.14,13,10", "ui.pixelart.14,14,10", "ui.pixelart.14,15,10",
        "ui.pixelart.14,0,11",  "ui.pixelart.14,1,11",  "ui.pixelart.14,2,11",  "ui.pixelart.14,3,11",
        "ui.pixelart.14,4,11",  "ui.pixelart.14,5,11",  "ui.pixelart.14,6,11",  "ui.pixelart.14,7,11",
        "ui.pixelart.14,8,11",  "ui.pixelart.14,9,11",  "ui.pixelart.14,10,11", "ui.pixelart.14,11,11",
        "ui.pixelart.14,12,11", "ui.pixelart.14,13,11", "ui.pixelart.14,14,11", "ui.pixelart.14,15,11",
        "ui.pixelart.14,0,12",  "ui.pixelart.14,1,12",  "ui.pixelart.14,2,12",  "ui.pixelart.14,3,12",
        "ui.pixelart.14,4,12",  "ui.pixelart.14,5,12",  "ui.pixelart.14,6,12",  "ui.pixelart.14,7,12",
        "ui.pixelart.14,8,12",  "ui.pixelart.14,9,12",  "ui.pixelart.14,10,12", "ui.pixelart.14,11,12",
        "ui.pixelart.14,12,12", "ui.pixelart.14,13,12", "ui.pixelart.14,14,12", "ui.pixelart.14,15,12",
        "ui.pixelart.14,0,13",  "ui.pixelart.14,1,13",  "ui.pixelart.14,2,13",  "ui.pixelart.14,3,13",
        "ui.pixelart.14,4,13",  "ui.pixelart.14,5,13",  "ui.pixelart.14,6,13",  "ui.pixelart.14,7,13",
        "ui.pixelart.14,8,13",  "ui.pixelart.14,9,13",  "ui.pixelart.14,10,13", "ui.pixelart.14,11,13",
        "ui.pixelart.14,12,13", "ui.pixelart.14,13,13", "ui.pixelart.14,14,13", "ui.pixelart.14,15,13",
        "ui.pixelart.14,0,14",  "ui.pixelart.14,1,14",  "ui.pixelart.14,2,14",  "ui.pixelart.14,3,14",
        "ui.pixelart.14,4,14",  "ui.pixelart.14,5,14",  "ui.pixelart.14,6,14",  "ui.pixelart.14,7,14",
        "ui.pixelart.14,8,14",  "ui.pixelart.14,9,14",  "ui.pixelart.14,10,14", "ui.pixelart.14,11,14",
        "ui.pixelart.14,12,14", "ui.pixelart.14,13,14", "ui.pixelart.14,14,14", "ui.pixelart.14,15,14",
        "ui.pixelart.14,0,15",  "ui.pixelart.14,1,15",  "ui.pixelart.14,2,15",  "ui.pixelart.14,3,15",
        "ui.pixelart.14,4,15",  "ui.pixelart.14,5,15",  "ui.pixelart.14,6,15",  "ui.pixelart.14,7,15",
        "ui.pixelart.14,8,15",  "ui.pixelart.14,9,15",  "ui.pixelart.14,10,15", "ui.pixelart.14,11,15",
        "ui.pixelart.14,12,15", "ui.pixelart.14,13,15", "ui.pixelart.14,14,15", "ui.pixelart.14,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/pixelart_ui_horiz_scroll1.tga", "ui_pixelart_box14", 8, 8, arr);
  }
}
