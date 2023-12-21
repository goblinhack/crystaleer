//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_color_defs.hpp"
#include "my_game.hpp"
#include "my_gl.hpp"
#include "my_level.hpp"
#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_ptrcheck.hpp"
#include "my_tile.hpp"

void Level::display(void)
{
  TRACE_NO_INDENT();

  auto minx = 0;
  auto miny = 0;
  auto maxx = MAP_WIDTH;
  auto maxy = MAP_HEIGHT;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glcolor(WHITE);

  {
    int fbo = FBO_MAP_VISIBLE;
    blit_fbo_bind(fbo);
    glClear(GL_COLOR_BUFFER_BIT);
    blit_init();

    const auto dw = game->config.ascii_gl_width / game->config.game_pix_zoom;
    const auto dh = game->config.ascii_gl_height / game->config.game_pix_zoom;

    for (auto z = 0; z < MAP_DEPTH; z++) {
      for (auto y = miny; y < maxy; y++) {
        for (auto x = minx; x < maxx; x++) {
          point tl;
          point br;

          tl.x = x * dw;
          tl.y = y * dh;
          tl.x -= pixel_map_at.x;
          tl.y -= pixel_map_at.y;
          br.x = tl.x + dw;
          br.y = tl.y + dh;

          for (auto layer = 0; layer < LAYER_MAX; layer++) {
            auto tile_index = data->tp[ x ][ y ][ z ].tile[ layer ];
            if (tile_index) {
              auto tile = tile_index_to_tile(tile_index);
              if (tile) {
                tile_blit(tile, tl, br);
              }
            }
          }
        }
      }
    }
    blit_flush();
  }

  {
    blit_fbo_bind(FBO_MAP);
    glClear(GL_COLOR_BUFFER_BIT);

    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    blit_fbo_game_pix(FBO_MAP_HIDDEN);
    glBlendFunc(GL_ONE, GL_ONE);

    blit_fbo_game_pix(FBO_MAP_VISIBLE);
  }

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
