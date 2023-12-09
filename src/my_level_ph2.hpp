//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once

#include <array>

#include "my_game_defs.hpp"
#include "my_level_ph1.hpp"
#include "my_sys.hpp"

class LevelPh2
{
public:
  std::array< std::array< uint8_t, LEVEL_PH2_HEIGHT >, LEVEL_PH2_WIDTH > val {};

  bool ok {};

  LevelPh2(const LevelPh1 &in);

  void dump(void);
};

void level_ph2_room_set_add(const char *);
void level_ph2_norm_init(void);
void level_ph2_init_init(void);
void level_ph2_exit_init(void);
void level_ph2_secr_init(void);
void level_ph2_lock_init(void);
void level_ph2_key_init(void);

LevelPh2 level_ph2(const LevelPh1 &ph1);
