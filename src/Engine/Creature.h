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
    int baseDamage = 10 * stats.strength;
    int baseCritical = stats.agility;
    int health = 10 * stats.vigor;
    int maxHealth = 10 * stats.vigor;
    int mana = 10 * stats.intelligence;
    int xp = 100;
    int level = xp / 100;
    std::string tex;
public:
    ~Creature() = default;
    Creature(std::string  name, std::string  desc, Stats  stats, int xp = 100, int baseDmg = 10, std::string tex = "");

    // Load a creature from a JSON file
    static Creature fromJsonFile(const std::string& filepath);

    // Getters
    [[nodiscard]] const std::string& getName() const { return name; };
    [[nodiscard]] const int& getBaseDamage() const { return baseDamage; };
    [[nodiscard]] const int& getBaseCritical() const { return baseCritical; };
    [[nodiscard]] const Stats &getStats() const { return stats; };
    [[nodiscard]] const std::string& getDescription() const { return description; };
    [[nodiscard]] const int& getHealth() const { return health; };
    [[nodiscard]] const int& getMaxHealth() const { return maxHealth; };
    [[nodiscard]] const int& getMana() const { return mana; };
    [[nodiscard]] const int& getXP() const { return xp; };
    [[nodiscard]] const int& getLevel() const { return level; };
    [[nodiscard]] const std::string& getTexture() const {return tex; };
    // Setters
    void setBaseDamage(int baseDmg) { this->baseDamage = baseDmg; }
    void setHealth(int healthInput) { this->health = healthInput; }
    void setMana(int manaInput) { this->mana = manaInput; }
    void setXP(int xpInput) { this->xp = xpInput; }
    void setLevel() { this->level = this->xp / 100; }
};

} // namespace DespoilerEngine

#endif // CREATURE_H