//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_thing_template.hpp"
#include "my_thing_templates.hpp"

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

  for (auto x = 0; x < 6; x++) {
    for (auto y = 0; y < 6; y++) {
      auto tile = tile_find_mand("wall." + std::to_string(x) + "." + std::to_string(y));
      tp->tiles.push_back(tile);
    }
  }

  for (auto x = 0; x < 6; x++) {
    auto tile = tile_find_mand("wall.top." + std::to_string(x));
    tp->tiles_top.push_back(tile);
  }

  for (auto x = 0; x < 6; x++) {
    auto tile = tile_find_mand("wall.bot." + std::to_string(x));
    tp->tiles_bot.push_back(tile);
  }

  for (auto y = 0; y < 6; y++) {
    auto tile = tile_find_mand("wall.left." + std::to_string(y));
    tp->tiles_left.push_back(tile);
  }

  for (auto y = 0; y < 6; y++) {
    auto tile = tile_find_mand("wall.right." + std::to_string(y));
    tp->tiles_right.push_back(tile);
  }

  for (auto i = 0; i < 1; i++) {
    auto tile = tile_find_mand("wall.tl." + std::to_string(i));
    tp->tiles_tl.push_back(tile);
    tile = tile_find_mand("wall.tr." + std::to_string(i));
    tp->tiles_tr.push_back(tile);
    tile = tile_find_mand("wall.bl." + std::to_string(i));
    tp->tiles_bl.push_back(tile);
    tile = tile_find_mand("wall.br." + std::to_string(i));
    tp->tiles_br.push_back(tile);
  }

  return true;
}
