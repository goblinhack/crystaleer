//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_GAME_DEFS_HPP_
#define _MY_GAME_DEFS_HPP_

//
// Grid chunks are used to construct the levels
//
#define ROOMS_DOWN   4 // Levels are split into grids. Each grid can have a room.
#define ROOMS_ACROSS 4 // Rooms across and down
#define ROOMS_DEPTH  2 // Max difficulty level

#define ROOM_HEIGHT 8  // Max room dimensions
#define ROOM_WIDTH  10 // Max room dimensions

#define MAP_HEIGHT (ROOMS_DOWN * ROOM_HEIGHT)
#define MAP_WIDTH  (ROOMS_ACROSS * ROOM_WIDTH)

#define GAME_MOST_ZOOMED_IN   5
#define GAME_MOST_ZOOMED_OUT  1
#define GAME_DEFAULT_UI_ZOOM  1
#define GAME_DEFAULT_PIX_ZOOM GAME_MOST_ZOOMED_IN

#endif
