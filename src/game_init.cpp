//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_random.hpp"
#include "my_random_name.hpp"

void Game::init(void)
{
  CON("Game init");
  TRACE_AND_INDENT();

  set_seed();

  CON("Creating level, name '%s', seed %u", seed_name.c_str(), seed);
}

void Game::set_seed(void)
{
  CON("Game set seed");
  TRACE_AND_INDENT();

  if (g_opt_seed_name != "") {
    seed_name = g_opt_seed_name;
  } else {
    seed_name = random_name(sizeof("4294967295") - 1);
  }
  seed = string_to_hash(seed_name);
  pcg_srand(seed);
}
