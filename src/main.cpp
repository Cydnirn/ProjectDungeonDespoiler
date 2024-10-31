#include <ncurses.h>
#include <string>

#include "Utils/Game.h"

int main(int argv, char** argc)
{
    if (const int init_status = ProjectDungeonDespoiler::Game::init(); init_status == 0)
    {
        ProjectDungeonDespoiler::Game().run();
    }
    ProjectDungeonDespoiler::Game::close();
    return 0;
}
