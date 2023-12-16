//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph3.hpp"
#include "my_level_ph4.hpp"
#include "my_ptrcheck.hpp"

TpId Level::is_oob(uint8_t x, uint8_t y)
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

bool Level::set_tpid(uint8_t x, uint8_t y, uint8_t z, TpId tpid)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return false;
  }
  data->tpid[ x ][ y ][ z ] = tpid;
  return true;
}

TpId Level::get_tpid(uint8_t x, uint8_t y, uint8_t z)
{
  TRACE_NO_INDENT();
  if (is_oob(x, y)) {
    return NoTpId;
  }
  return data->tpid[ x ][ y ][ z ];
}
