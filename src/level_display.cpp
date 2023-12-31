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
#include "my_thing_template.hpp"
#include "my_tile.hpp"

void Level::display_tile(Tpp tp, Tilep tile, point tl, point br, point offset, bool shadow)
{
  tl += offset;
  br += offset;

  if (shadow) {
    const point shadow1(2, 2);
    const point shadow2(4, 4);
    tile_blit(tile, tl + shadow1, br + shadow1);
    tile_blit(tile, tl + shadow2, br + shadow2);
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

void Level::display_z_layer(int z, bool shadow, bool deco)
{
  float      dw          = TILE_WIDTH / game->config.game_pix_zoom;
  float      dh          = TILE_HEIGHT / game->config.game_pix_zoom;
  const auto deco_offset = (dw / 2);

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    for (auto y = miny; y < maxy; y++) {
      for (auto x = minx; x < maxx; x++) {
        point tl;
        point br;

        auto tp_id      = data->tp[ x ][ y ][ z ].tp_id;
        auto tile_index = data->tp[ x ][ y ][ z ].tile;
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

        auto tp = tp_find(tp_id);
        if (! tp) {
          continue;
        }

        if (tp->z_depth != z) {
          continue;
        }

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
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_top, tl, br, point(0, -deco_offset), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_bot, tl, br, point(0, deco_offset), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_left, tl, br, point(-deco_offset, 0), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_right, tl, br, point(deco_offset, 0), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_tl, tl, br, point(-deco_offset, -deco_offset), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_tr, tl, br, point(deco_offset, -deco_offset), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_bl, tl, br, point(-deco_offset, deco_offset), shadow);
          display_tile(tp, data->tp[ x ][ y ][ z ].tile_br, tl, br, point(deco_offset, deco_offset), shadow);
        } else {
          display_tile(tp, tile_index, tl, br, point(0, 0), shadow);
        }
      }
    }
  }
}

void Level::display(void)
{
  TRACE_NO_INDENT();

  minx = 0;
  miny = 0;
  maxx = MAP_WIDTH;
  maxy = MAP_HEIGHT;

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

    const bool no_shadow = false;
    const bool shadow    = true;
    const bool no_deco   = false;
    const bool deco      = true;

    glcolor(BLACK);
    display_z_layer(MAP_DEPTH_ROCK, shadow, no_deco);
    display_z_layer(MAP_DEPTH_ROCK, shadow, deco);
    display_z_layer(MAP_DEPTH_WALL, shadow, no_deco);
    display_z_layer(MAP_DEPTH_WALL, shadow, deco);

    glcolor(WHITE);
    display_z_layer(MAP_DEPTH_ROCK, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_ROCK, no_shadow, deco);

    display_z_layer(MAP_DEPTH_WALL, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_WALL, no_shadow, deco);

    display_z_layer(MAP_DEPTH_OBJ, no_shadow, no_deco);
    display_z_layer(MAP_DEPTH_WALL, no_shadow, deco);
    display_z_layer(MAP_DEPTH_EXIT, no_shadow, no_deco);
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
