//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once

#include <array>

#include "my_game_defs.hpp"
#include "my_level_ph2.hpp"
#include "my_sys.hpp"

class LevelPh3
{
public:
  std::array< std::array< char, LEVEL_PH3_HEIGHT >, LEVEL_PH3_WIDTH > data {};

  bool ok {};

  LevelPh3(const LevelPh2 &);

  void dump(void);
  bool expand(const LevelPh2 &);
};

void level_ph3_obst_init(void);
void level_ph3_obst_add(const char, const char *);

LevelPh3 level_ph3(const LevelPh2 &);
