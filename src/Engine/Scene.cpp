//
// Created by rei on 01.11.24.
//

#include "Scene.h"
#include <curses.h>

#include "../Creatures/CreatureLoader.h"

namespace DespoilerEngine
{
    CreatureLoader creatureLoader;
    std::pmr::vector<Creature> creatures = CreatureLoader::loadCreatures();

}
