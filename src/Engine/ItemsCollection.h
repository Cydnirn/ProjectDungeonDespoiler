//
// Created by rei on 12/11/24.
//

#ifndef PROJECTDUNGEONDESPOILER_ITEMSCOLLECTION_H
#define PROJECTDUNGEONDESPOILER_ITEMSCOLLECTION_H

#include "Items.h"
#include <memory>
#include <unordered_map>

namespace DespoilerEngine {

class ItemsCollection {
public:
  static std::shared_ptr<ItemsCollection> getInstance();
  void addCollection(const Items& item, const std::string& title);
  Items fromJsonFile(const std::string & filepath);
  std::unordered_map<std::string, Items> loadItems(const std::string& directory = ".");
  Items getItem(const std::string& title);
  ItemsCollection(const ItemsCollection&) = delete;
  ItemsCollection& operator=(const ItemsCollection&) = delete;

private:
  std::unordered_map<std::string, Items> items;
  ItemsCollection() = default;
};
} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_ITEMSCOLLECTION_H
