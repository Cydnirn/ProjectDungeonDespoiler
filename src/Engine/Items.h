//
// Created by rei on 12/8/24.
//

#ifndef PROJECTDUNGEONDESPOILER_ITEMS_H
#define PROJECTDUNGEONDESPOILER_ITEMS_H
#pragma once
#include "Stats.h"
#include <string>

namespace DespoilerEngine {

class Items {
public:
  Items(Items const &items) {
    baseRequirements = items.baseRequirements;
    baseDmg = items.baseDmg;
    name = items.name;
  }
  ~Items() = default;
  std::string name;
  [[maybe_unused]] Stats baseRequirements = {0,0,0,0,};
  [[maybe_unused]] int baseDmg;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_ITEMS_H
