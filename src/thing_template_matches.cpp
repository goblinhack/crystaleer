//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_string.hpp"
#include "my_thing_template.hpp"
#include "slre.hpp"

bool Tp::matches(const std::string &what)
{
  if (strisregexp(what.c_str())) {
    struct slre slre;
    if (slre_compile(&slre, what.c_str())) {
      auto name = text_short_name;
      if (slre_match(&slre, name.c_str(), name.size(), nullptr /* captures */)) {
        return true;
      }
    }
    return false;
  }

  // clang-format off
  // begin sort marker1 {
  if (is_rock && (what == "is_rock")) { return true; }
  if (is_spike && (what == "is_spike")) { return true; }
  if (is_wall && (what == "is_wall")) { return true; }
  if (is_entrance && (what == "is_entrance")) { return true; }
  if (is_exit && (what == "is_exit")) { return true; }
  // end sort marker1 }

  // clang-format on
  return (what == text_short_name);
}
