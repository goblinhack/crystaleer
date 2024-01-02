//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <iostream>
#include <sstream>
#include <string.h>

#include "my_level.hpp"
#include "my_level_data.hpp"
#include "my_main.hpp"
#include "my_thing.hpp"
#include "my_thing_id.hpp"
#include "my_thing_template.hpp"

Thingp thing_find_optional(LevelData *data, ThingId id)
{
  auto thing_id = id;
  auto x        = THING_ID_GET_X(thing_id);
  auto y        = THING_ID_GET_Y(thing_id);

  ASSERT_EX(x, <, (1 << THING_ID_X_BITS));
  ASSERT_EX(y, <, (1 << THING_ID_Y_BITS));

  auto t = &data->things[ x ][ y ];
  if (t->id == thing_id) {
    return t;
  }
  return nullptr;
}

Thingp Level::thing_find_optional(ThingId id) { return ::thing_find_optional(data, id); }

Thingp thing_find(LevelData *data, ThingId id)
{
  auto thing_id = id;
  auto x        = THING_ID_GET_X(thing_id);
  auto y        = THING_ID_GET_Y(thing_id);

  ASSERT_EX(x, <, (1 << THING_ID_X_BITS));
  ASSERT_EX(y, <, (1 << THING_ID_Y_BITS));

  auto t = &data->things[ x ][ y ];
  if (t->id != id) {
    DIE("Thing not found for id, %" PRIX32 "", id);
  }

  return t;
}

Thingp Level::thing_find(ThingId id) { return ::thing_find_optional(data, id); }

Thingp thing_new(LevelData *data, Tpp tp, uint8_t at_x, uint8_t at_y)
{
  uint16_t x = 0;
  uint16_t y = 0;

  for (x = 0; x < (1 << THING_ID_X_BITS); x++) {
    for (y = 0; y < (1 << THING_ID_Y_BITS); y++) {
      auto t = &data->things[ x ][ y ];
      if (t->id) {
        continue;
      }

      static uint16_t entropy;
      entropy++;
      entropy &= (1 << THING_ID_ENTROPY_BITS) - 1;
      if (! entropy) {
        entropy++;
      }

      memset(t, 0, sizeof(*t));

      ThingId thing_id;
      thing_id = (entropy << (THING_ID_X_BITS + THING_ID_Y_BITS)) | (x << THING_ID_Y_BITS) | y;
      t->id    = thing_id;
      t->pix_x = (int) at_x * TILE_WIDTH;
      t->pix_y = (int) at_y * TILE_HEIGHT;

      if (tp) {
        t->tp_id = tp->id;
      }

      return t;
    }
  }

  DIE("out of things");
}

Thingp Level::thing_new(Tpp tp, uint8_t x, uint8_t y) { return ::thing_new(data, tp, x, y); }

void thing_free(LevelData *data, Thingp t)
{
  auto o = ::thing_find(data, t->id);
  if (t != o) {
    DIE("Thing mismatch found for id, %" PRIX32 "", t->id);
  }

  memset(t, 0, sizeof(*t));
}

void Level::thing_free(Thingp t) { ::thing_free(data, t); }

void thing_push(LevelData *data, Thingp t)
{
  uint8_t x = t->pix_x / TILE_WIDTH;
  uint8_t y = t->pix_y / TILE_HEIGHT;

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    auto o = &data->thing_or_tp[ x ][ y ][ slot ];
    if (o->thing_id == t->id) {
      return;
    }
  }

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    auto o = &data->thing_or_tp[ x ][ y ][ slot ];
    if (! o->thing_id) {
      o->thing_id = t->id;
      return;
    }
  }

  ERR("out of thing slots");
}

void Level::thing_push(Thingp t) { return ::thing_push(data, t); }

void thing_pop(LevelData *data, Thingp t)
{
  uint8_t x = t->pix_x / TILE_WIDTH;
  uint8_t y = t->pix_y / TILE_HEIGHT;

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    auto o = &data->thing_or_tp[ x ][ y ][ slot ];
    if (o->thing_id == t->id) {
      o->thing_id = 0;
      return;
    }
  }
}

void Level::thing_pop(Thingp t) { return ::thing_pop(data, t); }
