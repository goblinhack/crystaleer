//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level_data.hpp"
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

  if (! tp_load_spike()) {
    return false;
  }

  if (! tp_load_entrance()) {
    return false;
  }

  if (! tp_load_exit()) {
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

  tp->z_depth_set(MAP_DEPTH_WALL);
  tp->is_wall  = true;
  tp->is_tiled = true;

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

  tp->z_depth_set(MAP_DEPTH_WALL);
  tp->is_rock  = true;
  tp->is_tiled = true;

  return true;
}

bool tp_load_spike(void)
{
  TRACE_NO_INDENT();

  auto tp = tp_load("spike");
  if (! tp) {
    ERR("failed to load template spike");
    return false;
  }

  tp->z_depth_set(MAP_DEPTH_WALL);
  tp->is_spike = true;
  tp->tiles.push_back(tile_find("spike"));

  return true;
}

bool tp_load_entrance(void)
{
  TRACE_NO_INDENT();

  auto tp = tp_load("entrance");
  if (! tp) {
    ERR("failed to load template entrance");
    return false;
  }

  tp->z_depth_set(MAP_DEPTH_OBJ);
  tp->is_entrance = true;
  tp->tiles.push_back(tile_find("entrance"));

  return true;
}

bool tp_load_exit(void)
{
  TRACE_NO_INDENT();

  auto tp = tp_load("exit");
  if (! tp) {
    ERR("failed to load template exit");
    return false;
  }

  tp->z_depth_set(MAP_DEPTH_OBJ);
  tp->is_exit = true;
  tp->tiles.push_back(tile_find("exit.0"));
  tp->tiles.push_back(tile_find("exit.1"));
  tp->tiles.push_back(tile_find("exit.2"));
  tp->tiles.push_back(tile_find("exit.3"));
  tp->tiles.push_back(tile_find("exit.4"));
  tp->tiles.push_back(tile_find("exit.5"));
  tp->tiles.push_back(tile_find("exit.6"));
  tp->tiles.push_back(tile_find("exit.7"));

  return true;
}
