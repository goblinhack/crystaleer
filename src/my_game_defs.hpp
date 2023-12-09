//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_GAME_DEFS_HPP_
#define _MY_GAME_DEFS_HPP_

#define LEVEL_PH1_DOWN       4 // Levels are split into grids. Each grid can have a room.
#define LEVEL_PH1_ACROSS     4 //
#define LEVEL_PH1_LOCK_DEPTH 2 // Max difficulty level

#define LEVEL_PH2_ROOM_HEIGHT 8  // Max room dimensions
#define LEVEL_PH2_ROOM_WIDTH  10 // Max room dimensions

#define LEVEL_PH3_BLOCK_SIZE 3 // LevelPh2Room blocks are composed of X*X character cells

#define LEVEL_PH2_MAP_BORDER 1 // Border around the level

#define LEVEL_PH2_HEIGHT ((LEVEL_PH1_DOWN * LEVEL_PH2_ROOM_HEIGHT) + LEVEL_PH2_MAP_BORDER)
#define LEVEL_PH2_WIDTH  ((LEVEL_PH1_ACROSS * LEVEL_PH2_ROOM_WIDTH) + LEVEL_PH2_MAP_BORDER)

#define MAP_HEIGHT (LEVEL_PH2_HEIGHT * LEVEL_PH3_BLOCK_SIZE)
#define MAP_WIDTH  (LEVEL_PH2_WIDTH * LEVEL_PH3_BLOCK_SIZE)

#define GAME_MOST_ZOOMED_IN   5
#define GAME_MOST_ZOOMED_OUT  1
#define GAME_DEFAULT_UI_ZOOM  1
#define GAME_DEFAULT_PIX_ZOOM GAME_MOST_ZOOMED_IN

#endif
