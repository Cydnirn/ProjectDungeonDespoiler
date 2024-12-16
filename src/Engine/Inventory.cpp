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
  Items *Inventory::get(std::string name) {
    auto item = items.find(name);
    if(item != items.end()){
      return &item->second;
    }
    return nullptr;
  }
  } // namespace DespoilerEngine