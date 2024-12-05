//
// Created by rei on 31.10.24.
//

#include "Game.h"
#include "CreatureLoader.h"
#include "Scene.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace DespoilerEngine {
    int* Game::SCREEN_WIDTH = new int(720);
    int *Game::SCREEN_HEIGHT = new int(480);
    TTF_Font *font = nullptr;
    auto Title = "Dungeon Despoiler";
    auto Window = new Scene(Title, *Game::SCREEN_WIDTH, *Game::SCREEN_HEIGHT);
    auto Screens = new ScreenLoader();
    SDL_Texture* BgTexture;
    CreatureCollection LowCreatures;
    CreatureCollection MediumCreatures;
    int state = 0;

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
        font = TTF_OpenFont("./resources/Fonts/arial.ttf", 24);
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            Window->cleanUp();
            return -1;
        }
        loadCreature();
        Window->loadIcon("resources/Textures/icon.jpeg");
        BgTexture = Window->loadTexture("resources/Textures/background.png");
        Screens->addScreen(Window);
        return 0;
    }

    void Game::run()
    {
        SDL_Event e;
        bool isRunning = true;
        while( isRunning == true ) {
            while( SDL_PollEvent( &e ) ) {
                Window->handleEvents(e, isRunning, state);
                Window->clear();
                Window->render(0,0, BgTexture);
                Window->renderCenter(0, 0, Title, font, {255, 255, 255});
                Window->renderCenter(0,25, "Press Q to quit", font, {255, 255, 255});
                Window->display();
            }
        }
    }

    void Game::close()
    {
        Window->cleanUp();
    }

} // DespoilerEngine