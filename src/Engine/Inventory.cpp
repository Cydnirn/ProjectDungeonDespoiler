//
// Created by rei on 12/8/24.
//

#include "Inventory.h"
#include "Items.h"
#include <string>

namespace DespoilerEngine {
  void Inventory::addItem(std::string name, Items item) {
    items.insert({name,item});
  }

  void Inventory::removeItem(std::string name) {
    items.erase(name);
  }
} // namespace DespoilerEngine