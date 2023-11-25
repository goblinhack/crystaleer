//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_game.hpp"
#include "my_sdl_proto.hpp"
#include "my_wid_warning.hpp"

//
// Return true on the event being consumed
//
uint8_t game_mouse_down(int x, int y, uint32_t button)
{
  DBG("Game mouse down");
  TRACE_AND_INDENT();

  if (! game) {
    DBG2("Game mouse down; no game or not started");
    return false;
  }

  if (wid_some_recent_event_occurred()) {
    DBG2("Game mouse down; some recent wid event occurred");
    return false;
  }

  //
  // Waiting on move confirmation
  //
  if (wid_warning_window) {
    return true;
  }

  return false;
}

uint8_t game_mouse_up(int x, int y, uint32_t button) { return false; }

uint8_t game_mouse_motion(int x, int y, int relx, int rely, int wheelx, int wheely)
{
  DBG2("Game mouse motion");
  TRACE_AND_INDENT();

  if (wid_some_recent_event_occurred()) {
    return false;
  }

  //
  // If move confirmation exists, do not remake the cursor or the path will end up
  // under the Yes buttion
  //
  if (wid_warning_window) {
    return false;
  }

  return true;
}
