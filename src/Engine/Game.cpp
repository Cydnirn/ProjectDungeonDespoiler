//
// Created by rei on 31.10.24.
//

#include "Game.h"
#include "CreatureLoader.h"
#include "Scene.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "Screens/MainMenu.h"
#include "Screens/Map.h"

namespace DespoilerEngine {
    TTF_Font *Game::font = nullptr;
    auto Screens = new ScreenLoader();
    CreatureCollection LowCreatures;
    CreatureCollection MediumCreatures;

    void Game::loadCreature()
    {
        LowCreatures.Creatures = CreatureLoader::loadCreatures("./resources/Creatures/low");
        MediumCreatures.Creatures = CreatureLoader::loadCreatures("./resources/Creatures/medium");
    }

    int Game::init()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        if (!(IMG_Init(IMG_INIT_PNG)))
            std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
        if (TTF_Init() < 0)
            std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
        if (!renderer)
            std::cout << "Renderer failed. Error: " << SDL_GetError() << std::endl;
        if (!MainWindow)
            std::cout << "Renderer failed. Error: " << SDL_GetError() << std::endl;
        font = TTF_OpenFont("./resources/Fonts/arial.ttf", 24);
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            return -1;
        }
        Screens->addScreen(main_menu_window);
        Screens->addScreen(map_window);
        return 0;
    }

    void Game::run()
    {
        bool isRunning = true;
        int state = 0;
        SDL_Event e;
        while (isRunning) {
            while (SDL_PollEvent(&e)) {
                Screens->handleEvents(e, isRunning, state);
            }
            // Clear the screen
            SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
            SDL_RenderClear(renderer);
            // Render current screen
            Screens->runScreen(state);
            // Present the updated screen
            SDL_RenderPresent(renderer);
        }
    }

    void Game::close()
    {
        Screens->clear();
        TTF_Quit();
        SDL_Quit();
    }

} // DespoilerEngine