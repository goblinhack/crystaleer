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
  this->blkno = all_blocks.size();
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
      auto c = get(data, x, y);
      set(f->data, LEVEL_PH4_BLOCK_WIDTH - x - 1, y, c);
    }
  }

  return f;
}

void LevelPh4Block::dump(void)
{
  TRACE_NO_INDENT();

  LOG("LevelPh4Blockno: %u", blkno);

  std::array< std::array< char, LEVEL_PH4_BLOCK_WIDTH >, LEVEL_PH4_BLOCK_HEIGHT > out {};

  for (auto ry = 0; ry < LEVEL_PH4_BLOCK_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_PH4_BLOCK_WIDTH; rx++) {
      auto c = get(data, rx, ry);
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

void level_ph4_block_add(BlockType type, const char *pattern, const char *data)
{
  TRACE_NO_INDENT();

  const auto row_len      = LEVEL_PH4_BLOCK_WIDTH;
  auto       expected_len = row_len * LEVEL_PH4_BLOCK_HEIGHT;

  if (strlen(data) != expected_len) {
    DIE("bad match block size, expected %d, got %d", (int) strlen(data), (int) expected_len);
  }

  if (strlen(data) != expected_len) {
    DIE("bad replace block size, expected %d, got %d", (int) strlen(data), (int) expected_len);
  }

  //
  // Break the grid of blocks up into individual blocks
  //
  auto o  = block_new();
  o->type = type;

  for (auto ry = 0; ry < LEVEL_PH4_BLOCK_HEIGHT; ry++) {
    for (auto rx = 0; rx < LEVEL_PH4_BLOCK_WIDTH; rx++) {
      auto offset = (row_len * ry) + rx;
      auto c      = data[ offset ];

      switch (c) {
        case PH4_CHAR_WILDCARD : DIE("block should not have a wildcard"); break;
        case PH4_CHAR_SPIKE_33_PERCENT : break;
        case PH4_CHAR_WALL_100_PERCENT : break;
        case PH4_CHAR_WALL_50_PERCENT : break;
        case PH4_CHAR_EMPTY : break;
        default : DIE("unexpected block char '%c'", c);
      }

      o->data[ rx ][ ry ] = c;
    }
  }

  LevelPh4Block::all_blocks_of_type[ o->type ].push_back(o);
  // o->dump();

  auto f = o->flip();
  LevelPh4Block::all_blocks_of_type[ f->type ].push_back(f);
  // f->dump();
}