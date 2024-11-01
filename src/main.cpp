#include "Engine/Game.h"

int main(int argv, char** argc)
{
    if (const int init_status = DespoilerEngine::Game::init(); init_status == 0)
    {
        DespoilerEngine::Game().run();
    }
    DespoilerEngine::Game::close();
    return 0;
}
