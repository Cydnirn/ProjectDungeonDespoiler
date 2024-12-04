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
    constexpr int SCREEN_WIDTH=720;
    constexpr int SCREEN_HEIGHT=480;
    Scene Window("Dungeon Despoiler", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Texture* BgTexture;
    CreatureCollection LowCreatures;
    CreatureCollection MediumCreatures;
    int level = 0;

    void Game::loadCreature()
    {
        LowCreatures.Creatures = CreatureLoader::loadCreatures("./resources/Creatures/low");
        MediumCreatures.Creatures = CreatureLoader::loadCreatures("./resources/Creatures/medium");
    }


    int Game::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) > 0)
            std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        if (!(IMG_Init(IMG_INIT_PNG)))
            std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
        if (!(TTF_Init()))
            std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
        loadCreature();
        Window.loadIcon("resources/Textures/icon.jpeg");
        //MainWindow = SDL_CreateWindow("Dungeon Despoiler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        BgTexture = Window.loadTexture("resources/Textures/background.png");
        return 0;
    }

    void Game::run()
    {
        SDL_Event e;
        bool quit = false;
        while( quit == false ) {
            while( SDL_PollEvent( &e ) ) {
                if( e.type == SDL_QUIT ) quit = true;
                Window.clear();
                Window.render(0,0, BgTexture);
                Window.display();
            }
        }
    }

    void Game::close()
    {
        Window.cleanUp();
    }

} // DespoilerEngine