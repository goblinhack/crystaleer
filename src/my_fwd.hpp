//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_FWD_HPP_
#define _MY_FWD_HPP_

#include <vector>

class Charmap;
class Font;
class Tex;
class Tile;
class Tp;
class Wid;
class WidPopup;

struct Dmap_;
struct SDL_Surface;

#define NoThingId 0
using ThingId = unsigned int;
using Thingp  = void *;
using Tpp     = void *;
using Dmapp   = struct Dmap_ *;
using Fontp   = class Font *;
using Lightp  = class Light *;
using Texp    = class Tex *;
using Tilemap = std::vector< class Tile * >;
using Widp    = class Wid *;

#endif
