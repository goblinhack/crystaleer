/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the README file for license info.
 */

#pragma once

#undef ENABLE_THING_NAME_IS_UNIQUE_CHECK
#undef ENABLE_LEAKCHECK           // Memory leak check
#undef ENABLE_PTRCHECK            // Check validity of pointers too
#undef ENABLE_PTRCHECK_HISTORY    // Slower
#undef ENABLE_WID_PTRCHECK        // Check validity of wid pointers too
#undef ENABLE_THING_SANITY        // Check what things carry
#undef ENABLE_MATH_ESTIMATES      // Enable estimated versions of sin/cos/...
#undef ENABLE_ASSERT              // DIE on errors
#undef ENABLE_TREE_SANITY         // Slow tree sanity
#undef ENABLE_DEBUG               // More debugs
#undef ENABLE_DEMARSHAL_DEBUG     // Demarshalling, prints structures
#undef ENABLE_MAP_DEBUG           // Debug AI by printing the map
#undef ENABLE_WID_DEBUG           // Widget debug
#undef ENABLE_CONSOLE
#undef ENABLE_BLACK_AND_WHITE

/*
 * Other windows are darker when popups appear
 */
#undef ENABLE_FADE_OUT_OTHER_WIDGETS_WHEN_FOCUS_LOCKED

/*
 * Retro text. Makes alpha blending look odd tho in overlay.
 */
#define ENABLE_LARGE_TEXT_OUTLINE

/*
 * How much the wheel mouse moves.
 */
#define ENABLE_WHEEL_SCROLL_SPEED_SCALE         1.2
#define ENABLE_WHEEL_MAX_SCROLL_SPEED_SCALE     15

#define ENABLE_JOY_SCROLL_SPEED_SCALE           1.0
#define ENABLE_JOY_MAX_SCROLL_SPEED_SCALE       1.5

/*
 * Tooltip appears above mouse. I prefer it to zoom into the top
 */
#undef ENABLE_TOOLTIP_OVER_MOUSE

/*
 * Tries to batch calls to draw arrays for more speed.
 */
#define ENABLE_GL_BULK_DRAW_ARRAYS

/*
 * Screen sizes.
 */
#define DEFAULT_VIDEO_WIDTH         1008
#define DEFAULT_VIDEO_HEIGHT        672

/*
 * Dungeon size
 */
#define MAP_WIDTH                   12
#define MAP_HEIGHT                  12
#define MAP_DEPTH                   10

/*
 * Console
 */
#define CONSOLE_CURSOR_COLOR        GREEN
#define CONSOLE_CURSOR_OTHER_COLOR  GREEN
#define CONSOLE_TEXT_COLOR          WHITE
#define CURSOR_FLASH
#define CONSOLE_LINES               200

/*
 * Fonts
 */
#undef ENABLE_GENERATE_TTF         // Edit RUNME to add -lSDL_ttf

#define FIXED_FONT                  "data/ttf/monaco.ttf"
#define VSMALL_FONT                 "data/ttf/tekton.ttf"
#define SMALL_FONT                  "data/ttf/tekton.ttf"
#define MED_FONT                    "data/ttf/tekton.ttf"
#define LARGE_FONT                  "data/ttf/tekton.ttf"
#define VLARGE_FONT                 "data/ttf/tekton.ttf"
#define VVLARGE_FONT                "data/ttf/tekton.ttf"

#define FIXED_FONT_SIZE             18
#define VSMALL_FONT_SIZE            16
#define SMALL_FONT_SIZE             20
#define MED_FONT_SIZE               22
#define LARGE_FONT_SIZE             24
#define VLARGE_FONT_SIZE            32
#define VVLARGE_FONT_SIZE           34
#define MAX_FONT_SIZE               60

/*
 * Messages.
 */
#define SMALL_STRING_LEN_MAX        30
#define MED_STRING_LEN_MAX          512

/*
 * Maximum number of thing types. This cannot be exceeded without changing
 * the message format in tx updates.
 */
#define TP_MAX                      10000

void set_game_video_pix_width(int width);
int get_game_video_pix_width(void);
void set_game_video_pix_height(int height);
int get_game_video_pix_height(void);
void set_game_sound_volume(int sound_volume);
int get_game_sound_volume(void);
void set_game_music_volume(int music_volume);
int get_game_music_volume(void);
void set_game_display_sync(int display_sync);
int get_game_display_sync(void);
void set_game_full_screen(int full_screen);
int get_game_full_screen(void);
void set_game_fps_counter(int fps_counter);
int get_game_fps_counter(void);
void set_game_tile_width(int tile_width);
int get_game_tile_width(void);
void set_game_tile_height(int tile_height);
int get_game_tile_height(void);
void save_game_config(void);

#define SOUND_MAX                   20
