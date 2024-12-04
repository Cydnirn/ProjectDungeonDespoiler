//
// Created by rei on 01.11.24.
//

#ifndef SCENE_H
#define SCENE_H
#include "Game.h"

#include <vector>

namespace DespoilerEngine
{
    class Scene : Game
    {
        std::pmr::vector<WINDOW> Scenes;
        
    };
}


#endif //SCENE_H
