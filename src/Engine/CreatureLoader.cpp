#include "CreatureLoader.h"
#include <filesystem>
#include <iostream>
#include <random>

#include "../Engine/Creature.h"

namespace DespoilerEngine {

    std::pmr::vector<Creature> CreatureLoader::loadCreatures(const std::string& directory)
    {
        std::pmr::vector<Creature> Creatures;
        for (const auto& entry : std::filesystem::directory_iterator(directory))
        {
            if (entry.path().extension() == ".obj"){
                try
                {
                    Creatures.emplace_back(Creature::fromJsonFile(entry.path().string()));
                }
                catch (const std::exception& e)
                {
                    std::cerr << "Error loading creature from file: " << entry.path().string() << std::endl;
                }
            }
        }
        return Creatures;
    }

    Creature CreatureLoader::spawnRandomCreature(const CreatureCollection& collection)
    {
        if (collection.Creatures.empty())
        {
            throw std::runtime_error("No creatures loaded.");
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, collection.Creatures.size() - 1);

        // Pick random Creature from collection
        const size_t index = dist(gen);
        return collection.Creatures[index];
    }

    CreatureLoader::~CreatureLoader() {
        // No need to manually clear as std::pmr::vector will handle its own cleanup
    }

} // DespoilerEngine