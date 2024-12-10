//
// Created by rei on 12/8/24.
//

#ifndef PROJECTDUNGEONDESPOILER_INVENTORY_H
#define PROJECTDUNGEONDESPOILER_INVENTORY_H
#include "vector"
#include <string>
#include "Items.h"

namespace DespoilerEngine {

class Inventory {
public:
  Inventory() = default;
  ~Inventory() = default;
  void addItem(Items item);
  void removeItem(std::string name);
  std::vector<Items> items;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_INVENTORY_H
