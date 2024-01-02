//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_THING_ID_HPP_
#define _MY_THING_ID_HPP_

#include "my_sys.hpp"

#define THING_ID_ENTROPY_BITS 6
#define THING_ID_X_BITS       5
#define THING_ID_Y_BITS       5

//
// A thing ID is composed like:
// [ Entropy bits] [ X bits ] [ Y bits]
//
#define THING_ID_ENTROPY_MASK (((1U << THING_ID_ENTROPY_BITS) - 1) << (THING_ID_X_BITS + THING_ID_Y_BITS))
#define THING_ID_X_MASK       (((1U << THING_ID_X_BITS) - 1) << THING_ID_Y_BITS)
#define THING_ID_Y_MASK       ((1U << THING_ID_Y_BITS) - 1)

#define THING_ID_GET_ENTROPY(id) ((id & THING_ID_ENTROPY_MASK) >> (THING_ID_X_BITS + THING_ID_Y_BITS))
#define THING_ID_GET_X(id)       ((id & THING_ID_X_MASK) >> (THING_ID_Y_BITS))
#define THING_ID_GET_Y(id)       ((id & THING_ID_Y_MASK))

// All levels share the same thing ID namespace so we can find any
// thing on any level just by its number
//
// If this gets too slow, consider using the first byte as level
// number.
//
using ThingId = struct ThingId_ {
public:
  uint16_t id {};
  ThingId_(int16_t id) { DIE("error, ThingID must be uint16"); }
  ThingId_(int32_t id) { DIE("error, ThingID must be uint16"); }
  ThingId_(uint32_t id) { DIE("error, ThingID must be uint16"); }
  ThingId_(uint16_t id) : id(id) {}
  constexpr ThingId_() = default;

  bool operator<(const ThingId_ &rhs) const { return (id < rhs.id); }
  bool operator!() const { return id == 0; }
  bool operator==(const ThingId_ &rhs) const { return (id == rhs.id); }
  bool operator!=(const ThingId_ &rhs) const { return (id != rhs.id); }
  bool ok(void) const { return id != 0; }
};

constexpr auto NoThingId = ThingId_();

#endif
