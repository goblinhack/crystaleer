//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_dice.hpp"
#include "my_game.hpp"
#include "my_random.hpp"
#include "my_thing_template.hpp"
#include "my_vector_bounds_check.hpp"

// begin sort marker1 {
static Tpidmap tp_rock;
static Tpidmap tp_wall;
static Tpidmap tp_spike;
// end sort marker1 }

void tp_random_init(void)
{
  TRACE_NO_INDENT();
  for (auto &tp : tp_id_map) {
    if (tp->is_rock) {
      tp_rock.push_back(tp);
    }
    if (tp->is_wall) {
      tp_wall.push_back(tp);
    }
    if (tp->is_spike) {
      tp_spike.push_back(tp);
    }
  }
}

Tpp tp_get_with_rarity_filter(Tpidmap &m)
{
  TRACE_NO_INDENT();

  if (m.empty()) {
    return nullptr;
  }

  int tries = 1000;
  while (tries--) {
    auto roll   = pcg_random_range(0, 1000);
    int  tries2 = 1000;
    while (tries2--) {
      auto tp = get(m, pcg_rand() % m.size());
      //
      // 0  .. 800 comon
      // 800.. 900 uncomon
      // 900.. 950 rare
      // 950.. 990 very rare
      // 999       unique
      //
      if (roll < 800) {
        if (tp->rarity != THING_RARITY_COMMON) {
          continue;
        }
        DBG("chose THING_RARITY_COMMON -- %s (roll %d)", tp->name.c_str(), roll);
      } else if (roll < 900) {
        if (tp->rarity != THING_RARITY_UNCOMMON) {
          continue;
        }
        DBG("chose THING_RARITY_UNCOMMON -- %s (roll %d)", tp->name.c_str(), roll);
      } else if (roll < 950) {
        if (tp->rarity != THING_RARITY_RARE) {
          continue;
        }
        DBG("chose THING_RARITY_RARE -- %s (roll %d)", tp->name.c_str(), roll);
      } else if (roll < 990) {
        if (tp->rarity != THING_RARITY_VERY_RARE) {
          continue;
        }
        DBG("chose THING_RARITY_VERY_RARE -- %s (roll %d)", tp->name.c_str(), roll);
      } else if (roll == 999) {
        if (tp->rarity != THING_RARITY_UNIQUE) {
          continue;
        }
        DBG("chose THING_RARITY_UNIQUE -- %s (roll %d)", tp->name.c_str(), roll);
      }
      return tp;
    }
  }

  //
  // Well, it can happen... Just choose one
  //
  LOG("Could not find a thing according to rarity");

  return get(m, pcg_rand() % m.size());
}

static Tpp tp_get_with_no_rarity_filter(Tpidmap &m)
{
  TRACE_NO_INDENT();

  int tries = 1000;
  while (tries-- > 0) {
    auto index = pcg_rand() % m.size();
    auto tp    = get(m, index);
    if (! tp) {
      break;
    }

    //
    // If this thing has a limited chance of appearing, roll the dice.
    //
    auto chance = tp->chance_d1000_appearing;
    if (chance) {
      auto roll = d1000();
      if (roll < chance) {
        return tp;
      }
    } else {
      return tp;
    }
  }

  //
  // Give in and return the first we find.
  //
  auto index = pcg_rand() % m.size();
  auto tp    = get(m, index);
  return tp;
}

Tpp tp_random_rock(void)
{
  TRACE_NO_INDENT();
  if (unlikely(! tp_rock.size())) {
    DIE("No rocks found");
    return nullptr;
  }
  return tp_get_with_no_rarity_filter(tp_rock);
}

Tpp tp_random_wall(void)
{
  TRACE_NO_INDENT();
  if (unlikely(! tp_wall.size())) {
    DIE("No walls found");
    return nullptr;
  }
  return tp_get_with_no_rarity_filter(tp_wall);
}
