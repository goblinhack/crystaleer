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
  auto thing_id = id.id;
  auto x        = THING_ID_GET_X(thing_id);
  auto y        = THING_ID_GET_Y(thing_id);

  ASSERT_EX(x, <, (1 << THING_ID_X_BITS));
  ASSERT_EX(y, <, (1 << THING_ID_Y_BITS));

  auto t = &data->things[ x ][ y ];
  if (t->id.id == thing_id) {
    return t;
  }
  return nullptr;
}

Thingp Level::thing_find_optional(ThingId id) { return ::thing_find_optional(data, id); }

Thingp thing_find(LevelData *data, ThingId id)
{
  auto thing_id = id.id;
  auto x        = THING_ID_GET_X(thing_id);
  auto y        = THING_ID_GET_Y(thing_id);

  ASSERT_EX(x, <, (1 << THING_ID_X_BITS));
  ASSERT_EX(y, <, (1 << THING_ID_Y_BITS));

  auto t = &data->things[ x ][ y ];
  if (t->id != id) {
    DIE("Thing not found for id, %" PRIX32 "", id.id);
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
      if (t->id.id != NoThingId) {
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
      thing_id.id = (entropy << (THING_ID_X_BITS + THING_ID_Y_BITS)) | (x << THING_ID_Y_BITS) | y;
      t->id       = thing_id;
      t->pix_x    = (int) at_x * TILE_WIDTH;
      t->pix_y    = (int) at_y * TILE_HEIGHT;

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
    DIE("Thing mismatch found for id, %" PRIX32 "", t->id.id);
  }

  memset(t, 0, sizeof(*t));
}

void Level::thing_free(Thingp t) { ::thing_free(data, t); }
