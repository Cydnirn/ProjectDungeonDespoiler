#ifndef CREATURE_H
#define CREATURE_H

#include <cstdint>
#include <string>

namespace DespoilerEngine {

class Creature {
    struct Stats {
        uint8_t vigor;
        uint8_t strength;
        uint8_t agility;
        uint8_t intelligence;
    };

private:
    std::string description;
    std::string name;
    Stats stats{};
    int health = 10;

public:
    Creature() = default;
    ~Creature();
    Creature(std::string  name, std::string  desc, Stats  stats);

    // Load a creature from a JSON file
    static Creature fromJsonFile(const std::string& filepath);

    // Save a creature to a JSON file
    void toJsonFile(const std::string& filepath) const;

    // Getters
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const Stats& getStats() const;
    [[nodiscard]] const int* getHealth() const;
};

} // namespace DespoilerEngine

#endif // CREATURE_H