//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_FWD_HPP_
#define _MY_FWD_HPP_

#include <vector>

class Charmap;
class Font;
class LevelPh2Room;
class LevelPh3Obstacles;
class LevelPh4Block;
class Tex;
class Tile;
class Tp;
class Wid;
class WidPopup;

struct Dmap_;
struct SDL_Surface;

#define NoThingId 0

using Dmapp              = struct Dmap_ *;
using Fontp              = class Font *;
using LevelPh2Roomp      = class LevelPh2Room *;
using LevelPh3Obstaclesp = class LevelPh3Obstacles *;
using LevelPh4Blockp     = class LevelPh4Block *;
using Lightp             = class Light *;
using Texp               = class Tex *;
using ThingId            = unsigned int;
using Thingp             = void *;
using Tilemap            = std::vector< class Tile            *>;
using TpId               = unsigned short;
using Tpp                = class Tp *;
using Widp               = class Wid *;

#endif
