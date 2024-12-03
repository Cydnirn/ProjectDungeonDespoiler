//
// Created by rei on 31.10.24.
//

#include "Creature.h"
#include <fstream>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <utility>

using json = nlohmann::json;

namespace DespoilerEngine {
    Creature::Creature(std::string  name, const std::string& desc, const Stats  stats)
    : name(std::move(name)), stats(stats) {}

    Creature Creature::fromJsonFile(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filepath);
        }

        json j;
        file >> j;

        Stats stats = {
            j["stats"]["vigor"].get<uint8_t>(),
            j["stats"]["strength"].get<uint8_t>(),
            j["stats"]["agility"].get<uint8_t>(),
            j["stats"]["intelligence"].get<uint8_t>()
        };

        return {j["name"].get<std::string>(), j["desc"].get<std::string>() , stats};
    }

    void Creature::toJsonFile(const std::string& filepath) const {
        json j;
        j["name"] = name;
        j["description"] = description;
        j["stats"]["vigor"] = stats.vigor;
        j["stats"]["strength"] = stats.strength;
        j["stats"]["agility"] = stats.agility;
        j["stats"]["intelligence"] = stats.intelligence;

        std::ofstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file for writing: " + filepath);
        }
        file << j.dump(4); // Pretty-print with 4 spaces
    }

    const std::string& Creature::getName() const {
        return name;
    }

    const Creature::Stats& Creature::getStats() const {
        return stats;
    }

    const int* Creature::getHealth() const {
        return &health;
    }


} // DungeonDespoiler