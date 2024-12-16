#include <memory>

#include "Engine/Game.h"

int main(int argv, char** argc)
{
    const auto Game = std::make_unique<DespoilerEngine::Game>();
    if (const int init_status = Game->init(); init_status == 0)
    {
        Game->run();
    }
    Game->close();
    return 0;
}
