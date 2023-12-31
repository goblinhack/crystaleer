/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the README file for license info for license.
 */

#include <SDL.h>

#include "sdl.h"
#include "slre.h"

#include "main.h"
#include "wid_console.h"
#include "command.h"
#include "ttf.h"
#include "string_ext.h"
#include "config.h"
#include "wid.h"

#define CONSOLE_MAGIC_KEY

static int32_t wid_console_inited;
static int32_t wid_console_exiting;
static void wid_console_wid_create(void);

widp wid_console_container;
widp wid_console_vert_scroll;
#ifdef CONSOLE_HORIZ_SCROLL
widp wid_console_horiz_scroll;
#endif

widp wid_console_input_line;

static tree_root *tree_wid_console;

widp wid_console_window;

typedef struct tree_wid_console_node_ {
    tree_key_int tree;
    char *buf;
} tree_wid_console_node;

void wid_console_fini (void)
{
    tree_wid_console_node *node;

    wid_console_exiting = true;

    if (wid_console_inited) {
        wid_console_inited = false;
    }

    /*
     * Flush the logs now the console exists.
     */
    if (tree_wid_console) {
        TREE_WALK(tree_wid_console, node) {
            myfree(node->buf);
            tree_remove(tree_wid_console, &node->tree.node);
            myfree(node);
        }

        myfree(tree_wid_console);
        tree_wid_console = 0;
    }
}

uint8_t wid_console_init (void)
{
    wid_console_inited = true;

    command_add(debug_enable, "set debug [01]", "enable/disable debug mode");

    command_add(fps_enable, "set fps [01]", "frames per sec counter");

    command_add(sdl_user_exit, "quit", "exit game");

    wid_console_wid_create();

    return (true);
}

/*
 * Scroll back to the bottom of the screen.
 */
static void wid_console_reset_scroll (void)
{
    if (!wid_console_vert_scroll) {
        return;
    }

    wid_move_to_bottom(wid_console_vert_scroll);
}

/*
 * Log a message to the console
 */
static void wid_console_log_ (const char *s)
{
    static int32_t log_wid_console_buffered_lines;
    tree_wid_console_node *node;

    if (wid_console_exiting) {
        return;
    }

    wid_console_reset_scroll();

    /*
     * Before the console is ready, we buffer the logs.
     */
    if (!wid_console_input_line) {
        if (!tree_wid_console) {
            tree_wid_console = tree_alloc(TREE_KEY_INTEGER,
                                          "TREE ROOT: wid_console lines");
        }

        node = (TYPEOF(node)) myzalloc(sizeof(*node),
                                       "TREE NODE: wid_console log");
        node->tree.key = log_wid_console_buffered_lines++;
        node->buf = dupstr(s, "TREE KEY: wid_console log");

        if (!tree_insert(tree_wid_console, &node->tree.node)) {
            ERR("insert log %s fail", s);
        }

        return;
    }

    /*
     * Flush the logs now the console exists.
     */
    if (tree_wid_console) {
        TREE_WALK(tree_wid_console, node) {
            wid_scroll_with_input(wid_console_input_line, node->buf);
            myfree(node->buf);
            tree_remove(tree_wid_console, &node->tree.node);
            myfree(node);
        }

        myfree(tree_wid_console);
        tree_wid_console = 0;
    }

    wid_scroll_with_input(wid_console_input_line, s);
}

/*
 * Log a message to the console
 */
void wid_console_log (const char *s)
{
    tree_string_split_node *n;
    tree_root *d;
    int chars_per_line = 100;

    d = split(s, chars_per_line);

    /*
    * Get some rough sizes for the font.
    */
    { TREE_WALK(d, n) {
        wid_console_log_(n->line);
    } }

    split_free(&d);
}

/*
 * Key down etc...
 */
uint8_t wid_console_receive_input (widp w, const SDL_KEYSYM *key)
{
    wid_console_reset_scroll();

    switch (key->sym) {
        case SDLK_RETURN: {
            break;
        }

        default:
            break;
    }

    /*
     * Feed to the general input handler
     */
    return (wid_receive_input(w, key));
}

/*
 * Create the console
 */
static void wid_console_wid_create (void)
{
    fontp font = fixed_font;

    float lines;

    double w;
    double h;

    ttf_text_size(&font,
                  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                  &w, &h, 0, 0, 1.0f, 1.0f,
                  true /* fixed width */);

    float H = 1.00;
    lines = floor(((float) (game.video_gl_height * H)) / h);

    float line_pct_height = (float)H / (float)lines;

    float console_height = lines * line_pct_height * (1.0 / H);

    {
        fpoint tl = {0.0f, 0.0f};
        fpoint br = {1.0f, console_height};
        color c;

        wid_console_window = wid_new_square_window("wid_console");

        c = BLACK;
        c.a = 100;

        wid_set_mode(wid_console_window, WID_MODE_NORMAL);
        wid_set_color(wid_console_window, WID_COLOR_TL, c);
        wid_set_color(wid_console_window, WID_COLOR_BG, c);
        wid_set_color(wid_console_window, WID_COLOR_BR, c);
        wid_set_font(wid_console_window, font);
        wid_set_name(wid_console_window, "wid_console window");

        wid_set_text_bot(wid_console_window, true);
        wid_set_text_lhs(wid_console_window, true);
        wid_set_pos_pct(wid_console_window, tl, br);
    }

    {
        fpoint tl = {0.0f, 0.0f};
        fpoint br = {1.0f, 1.0f};

        wid_console_container = wid_new_container(wid_console_window,
                                                  "wid console container");

        wid_set_pos_pct(wid_console_container, tl, br);
        wid_set_text_lhs(wid_console_container, true);
        wid_set_text_bot(wid_console_container, true);
    }

    {
        int32_t row;
        float row_bottom = 1.0f;

        widp child = 0;
        widp prev = 0;

        for (row = 0; row < CONSOLE_LINES; row++) {

            fpoint tl = {
                0.0f,
                row_bottom - (line_pct_height * (float)(row+1))
            };

            fpoint br = {
                2.0f,
                row_bottom - (line_pct_height * ((float)row))
            };

            if (row != 0) {
                tl.y -= line_pct_height * 0.1;
                br.y -= line_pct_height * 0.1;
            } else {
                tl.y -= line_pct_height;
            }

            child = wid_new_container(wid_console_container, "");

            wid_set_pos_pct(child, tl, br);
            wid_set_text_lhs(child, true);
            wid_set_text_bot(child, true);
            wid_set_text_fixed_width(child, true);
            wid_set_text_outline(child, false);
            wid_set_font(child, font);

            wid_set_prev(child, prev);
            prev = child;

            if (row == 0) {
                wid_set_on_key_down(child, wid_console_receive_input);

                wid_set_show_cursor(child, true);
                wid_set_name(child, "console input");
#ifdef CONSOLE_MAGIC_KEY
                wid_set_focusable(child, 1);
                wid_move_delta(child, 15, 0);
#endif
                wid_console_input_line = child;

                widp prefix = wid_new_container(wid_console_container, "");
                wid_set_pos_pct(prefix, tl, br);
                wid_set_text_lhs(prefix, true);
                wid_set_text_bot(prefix, true);
                wid_set_text_fixed_width(prefix, true);
                wid_set_text_outline(prefix, false);
                wid_set_font(prefix, font);
#ifdef CONSOLE_MAGIC_KEY
                wid_set_text(prefix, ">");
#endif

            } else {
                wid_set_color(child, WID_COLOR_TEXT, CONSOLE_TEXT_COLOR);
                wid_set_name(child, "console output");
            }
        }

        wid_raise(wid_console_input_line);
    }

    wid_console_vert_scroll =
        wid_new_vert_scroll_bar(wid_console_window, 0, wid_console_container);
#ifdef CONSOLE_HORIZ_SCROLL
    wid_console_horiz_scroll =
        wid_new_horiz_scroll_bar(wid_console_window, 0, wid_console_container);
#endif

    wid_visible(wid_get_parent(wid_console_vert_scroll), 0);
#ifdef CONSOLE_HORIZ_SCROLL
    wid_visible(wid_get_parent(wid_console_horiz_scroll), 0);
#endif
    wid_visible(wid_console_vert_scroll, 0);
#ifdef CONSOLE_HORIZ_SCROLL
    wid_visible(wid_console_horiz_scroll, 0);
#endif

#ifdef CONSOLE_MAGIC_KEY
    wid_hide(wid_console_window, 0);
#endif

    color c = BLACK;
    c.a = 0;
    wid_set_color(wid_console_window, WID_COLOR_BG, c);
    wid_set_color(wid_console_window, WID_COLOR_TL, c);
    wid_set_color(wid_console_window, WID_COLOR_BR, c);
    wid_set_square(wid_console_window);
    wid_console_window->ignore_for_mouse_down = true;

    wid_move_delta_pct(wid_console_window, 0, -0.075);
}
