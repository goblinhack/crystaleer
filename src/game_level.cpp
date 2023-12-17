//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_level.hpp"

void Game::create_level(void)
{
  CON("Game create level");
  TRACE_AND_INDENT();

  if (level) {
    TRACE_NO_INDENT();
    auto l = level;
    if (l) {
      CON("INI: Remove old level");
      delete l;
      level = nullptr;
    }
  }

  {
    TRACE_NO_INDENT();
    CON("INI: Level create");
    level = new Level();
  }
}
