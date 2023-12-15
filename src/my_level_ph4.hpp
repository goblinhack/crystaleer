//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once

#include <array>

#include "my_game_defs.hpp"
#include "my_level_ph3.hpp"
#include "my_level_ph4_blk.hpp"
#include "my_sys.hpp"

class LevelPh4
{
public:
  std::array< std::array< char, LEVEL_PH4_HEIGHT >, LEVEL_PH4_WIDTH > data {};

  bool ok {};

  LevelPh4(const LevelPh3 &);

  void dump(void);
  bool expand(const LevelPh3 &);
  void add_blocks(const LevelPh3 &);
  void add_block_at(const LevelPh3 &, point at, LevelPh4Blockp);
  void fix_blocks(const LevelPh3 &);
};

void level_ph4_block_init(void);
void level_ph4_block_add(ObstacleType, const char *);

LevelPh4 level_ph4(const LevelPh3 &);
