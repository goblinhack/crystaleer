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
class Tex;
class Tile;
class Tp;
class Wid;
class WidPopup;

struct Dmap_;
struct SDL_Surface;

#define NoThingId 0
using Dmapp         = struct Dmap_ *;
using Fontp         = class Font *;
using Lightp        = class Light *;
using LevelPh2Roomp = class LevelPh2Room *;
using Texp          = class Tex *;
using ThingId       = unsigned int;
using Thingp        = void *;
using Tilemap       = std::vector< class Tile       *>;
using Tpp           = void *;
using Widp          = class Wid *;

#endif
