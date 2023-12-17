//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_level.hpp"
#include "my_level_ph1.hpp"
#include "my_level_ph2.hpp"
#include "my_level_ph3.hpp"
#include "my_level_ph4.hpp"
#include "my_random.hpp"
#include "my_random_name.hpp"

void Game::init(void)
{
  CON("Game init");
  TRACE_AND_INDENT();

  set_seed();

  static bool first_init_done;

  if (! first_init_done) {
    first_init_done = true;
    CON("INI: Init level phases");
    TRACE_NO_INDENT();
    level_ph2_norm_init();
    level_ph2_entrances();
    level_ph2_exit_init();
    level_ph2_secr_init();
    level_ph2_lock_init();
    level_ph2_key_init();
    level_ph3_obstacle_init();
    level_ph4_block_init();
  }
}

void Game::set_seed(void)
{
  if (g_opt_seed_name != "") {
    seed_name = g_opt_seed_name;
  } else {
    seed_name = random_name(sizeof("4294967295") - 1);
  }

  seed = string_to_hash(seed_name);

  CON("Sed seed, name '%s', seed %u", seed_name.c_str(), seed);
  pcg_srand(seed);
}
