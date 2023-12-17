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

  u_int16_t minx = 0;
  u_int16_t miny = 0;
  u_int16_t maxx = MAP_WIDTH;
  u_int16_t maxy = MAP_HEIGHT;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glcolor(WHITE);

  {
    int fbo = FBO_MAP_VISIBLE;
    blit_fbo_bind(fbo);
    glClear(GL_COLOR_BUFFER_BIT);
    blit_init();

    const auto dw = game->config.ascii_gl_width / game->config.game_pix_zoom;
    const auto dh = game->config.ascii_gl_height / game->config.game_pix_zoom;

    auto tile = tile_find("1.3");

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

          auto tpid = data->tpid[ x ][ y ][ z ];
          if (tpid) {
            tile_blit(tile, tl, br);
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
