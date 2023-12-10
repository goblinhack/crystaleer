//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <array>
#include <string.h>

#include "my_array_bounds_check.hpp"
#include "my_charmap.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph3.hpp"
#include "my_main.hpp"
#include "my_point.hpp"
#include "my_template.hpp"

void LevelPh3::dump(void) { TRACE_NO_INDENT(); }

bool LevelPh3::expand(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  return true;
}

LevelPh3::LevelPh3(const LevelPh2 &ph2)
{
  TRACE_NO_INDENT();

  ok = true;
}

LevelPh3 level_ph3(const LevelPh2 &ph2)
{
  TRACE_AND_INDENT();

  LevelPh3 ph3(ph2);
  return ph3;
}
