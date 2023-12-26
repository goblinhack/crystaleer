//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level.hpp"
#include "my_thing_template.hpp"

bool Level::is_wall(const uint8_t x, const uint8_t y)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }

  if (! data) {
    return false;
  }

  static const auto wall = tp_find("wall");
  if (! wall) {
    return false;
  }

  auto tp_id = data->tp[ x ][ y ][ wall->z_depth ].id;
  if (! tp_id) {
    return false;
  }

  return tp_id == wall->id;
}

bool Level::is_wall(const point p) { return is_wall(p.x, p.y); }

bool Level::is_ladder(const uint8_t x, const uint8_t y)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }

  if (! data) {
    return false;
  }

  static const auto ladder = tp_find("ladder");
  if (! ladder) {
    return false;
  }

  auto tp_id = data->tp[ x ][ y ][ ladder->z_depth ].id;
  if (! tp_id) {
    return false;
  }

  return tp_id == ladder->id;
}

bool Level::is_ladder(const point p) { return is_ladder(p.x, p.y); }

bool Level::is_pushblock(const uint8_t x, const uint8_t y)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }

  if (! data) {
    return false;
  }

  static const auto pushblock = tp_find("pushblock");
  if (! pushblock) {
    return false;
  }

  auto tp_id = data->tp[ x ][ y ][ pushblock->z_depth ].id;
  if (! tp_id) {
    return false;
  }

  return tp_id == pushblock->id;
}

bool Level::is_pushblock(const point p) { return is_pushblock(p.x, p.y); }
