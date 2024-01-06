//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_tile.hpp"
#include "my_ui.hpp"

void gfx_init_16x16(void)
{
  std::initializer_list< std::string > tiles = {
      // clang-format off
      "wall.tl.0",     "wall.top.0",    "wall.top.1",    "wall.top.2",   "wall.top.3",   "wall.top.4",   "wall.top.5", "wall.tr.0",    "", "",
      "wall.left.0",   "wall.0.0",      "wall.1.0",      "wall.2.0",     "wall.3.0",     "wall.4.0",     "wall.5.0",   "wall.right.0", "", "",
      "wall.left.1",   "wall.0.1",      "wall.1.1",      "wall.2.1",     "wall.3.1",     "wall.4.1",     "wall.5.1",   "wall.right.1", "", "",
      "wall.left.2",   "wall.0.2",      "wall.1.2",      "wall.2.2",     "wall.3.2",     "wall.4.2",     "wall.5.2",   "wall.right.2", "", "",
      "wall.left.3",   "wall.0.3",      "wall.1.3",      "wall.2.3",     "wall.3.3",     "wall.4.3",     "wall.5.3",   "wall.right.3", "", "",
      "wall.left.4",   "wall.0.4",      "wall.1.4",      "wall.2.4",     "wall.3.4",     "wall.4.4",     "wall.5.4",   "wall.right.4", "", "",
      "wall.left.5",   "wall.0.5",      "wall.1.5",      "wall.2.5",     "wall.3.5",     "wall.4.5",     "wall.5.5",   "wall.right.5", "", "",
      "wall.bl.0",     "wall.bot.0",    "wall.bot.1",    "wall.bot.2",   "wall.bot.3",   "wall.bot.4",   "wall.bot.5", "wall.br.0",    "", "",
      "rock.tl.0",     "rock.top.0",    "rock.top.1",    "rock.top.2",   "rock.top.3",   "rock.top.4",   "rock.top.5", "rock.tr.0",    "", "",
      "rock.left.0",   "rock.0.0",      "rock.1.0",      "rock.2.0",     "rock.3.0",     "rock.4.0",     "rock.5.0",   "rock.right.0", "", "",
      "rock.left.1",   "rock.0.1",      "rock.1.1",      "rock.2.1",     "rock.3.1",     "rock.4.1",     "rock.5.1",   "rock.right.1", "", "",
      "rock.left.2",   "rock.0.2",      "rock.1.2",      "rock.2.2",     "rock.3.2",     "rock.4.2",     "rock.5.2",   "rock.right.2", "", "",
      "rock.left.3",   "rock.0.3",      "rock.1.3",      "rock.2.3",     "rock.3.3",     "rock.4.3",     "rock.5.3",   "rock.right.3", "", "",
      "rock.left.4",   "rock.0.4",      "rock.1.4",      "rock.2.4",     "rock.3.4",     "rock.4.4",     "rock.5.4",   "rock.right.4", "", "",
      "rock.left.5",   "rock.0.5",      "rock.1.5",      "rock.2.5",     "rock.3.5",     "rock.4.5",     "rock.5.5",   "rock.right.5", "", "",
      "rock.bl.0",     "rock.bot.0",    "rock.bot.1",    "rock.bot.2",   "rock.bot.3",   "rock.bot.4",   "rock.bot.5", "rock.br.0",    "", "",
      "ladder.0",      "block.0",       "rock_gold.0",   "spike.0",      "snake.0",      "snake.1",      "snake.2",    "snake.3",      "", "",
      "ladder.1",      "block.1",       "rock_gold.1",   "spike.1",      "",             "",             "",           "",             "", "",
      "ladder.2",      "block.2",       "rock_gold.2",   "spike.2",      "",             "",             "",           "",             "", "",
      "ladder.3",      "block.3",       "rock_gold.3",   "spike.3",      "",             "",             "",           "",             "", "",
      "ladder.4",      "block.4",       "rock_gold.4",   "spike.4",      "",             "",             "",           "",             "", "",
      "key0",          "",              "",              "",             "",             "",             "",           "",             "", "",
      "crystal0",      "crystal1",      "crystal2",      "crystal3",     "crystal4",     "crystal5",     "crystal6",   "",             "", "",
      "player.idle.0", "player.idle.1", "",              "",             "",             "",             "",           "",             "", "",
      "player.up.0",   "player.up.1",   "",              "",             "",             "",             "",           "",             "", "",
      "player.walk.0", "player.walk.1", "",              "",             "",             "",             "",           "",             "", "",
      "player.run.0",  "player.run.1",  "player.run.2",  "player.run.3", "player.run.4", "player.run.5", "",           "",             "", "",
      // clang-format on
  };
  const std::vector< std::string > arr(tiles);
  tile_load_arr_sprites("data/gfx/tiles_16x16.tga", "tiles_16x16", 16, 16, arr);
}
