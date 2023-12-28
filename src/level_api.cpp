//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph3.hpp"
#include "my_level_ph4.hpp"
#include "my_tile.hpp"

bool Level::is_oob(uint8_t x, uint8_t y)
{
  TRACE_NO_INDENT();
  if (x < 0) {
    return true;
  }
  if (y < 0) {
    return true;
  }
  if (x >= MAP_WIDTH) {
    return true;
  }
  if (y >= MAP_HEIGHT) {
    return true;
  }
  return false;
}

bool Level::set_tp_id(uint8_t x, uint8_t y, uint8_t z, TpId tp_id)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }
  data->tp[ x ][ y ][ z ].tp_id = tp_id;
  return true;
}

void Level::set_tp_id_no_check(uint8_t x, uint8_t y, uint8_t z, TpId tp_id) { data->tp[ x ][ y ][ z ].tp_id = tp_id; }

TpId Level::get_tp_id(uint8_t x, uint8_t y, uint8_t z)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return NoTpId;
  }
  return data->tp[ x ][ y ][ z ].tp_id;
}

TpId Level::get_tp_id_no_check(uint8_t x, uint8_t y, uint8_t z) { return data->tp[ x ][ y ][ z ].tp_id; }

bool Level::set_tp_tile(uint8_t x, uint8_t y, uint8_t z, Tilep tile)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }
  if (tile) {
    data->tp[ x ][ y ][ z ].tile = tile->global_index;
  } else {
    data->tp[ x ][ y ][ z ].tile = 0;
  }
  return true;
}

void Level::set_tp_tile_no_check(uint8_t x, uint8_t y, uint8_t z, Tilep tile)
{
  data->tp[ x ][ y ][ z ].tile = tile->global_index;
}

Tilep Level::get_tp_tile(uint8_t x, uint8_t y, uint8_t z)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return nullptr;
  }
  return tile_index_to_tile(data->tp[ x ][ y ][ z ].tile);
}

Tilep Level::get_tp_tile_no_check(uint8_t x, uint8_t y, uint8_t z)
{
  return tile_index_to_tile(data->tp[ x ][ y ][ z ].tile);
}
