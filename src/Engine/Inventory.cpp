//
// Created by rei on 12/8/24.
//

#include "Inventory.h"
#include <string>
#include <algorithm>

namespace DespoilerEngine {
  void Inventory::addItem(Items item) {
    items.push_back(item);
  }

  void Inventory::removeItem(std::string name) {
    for(int i = 0; i < items.size(); i++) {
      if(items[i].name == name) {
        items.erase(items.begin() + i);
        break;
      }
    }
  }
} // namespace DespoilerEngine