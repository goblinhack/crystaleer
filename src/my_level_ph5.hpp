//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once

#include "my_game_defs.hpp"
#include "my_level_data.hpp"
#include "my_level_ph4.hpp"
#include "my_sys.hpp"

class LevelPh5
{
public:
  LevelData data;

  bool ok {};

  LevelPh5(const LevelPh4 &);

  void add_objects(const LevelPh4 &);
};

LevelPh5 level_ph5(const LevelPh4 &);
