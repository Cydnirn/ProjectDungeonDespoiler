//
// Created by rei on 12/3/24.
//

#include <vector>

#include "../Engine/Creature.h"
#ifndef CREATURELOADER_H
#define CREATURELOADER_H
namespace DespoilerEngine {
    typedef struct
    {
        std::pmr::vector<Creature> Creatures;
    } CreatureCollection;
    class CreatureLoader {
    public:
        static std::pmr::vector<Creature> loadCreatures(const std::string& directory = ".");
        static Creature spawnRandomCreature(const CreatureCollection& collection);
    };
} // DespoilerEngine
#endif //CREATURELOADER_H