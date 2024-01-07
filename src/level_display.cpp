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
#include "my_tex.hpp"
#include "my_thing_template.hpp"
#include "my_tile.hpp"

void Level::display_tile(Tpp tp, Tilep tile, point tl, point br, point offset, bool shadow)
{
  tl += offset;
  br += offset;

  if (shadow) {
    const point shadow1(1, 1);
    const point shadow2(2, 2);
    tile_blit(tile, tl + shadow1, br + shadow1);
    tile_blit(tile, tl + shadow2, br + shadow2);
  } else if (tp->is_blit_outlined) {
    tile_blit_outline(tile, tl, br, WHITE, BLACK, true);
  } else if (tp->is_blit_square_outlined) {
    tile_blit_outline(tile, tl, br, WHITE, BLACK, false);
  } else {
    tile_blit(tile, tl, br);
  }
}

void Level::display_tile(Tpp tp, uint16_t tile_index, point tl, point br, point offset, bool shadow)
{
  auto tile = tile_index_to_tile(tile_index);
  if (! tile) {
    return;
  }

  display_tile(tp, tile, tl, br, offset, shadow);
}

#define BLIT_UP_TILE                                                                                                 \
  tile = tile_index_to_tile(tile_index - offset);                                                                    \
  display_tile(tp, tile, tl, br, point(0, -dh), shadow);

#define BLIT_DOWN_TILE                                                                                               \
  tile = tile_index_to_tile(tile_index + offset);                                                                    \
  display_tile(tp, tile, tl, br, point(0, dh), shadow);

#define BLIT_LEFT_TILE                                                                                               \
  tile = tile_index_to_tile(tile_index - 1);                                                                         \
  display_tile(tp, tile, tl, br, point(-dw, 0), shadow);

#define BLIT_RIGHT_TILE                                                                                              \
  tile = tile_index_to_tile(tile_index + 1);                                                                         \
  display_tile(tp, tile, tl, br, point(dw, 0), shadow);

#define BLIT_TL_TILE                                                                                                 \
  tile = tile_index_to_tile(tile_index - offset - 1);                                                                \
  display_tile(tp, tile, tl, br, point(-dw, -dh), shadow);

#define BLIT_TR_TILE                                                                                                 \
  tile = tile_index_to_tile(tile_index - offset + 1);                                                                \
  display_tile(tp, tile, tl, br, point(dw, -dh), shadow);

#define BLIT_BL_TILE                                                                                                 \
  tile = tile_index_to_tile(tile_index + offset - 1);                                                                \
  display_tile(tp, tile, tl, br, point(-dw, dh), shadow);

#define BLIT_BR_TILE                                                                                                 \
  tile = tile_index_to_tile(tile_index + offset + 1);                                                                \
  display_tile(tp, tile, tl, br, point(dw, dh), shadow);

void Level::display_z_layer(int z, bool shadow, bool deco)
{
  int dw = TILE_WIDTH / game->config.game_pix_zoom;
  int dh = TILE_HEIGHT / game->config.game_pix_zoom;

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    for (auto y = miny; y < maxy; y++) {
      for (auto x = minx; x < maxx; x++) {
        point tl;
        point br;

        Tpp tp;
        thing_get(x, y, slot, &tp);
        if (! tp) {
          continue;
        }

        if (tp->z_depth != z) {
          continue;
        }

        auto obj        = &data->obj[ x ][ y ][ slot ];
        auto tile_index = obj->tile;
        if (! tile_index) {
          continue;
        }

        auto tile = tile_index_to_tile(tile_index);
        if (! tile) {
          return;
        }

        auto pix_height = tile->pix_height / game->config.game_pix_zoom;
        auto pix_width  = tile->pix_width / game->config.game_pix_zoom;

        tl.x = x * dw;
        tl.y = y * dh;
        tl.x -= pixel_map_at.x;
        tl.y -= pixel_map_at.y;

        if (tp->is_blit_on_ground) {
          //
          // On the ground
          //
          tl.y -= (pix_height - dh);
          //
          // Center x
          //
          tl.x -= (pix_width - dw) / 2;
        } else if (tp->is_blit_centered) {
          //
          // Centered
          //
          tl.x -= (pix_width - dw) / 2;
          tl.y -= (pix_height - dh) / 2;
        }

        br.x = tl.x + pix_width;
        br.y = tl.y + pix_height;

        if (deco) {
          auto offset = tex_get_width(tile_get_tex(tile)) / TILE_WIDTH;

          if (obj->deco_up) {
            BLIT_UP_TILE
          }
          if (obj->deco_down) {
            BLIT_DOWN_TILE
          }
          if (obj->deco_left) {
            BLIT_LEFT_TILE
          }
          if (obj->deco_right) {
            BLIT_RIGHT_TILE
          }
          if (obj->deco_tl) {
            BLIT_TL_TILE
          }
          if (obj->deco_bl) {
            BLIT_BL_TILE
          }
          if (obj->deco_tr) {
            BLIT_TR_TILE
          }
          if (obj->deco_br) {
            BLIT_BR_TILE
          }
        } else {
          display_tile(tp, tile_index, tl, br, point(0, 0), shadow);
        }
      }
    }
  }
}

void Level::set_display_bounds(void)
{
  TRACE_NO_INDENT();

  auto border = 2;

  int level_minx = pixel_map_at.x / TILE_WIDTH;
  int level_miny = pixel_map_at.y / TILE_HEIGHT;
  level_minx -= border;
  level_minx -= border;

  if (level_minx < 0) {
    level_minx = 0;
  }
  if (level_miny < 0) {
    level_miny = 0;
  }

  int level_maxx = (pixel_map_at.x + game->config.game_pix_width) / TILE_WIDTH;
  int level_maxy = (pixel_map_at.y + game->config.game_pix_height) / TILE_HEIGHT;

  level_maxx += border;
  level_maxy += border;

  if (level_maxx >= MAP_WIDTH) {
    level_maxx = MAP_WIDTH;
  }
  if (level_maxy >= MAP_HEIGHT) {
    level_maxy = MAP_HEIGHT;
  }

  minx = level_minx;
  miny = level_miny;
  maxx = level_maxx;
  maxy = level_maxy;
}

void Level::display(void)
{
  TRACE_NO_INDENT();

  set_display_bounds();

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glcolor(WHITE);

  {
    int fbo = FBO_MAP_VISIBLE;
    blit_fbo_bind(fbo);
    glClear(GL_COLOR_BUFFER_BIT);
    blit_init();

    {
      Tilep bg1 = tile_find("background1");
      point tl  = point(-pixel_map_at.x, -pixel_map_at.y);
      point br
          = tl + point(bg1->pix_width / game->config.game_pix_zoom, bg1->pix_height / game->config.game_pix_zoom);
      tile_blit(bg1, tl, br);
    }

    const bool no_shadow   = false;
    const bool shadow_only = true;
    const bool no_deco     = false;
    const bool deco        = true;

    glcolor(BLACK);
    display_z_layer(MAP_DEPTH_WALL, shadow_only, no_deco);
    display_z_layer(MAP_DEPTH_WALL, shadow_only, deco);

    display_z_layer(MAP_DEPTH_OBJ1, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_OBJ2, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_OBJ3, no_shadow, no_deco);

    glcolor(WHITE);
    display_z_layer(MAP_DEPTH_WALL, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_WALL, no_shadow, deco);

    display_z_layer(MAP_DEPTH_WALL, no_shadow, deco);

    glcolor(WHITE);
    display_z_layer(MAP_DEPTH_ROCK, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_ROCK, no_shadow, deco);
  }

  glcolor(WHITE);
  blit_flush();

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
