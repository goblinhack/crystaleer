//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once

#include <array>

#include "my_game_defs.hpp"
#include "my_level_ph2.hpp"
#include "my_sys.hpp"

using LevelPh3 = struct LevelPh3_ {
  std::array< std::array< uint8_t, MAP_HEIGHT >, MAP_WIDTH > val {};
};

void level_ph3_obst_init(void);
void level_ph3_obst_add(const char, const char *);

void level_ph3(const LevelPh2 &in, LevelPh3 &out);
