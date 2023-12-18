//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_level_ph4_blk.hpp"
#include "my_ptrcheck.hpp"

LevelPh4Blocks LevelPh4Block::all_blocks_of_type[ BLOCK_TYPE_MAX ];
LevelPh4Blocks LevelPh4Block::all_blocks;

void level_ph4_init(void) { TRACE_NO_INDENT(); }

void level_ph4_fini(void)
{
  TRACE_NO_INDENT();
  for (auto &o : LevelPh4Block::all_blocks) {
    delete o;
  }
}

LevelPh4Block::LevelPh4Block(void)
{
  TRACE_NO_INDENT();
  this->unique_id = all_blocks.size();
  newptr(MTYPE_BLOCK, this, "blk");
}

LevelPh4Block::~LevelPh4Block(void)
{
  TRACE_NO_INDENT();
  oldptr(MTYPE_BLOCK, this);
}

LevelPh4Blockp LevelPh4Block::flip(void)
{
  TRACE_NO_INDENT();
  auto f = new LevelPh4Block();

  f->type = type;

  for (auto x = 0; x < LEVEL_PH4_BLOCK_WIDTH; x++) {
    for (auto y = 0; y < LEVEL_PH4_BLOCK_HEIGHT; y++) {
      auto c = get(match_with, x, y);
      set(f->match_with, LEVEL_PH4_BLOCK_WIDTH - x - 1, y, c);

      c = get(replace_with, x, y);
      set(f->replace_with, LEVEL_PH4_BLOCK_WIDTH - x - 1, y, c);
    }
  }

  return f;
}

void LevelPh4Block::dump(void)
{
  TRACE_NO_INDENT();

  LOG("LevelPh4Blockno: %u", unique_id);

  std::array< std::array< char, LEVEL_PH4_BLOCK_WIDTH >, LEVEL_PH4_BLOCK_HEIGHT > out {};

  for (auto ry = 0; ry < LEVEL_PH4_BLOCK_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_PH4_BLOCK_WIDTH; rx++) {
      auto c = get(match_with, rx, ry);
      set(out, rx, ry, c);
    }
  }

  for (auto y = 0; y < LEVEL_PH4_BLOCK_HEIGHT; y++) {
    std::string s;
    for (auto x = 0; x < LEVEL_PH4_BLOCK_WIDTH; x++) {
      auto c = get(out, x, y);
      if (c) {
        s += c;
      } else {
        s += ' ';
      }
    }
    LOG("%s", s.c_str());
  }

  LOG("-");
}

LevelPh4Blockp block_new(void)
{
  TRACE_NO_INDENT();
  auto o = new LevelPh4Block();
  LevelPh4Block::all_blocks.push_back(o);
  return o;
}

void level_ph4_block_add(BlockType type, const char *match_with, const char *replace_with)
{
  TRACE_NO_INDENT();

  const auto row_len      = LEVEL_PH4_BLOCK_WIDTH;
  auto       expected_len = row_len * LEVEL_PH4_BLOCK_HEIGHT;

  if (strlen(match_with) != expected_len) {
    DIE("bad match with block size, expected %d, got %d", (int) strlen(match_with), (int) expected_len);
  }

  if (strlen(replace_with) != expected_len) {
    DIE("bad replace with block size, expected %d, got %d", (int) strlen(replace_with), (int) expected_len);
  }

  //
  // Break the grid of blocks up into individual blocks
  //
  auto o  = block_new();
  o->type = type;

  for (auto ry = 0; ry < LEVEL_PH4_BLOCK_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_PH4_BLOCK_WIDTH; rx++) {
      auto offset = (row_len * ry) + rx;

      //
      // Match with...
      //
      auto c                    = match_with[ offset ];
      o->match_with[ rx ][ ry ] = c;

      //
      // Replace with...
      //
      c = replace_with[ offset ];

      switch (c) {
        case PH2_CHAR_WILDCARD : DIE("replace block should not have a wildcard"); break;
        case PH2_CHAR_SPIKE_33_PERCENT : break;
        case PH2_CHAR_WALL_100_PERCENT : break;
        case PH2_CHAR_WALL_50_PERCENT : break;
        case PH2_CHAR_EMPTY : break;
        case PH2_CHAR_ROCK : break;
        default : DIE("unexpected block char '%c'", c);
      }

      o->replace_with[ rx ][ ry ] = c;
    }
  }

  LevelPh4Block::all_blocks_of_type[ o->type ].push_back(o);
  // o->dump();

  auto f = o->flip();
  LevelPh4Block::all_blocks_of_type[ f->type ].push_back(f);
  // f->dump();
}
