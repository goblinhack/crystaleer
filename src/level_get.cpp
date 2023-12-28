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

  auto tp_id = data->tp[ x ][ y ][ wall->z_depth ].tp_id;
  if (! tp_id) {
    return false;
  }

  return tp_id == wall->id;
}

bool Level::is_wall(const point p) { return is_wall(p.x, p.y); }

bool Level::is_rock(const uint8_t x, const uint8_t y)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }

  if (! data) {
    return false;
  }

  static const auto rock = tp_find("rock");
  if (! rock) {
    return false;
  }

  auto tp_id = data->tp[ x ][ y ][ rock->z_depth ].tp_id;
  if (! tp_id) {
    return false;
  }

  return tp_id == rock->id;
}

bool Level::is_rock(const point p) { return is_rock(p.x, p.y); }

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

  auto tp_id = data->tp[ x ][ y ][ ladder->z_depth ].tp_id;
  if (! tp_id) {
    return false;
  }

  return tp_id == ladder->id;
}

bool Level::is_ladder(const point p) { return is_ladder(p.x, p.y); }

bool Level::is_block(const uint8_t x, const uint8_t y)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }

  if (! data) {
    return false;
  }

  static const auto block = tp_find("block");
  if (! block) {
    return false;
  }

  auto tp_id = data->tp[ x ][ y ][ block->z_depth ].tp_id;
  if (! tp_id) {
    return false;
  }

  return tp_id == block->id;
}

bool Level::is_block(const point p) { return is_block(p.x, p.y); }
