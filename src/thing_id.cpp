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

Tpp tp_get(LevelData *data, uint8_t x, uint8_t y, uint8_t slot)
{
  TRACE_NO_INDENT();

  Id id = data->obj[ x ][ y ][ slot ].id;
  if (! id) {
    return nullptr;
  }

  if (id >= THING_ID_BASE) {
    return nullptr;
  }

  return tp_find(id);
}

Tpp Level::tp_get(uint8_t x, uint8_t y, uint8_t slot)
{
  TRACE_NO_INDENT();
  return ::tp_get(data, x, y, slot);
}

Thingp thing_get(LevelData *data, uint8_t x, uint8_t y, uint8_t slot, Tpp *out)
{
  TRACE_NO_INDENT();

  Id id = data->obj[ x ][ y ][ slot ].id;

  if (out) {
    *out = nullptr;
  }

  if (! id) {
    return nullptr;
  }

  if (id >= THING_ID_BASE) {
    auto t = thing_find(data, id);
    if (! t) {
      return nullptr;
    }

    if (out) {
      *out = tp_find(t->tp_id);
    }

    return t;
  }

  if (out) {
    *out = tp_find(id);
  }

  return nullptr;
}

Thingp Level::thing_get(uint8_t x, uint8_t y, uint8_t slot, Tpp *out)
{
  TRACE_NO_INDENT();
  return ::thing_get(data, x, y, slot, out);
}

Thingp thing_find_optional(LevelData *data, ThingId id)
{
  TRACE_NO_INDENT();

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

Thingp Level::thing_find_optional(ThingId id)
{
  TRACE_NO_INDENT();
  return ::thing_find_optional(data, id);
}

Thingp thing_find(LevelData *data, ThingId id)
{
  TRACE_NO_INDENT();

  auto thing_id = id;
  auto x        = THING_ID_GET_X(thing_id);
  auto y        = THING_ID_GET_Y(thing_id);

  ASSERT_EX(x, <, (1 << THING_ID_X_BITS));
  ASSERT_EX(y, <, (1 << THING_ID_Y_BITS));

  auto t = &data->things[ x ][ y ];
  if (! t) {
    DIE("Thing not found for id, %" PRIX32 "", id);
  }

  if (t->id != id) {
    DIE("Thing found but entropy mismatch for id, %" PRIX32 "", id);
  }

  return t;
}

Thingp Level::thing_find(ThingId id)
{
  TRACE_NO_INDENT();
  return ::thing_find_optional(data, id);
}

Thingp thing_new(LevelData *data, Tpp tp, uint8_t at_x, uint8_t at_y)
{
  TRACE_NO_INDENT();

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

Thingp Level::thing_new(Tpp tp, uint8_t x, uint8_t y)
{
  TRACE_NO_INDENT();
  return ::thing_new(data, tp, x, y);
}

void thing_free(LevelData *data, Thingp t)
{
  TRACE_NO_INDENT();

  auto o = ::thing_find(data, t->id);
  if (t != o) {
    DIE("Thing mismatch found for id, %" PRIX32 "", t->id);
  }

  memset(t, 0, sizeof(*t));
}

void Level::thing_free(Thingp t) { ::thing_free(data, t); }

void thing_push(LevelData *data, Thingp t)
{
  TRACE_NO_INDENT();

  uint8_t x = t->pix_x / TILE_WIDTH;
  uint8_t y = t->pix_y / TILE_HEIGHT;

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    auto o = &data->obj[ x ][ y ][ slot ];
    if (o->id == t->id) {
      return;
    }
  }

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    auto o = &data->obj[ x ][ y ][ slot ];
    if (! o->id) {
      o->id     = t->id;
      auto tp   = tp_find(t->tp_id);
      auto tile = tp_first_tile(tp);
      if (tile) {
        o->tile = tile->global_index;
      }
      return;
    }
  }

  ERR("out of thing slots");
}

void Level::thing_push(Thingp t)
{
  TRACE_NO_INDENT();
  return ::thing_push(data, t);
}

void thing_pop(LevelData *data, Thingp t)
{
  TRACE_NO_INDENT();

  uint8_t x = t->pix_x / TILE_WIDTH;
  uint8_t y = t->pix_y / TILE_HEIGHT;

  for (auto slot = 0; slot < MAP_SLOTS; slot++) {
    auto o = &data->obj[ x ][ y ][ slot ];
    if (o->id == t->id) {
      o->id = 0;
      return;
    }
  }
}

void Level::thing_pop(Thingp t)
{
  TRACE_NO_INDENT();
  return ::thing_pop(data, t);
}
