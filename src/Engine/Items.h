//
// Created by rei on 12/8/24.
//

#ifndef PROJECTDUNGEONDESPOILER_ITEMS_H
#define PROJECTDUNGEONDESPOILER_ITEMS_H
#pragma once
#include "Stats.h"
#include <string>
#include <stdexcept>

namespace DespoilerEngine {

enum ItemType {
  Weapon,
  Armor,
  Consumable,
  Quest,
  Junk
};

inline std::string itemTypeToString(ItemType type) {
  switch (type) {
  case ItemType::Weapon: return "Weapon";
  case ItemType::Armor: return "Armor";
  case ItemType::Consumable: return "Consumable";
  case ItemType::Quest: return "Quest";
  case ItemType::Junk: return "Junk";
  default: throw std::invalid_argument("Unknown ItemType");
  }
}

inline ItemType stringToItemType(const std::string& str) {
  if (str == "Weapon") return ItemType::Weapon;
  if (str == "Armor") return ItemType::Armor;
  if (str == "Consumable") return ItemType::Consumable;
  if (str == "Quest") return ItemType::Quest;
  if (str == "Junk") return ItemType::Junk;
  throw std::invalid_argument("Invalid ItemType string: " + str);
}

typedef struct Items {
  std::string name;
  Stats baseRequirements = {0,0,0,0,};
  int base;
  ItemType type;
}Items;

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_ITEMS_H
