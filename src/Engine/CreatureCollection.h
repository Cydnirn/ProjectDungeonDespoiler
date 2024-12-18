//
// Created by rei on 12/3/24.
//
#pragma once

#include <vector>
#include <memory>
#include "../Engine/Creature.h"
#ifndef CREATURELOADER_H
#define CREATURELOADER_H
namespace DespoilerEngine {
    class CreatureCollection {
      public:
        static std::shared_ptr<CreatureCollection> getInstance();
        void loadCreatures(const std::string& directory = ".");
        Creature spawnRandomCreature();
        ~CreatureCollection() = default;
        CreatureCollection() = default;
      private:
        std::vector<Creature> Creatures;
    };
} // DespoilerEngine
#endif //CREATURELOADER_H
