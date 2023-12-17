//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_color_defs.hpp"
#include "my_gl.hpp"
#include "my_level.hpp"
#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_ptrcheck.hpp"

void Level::display(void)
{
  TRACE_NO_INDENT();

  CON("DISP");
  u_int16_t minx = 0;
  u_int16_t miny = 0;
  u_int16_t maxx = MAP_WIDTH;
  u_int16_t maxy = MAP_HEIGHT;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glcolor(WHITE);

  int fbo = FBO_MAP_VISIBLE;
  blit_fbo_bind(fbo);
  glClear(GL_COLOR_BUFFER_BIT);
  blit_init();

  for (auto z = 0; z <= MAP_DEPTH; z++) {
    for (auto y = miny; y < maxy; y++) {
      for (auto x = minx; x < maxx; x++) {
        // todo
      }
    }
  }
  blit_flush();
}
