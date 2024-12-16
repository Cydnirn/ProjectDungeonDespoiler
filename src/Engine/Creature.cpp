//
// Created by rei on 31.10.24.
//

#include "Creature.h"
#include <fstream>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <utility>
#include "Stats.h"

using json = nlohmann::json;

namespace DespoilerEngine {
    Creature::Creature(std::string  name, std::string  desc, const Stats  stats, int xp, int baseDmg)
    : name(std::move(name)), description(std::move(desc)), stats(stats), xp(xp), baseDamage(baseDmg) {}

    Creature Creature::fromJsonFile(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filepath);
        }

        json j;
        file >> j;

        Stats stats = {
            j["stats"]["vigor"].get<int>(),
            j["stats"]["strength"].get<int>(),
            j["stats"]["agility"].get<int>(),
            j["stats"]["intelligence"].get<int>()
        };

        return {j["name"].get<std::string>(), j["desc"].get<std::string>() , stats, j["xp"].get<int>(), j["baseDmg"].get<int>()};
    }



} // DungeonDespoiler