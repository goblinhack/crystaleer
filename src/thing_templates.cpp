//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_main.hpp"
#include "my_thing_template.hpp"
#include "my_thing_templates.hpp"

bool templates_init(void)
{
  TRACE_NO_INDENT();

  if (! tp_load_rock()) {
    return false;
  }

  if (! tp_load_wall()) {
    return false;
  }

  return true;
}

bool tp_load_wall(void)
{
  TRACE_NO_INDENT();

  auto tp = tp_load("wall");
  if (! tp) {
    ERR("failed to load template wall");
    return false;
  }

  return true;
}

bool tp_load_rock(void)
{
  TRACE_NO_INDENT();

  auto tp = tp_load("rock");
  if (! tp) {
    ERR("failed to load template rock");
    return false;
  }

  return true;
}
