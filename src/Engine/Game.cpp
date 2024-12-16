//
// Created by rei on 31.10.24.
//

#include "Game.h"
#include "CreatureCollection.h"
#include "ScreenManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

#include "ItemsCollection.h"
#include "Screens/Battle.h"
#include "Screens/MainMenu.h"
#include "Screens/Map.h"
#include <iostream>

namespace DespoilerEngine {
    TTF_Font *Game::font = nullptr;
    auto LowCreatures = CreatureCollection::getInstance();
    std::shared_ptr<ItemsCollection> Game::ItemsCol = ItemsCollection::getInstance();
    Game::Game() = default;
    auto Screens =  std::make_unique<ScreenManager>();

    void Game::loadEssentials()
    {
        Game::ItemsCol->loadItems("./resources/Items");
        LowCreatures->loadCreatures("./resources/Creatures/low");
    }

    /**
     * Initializes the game by setting up SDL, SDL_image, and SDL_ttf libraries,
     * and loading the necessary resources such as fonts and screens.
     *
     * @return int Returns 0 on success, -1 on failure.
     */
    int Game::init()
    {
        this->loadEssentials();
        this->SCREEN_WIDTH=720;
        this->SCREEN_HEIGHT = 480;
        this->fps=30;
        this->desiredDelta = 1000 / this->fps;
        const auto Title = "Dungeon Despoiler";
        // Initialize SDL with all subsystems
        SDL_Init(SDL_INIT_EVERYTHING);

        // Initialize SDL video subsystem and check for errors
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
          std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
          return -1;
        }
        // Initialize SDL_image with PNG support and check for errors
        if (!(IMG_Init(IMG_INIT_PNG))) {
          std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
          return -1;
        }

        // Initialize SDL_ttf and check for errors
        if (TTF_Init() < 0) {
          std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
          return -1;
        }

        this->MainWindow = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->SCREEN_WIDTH, this->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        this->s_renderer = SDL_CreateRenderer(this->MainWindow, -1, SDL_RENDERER_ACCELERATED );

        // Check if the renderer is created successfully
        if (!s_renderer) {
          std::cout << "Renderer failed. Error: " << SDL_GetError() << std::endl;
          return -1;
        }

        // Check if the main window is created successfully
        if (!MainWindow) {
          std::cout << "Renderer failed. Error: " << SDL_GetError() << std::endl;
          return -1;
        }

        // Load the font from the specified path and size
        font = TTF_OpenFont("./resources/Fonts/upheavtt.ttf", 24);
        if (!font) {
          std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
          return -1;
        }

        //Load Player to map
        auto p_img = IMG_Load("./resources/Textures/Player_idle.png");
        if (p_img == nullptr) {
          std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
          return -1;
        }
        auto p_texture = SDL_CreateTextureFromSurface(this->s_renderer, p_img);
        if(p_texture == nullptr){
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            return -1;
        }
        int dst_x = this->SCREEN_WIDTH / 2 - Player::p_Width / 2;
        int dst_y = this->SCREEN_HEIGHT / 2 - Player::p_Height / 2;
        const auto player = std::make_shared<Player>(p_texture, SDL_Rect{0, 0, Player::p_Width, Player::p_Height}, SDL_Rect{dst_x, dst_y, Player::p_Width, Player::p_Height});

        const auto main_menu_window = std::make_shared<MainMenu>(this->MainWindow, this->s_renderer, &this->SCREEN_WIDTH, &this->SCREEN_HEIGHT);
        const auto map_window = std::make_shared<Map>(this->MainWindow, this->s_renderer, &this->SCREEN_WIDTH, &this->SCREEN_HEIGHT, player);
        const auto battle_window = std::make_shared<BattleScene>(this->MainWindow, this->s_renderer, &this->SCREEN_WIDTH, &this->SCREEN_HEIGHT, LowCreatures);

        // Add screens to the screen loader
        Screens->addScreen(main_menu_window);
        Screens->addScreen(map_window);
        Screens->addScreen(battle_window);

        return 0;
    }

    bool Game::checkCollision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>&b){
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        for(auto & ABox : a){
          leftA = ABox.x;
          rightA = ABox.x + ABox.w;
          topA = ABox.y;
          bottomA = ABox.y + ABox.h;
        }

        for(auto & BBox : b){
          leftB = BBox.x;
          rightB = BBox.x + BBox.w;
          topB = BBox.y;
          bottomB = BBox.y + BBox.h;

          if(bottomA <= topB) return false;
          if(topA >= bottomB) return false;
          if(rightA <= leftB) return false;
          if(leftA >= rightB) return false;
          return true;
        }
        return false;
    }

    /**
     * Runs the main game loop, handling events, updating the screen, and rendering the current screen.
     */
    void Game::run() const
    {
        bool isRunning = true;  // Flag to control the game loop
        int state = 0;          // Variable to track the current state of the game
        int prevState = 0;  // Variable to track the previous state of the game
        SDL_Event e;            // SDL event structure to handle events
        Screens->initializeScreen(state);
        while (isRunning) {
            Uint32 frameStart = SDL_GetTicks();
            //Clear screen with black color
            SDL_SetRenderDrawColor(this->s_renderer, 0, 0, 0, 255);
            SDL_RenderClear(this->s_renderer);
            // Poll for events and handle them
            while (SDL_PollEvent(&e)) {
                Screens->handleEvents(e, isRunning, state);
            }
            if(state != prevState)
            {
              Screens->initializeScreen(state);
              prevState = state;
            }
            // Render the current screen based on the state
            Screens->runScreen(state);
            // Present the updated screen
            SDL_RenderPresent(this->s_renderer);
            Uint32 frameTime = SDL_GetTicks() - frameStart;
            Uint32 avgFps = (this-> desiredDelta > frameTime) ? 1000 / (this->desiredDelta - frameTime): 0;
            if(frameTime < this->desiredDelta)
            {
                SDL_Delay(this->desiredDelta - frameTime);
            }
            //std::cout << avgFps << std::endl;
        }
    }

    void Game::close() const
    {
        Screens->clear();
        SDL_DestroyRenderer(this->s_renderer);
        SDL_DestroyWindow(this->MainWindow);
        if (font) {
            TTF_CloseFont(font);
            font = nullptr;
        }
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

} // DespoilerEngine