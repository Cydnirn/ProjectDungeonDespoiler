//
// Created by rei on 31.10.24.
//

#include "Game.h"
#include "CreatureLoader.h"
#include "Scene.h"
#include "ScreenManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>

#include "Screens/MainMenu.h"
#include "Screens/Map.h"

namespace DespoilerEngine {
    TTF_Font *Game::font = nullptr;
    auto Screens =  std::make_shared<ScreenManager>();
    CreatureCollection LowCreatures;
    CreatureCollection MediumCreatures;
    Game::Game(){};
    Game::~Game(){};

    void Game::loadCreature()
    {
        LowCreatures.Creatures = CreatureLoader::loadCreatures("./resources/Creatures/low");
        MediumCreatures.Creatures = CreatureLoader::loadCreatures("./resources/Creatures/medium");
    }

    /**
     * Initializes the game by setting up SDL, SDL_image, and SDL_ttf libraries,
     * and loading the necessary resources such as fonts and screens.
     *
     * @return int Returns 0 on success, -1 on failure.
     */
    int Game::init()
    {
        // Initialize SDL with all subsystems
        SDL_Init(SDL_INIT_EVERYTHING);

        // Initialize SDL video subsystem and check for errors
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

        // Initialize SDL_image with PNG support and check for errors
        if (!(IMG_Init(IMG_INIT_PNG)))
            std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

        // Initialize SDL_ttf and check for errors
        if (TTF_Init() < 0)
            std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;

        // Check if the renderer is created successfully
        if (!renderer)
            std::cout << "Renderer failed. Error: " << SDL_GetError() << std::endl;

        // Check if the main window is created successfully
        if (!MainWindow)
            std::cout << "Renderer failed. Error: " << SDL_GetError() << std::endl;

        // Load the font from the specified path and size
        font = TTF_OpenFont("./resources/Fonts/arial.ttf", 24);
        if (!font) {
          std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
          return -1;
        }

        const auto main_menu_window = std::make_shared<MainMenu>();
        const auto map_window = std::make_shared<Map>();

        // Add screens to the screen loader
        Screens->addScreen(main_menu_window);
        Screens->addScreen(map_window);

        return 0;
    }

    /**
     * Runs the main game loop, handling events, updating the screen, and rendering the current screen.
     */
    void Game::run()
    {
        bool isRunning = true;  // Flag to control the game loop
        int state = 0;          // Variable to track the current state of the game
        SDL_Event e;            // SDL event structure to handle events

        while (isRunning) {
            // Poll for events and handle them
            while (SDL_PollEvent(&e)) {
                Screens->handleEvents(e, isRunning, state);
            }
            // Clear the screen with a black color
            SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
            SDL_RenderClear(renderer.get());
            // Render the current screen based on the state
            Screens->runScreen(state);
            // Present the updated screen
            SDL_RenderPresent(renderer.get());
        }
    }

    void Game::close()
    {
        Screens->clear();
        if (font) {
            TTF_CloseFont(font);
            font = nullptr;
        }
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

} // DespoilerEngine