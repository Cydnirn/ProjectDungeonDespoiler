#include "CreatureCollection.h"
#include "RandomGenerator.h"
#include <filesystem>
#include <iostream>

namespace DespoilerEngine {

  std::shared_ptr<CreatureCollection> CreatureCollection::getInstance() {
    static std::shared_ptr<CreatureCollection> instance(new CreatureCollection());
    return instance;
  }

    void CreatureCollection::loadCreatures(const std::string& directory)
    {
        for (const auto& entry : std::filesystem::directory_iterator(directory))
        {
            if (entry.path().extension() == ".obj"){
                try
                {
                  Creatures.emplace_back(Creature::fromJsonFile(entry.path().string()));
                }
                catch (const std::exception& e)
                {
                    std::cerr << "Error loading creature from file: "
                            << entry.path().string()
                            << " with exception: " << e.what()
                            << "\n";
                }
            }
        }
    }

    Creature CreatureCollection::spawnRandomCreature()
    {
        if (Creatures.empty())
        {
            throw std::runtime_error("No creatures loaded.");
        }

        // Pick random Creature from collection
        const size_t index = RandomGenerator::generateRandomNumber(0, Creatures.size() - 1);
        return Creatures[index];
    }

    CreatureCollection::~CreatureCollection() =default;

} // DespoilerEngine