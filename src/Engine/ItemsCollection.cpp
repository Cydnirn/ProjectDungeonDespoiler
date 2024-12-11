//
// Created by rei on 12/11/24.
//

#include "ItemsCollection.h"
#include "Items.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace DespoilerEngine {
  inline void to_json(json& j, const ItemType& type) {
    j = itemTypeToString(type);
  }

  inline void from_json(const json& j, ItemType& type) {
    type = stringToItemType(j.get<std::string>());
  }

  std::shared_ptr<ItemsCollection> ItemsCollection::getInstance() {
    static std::shared_ptr<ItemsCollection> instance(new ItemsCollection());
    return instance;
  }

  void ItemsCollection::addCollection(const DespoilerEngine::Items& item, const std::string& title) {
    items.insert({title, item});
  }

  Items ItemsCollection::fromJsonFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if(!file.is_open()) throw std::runtime_error("Could not open file: " + filepath);
    json j;
    file >> j;
    Stats stats = {
                j["baseRequirements"]["vigor"].get<int>(),
                j["baseRequirements"]["strength"].get<int>(),
                j["baseRequirements"]["agility"].get<int>(),
                j["baseRequirements"]["intelligence"].get<int>()
    };
    return Items({j["name"].get<std::string>(), stats, j["base"].get<int>(), j["type"].get<ItemType>()});
  }

  std::unordered_map<std::string, Items> ItemsCollection::loadItems(const std::string& directory) {
    for(const auto &entry:std::filesystem::directory_iterator(directory)){
      if(entry.path().extension() == ".obj"){
        try{
          Items item = this->fromJsonFile(entry.path().string());
          this->addCollection(item, item.name);
        }catch(const std::exception& e){
          std::cerr << "Error loading item from file: " << entry.path().string() << " with exception: " << e.what() << "\n";
        }
      }
    }
    return items;
  }

  Items ItemsCollection::getItem(const std::string& title) {
        auto item = items.find(title);
        if(item == items.end()) throw std::runtime_error("Item not found: " + title);
        return item->second;
  }
} // namespace DespoilerEngine