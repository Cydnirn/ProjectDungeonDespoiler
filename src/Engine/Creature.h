#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>
#include <string>
#include "Stats.h"

namespace DespoilerEngine {

class Creature {
    std::string description;
    std::string name;
    Stats stats{0,0,0,0};
    int health = 10 * stats.vigor;
public:
    Creature() = default;
    ~Creature() = default;
    Creature(std::string  name, std::string  desc, Stats  stats);

    // Load a creature from a JSON file
    static Creature fromJsonFile(const std::string& filepath);

    // Getters
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const Stats &getStats() const;
    [[nodiscard]] const int* getHealth() const;
};

} // namespace DespoilerEngine

#endif // CREATURE_H