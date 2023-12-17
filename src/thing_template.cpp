//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include <inttypes.h>

#include "my_ptrcheck.hpp"
#include "my_string.hpp"
#include "my_thing_template.hpp"
#include "my_thing_templates.hpp"
#include "my_vector_bounds_check.hpp"

Tpnamemap tp_name_map;
Tpidmap   tp_id_map;

static uint8_t tp_init_done;

Tp::Tp(void) { newptr(MTYPE_TP, this, "Tp"); }

Tp::~Tp(void) { oldptr(MTYPE_TP, this); }

Tpp tp_find(const std::string &name)
{
  TRACE_NO_INDENT();

  auto result = tp_name_map.find(name);

  if (unlikely(result != tp_name_map.end())) {
    return (result->second);
  }

  return nullptr;
}

std::vector< Tpp > tp_find_wildcard(const std::string &name)
{
  TRACE_NO_INDENT();

  std::vector< Tpp > out;
  auto               result = tp_name_map.find(name);

  if (unlikely(result != tp_name_map.end())) {
    out.push_back(result->second);
    return out;
  }

  if (name == "random_wall") {
    out.push_back(tp_random_wall());
    return out;
  }

  if (name == "random_rock") {
    out.push_back(tp_random_rock());
    return out;
  }

  //
  // Try matching patterns e.g. is_monst_class_B
  //
  for (auto &tp : tp_id_map) {
    if (tp->matches(name)) {
      out.push_back(tp);
    }
  }

  return out;
}

Tpp tp_find(uint32_t id)
{
  TRACE_NO_INDENT();
  auto result = get(tp_id_map, id - 1);
  if (! result) {
    ERR("Thing template %" PRIX32 " not found", id);
  }

  return result;
}

uint8_t tp_init(void)
{
  TRACE_NO_INDENT();
  tp_init_done = true;

  templates_init();
  tp_random_init();
  tp_fixup();

  return true;
}

void tp_fini(void)
{
  TRACE_NO_INDENT();
  if (tp_init_done) {
    tp_init_done = false;
  }
  for (auto &tp : tp_name_map) {
    delete tp.second;
  }
}

Tpp tp_load(std::string const &name)
{
  TRACE_NO_INDENT();

  int id;
  tp_get_id(name, &id);

  if (tp_find(name)) {
    DIE("Thing template name [%s] already loaded", name.c_str());
  }

  auto tp = new Tp();
  tp->name_set(name);
  tp->text_short_name_set(name);

  auto result = tp_name_map.insert(std::make_pair(name, tp));
  if (! result.second) {
    ERR("Thing insert name [%s] failed", name.c_str());
  }

  tp_id_map.push_back(tp);
  tp->id = tp_id_map.size();

  return tp;
}

Tilep tp_first_tile(Tpp tp)
{
  TRACE_NO_INDENT();
  if (! tp) {
    return nullptr;
  }

  auto tiles = &tp->tiles;

  if (! tiles || tiles->empty()) {
    ERR("Tp %s has no tiles", tp->name.c_str());
  }

  //
  // Get the first anim tile.
  //
  return (tile_first(tiles));
}
