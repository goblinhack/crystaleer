//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_thing_template.hpp"
#include "my_thing_templates.hpp"

bool tp_load_rock(void)
{
  TRACE_NO_INDENT();

  auto tp = tp_load("rock");
  if (! tp) {
    ERR("failed to load template rock");
    return false;
  }

  tp->z_depth_set(MAP_DEPTH_WALL);
  tp->is_rock  = true;
  tp->is_tiled = true;

  return true;
}
