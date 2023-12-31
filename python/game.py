import mm
import level
import thing
import pickle
import os.path
import game
import wid_help
import wid_help_editor
import wid_tp_editor
import wid_quit
import console
from point import Point

global g


class Game:

    class_version = 1

    def __init__(self):

        self.version = self.__class__.class_version

        #
        # Max thing ID in use in any level. This grows forever.
        #
        self.wid_player_location = None
        self.save_file = "save_file"
        self.player = None
        self.editor_mode = False
        self.editor_mode_draw = False
        self.editor_mode_erase = False
        self.editor_mode_yank = False
        self.editor_mode_tp = None

        self.last_level_seed = None
        self.last_selected_tile_x = 0
        self.last_selected_tile_y = 0

    def new_game(self):

        self.seed = 10
        self.where = Point(0, 0, 0)
        self.load_level(self.seed)

    def load_level(self, seed):

        self.game_map_create()
        self.level = level.Level(at=self.where, seed=seed)

    def load_level_finalize(self):
        self.zzz1 = 0.0
        mm.game_set_zzz1(self.zzz1)
        self.zzz2 = 0.0
        mm.game_set_zzz2(self.zzz2)
        self.zzz3 = 0.0
        mm.game_set_zzz3(self.zzz3)
        self.zzz4 = 0.0
        mm.game_set_zzz4(self.zzz4)
        self.zzz5 = 0.0
        mm.game_set_zzz5(self.zzz5)
        self.zzz6 = 0.0
        mm.game_set_zzz6(self.zzz6)
        self.zzz7 = 0.0
        mm.game_set_zzz7(self.zzz7)
        self.zzz8 = 0.0
        mm.game_set_zzz8(self.zzz8)
        self.zzz9 = 0.0
        mm.game_set_zzz9(self.zzz9)
        self.zzz10 = 0.0
        mm.game_set_zzz10(self.zzz10)
        self.zzz11 = 0.0
        mm.game_set_zzz11(self.zzz11)
        self.zzz12 = 0.0
        mm.game_set_zzz12(self.zzz12)
        self.zzz13 = 0.0
        mm.game_set_zzz13(self.zzz13)
        self.zzz14 = 0.0
        mm.game_set_zzz14(self.zzz14)
        self.zzz15 = 0.0
        mm.game_set_zzz15(self.zzz15)
        self.zzz16 = 0.0
        mm.game_set_zzz16(self.zzz16)
        self.zzz17 = 0.0
        mm.game_set_zzz17(self.zzz17)
        self.zzz18 = 0.0
        mm.game_set_zzz18(self.zzz18)
        self.zzz19 = 0.0
        mm.game_set_zzz19(self.zzz19)
        self.zzz20 = 0.0
        mm.game_set_zzz20(self.zzz20)
        self.zzz21 = 0.0
        mm.game_set_zzz21(self.zzz21)
        self.zzz22 = 0.0
        mm.game_set_zzz22(self.zzz22)
        self.zzz23 = 0.0
        mm.game_set_zzz23(self.zzz23)
        self.zzz24 = 0.0
        mm.game_set_zzz24(self.zzz24)
        self.zzz25 = 0.0
        mm.game_set_zzz25(self.zzz25)
        self.zzz26 = 0.0
        mm.game_set_zzz26(self.zzz26)
        self.zzz27 = 0.0
        mm.game_set_zzz27(self.zzz27)
        self.zzz28 = 0.0
        mm.game_set_zzz28(self.zzz28)
        self.zzz29 = 0.0
        mm.game_set_zzz29(self.zzz29)
        self.zzz30 = 0.0
        mm.game_set_zzz30(self.zzz30)
        self.zzz31 = 0.0
        mm.game_set_zzz31(self.zzz31)
        self.zzz32 = 0.0
        mm.game_set_zzz32(self.zzz32)
        self.zzz33 = 0.0
        mm.game_set_zzz33(self.zzz33)
        self.zzz34 = 0.0
        mm.game_set_zzz34(self.zzz34)
        self.zzz35 = 0.0
        mm.game_set_zzz35(self.zzz35)
        self.zzz36 = 0.0
        mm.game_set_zzz36(self.zzz36)
        self.zzz37 = 0.0
        mm.game_set_zzz37(self.zzz37)
        self.zzz38 = 0.0
        mm.game_set_zzz38(self.zzz38)
        self.zzz39 = 0.0
        mm.game_set_zzz39(self.zzz39)
        self.zzz40 = 0.0
        mm.game_set_zzz40(self.zzz40)
        self.zzz41 = 0.0
        mm.game_set_zzz41(self.zzz41)
        self.zzz42 = 0.0
        mm.game_set_zzz42(self.zzz42)
        self.zzz43 = 0.0
        mm.game_set_zzz43(self.zzz43)
        self.zzz44 = 0.0
        mm.game_set_zzz44(self.zzz44)
        self.zzz45 = 0.0
        mm.game_set_zzz45(self.zzz45)
        self.zzz46 = 0.0
        mm.game_set_zzz46(self.zzz46)
        self.zzz47 = 0.0
        mm.game_set_zzz47(self.zzz47)
        self.zzz48 = 0.0
        mm.game_set_zzz48(self.zzz48)
        self.zzz49 = 0.0
        mm.game_set_zzz49(self.zzz49)
        self.zzz50 = 0.0
        mm.game_set_zzz50(self.zzz50)
        self.zzz51 = 0.0
        mm.game_set_zzz51(self.zzz51)
        self.zzz52 = 0.0
        mm.game_set_zzz52(self.zzz52)
        self.zzz53 = 0.0
        mm.game_set_zzz53(self.zzz53)
        self.zzz54 = 0.0
        mm.game_set_zzz54(self.zzz54)
        self.zzz55 = 0.0
        mm.game_set_zzz55(self.zzz55)
        self.zzz56 = 0.0
        mm.game_set_zzz56(self.zzz56)
        self.zzz57 = 0.0
        mm.game_set_zzz57(self.zzz57)
        self.zzz58 = 0.0
        mm.game_set_zzz58(self.zzz58)
        self.zzz59 = 0.0
        mm.game_set_zzz59(self.zzz59)
        self.zzz60 = 0.0
        mm.game_set_zzz60(self.zzz60)
        self.zzz61 = 0.0
        mm.game_set_zzz61(self.zzz61)
        self.zzz62 = 0.0
        mm.game_set_zzz62(self.zzz62)
        self.zzz63 = 0.0
        mm.game_set_zzz63(self.zzz63)
        self.zzz64 = 0.0
        mm.game_set_zzz64(self.zzz64)
        self.zzz65 = 0.0
        mm.game_set_zzz65(self.zzz65)
        self.zzz66 = 0.0
        mm.game_set_zzz66(self.zzz66)
        self.zzz67 = 0.0
        mm.game_set_zzz67(self.zzz67)
        self.zzz68 = 0.0
        mm.game_set_zzz68(self.zzz68)
        self.zzz69 = 0.0
        mm.game_set_zzz69(self.zzz69)
        self.zzz70 = 0.0
        mm.game_set_zzz70(self.zzz70)
        self.zzz71 = 0.0
        mm.game_set_zzz71(self.zzz71)
        self.zzz72 = 0.0
        mm.game_set_zzz72(self.zzz72)
        self.zzz73 = 0.0
        mm.game_set_zzz73(self.zzz73)
        self.zzz74 = 0.0
        mm.game_set_zzz74(self.zzz74)
        self.zzz75 = 0.0
        mm.game_set_zzz75(self.zzz75)
        self.zzz76 = 0.0
        mm.game_set_zzz76(self.zzz76)
        self.zzz77 = 0.0
        mm.game_set_zzz77(self.zzz77)
        self.zzz78 = 0.0
        mm.game_set_zzz78(self.zzz78)
        self.zzz79 = 0.0
        mm.game_set_zzz79(self.zzz79)
        self.zzz80 = 0.0
        mm.game_set_zzz80(self.zzz80)
        self.zzz81 = 0.0
        mm.game_set_zzz81(self.zzz81)

        self.thing_jump_duration = 0.2
        mm.game_set_thing_jump_duration(self.thing_jump_duration)

        self.thing_jump_step = 0.02
        mm.game_set_thing_jump_step(self.thing_jump_step)

        self.thing_jump_speed_max = 0.20
        mm.game_set_thing_jump_speed_max(self.thing_jump_speed_max)

        self.thing_accel_max = 0.2
        mm.game_set_thing_accel_max(self.thing_accel_max)

        self.thing_accel_decay = 0.5
        mm.game_set_thing_accel_decay(self.thing_accel_decay)

        self.thing_accel_step = 0.05
        mm.game_set_thing_accel_step(self.thing_accel_step)

        self.thing_fall_speed = 0.01
        mm.game_set_thing_fall_speed(self.thing_fall_speed)

        self.thing_fall_speed_max = 0.3
        mm.game_set_thing_fall_speed_max(self.thing_fall_speed_max)

        self.thing_velocity_air_decay = 0.8
        mm.game_set_thing_velocity_air_decay(self.thing_velocity_air_decay)

        self.thing_velocity_max = 0.10
        mm.game_set_thing_velocity_max(self.thing_velocity_max)

        self.thing_velocity_decay = 0.70
        mm.game_set_thing_velocity_decay(self.thing_velocity_decay)

    def save(self):
        l = self.level
        s = os.path.normcase(
                os.path.join(os.environ["APPDATA"], self.save_file))

        with open(s, 'wb') as f:
            pickle.dump(self.seed, f, pickle.HIGHEST_PROTOCOL)
            pickle.dump(self.where, f, pickle.HIGHEST_PROTOCOL)

            self.last_level_seed = l.seed
            pickle.dump(self.last_level_seed, f, pickle.HIGHEST_PROTOCOL)

            l.save(f)
            mm.con("Game saved @ level {} to {}".format(str(l), s))

    def upgrade(self):

        if self.version < 2:
            self.v2_field = 2

#        self.debug("upgraded from ver {} to {}".format(
#                   self.version, self.__class__.class_version))

        self.version = self.__class__.class_version

    def load(self):

        s = os.path.normcase(os.path.join(os.environ["APPDATA"],
                                          self.save_file))
        with open(s, 'rb') as f:
            mm.log("Game loading from {}".format(s))

            self.seed = pickle.load(f)
            self.where = pickle.load(f)
            self.last_level_seed = pickle.load(f)

            self.load_level(self.last_level_seed)
            mm.log("Game loaded @ level {} to {}".format(str(self.level), s))
            mm.con("Loaded previously saved game")

        if self.version != self.__class__.class_version:
            self.upgrade()

    def destroy(self):
        l = self.level
        l.destroy()

    def game_map_create(self):
        mm.game_map_create()

    def map_wid_destroy(self):
        mm.game_map_destroy()

    #
    # Mouse is over a map tile; show the route back to the player
    #
    def mouse_over(self, w, x, y, wheelx, wheely, button):
        #
        # Check we can get back from the chosen point to the player.
        #
        self.map_selected_tile(x, y)

        if self.editor_mode:
            if button == 1:
                return self.mouse_down(w, x, y, button)
            return True

    #
    # Mouse is over a map tile; show the route back to the player
    #
    def map_selected_tile(self, x, y):

        self.last_selected_tile_x = x
        self.last_selected_tile_y = y

    #
    # Move the player to the chosen tile
    #
    def mouse_down(self, w, x, y, button):

        l = self.level

        if self.editor_mode:

            if button == 3 or self.editor_mode_erase:
                got_one = False
                if self.editor_mode_tp:
                    t = l.thing_find(x, y, self.editor_mode_tp.name)
                    if t is not None:
                        t.destroy("via editor erase")
                        got_one = True

                if not got_one:
                    t = l.thing_top(x, y)
                    if t is not None and not t.tp.is_player:
                        t.destroy("via editor erase 2")

            elif self.editor_mode_draw and self.editor_mode_tp:
                t = l.thing_find_same_type(x, y,
                                           self.editor_mode_tp.name)
                if t is not None:
                    t.destroy("via editor draw")

                t = thing.Thing(level=l,
                                tp_name=self.editor_mode_tp.name,
                                x=x, y=y)
                t.push()

            return True

        return True

    #
    # Player input
    #
    def key_down(self, w, sym, mod):

        player = self.player

        self.map_help()

        x = self.last_selected_tile_x
        y = self.last_selected_tile_y
        l = self.level

        if sym == mm.SDLK_BACKQUOTE:
            return False

        if self.editor_mode:
            if sym == mm.SDLK_TAB:
                self.editor_mode_draw = True
                self.editor_mode_erase = False
                wid_tp_editor.visible()
                self.map_help()
                return True

            if sym == mm.SDLK_d:
                self.editor_mode_draw = True
                self.editor_mode_erase = False
                self.map_help()
                return True

            if sym == mm.SDLK_x:
                self.editor_mode_draw = False
                self.editor_mode_erase = True
                self.map_help()
                return True

            if sym == mm.SDLK_y:
                t = l.thing_top(x, y)
                if t and not t.tp.is_player:
                    self.editor_mode_tp = t.tp
                    self.editor_mode_draw = True
                    self.editor_mode_erase = False
                self.map_help()
                return True

            if sym == mm.SDLK_ESCAPE:
                wid_tp_editor.hide()
                self.editor_mode = False
                self.editor_mode_draw = True
                self.editor_mode_erase = False
                self.map_help()
                return True

            if mod == mm.KMOD_LCTRL or mod == mm.KMOD_RCTRL:
                if sym == mm.SDLK_z:
                    l.things_remove_all_except_player()
                    return True

            if mod == mm.KMOD_LCTRL or mod == mm.KMOD_RCTRL:
                if sym == mm.SDLK_f:
                    l.things_flood_fill(x, y, self.editor_mode_tp)
                    return True

            if mod == mm.KMOD_LSHIFT or mod == mm.KMOD_RSHIFT:
                if sym == mm.SDLK_EQUALS:
                    t = l.thing_top(x, y)
                    if t:
                        t.set_depth(t.depth + 1)
                    return True

            if sym == mm.SDLK_MINUS:
                t = l.thing_top(x, y)
                if t:
                    t.set_depth(t.depth - 1)
                return True

            if sym == mm.SDLK_SPACE:
                return self.mouse_down(w, x, y, 1)

            if sym == mm.SDLK_DELETE or sym == mm.SDLK_BACKSPACE:
                return self.mouse_down(w, x, y, 3)

            if sym == mm.SDLK_s:
                self.save()
                return True

            if sym == mm.SDLK_q:
                wid_quit.visible()
                return True

            if sym == mm.SDLK_LCTRL:
                return False
            if sym == mm.SDLK_LSHIFT:
                return False
            if sym == mm.SDLK_LALT:
                return False
            if sym == mm.SDLK_LGUI:
                return False
            if sym == mm.SDLK_RCTRL:
                return False
            if sym == mm.SDLK_RSHIFT:
                return False
            if sym == mm.SDLK_RALT:
                return False
            if sym == mm.SDLK_RGUI:
                return False

            wid_help_editor.visible()

            return True
        else:
            if sym == mm.SDLK_s:
                self.save()
                return True

            if sym == mm.SDLK_q:
                wid_quit.visible()
                return True

            delta = self.thing_accel_step
            if sym == mm.SDLK_LEFT:
                player.move_delta(Point(0, -delta, 0))
                return True

            if sym == mm.SDLK_RIGHT:
                player.move_delta(Point(0, delta, 0))
                return True

            if sym == mm.SDLK_DOWN:
                player.move_delta(Point(delta, 0, 0))
                return True

            if sym == mm.SDLK_UP:
                player.move_delta(Point(-delta, 0, 0))
                return True

            if sym == mm.SDLK_SPACE:
                player.move_delta(Point(0, 0, self.thing_jump_step))
                return True

        if mod == mm.KMOD_LCTRL or mod == mm.KMOD_RCTRL:
            if sym == mm.SDLK_e:
                if not self.editor_mode:
                    game.g.editor_mode = True
                    game.g.editor_mode_draw = True
                    game.g.editor_mode_erase = False
                self.map_help()
                return True

        if sym == mm.SDLK_LCTRL:
            return False
        if sym == mm.SDLK_LSHIFT:
            return False
        if sym == mm.SDLK_LALT:
            return False
        if sym == mm.SDLK_LGUI:
            return False
        if sym == mm.SDLK_RCTRL:
            return False
        if sym == mm.SDLK_RSHIFT:
            return False
        if sym == mm.SDLK_RALT:
            return False
        if sym == mm.SDLK_RGUI:
            return False

        wid_help.visible()

        return True

    def tick(self):
        keys = mm.SDLGetKeyState()

        player = self.player

        delta = self.thing_accel_step

        if keys[mm.SDL_SCANCODE_LEFT]:
            player.move_delta(Point(0, -delta, 0))

        if keys[mm.SDL_SCANCODE_RIGHT]:
            player.move_delta(Point(0, delta, 0))

        if keys[mm.SDL_SCANCODE_DOWN]:
            player.move_delta(Point(delta, 0, 0))

        if keys[mm.SDL_SCANCODE_UP]:
            player.move_delta(Point(-delta, 0, 0))

        if keys[mm.SDL_SCANCODE_SPACE]:
            player.move_delta(Point(0, 0, self.thing_jump_step))

    def map_help(self):

        mm.tip("")
        mm.tip2("")

        if self.editor_mode:
            tip = ""

            if self.editor_mode_tp:
                tp_name = self.editor_mode_tp.name
                tip += "%%tp={}$ ".format(tp_name)

            if self.editor_mode_draw:
                tip += "%%fg=green$Draw mode. "
                tip += "%%fg=green$h%%fg=reset$ for help. "
                tip += "%%fg=green$x%%fg=reset$ erase. "

            if self.editor_mode_erase:
                tip += "%%fg=green$Erase mode. "
                tip += "%%fg=green$h%%fg=reset$ for help. "
                tip += "%%fg=green$d%%fg=reset$ draw mode. "

            tip += "%%fg=green$y%%fg=reset$ yank. "
            tip += "%%fg=green$TAB%%fg=reset$ to select. "
            tip += "%%fg=red$ESC%%fg=reset$ to game mode"

            mm.tip2(tip)
        else:
            mm.tip2("Press h for help. Click to move.")

    def push_block(self, tp_name, at):

        l = g.level

        t = thing.Thing(level=l, tp_name=tp_name, at=at)

        if t.collision_check():
            t.destroy(reason="collision")
            return None

        t.push()

        return t


def game_mouse_over(w, relx, rely, wheelx, wheely, button):
    g.mouse_over(w, relx, rely, wheelx, wheely, button)


def game_mouse_down(w, x, y, button):
    return g.mouse_down(w, x, y, button)


def game_key_down(w, sym, mod):
    return g.key_down(w, sym, mod)


def game_tick(w, sym, mod):
    return g.tick()

g = None


def game_new():
    global g

    game_dir = os.path.join(os.environ["APPDATA"], "crystaleer")

    mm.log("Appdata dir is " + game_dir)

    g = Game()
    s = os.path.normcase(os.path.join(os.environ["APPDATA"], g.save_file))
    if os.path.isfile(s):
        g.load()
    else:
        g.new_game()

    g.load_level_finalize()
    console.hello()

    t = g.push_block(tp_name="player1", at=Point(8, 8, 8))
    g.player = t

    g.push_block(tp_name="wall3", at=Point(8, 8, 1))
    g.push_block(tp_name="wall3", at=Point(8, 8, 2))
    g.push_block(tp_name="wall3", at=Point(8, 8, 3))
    g.push_block(tp_name="wall3", at=Point(8, 8, 4))

    g.push_block(tp_name="wall2", at=Point(7, 7, 0))
    g.push_block(tp_name="wall1", at=Point(4, 4, 0))

    g.push_block(tp_name="wall1", at=Point(1, 1, 0))
    g.push_block(tp_name="wall1", at=Point(0, 0, 0))

#    for z in range(4):
#        for x in range(mm.MAP_WIDTH):
#            if x & 2:
#                g.push_block(tp_name="wall1", at=Point(x, 3, z))
#                g.push_block(tp_name="wall2", at=Point(3, x, z))

#    for z in range(1):
#        for x in range(mm.MAP_WIDTH):
#            g.push_block(tp_name="wall2", at=Point(x, 3, 3))
#            g.push_block(tp_name="wall2", at=Point(3, x, 3))

    for x in range(mm.MAP_WIDTH):
        for y in range(mm.MAP_HEIGHT):
            g.push_block(tp_name="wall3", at=Point(x, y, 0))

    for x in range(mm.MAP_WIDTH):
        g.push_block(tp_name="wall2", at=Point(x, mm.MAP_HEIGHT - 1, 1))
    for y in range(mm.MAP_HEIGHT):
        g.push_block(tp_name="wall2", at=Point(mm.MAP_WIDTH - 1, y, 1))

    for z in range(int(mm.MAP_DEPTH)):
        for x in range(mm.MAP_WIDTH):
            g.push_block(tp_name="wall2", at=Point(x, 0, z))

        for y in range(mm.MAP_HEIGHT):
            g.push_block(tp_name="wall2", at=Point(0, y, z))
