//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_color_defs.hpp"
#include "my_game.hpp"
#include "my_sdl_event.hpp"
#include "my_sdl_proto.hpp"
#include "my_ui.hpp"
#include "my_wid_notice.hpp"
#include "my_wid_popup.hpp"

static int  last_vert_scroll_offset = -1;
WidPopup   *wid_cfg_keyboard_window;
static bool config_changed;

static void wid_cfg_check_for_conflicts(SDL_Keysym code)
{
  TRACE_AND_INDENT();

  if (sdlk_eq(game->config.key_action0, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action0%%fg=reset$");
    game->config.key_action0 = {};
  }
  if (sdlk_eq(game->config.key_action1, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action1%%fg=reset$");
    game->config.key_action1 = {};
  }
  if (sdlk_eq(game->config.key_action2, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action2%%fg=reset$");
    game->config.key_action2 = {};
  }
  if (sdlk_eq(game->config.key_action3, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action3%%fg=reset$");
    game->config.key_action3 = {};
  }
  if (sdlk_eq(game->config.key_action4, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action4%%fg=reset$");
    game->config.key_action4 = {};
  }
  if (sdlk_eq(game->config.key_action5, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action5%%fg=reset$");
    game->config.key_action5 = {};
  }
  if (sdlk_eq(game->config.key_action6, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action6%%fg=reset$");
    game->config.key_action6 = {};
  }
  if (sdlk_eq(game->config.key_action7, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action7%%fg=reset$");
    game->config.key_action7 = {};
  }
  if (sdlk_eq(game->config.key_action8, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action8%%fg=reset$");
    game->config.key_action8 = {};
  }
  if (sdlk_eq(game->config.key_action9, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key action9%%fg=reset$");
    game->config.key_action9 = {};
  }
  if (sdlk_eq(game->config.key_drop, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key drop.%%fg=reset$");
    game->config.key_drop = {};
  }
  if (sdlk_eq(game->config.key_help, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key help.%%fg=reset$");
    game->config.key_help = {};
  }
  if (sdlk_eq(game->config.key_jump, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key jump.%%fg=reset$");
    game->config.key_jump = {};
  }
  if (sdlk_eq(game->config.key_load, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key load.%%fg=reset$");
    game->config.key_load = {};
  }
  if (sdlk_eq(game->config.key_move_down, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key move down.%%fg=reset$");
    game->config.key_move_down = {};
  }
  if (sdlk_eq(game->config.key_move_left, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key move left.%%fg=reset$");
    game->config.key_move_left = {};
  }
  if (sdlk_eq(game->config.key_move_right, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key move right.%%fg=reset$");
    game->config.key_move_right = {};
  }
  if (sdlk_eq(game->config.key_move_up, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key move up.%%fg=reset$");
    game->config.key_move_up = {};
  }
  if (sdlk_eq(game->config.key_quit, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key quit.%%fg=reset$");
    game->config.key_quit = {};
  }
  if (sdlk_eq(game->config.key_save, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key save.%%fg=reset$");
    game->config.key_save = {};
  }
  if (sdlk_eq(game->config.key_screenshot, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key screenshot.%%fg=reset$");
    game->config.key_screenshot = {};
  }
  if (sdlk_eq(game->config.key_console, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key console%%fg=reset$");
    game->config.key_console = {};
  }
  if (sdlk_eq(game->config.key_unused1, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused1%%fg=reset$");
    game->config.key_unused1 = {};
  }
  if (sdlk_eq(game->config.key_unused2, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused2%%fg=reset$");
    game->config.key_unused2 = {};
  }
  if (sdlk_eq(game->config.key_unused3, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused3%%fg=reset$");
    game->config.key_unused3 = {};
  }
  if (sdlk_eq(game->config.key_unused4, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused4%%fg=reset$");
    game->config.key_unused4 = {};
  }
  if (sdlk_eq(game->config.key_unused5, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused5%%fg=reset$");
    game->config.key_unused5 = {};
  }
  if (sdlk_eq(game->config.key_unused6, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused6%%fg=reset$");
    game->config.key_unused6 = {};
  }
  if (sdlk_eq(game->config.key_unused7, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused7%%fg=reset$");
    game->config.key_unused7 = {};
  }
  if (sdlk_eq(game->config.key_unused8, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused8%%fg=reset$");
    game->config.key_unused8 = {};
  }
  if (sdlk_eq(game->config.key_unused9, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused9%%fg=reset$");
    game->config.key_unused9 = {};
  }
  if (sdlk_eq(game->config.key_unused10, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused10%%fg=reset$");
    game->config.key_unused10 = {};
  }
  if (sdlk_eq(game->config.key_unused11, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused11%%fg=reset$");
    game->config.key_unused11 = {};
  }
  if (sdlk_eq(game->config.key_unused12, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused12%%fg=reset$");
    game->config.key_unused12 = {};
  }
  if (sdlk_eq(game->config.key_unused13, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused13%%fg=reset$");
    game->config.key_unused13 = {};
  }
  if (sdlk_eq(game->config.key_unused14, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused14%%fg=reset$");
    game->config.key_unused14 = {};
  }
  if (sdlk_eq(game->config.key_unused15, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused15%%fg=reset$");
    game->config.key_unused15 = {};
  }
  if (sdlk_eq(game->config.key_unused16, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused16%%fg=reset$");
    game->config.key_unused16 = {};
  }
  if (sdlk_eq(game->config.key_unused17, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused17%%fg=reset$");
    game->config.key_unused17 = {};
  }
  if (sdlk_eq(game->config.key_unused18, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused18%%fg=reset$");
    game->config.key_unused18 = {};
  }
  if (sdlk_eq(game->config.key_unused19, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused19%%fg=reset$");
    game->config.key_unused19 = {};
  }
  if (sdlk_eq(game->config.key_unused20, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key unused20%%fg=reset$");
    game->config.key_unused20 = {};
  }
  if (sdlk_eq(game->config.key_zoom_in, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key zoom in.%%fg=reset$");
    game->config.key_zoom_in = {};
  }
  if (sdlk_eq(game->config.key_zoom_out, code)) {
    CON("%%fg=orange$Conflicting keyboard mapping, disabling key zoom out.%%fg=reset$");
    game->config.key_zoom_out = {};
  }
}

void wid_cfg_keyboard_destroy(void)
{
  TRACE_AND_INDENT();
  config_changed = false;

  if (! wid_cfg_keyboard_window) {
    return;
  }

  auto w                  = wid_cfg_keyboard_window->wid_text_area->wid_vert_scroll;
  last_vert_scroll_offset = wid_get_tl_y(w) - wid_get_tl_y(w->parent);

  delete wid_cfg_keyboard_window;
  wid_cfg_keyboard_window = nullptr;

  game->change_state(Game::STATE_NORMAL, "config close");
}

static uint8_t wid_cfg_keyboard_cancel(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  CON("INF: Reload config");
  if (config_changed) {
    config_changed = false;
    game->load_config();
    sdl_config_update_all();
  }
  wid_cfg_keyboard_destroy();
  if (game->started) {
    //
    // Back to the game
    //
  } else {
    game->wid_cfg_top_menu();
  }
  sdl_config_update_all();
  return true;
}

static uint8_t wid_cfg_keyboard_save(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  CON("INF: Save config");
  game->save_config();
  wid_cfg_keyboard_destroy();
  if (game->started) {
    //
    // Back to the game
    //
  } else {
    game->wid_cfg_top_menu();
  }
  return true;
}

static uint8_t wid_cfg_keyboard_back(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  wid_cfg_keyboard_destroy();
  if (game->started) {
    //
    // Back to the game
    //
  } else {
    game->wid_cfg_top_menu();
  }
  return true;
}

static void wid_cfg_key_move_left_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed             = true;
  game->config.key_move_left = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_move_left = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_move_right_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed              = true;
  game->config.key_move_right = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_move_right = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_move_up_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_move_up = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_move_up = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_move_down_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed             = true;
  game->config.key_move_down = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_move_down = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_attack_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed          = true;
  game->config.key_attack = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_attack = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_jump_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed        = true;
  game->config.key_jump = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_jump = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_drop_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed        = true;
  game->config.key_drop = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_drop = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused1_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused1 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused1 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused2_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused2 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused2 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused3_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused3 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused3 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused4_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused4 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused4 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused5_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused5 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused5 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused6_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused6 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused6 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused7_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused7 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused7 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused8_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused8 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused8 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused9_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_unused9 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused9 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused10_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused10 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused10 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused11_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused11 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused11 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused12_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused12 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused12 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused13_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused13 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused13 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused14_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused14 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused14 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused15_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused15 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused15 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused16_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused16 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused16 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused17_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused17 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused17 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused18_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused18 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused18 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused19_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused19 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused19 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_unused20_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_unused20 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_unused20 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action0_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action0 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action0 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action1_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action1 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action1 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action2_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action2 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action2 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action3_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action3 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action3 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action4_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action4 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action4 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action5_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action5 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action5 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action6_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action6 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action6 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action7_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action7 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action7 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action8_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_action8 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action8 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_action9_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  game->config.key_action9 = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_action9 = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_save_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed        = true;
  game->config.key_save = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_save = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_load_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed        = true;
  game->config.key_load = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_load = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_zoom_in_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_zoom_in = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_zoom_in = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_zoom_out_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed            = true;
  game->config.key_zoom_out = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_zoom_out = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_help_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed        = true;
  game->config.key_help = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_help = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_console_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed           = true;
  game->config.key_console = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_console = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_quit_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed        = true;
  game->config.key_quit = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_quit = code;
  game->wid_cfg_keyboard_select();
}

static void wid_cfg_key_screenshot_set(SDL_Keysym code)
{
  TRACE_AND_INDENT();
  config_changed              = true;
  game->config.key_screenshot = {};
  wid_cfg_check_for_conflicts(code);
  game->config.key_screenshot = code;
  game->wid_cfg_keyboard_select();
}

static void grab_key(const std::string which)
{
  TRACE_AND_INDENT();
  wid_notice("Press a key for " + which);
  g_grab_next_key = true;
  config_changed  = true;
}

static uint8_t wid_cfg_keyboard_profile_arrow_keys(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  SDL_Keysym k {};

  config_changed           = true;
  game->config.key_move_up = {};
  k.sym                    = SDLK_UP;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_up = k;

  game->config.key_move_left = {};
  k.sym                      = SDLK_LEFT;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_left = k;

  game->config.key_move_down = {};
  k.sym                      = SDLK_DOWN;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_down = k;

  game->config.key_move_right = {};
  k.sym                       = SDLK_RIGHT;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_right = k;

  game->wid_cfg_keyboard_select();

  return true;
}

static uint8_t wid_cfg_keyboard_profile_wasd(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  SDL_Keysym k {};

  config_changed           = true;
  game->config.key_move_up = {};
  k.sym                    = SDLK_w;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_up = k;

  game->config.key_move_left = {};
  k.sym                      = SDLK_a;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_left = k;

  game->config.key_move_down = {};
  k.sym                      = SDLK_s;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_down = k;

  game->config.key_move_right = {};
  k.sym                       = SDLK_d;
  wid_cfg_check_for_conflicts(k);
  game->config.key_move_right = k;

  game->wid_cfg_keyboard_select();

  return true;
}

static uint8_t wid_cfg_key_move_left(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("move left");
  sdl.on_sdl_key_grab = wid_cfg_key_move_left_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_move_right(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("move right");
  sdl.on_sdl_key_grab = wid_cfg_key_move_right_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_move_up(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("move up");
  sdl.on_sdl_key_grab = wid_cfg_key_move_up_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_move_down(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("move down");
  sdl.on_sdl_key_grab = wid_cfg_key_move_down_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_attack(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("attack");
  sdl.on_sdl_key_grab = wid_cfg_key_attack_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_jump(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("jump");
  sdl.on_sdl_key_grab = wid_cfg_key_jump_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_drop(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item drop");
  sdl.on_sdl_key_grab = wid_cfg_key_drop_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused1(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused1");
  sdl.on_sdl_key_grab = wid_cfg_key_unused1_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused2(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused2");
  sdl.on_sdl_key_grab = wid_cfg_key_unused2_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused3(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused3");
  sdl.on_sdl_key_grab = wid_cfg_key_unused3_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused4(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused4");
  sdl.on_sdl_key_grab = wid_cfg_key_unused4_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused5(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused5");
  sdl.on_sdl_key_grab = wid_cfg_key_unused5_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused6(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused6");
  sdl.on_sdl_key_grab = wid_cfg_key_unused6_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused7(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused7");
  sdl.on_sdl_key_grab = wid_cfg_key_unused7_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused8(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused8");
  sdl.on_sdl_key_grab = wid_cfg_key_unused8_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused9(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused9");
  sdl.on_sdl_key_grab = wid_cfg_key_unused9_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused10(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused10");
  sdl.on_sdl_key_grab = wid_cfg_key_unused10_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused11(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused11");
  sdl.on_sdl_key_grab = wid_cfg_key_unused11_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused12(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused12");
  sdl.on_sdl_key_grab = wid_cfg_key_unused12_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused13(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused13");
  sdl.on_sdl_key_grab = wid_cfg_key_unused13_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused14(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused14");
  sdl.on_sdl_key_grab = wid_cfg_key_unused14_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused15(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused15");
  sdl.on_sdl_key_grab = wid_cfg_key_unused15_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused16(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused16");
  sdl.on_sdl_key_grab = wid_cfg_key_unused16_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused17(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused17");
  sdl.on_sdl_key_grab = wid_cfg_key_unused17_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused18(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused18");
  sdl.on_sdl_key_grab = wid_cfg_key_unused18_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused19(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused19");
  sdl.on_sdl_key_grab = wid_cfg_key_unused19_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_unused20(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("item unused20");
  sdl.on_sdl_key_grab = wid_cfg_key_unused20_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action0(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 0");
  sdl.on_sdl_key_grab = wid_cfg_key_action0_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action1(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 1");
  sdl.on_sdl_key_grab = wid_cfg_key_action1_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action2(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 2");
  sdl.on_sdl_key_grab = wid_cfg_key_action2_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action3(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 3");
  sdl.on_sdl_key_grab = wid_cfg_key_action3_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action4(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 4");
  sdl.on_sdl_key_grab = wid_cfg_key_action4_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action5(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 5");
  sdl.on_sdl_key_grab = wid_cfg_key_action5_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action6(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 6");
  sdl.on_sdl_key_grab = wid_cfg_key_action6_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action7(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 7");
  sdl.on_sdl_key_grab = wid_cfg_key_action7_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action8(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 8");
  sdl.on_sdl_key_grab = wid_cfg_key_action8_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_action9(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("action 9");
  sdl.on_sdl_key_grab = wid_cfg_key_action9_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_save(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("save game");
  sdl.on_sdl_key_grab = wid_cfg_key_save_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_load(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("load game");
  sdl.on_sdl_key_grab = wid_cfg_key_load_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_zoom_in(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("zoom in");
  sdl.on_sdl_key_grab = wid_cfg_key_zoom_in_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_zoom_out(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("zoom out");
  sdl.on_sdl_key_grab = wid_cfg_key_zoom_out_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_help(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("help");
  sdl.on_sdl_key_grab = wid_cfg_key_help_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_console(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("toggle console");
  sdl.on_sdl_key_grab = wid_cfg_key_console_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_quit(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("quit");
  sdl.on_sdl_key_grab = wid_cfg_key_quit_set;
  config_changed      = true;
  return true;
}

static uint8_t wid_cfg_key_screenshot(Widp w, int x, int y, uint32_t button)
{
  TRACE_AND_INDENT();
  grab_key("screenshot grab");
  config_changed      = true;
  sdl.on_sdl_key_grab = wid_cfg_key_screenshot_set;
  return true;
}

static uint8_t wid_cfg_keyboard_key_up(Widp w, const struct SDL_Keysym *key)
{
  TRACE_AND_INDENT();

  if (sdlk_eq(*key, game->config.key_console)) {
    return false;
  }

  switch (key->mod) {
    case KMOD_LCTRL :
    case KMOD_RCTRL :
    default :
      switch (key->sym) {
        default :
          {
            TRACE_AND_INDENT();
            auto c = wid_event_to_char(key);
            switch (c) {
              case 'b' :
              case SDLK_ESCAPE : wid_cfg_keyboard_cancel(nullptr, 0, 0, 0); return true;
            }
          }
      }
  }

  return false;
}

static uint8_t wid_cfg_keyboard_key_down(Widp w, const struct SDL_Keysym *key)
{
  TRACE_AND_INDENT();

  if (sdlk_eq(*key, game->config.key_console)) {
    return false;
  }

  return true;
}

void Game::wid_cfg_keyboard_select(void)
{
  TRACE_AND_INDENT();
  wid_notice_destroy();

  if (wid_cfg_keyboard_window) {
    wid_cfg_keyboard_destroy();
  }

  auto box_style           = UI_WID_STYLE_HORIZ_DARK;
  auto box_highlight_style = UI_WID_STYLE_HORIZ_LIGHT;
  auto m                   = TERM_WIDTH / 2;

  point tl    = make_point(m - TERM_WIDTH / 2, 2);
  point br    = make_point(m + TERM_WIDTH / 2 - 1, TERM_HEIGHT - 2);
  auto  width = br.x - tl.x;

  wid_cfg_keyboard_window = new WidPopup("Keyboard select", tl, br, nullptr, "", false, true);
  {
    TRACE_AND_INDENT();
    Widp w = wid_cfg_keyboard_window->wid_popup_container;
    wid_set_on_key_up(w, wid_cfg_keyboard_key_up);
    wid_set_on_key_down(w, wid_cfg_keyboard_key_down);
  }

  auto rhs_button_left  = 5;
  auto rhs_button_right = 20;

  int y_at = 0;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Keyboard");

    point tl = make_point(0, y_at);
    point br = make_point(width - 1, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text(w, "Keyboard");
  }

  y_at = 2;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Back");

    point tl = make_point(1, y_at);
    point br = make_point(8, y_at + 2);
    wid_set_shape_square(w);
    wid_set_style(w, UI_WID_STYLE_NORMAL);
    wid_set_on_mouse_up(w, wid_cfg_keyboard_back);
    wid_set_pos(w, tl, br);
    wid_set_text(w, "Back");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Save");

    point tl = make_point(width - 18, y_at);
    point br = make_point(width - 13, y_at + 2);
    wid_set_style(w, UI_WID_STYLE_GREEN);
    wid_set_on_mouse_up(w, wid_cfg_keyboard_save);
    wid_set_pos(w, tl, br);
    wid_set_text(w, "Save");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Cancel");

    point tl = make_point(width - 11, y_at);
    point br = make_point(width - 4, y_at + 2);
    wid_set_style(w, UI_WID_STYLE_RED);
    wid_set_on_mouse_up(w, wid_cfg_keyboard_cancel);
    wid_set_pos(w, tl, br);
    wid_set_text(w, "Cancel");
  }

  ///////////////////////////////////////////////////////////////////////
  y_at++;
  ///////////////////////////////////////////////////////////////////////

  y_at += 3;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "");

    point tl = make_point(1, y_at);
    point br = make_point(width - 4, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_on_mouse_up(w, wid_cfg_keyboard_profile_wasd);
    wid_set_pos(w, tl, br);
    wid_set_text(w, "Use W,A,S,D for moving");
  }
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "");

    point tl = make_point(1, y_at);
    point br = make_point(width - 4, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_on_mouse_up(w, wid_cfg_keyboard_profile_arrow_keys);
    wid_set_pos(w, tl, br);
    wid_set_text(w, "Use arrow keys for moving");
  }

  y_at++;
  ///////////////////////////////////////////////////////////////////////
  // save
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "save");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Save game");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_save));
    wid_set_on_mouse_up(w, wid_cfg_key_save);
  }
  ///////////////////////////////////////////////////////////////////////
  // load
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "load");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Load game");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_load));
    wid_set_on_mouse_up(w, wid_cfg_key_load);
  }

  ///////////////////////////////////////////////////////////////////////
  // Move up
  ///////////////////////////////////////////////////////////////////////
  y_at += 2;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Move up");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_text(w, "Move up");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_color(w, WID_COLOR_BG, WHITE);
    wid_set_color(w, WID_COLOR_TEXT_FG, WHITE);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_move_up));
    wid_set_on_mouse_up(w, wid_cfg_key_move_up);
  }
  ///////////////////////////////////////////////////////////////////////
  // Move left
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Move left");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Move left");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_move_left));
    wid_set_on_mouse_up(w, wid_cfg_key_move_left);
  }
  ///////////////////////////////////////////////////////////////////////
  // Move down
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Move down");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Move down");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_move_down));
    wid_set_on_mouse_up(w, wid_cfg_key_move_down);
  }
  ///////////////////////////////////////////////////////////////////////
  // Move right
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Move right");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Move right");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_move_right));
    wid_set_on_mouse_up(w, wid_cfg_key_move_right);
  }

  ///////////////////////////////////////////////////////////////////////
  y_at++;
  ///////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////
  // attack
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Attack");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Attack");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_attack));
    wid_set_on_mouse_up(w, wid_cfg_key_attack);
  }
  ///////////////////////////////////////////////////////////////////////
  // jump
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "jump");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Jump");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_jump));
    wid_set_on_mouse_up(w, wid_cfg_key_jump);
  }
  ///////////////////////////////////////////////////////////////////////
  // drop
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Drop");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Drop");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_drop));
    wid_set_on_mouse_up(w, wid_cfg_key_drop);
  }
  ///////////////////////////////////////////////////////////////////////
  // action0
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 0");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 0");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action0));
    wid_set_on_mouse_up(w, wid_cfg_key_action0);
  }
  ///////////////////////////////////////////////////////////////////////
  // action1
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 1");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 1");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action1));
    wid_set_on_mouse_up(w, wid_cfg_key_action1);
  }
  ///////////////////////////////////////////////////////////////////////
  // action2
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 2");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 2");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action2));
    wid_set_on_mouse_up(w, wid_cfg_key_action2);
  }
  ///////////////////////////////////////////////////////////////////////
  // action3
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 3");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 3");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action3));
    wid_set_on_mouse_up(w, wid_cfg_key_action3);
  }
  ///////////////////////////////////////////////////////////////////////
  // action4
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 4");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 4");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action4));
    wid_set_on_mouse_up(w, wid_cfg_key_action4);
  }
  ///////////////////////////////////////////////////////////////////////
  // action5
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 5");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 5");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action5));
    wid_set_on_mouse_up(w, wid_cfg_key_action5);
  }
  ///////////////////////////////////////////////////////////////////////
  // action6
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 6");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 6");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, to_string(game->config.key_action6));
    wid_set_on_mouse_up(w, wid_cfg_key_action6);
  }
  ///////////////////////////////////////////////////////////////////////
  // action7
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 7");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 7");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action7));
    wid_set_on_mouse_up(w, wid_cfg_key_action7);
  }
  ///////////////////////////////////////////////////////////////////////
  // action8
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 8");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 8");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action8));
    wid_set_on_mouse_up(w, wid_cfg_key_action8);
  }
  ///////////////////////////////////////////////////////////////////////
  // action9
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Inventory action 9");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Inventory action 9");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_action9));
    wid_set_on_mouse_up(w, wid_cfg_key_action9);
  }

  ///////////////////////////////////////////////////////////////////////
  y_at++;
  ///////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////
  // zoom_in
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "zoom_in");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Zoom in");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_zoom_in));
    wid_set_on_mouse_up(w, wid_cfg_key_zoom_in);
  }
  ///////////////////////////////////////////////////////////////////////
  // zoom_out
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "zoom_out");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Zoom out");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_zoom_out));
    wid_set_on_mouse_up(w, wid_cfg_key_zoom_out);
  }

  ///////////////////////////////////////////////////////////////////////
  y_at++;
  ///////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////
  // screenshot
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "Take a screenshot");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Take a screenshot");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_screenshot));
    wid_set_on_mouse_up(w, wid_cfg_key_screenshot);
  }

  ///////////////////////////////////////////////////////////////////////
  y_at++;
  ///////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////
  // quit
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "quit");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Quit");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_quit));
    wid_set_on_mouse_up(w, wid_cfg_key_quit);
  }
  ///////////////////////////////////////////////////////////////////////
  // console
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "console");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Debug console (+shift)");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "console");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_console));
    wid_set_on_mouse_up(w, wid_cfg_key_console);
  }
  ///////////////////////////////////////////////////////////////////////
  // help
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "help");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "This useless help");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_help));
    wid_set_on_mouse_up(w, wid_cfg_key_help);
  }

  y_at++;
  ///////////////////////////////////////////////////////////////////////
  // unused1
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused1");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused1");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused1));
    wid_set_on_mouse_up(w, wid_cfg_key_unused1);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused2
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused2");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused2");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused2));
    wid_set_on_mouse_up(w, wid_cfg_key_unused2);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused3
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused3");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused3");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused3));
    wid_set_on_mouse_up(w, wid_cfg_key_unused3);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused4
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused4");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused4");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused4));
    wid_set_on_mouse_up(w, wid_cfg_key_unused4);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused5
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused5");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused5");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused5));
    wid_set_on_mouse_up(w, wid_cfg_key_unused5);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused6
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused6");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused6");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused6));
    wid_set_on_mouse_up(w, wid_cfg_key_unused6);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused7
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused7");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused7");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused7));
    wid_set_on_mouse_up(w, wid_cfg_key_unused7);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused8
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused8");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused8");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused8));
    wid_set_on_mouse_up(w, wid_cfg_key_unused8);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused9
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused9");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused9");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused9));
    wid_set_on_mouse_up(w, wid_cfg_key_unused9);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused10
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused10");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused10");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused10));
    wid_set_on_mouse_up(w, wid_cfg_key_unused10);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused11
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused11");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused11");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused11));
    wid_set_on_mouse_up(w, wid_cfg_key_unused11);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused12
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused12");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused12");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused12));
    wid_set_on_mouse_up(w, wid_cfg_key_unused12);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused13
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused13");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused13");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused13));
    wid_set_on_mouse_up(w, wid_cfg_key_unused13);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused14
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused14");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused14");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused14));
    wid_set_on_mouse_up(w, wid_cfg_key_unused14);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused15
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused15");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused15");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused15));
    wid_set_on_mouse_up(w, wid_cfg_key_unused15);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused16
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused16");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused16");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused16));
    wid_set_on_mouse_up(w, wid_cfg_key_unused16);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused17
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused17");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused17");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused17));
    wid_set_on_mouse_up(w, wid_cfg_key_unused17);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused18
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused18");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused18");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused18));
    wid_set_on_mouse_up(w, wid_cfg_key_unused18);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused19
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused19");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused19");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused19));
    wid_set_on_mouse_up(w, wid_cfg_key_unused19);
  }

  ///////////////////////////////////////////////////////////////////////
  // unused20
  ///////////////////////////////////////////////////////////////////////
  y_at++;
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "unused20");

    point tl = make_point(1, y_at);
    point br = make_point(width / 2, y_at);
    wid_set_shape_none(w);
    wid_set_pos(w, tl, br);
    wid_set_text_lhs(w, true);
    wid_set_text(w, "Unused20");
  }
  {
    TRACE_AND_INDENT();
    auto p = wid_cfg_keyboard_window->wid_text_area->wid_text_area;
    auto w = wid_new_square_button(p, "value");

    point tl = make_point(width / 2 + rhs_button_left, y_at);
    point br = make_point(width / 2 + rhs_button_right, y_at);
    wid_set_mode(w, WID_MODE_OVER);
    wid_set_style(w, box_highlight_style);
    wid_set_mode(w, WID_MODE_NORMAL);
    wid_set_style(w, box_style);
    wid_set_pos(w, tl, br);
    wid_set_text(w, ::to_string(game->config.key_unused20));
    wid_set_on_mouse_up(w, wid_cfg_key_unused20);
  }

  wid_update(wid_cfg_keyboard_window->wid_text_area->wid_text_area);

  if (last_vert_scroll_offset != -1) {
    auto w = wid_cfg_keyboard_window->wid_text_area->wid_vert_scroll;
    wid_move_to_y_off(w, last_vert_scroll_offset);
  }

  game->change_state(Game::STATE_KEYBOARD_MENU, "configure keys");
}
