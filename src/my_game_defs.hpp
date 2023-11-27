//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_GAME_DEFS_HPP_
#define _MY_GAME_DEFS_HPP_

//
// Grid chunks are used to construct the levels and the overall dungeon
//
#define DUNGEON_GRID_CHUNK_HEIGHT_MAX 5 // Levels are split into grids. Each grid can have a room.
#define DUNGEON_GRID_CHUNK_WIDTH_MAX  5 // Rooms across and down
#define DUNGEON_MAX_DEPTH             3 // Max difficulty level

//
// The border needs to be big enough so that the player is not
// obscured by the left bar. This is about this many tiles:
//
#define MAP_BORDER_ROCK 1  // Map rock border
#define MAP_ROOM_HEIGHT 11 // Max room dimensions
#define MAP_ROOM_WIDTH  11 // Max room dimensions

extern int MAP_HEIGHT;
extern int MAP_WIDTH;
extern int DUNGEON_GRID_CHUNK_HEIGHT;
extern int DUNGEON_GRID_CHUNK_WIDTH;

#define MAP_HEIGHT_MAX (DUNGEON_GRID_CHUNK_HEIGHT_MAX * MAP_ROOM_HEIGHT)
#define MAP_WIDTH_MAX  (DUNGEON_GRID_CHUNK_WIDTH_MAX * MAP_ROOM_WIDTH)

#define GAME_MOST_ZOOMED_IN   5
#define GAME_MOST_ZOOMED_OUT  1
#define GAME_DEFAULT_UI_ZOOM  1
#define GAME_DEFAULT_PIX_ZOOM GAME_MOST_ZOOMED_IN

#define LIGHT_MAX_RAYS      180 // Max light rays cast
#define LIGHT_FLICKER_SPEED 10  // Max light rays cast

#endif
