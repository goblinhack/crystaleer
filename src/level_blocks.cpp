//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_level_ph4.hpp"
#include "my_level_ph4_blk.hpp"
#include "my_ptrcheck.hpp"
#include "my_vector_bounds_check.hpp"

void level_ph4_block_init(void)
{
  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "*R*"
                      "***",
                      // replaced with
                      "RRR"
                      "RRR"
                      "RRR");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "111"
                      "*1*",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "*1*"
                      "*1*"
                      "*1*",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "111"
                      "*.*",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "R11"
                      "***",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "*R*"
                      "*1*"
                      "***",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "*1*"
                      "*R*",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "*11"
                      "***",
                      // replaced with
                      "111"
                      "111"
                      ".11");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "*1*"
                      "*1*"
                      "***",
                      // replaced with
                      "111"
                      "111"
                      ".1.");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "*1*"
                      "*1*",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "*1*"
                      "***",
                      // replaced with
                      "111"
                      "111"
                      "111");

  TRACE_NO_INDENT();
  level_ph4_block_add(BLOCK_TYPE_NORMAL,
                      // look for this pattern
                      "***"
                      "*|*"
                      "***",
                      // replaced with
                      "..."
                      ".|."
                      "|1|");
}
