//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"

void gfx_init15(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.15,0,0",   "ui.pixelart.15,1,0",   "ui.pixelart.15,2,0",   "ui.pixelart.15,3,0",
        "ui.pixelart.15,4,0",   "ui.pixelart.15,5,0",   "ui.pixelart.15,6,0",   "ui.pixelart.15,7,0",
        "ui.pixelart.15,8,0",   "ui.pixelart.15,9,0",   "ui.pixelart.15,10,0",  "ui.pixelart.15,11,0",
        "ui.pixelart.15,12,0",  "ui.pixelart.15,13,0",  "ui.pixelart.15,14,0",  "ui.pixelart.15,15,0",
        "ui.pixelart.15,0,1",   "ui.pixelart.15,1,1",   "ui.pixelart.15,2,1",   "ui.pixelart.15,3,1",
        "ui.pixelart.15,4,1",   "ui.pixelart.15,5,1",   "ui.pixelart.15,6,1",   "ui.pixelart.15,7,1",
        "ui.pixelart.15,8,1",   "ui.pixelart.15,9,1",   "ui.pixelart.15,10,1",  "ui.pixelart.15,11,1",
        "ui.pixelart.15,12,1",  "ui.pixelart.15,13,1",  "ui.pixelart.15,14,1",  "ui.pixelart.15,15,1",
        "ui.pixelart.15,0,2",   "ui.pixelart.15,1,2",   "ui.pixelart.15,2,2",   "ui.pixelart.15,3,2",
        "ui.pixelart.15,4,2",   "ui.pixelart.15,5,2",   "ui.pixelart.15,6,2",   "ui.pixelart.15,7,2",
        "ui.pixelart.15,8,2",   "ui.pixelart.15,9,2",   "ui.pixelart.15,10,2",  "ui.pixelart.15,11,2",
        "ui.pixelart.15,12,2",  "ui.pixelart.15,13,2",  "ui.pixelart.15,14,2",  "ui.pixelart.15,15,2",
        "ui.pixelart.15,0,3",   "ui.pixelart.15,1,3",   "ui.pixelart.15,2,3",   "ui.pixelart.15,3,3",
        "ui.pixelart.15,4,3",   "ui.pixelart.15,5,3",   "ui.pixelart.15,6,3",   "ui.pixelart.15,7,3",
        "ui.pixelart.15,8,3",   "ui.pixelart.15,9,3",   "ui.pixelart.15,10,3",  "ui.pixelart.15,11,3",
        "ui.pixelart.15,12,3",  "ui.pixelart.15,13,3",  "ui.pixelart.15,14,3",  "ui.pixelart.15,15,3",
        "ui.pixelart.15,0,4",   "ui.pixelart.15,1,4",   "ui.pixelart.15,2,4",   "ui.pixelart.15,3,4",
        "ui.pixelart.15,4,4",   "ui.pixelart.15,5,4",   "ui.pixelart.15,6,4",   "ui.pixelart.15,7,4",
        "ui.pixelart.15,8,4",   "ui.pixelart.15,9,4",   "ui.pixelart.15,10,4",  "ui.pixelart.15,11,4",
        "ui.pixelart.15,12,4",  "ui.pixelart.15,13,4",  "ui.pixelart.15,14,4",  "ui.pixelart.15,15,4",
        "ui.pixelart.15,0,5",   "ui.pixelart.15,1,5",   "ui.pixelart.15,2,5",   "ui.pixelart.15,3,5",
        "ui.pixelart.15,4,5",   "ui.pixelart.15,5,5",   "ui.pixelart.15,6,5",   "ui.pixelart.15,7,5",
        "ui.pixelart.15,8,5",   "ui.pixelart.15,9,5",   "ui.pixelart.15,10,5",  "ui.pixelart.15,11,5",
        "ui.pixelart.15,12,5",  "ui.pixelart.15,13,5",  "ui.pixelart.15,14,5",  "ui.pixelart.15,15,5",
        "ui.pixelart.15,0,6",   "ui.pixelart.15,1,6",   "ui.pixelart.15,2,6",   "ui.pixelart.15,3,6",
        "ui.pixelart.15,4,6",   "ui.pixelart.15,5,6",   "ui.pixelart.15,6,6",   "ui.pixelart.15,7,6",
        "ui.pixelart.15,8,6",   "ui.pixelart.15,9,6",   "ui.pixelart.15,10,6",  "ui.pixelart.15,11,6",
        "ui.pixelart.15,12,6",  "ui.pixelart.15,13,6",  "ui.pixelart.15,14,6",  "ui.pixelart.15,15,6",
        "ui.pixelart.15,0,7",   "ui.pixelart.15,1,7",   "ui.pixelart.15,2,7",   "ui.pixelart.15,3,7",
        "ui.pixelart.15,4,7",   "ui.pixelart.15,5,7",   "ui.pixelart.15,6,7",   "ui.pixelart.15,7,7",
        "ui.pixelart.15,8,7",   "ui.pixelart.15,9,7",   "ui.pixelart.15,10,7",  "ui.pixelart.15,11,7",
        "ui.pixelart.15,12,7",  "ui.pixelart.15,13,7",  "ui.pixelart.15,14,7",  "ui.pixelart.15,15,7",
        "ui.pixelart.15,0,8",   "ui.pixelart.15,1,8",   "ui.pixelart.15,2,8",   "ui.pixelart.15,3,8",
        "ui.pixelart.15,4,8",   "ui.pixelart.15,5,8",   "ui.pixelart.15,6,8",   "ui.pixelart.15,7,8",
        "ui.pixelart.15,8,8",   "ui.pixelart.15,9,8",   "ui.pixelart.15,10,8",  "ui.pixelart.15,11,8",
        "ui.pixelart.15,12,8",  "ui.pixelart.15,13,8",  "ui.pixelart.15,14,8",  "ui.pixelart.15,15,8",
        "ui.pixelart.15,0,9",   "ui.pixelart.15,1,9",   "ui.pixelart.15,2,9",   "ui.pixelart.15,3,9",
        "ui.pixelart.15,4,9",   "ui.pixelart.15,5,9",   "ui.pixelart.15,6,9",   "ui.pixelart.15,7,9",
        "ui.pixelart.15,8,9",   "ui.pixelart.15,9,9",   "ui.pixelart.15,10,9",  "ui.pixelart.15,11,9",
        "ui.pixelart.15,12,9",  "ui.pixelart.15,13,9",  "ui.pixelart.15,14,9",  "ui.pixelart.15,15,9",
        "ui.pixelart.15,0,10",  "ui.pixelart.15,1,10",  "ui.pixelart.15,2,10",  "ui.pixelart.15,3,10",
        "ui.pixelart.15,4,10",  "ui.pixelart.15,5,10",  "ui.pixelart.15,6,10",  "ui.pixelart.15,7,10",
        "ui.pixelart.15,8,10",  "ui.pixelart.15,9,10",  "ui.pixelart.15,10,10", "ui.pixelart.15,11,10",
        "ui.pixelart.15,12,10", "ui.pixelart.15,13,10", "ui.pixelart.15,14,10", "ui.pixelart.15,15,10",
        "ui.pixelart.15,0,11",  "ui.pixelart.15,1,11",  "ui.pixelart.15,2,11",  "ui.pixelart.15,3,11",
        "ui.pixelart.15,4,11",  "ui.pixelart.15,5,11",  "ui.pixelart.15,6,11",  "ui.pixelart.15,7,11",
        "ui.pixelart.15,8,11",  "ui.pixelart.15,9,11",  "ui.pixelart.15,10,11", "ui.pixelart.15,11,11",
        "ui.pixelart.15,12,11", "ui.pixelart.15,13,11", "ui.pixelart.15,14,11", "ui.pixelart.15,15,11",
        "ui.pixelart.15,0,12",  "ui.pixelart.15,1,12",  "ui.pixelart.15,2,12",  "ui.pixelart.15,3,12",
        "ui.pixelart.15,4,12",  "ui.pixelart.15,5,12",  "ui.pixelart.15,6,12",  "ui.pixelart.15,7,12",
        "ui.pixelart.15,8,12",  "ui.pixelart.15,9,12",  "ui.pixelart.15,10,12", "ui.pixelart.15,11,12",
        "ui.pixelart.15,12,12", "ui.pixelart.15,13,12", "ui.pixelart.15,14,12", "ui.pixelart.15,15,12",
        "ui.pixelart.15,0,13",  "ui.pixelart.15,1,13",  "ui.pixelart.15,2,13",  "ui.pixelart.15,3,13",
        "ui.pixelart.15,4,13",  "ui.pixelart.15,5,13",  "ui.pixelart.15,6,13",  "ui.pixelart.15,7,13",
        "ui.pixelart.15,8,13",  "ui.pixelart.15,9,13",  "ui.pixelart.15,10,13", "ui.pixelart.15,11,13",
        "ui.pixelart.15,12,13", "ui.pixelart.15,13,13", "ui.pixelart.15,14,13", "ui.pixelart.15,15,13",
        "ui.pixelart.15,0,14",  "ui.pixelart.15,1,14",  "ui.pixelart.15,2,14",  "ui.pixelart.15,3,14",
        "ui.pixelart.15,4,14",  "ui.pixelart.15,5,14",  "ui.pixelart.15,6,14",  "ui.pixelart.15,7,14",
        "ui.pixelart.15,8,14",  "ui.pixelart.15,9,14",  "ui.pixelart.15,10,14", "ui.pixelart.15,11,14",
        "ui.pixelart.15,12,14", "ui.pixelart.15,13,14", "ui.pixelart.15,14,14", "ui.pixelart.15,15,14",
        "ui.pixelart.15,0,15",  "ui.pixelart.15,1,15",  "ui.pixelart.15,2,15",  "ui.pixelart.15,3,15",
        "ui.pixelart.15,4,15",  "ui.pixelart.15,5,15",  "ui.pixelart.15,6,15",  "ui.pixelart.15,7,15",
        "ui.pixelart.15,8,15",  "ui.pixelart.15,9,15",  "ui.pixelart.15,10,15", "ui.pixelart.15,11,15",
        "ui.pixelart.15,12,15", "ui.pixelart.15,13,15", "ui.pixelart.15,14,15", "ui.pixelart.15,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/pixelart_ui_horiz_scroll2.tga", "ui_pixelart_box15", 8, 8, arr);
  }
}
