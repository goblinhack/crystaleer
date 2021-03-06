/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the README file for license info for license.
 */

#include "slre.h"
#include "main.h"
#include "sdl.h"
#include "backtrace.h"
#include "wid.h"
#include "time_util.h"
#include "command.h"
#include "term.h"
#include "wid_tooltip.h"
#include "wid_notify.h"
#include "wid.h"
#include "sound.h"
#include "wid_console.h"

uint8_t debug_enabled = 0;
uint8_t croaked;

/*
 * putfg
 */
static void putfg (uint8_t fg, FILE *fp)
{
    static const char *data[] = {
            "\033[1;30m", "\033[1;31m", "\033[1;32m", "\033[1;33m",
            "\033[1;34m", "\033[1;35m", "\033[1;36m", "\033[1;37m",
            "\033[m",
    };

    fputs(data[fg], fp);
}

/*
 * putbg
 */
static void putbg (uint8_t bg, FILE *fp)
{
    static const char *data[] = {
            "\033[1;40m", "\033[1;41m", "\033[1;42m", "\033[1;43m",
            "\033[1;44m", "\033[1;45m", "\033[1;46m", "\033[1;47m",
            "\033[m",
    };

    fputs(data[bg], fp);
}

static int color_to_index (const char **s)
{
    if (!strncmp(*s, "black$", sizeof("black$")-1)) {
	*s += sizeof("black$")-1;
	return (TERM_COLOR_BLACK);
    }
    if (!strncmp(*s, "red$", sizeof("red$")-1)) {
	*s += sizeof("red$")-1;
	return (TERM_COLOR_RED);
    }
    if (!strncmp(*s, "green$", sizeof("green$")-1)) {
	*s += sizeof("green$")-1;
	return (TERM_COLOR_GREEN);
    }
    if (!strncmp(*s, "yellow$", sizeof("yellow$")-1)) {
	*s += sizeof("yellow$")-1;
	return (TERM_COLOR_YELLOW);
    }
    if (!strncmp(*s, "blue$", sizeof("blue$")-1)) {
	*s += sizeof("blue$")-1;
	return (TERM_COLOR_BLUE);
    }
    if (!strncmp(*s, "pink$", sizeof("pink$")-1)) {
	*s += sizeof("pink$")-1;
	return (TERM_COLOR_PINK);
    }
    if (!strncmp(*s, "cyan$", sizeof("cyan$")-1)) {
	*s += sizeof("cyan$")-1;
	return (TERM_COLOR_CYAN);
    }
    if (!strncmp(*s, "white$", sizeof("white$")-1)) {
	*s += sizeof("white$")-1;
	return (TERM_COLOR_WHITE);
    }
    if (!strncmp(*s, "reset$", sizeof("reset$")-1)) {
	*s += sizeof("reset$")-1;
	return (TERM_COLOR_RESET);
    }

    return (TERM_COLOR_WHITE);
}

static void putf (FILE *fp, const char *s)
{
    char c;
    uint8_t looking_for_start = false;

    while ((c = *s++) != '\0') {
	if (!looking_for_start) {
	    if (c == '%') {
		looking_for_start = true;
		continue;
	    }
	} else if (looking_for_start) {
	    if (c == '%') {
		if (!strncmp(s, "fg=", 3)) {
		    s += 3;
		    putfg(color_to_index(&s), fp);
		    looking_for_start = false;
		    continue;
		}

		if (!strncmp(s, "bg=", 3)) {
		    s += 3;
		    putbg(color_to_index(&s), fp);
		    looking_for_start = false;
		    continue;
		}
	    }

	    putc(c, fp);
	}

	looking_for_start = false;

	putc(c, fp);
    }

    putc('\n', fp);
}

static void log_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);
}

void LOG (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    log_(fmt, args);
    va_end(args);
}

static void logs_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];

    buf[0] = '\0';
    vsnprintf(buf, sizeof(buf), fmt, args);

    fwrite(buf, strlen(buf), 1, MY_STDOUT);
    fflush(MY_STDOUT);
}

void LOGS (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    logs_(fmt, args);
    va_end(args);
}

static void warn_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    wid_console_log(buf);
    term_log(buf);
}

void WARN (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    warn_(fmt, args);
    va_end(args);
}

static void con_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    wid_console_log(buf + len);
    term_log(buf + len);
}

static void tip_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];

    buf[0] = '\0';
    vsnprintf(buf, sizeof(buf), fmt, args);

    wid_tooltip_set(buf);
}

static void tip2_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];

    buf[0] = '\0';
    vsnprintf(buf, sizeof(buf), fmt, args);

    wid_tooltip2_set(buf);
}

void CON (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    con_(fmt, args);
    va_end(args);
}


static void dying_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);

    snprintf(buf + len, sizeof(buf) - len, "DYING: ");

    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);
}

static void err_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);

    snprintf(buf + len, sizeof(buf) - len, "ERROR: %%%%fg=red$");

    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "%%%%fg=reset$");

    putf(MY_STDERR, buf);
    fflush(MY_STDERR);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    wid_console_log(buf);
    term_log(buf);

    backtrace_print();
    fflush(MY_STDOUT);
}

static void croak_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;
    uint32_t tslen;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    tslen = len = (uint32_t)strlen(buf);

    snprintf(buf + len, sizeof(buf) - len, "FATAL ERROR: ");

    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    fprintf(stderr, "%s\n", buf);
    fflush(stderr);

    ERR("%s", buf + tslen);

    if (croaked) {
        return;
    }

    croaked = true;

    die();
}

void TIP (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    tip_(fmt, args);
    va_end(args);
}

void TIP2 (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    tip2_(fmt, args);
    va_end(args);
}

void DYING (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    dying_(fmt, args);
    va_end(args);
}

void DBG (const char *fmt, ...)
{
    va_list args;

    if (!debug_enabled) {
        return;
    }

    va_start(args, fmt);
    log_(fmt, args);
    va_end(args);
}

void ERR (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    err_(fmt, args);
    va_end(args);

    wid_visible(wid_console_window, 1);
}

void CROAK (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    croak_(fmt, args);
    va_end(args);

    quit();
}

static void msg_ (uint32_t level,
                  thingp t,
                  double x,
                  double y,
                  const char *fmt, va_list args)
{
    uint32_t len;
    char buf[MAXSTR];

    buf[0] = '\0';

    switch (level) {
    case WARNING:
        if (wid_notify(level, buf)) {
            wid_console_log(buf);
        }
        break;

    case CRITICAL:

        timestamp(buf, sizeof(buf));
        len = (uint32_t)strlen(buf);
        vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

        putf(MY_STDOUT, buf);
        fflush(MY_STDOUT);

        if (wid_notify(level, buf + len)) {
            wid_console_log(buf);
            term_log(buf);
        }
        break;

    case INFO:
        vsnprintf(buf, sizeof(buf), fmt, args);

        if (wid_notify(level, buf)) {
            wid_console_log(buf);
        }
        break;

    case POPUP:
        /*
         * Big popup window
         */
        {
            widp w;

            vsnprintf(buf, sizeof(buf), fmt, args);

            w = wid_tooltip_transient(buf, 3 * ONESEC);
            wid_move_to_pct_centered(w, 0.5, -0.1);
            wid_move_to_pct_centered_in(w, 0.5, 0.1, ONESEC / 2);

            wid_fade_out(w, 3000);
            wid_destroy_in(w, 3000);
        }
        break;

    case SOUND:
        vsnprintf(buf, sizeof(buf), fmt, args);
        sound_play_at(buf, x, y);
        break;

    case SOUND_GLOBAL:
        vsnprintf(buf, sizeof(buf), fmt, args);
        sound_play_global_at(buf, x, y);
        break;
    }
}

static void thing_log_ (thingp t, const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "c-thing %s: ", thing_logname(t));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);
}

void THING_LOG (thingp t, const char *fmt, ...)
{
    va_list args;

    verify(t);

    va_start(args, fmt);
    thing_log_(t, fmt, args);
    va_end(args);
}

static void thing_con_ (thingp t, const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "c-thing %s: ", thing_logname(t));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    wid_console_log(buf);
    term_log(buf);
}

void THING_CON (thingp t, const char *fmt, ...)
{
    va_list args;

    verify(t);

    va_start(args, fmt);
    thing_con_(t, fmt, args);
    va_end(args);
}

static void thing_err_ (thingp t, const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "ERROR: Thing %s: ", thing_logname(t));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    putf(MY_STDERR, buf);
    fflush(MY_STDERR);

    backtrace_print();
    fflush(MY_STDOUT);

    wid_console_log(buf);
    term_log(buf);
}

void THING_ERR (thingp t, const char *fmt, ...)
{
    va_list args;

    verify(t);

    va_start(args, fmt);
    thing_err_(t, fmt, args);
    va_end(args);
}

void THING_DBG (thingp t, const char *fmt, ...)
{
    va_list args;

    verify(t);

    if (!debug_enabled) {
        return;
    }

    va_start(args, fmt);
    thing_log_(t, fmt, args);
    va_end(args);
}

static void level_log_ (levelp l, const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);

    snprintf(buf + len, sizeof(buf) - len, "level (%p): ", l);
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);
}

void LEVEL_LOG (levelp t, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    level_log_(t, fmt, args);
    va_end(args);
}

/*
 * User has entered a command, run it
 */
uint8_t debug_enable (tokens_t *tokens, void *context)
{
    char *s = tokens->args[2];

    if (!s || (*s == '\0')) {
        debug_enabled = 1;
    } else {
        debug_enabled = strtol(s, 0, 10) ? 1 : 0;
    }

    if (!debug_enabled) {
        debug_enabled = 0;
    }

    CON("Debug mode set to %u", debug_enabled);

    return (true);
}

#ifdef ENABLE_WID_DEBUG
static void wid_log_ (widp t, const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "wid   %s: ", wid_logname(t));
    len = (uint32_t)strlen(buf);
    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);
}

void WID_LOG (widp t, const char *fmt, ...)
{
    va_list args;

    verify(t);

    va_start(args, fmt);
    wid_log_(t, fmt, args);
    va_end(args);
}

void WID_DBG (widp t, const char *fmt, ...)
{
    va_list args;

    verify(t);

    if (!debug_enabled) {
        return;
    }

    va_start(args, fmt);
    wid_log_(t, fmt, args);
    va_end(args);
}
#endif

void MESG (uint32_t level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    msg_(level,
         0, // thing
         0, // x
         0, // y
         fmt, args);

    va_end(args);
}

static void msgerr_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
    uint32_t ts_len;
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);

    snprintf(buf + len, sizeof(buf) - len, "ERROR: %%%%fg=red$");

    len = (uint32_t)strlen(buf);
    ts_len = len;

    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "%%%%fg=reset$");

    putf(MY_STDERR, buf);
    fflush(MY_STDERR);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    wid_console_log(buf);
    term_log(buf);

    if (wid_notify(CRITICAL, buf + ts_len)) {
    }

    backtrace_print();
    fflush(MY_STDOUT);
}

void MSG_BOX (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    msgerr_(fmt, args);
    va_end(args);
}

static void sdl_msgerr_ (const char *fmt, va_list args)
{
    char buf[MAXSTR];
#if SDL_MAJOR_VERSION >= 2
    uint32_t ts_len;
#endif
    uint32_t len;

    buf[0] = '\0';
    timestamp(buf, sizeof(buf));
    len = (uint32_t)strlen(buf);

    snprintf(buf + len, sizeof(buf) - len, "ERROR: %%%%fg=red$");

    len = (uint32_t)strlen(buf);
#if SDL_MAJOR_VERSION >= 2
    ts_len = len;
#endif

    vsnprintf(buf + len, sizeof(buf) - len, fmt, args);

#if SDL_MAJOR_VERSION >= 2
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
	"crystaleer", buf + ts_len, 0);
#endif

    len = (uint32_t)strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "%%%%fg=reset$");

    putf(MY_STDERR, buf);
    fflush(MY_STDERR);

    putf(MY_STDOUT, buf);
    fflush(MY_STDOUT);

    backtrace_print();
}

void SDL_MSG_BOX (const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    sdl_msgerr_(fmt, args);
    va_end(args);
}

void MSG_SHOUT_AT (uint32_t level,
                   thingp t,
                   double x,
                   double y,
                   const char *fmt, ...)
{
    va_list args;

    verify(t);

    va_start(args, fmt);
    msg_(level, t, x, y, fmt, args);
    va_end(args);
}

