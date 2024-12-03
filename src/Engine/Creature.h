#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>

namespace DespoilerEngine {

class Creature {
    struct Stats {
        uint8_t vigor;
        uint8_t strength;
        uint8_t agility;
        uint8_t intelligence;
    };

    int health = 10;
    Stats creatureStats = {};

public:
    explicit Creature(const Stats stats) : creatureStats(stats) {}
    Creature() = default;

    void setHealth(int newHealth) { health = newHealth; }
    [[nodiscard]] Stats getStats() const { return creatureStats; }
    [[nodiscard]] int getHealth() const { return health; }
};

} // namespace DespoilerEngine

#endif // CREATURE_H