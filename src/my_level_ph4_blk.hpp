//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_LEVEL_PH4_BLOCK_HPP_
#define _MY_LEVEL_PH4_BLOCK_HPP_

#include <array>
#include <string>

#include "my_fwd.hpp"
#include "my_game_defs.hpp"

using LevelPh4Blocks = std::vector< LevelPh4Blockp >;

using BlockType = enum {
  BLOCK_TYPE_NORMAL,
  BLOCK_TYPE_MAX,
};

class LevelPh4Block
{
private:
public:
  static LevelPh4Blocks all_blocks_of_type[ BLOCK_TYPE_MAX ];
  static LevelPh4Blocks all_blocks;

  LevelPh4Block(void);
  ~LevelPh4Block(void);

  //
  // Unique per block.
  //
  uint32_t  blkno {0};
  BlockType type;
  uint8_t   width {LEVEL_PH4_BLOCK_WIDTH};
  uint8_t   height {LEVEL_PH4_BLOCK_HEIGHT};

  std::array< std::array< char, LEVEL_PH4_HEIGHT >, LEVEL_PH4_WIDTH > match_with {};
  std::array< std::array< char, LEVEL_PH4_HEIGHT >, LEVEL_PH4_WIDTH > replace_with {};

  LevelPh4Blockp flip(void);
  void           dump(void);
};

void level_ph4_init(void);
void level_ph4_fini(void);

LevelPh4Blockp block_new(void);

void level_ph4_block_init(void);
void level_ph4_block_add(BlockType, const char *, const char *);

#endif
