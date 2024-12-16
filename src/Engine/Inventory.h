//
// Created by rei on 12/8/24.
//

#ifndef PROJECTDUNGEONDESPOILER_INVENTORY_H
#define PROJECTDUNGEONDESPOILER_INVENTORY_H
#include <string>
#include "Items.h"
#include <unordered_map>

namespace DespoilerEngine {

class Inventory {
public:
  Inventory() = default;
  ~Inventory() = default;
  void addItem(std::string name, Items item);
  Items *get(std::string name);
  void removeItem(std::string name);
  std::unordered_map<std::string, Items> items;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_INVENTORY_H
