//
// Created by rei on 12/5/24.
//

#include "Map.h"
#include <SDL_image.h>
#include "memory"
#include <iostream>
#include "../Player.h"

namespace DespoilerEngine {
  Map::Map(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width,
           const int *p_height)
      : Scene(p_window, p_renderer, p_width, p_height), BgTextureMain(nullptr), p_texture(nullptr), p_img(nullptr) {}

  void Map::init() {
    p_img = IMG_Load("./resources/Textures/Player_idle.png");
    if (p_img == nullptr) {
      std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
      return;
    }
    p_texture = SDL_CreateTextureFromSurface(this->s_renderer, p_img);
    if(p_texture == nullptr){
        std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        return;
    }
    int dst_x = *this->SCREEN_WIDTH / 2 - Player::p_Width / 2;
    int dst_y = *this->SCREEN_HEIGHT / 2 - Player::p_Height / 2;
    player = std::make_unique<Player>(p_texture, SDL_Rect{0, 0, Player::p_Width, Player::p_Height}, SDL_Rect{dst_x, dst_y, Player::p_Width, Player::p_Height});
    loadIcon("./resources/Textures/icon.ico");
    BgTextureMain = loadTexture("./resources/Textures/background.png");
    }

void Map::run(int &state) const {
  this->clear();
  this->render(0, 0, BgTextureMain);
  this->renderCenter(0, -210, "Dungeon Despoiler", Game::font, {255, 255, 255});
  this->render(*player);
  display();
}

void Map::handleEvents(SDL_Event &event, bool &isRunning,
                          int &currentIndex) const {
  player->handleEvent(event);
    if (event.type == SDL_QUIT)
    {
      isRunning = false;
    }
    if (event.type == SDL_KEYDOWN)
    {
      switch (event.key.keysym.sym)
      {
      case SDLK_q:
      case SDLK_ESCAPE:
        isRunning = false;
        break;
      case SDLK_BACKSPACE:
        currentIndex = 0;
        this->clear();
        break;
      default:
        break;
      }
    }
  }

  void Map::cleanUp() const {
    if (BgTextureMain) {
      SDL_DestroyTexture(BgTextureMain);
      BgTextureMain = nullptr;
    }
    if(player){
      SDL_DestroyTexture(p_texture);
      SDL_FreeSurface(p_img);
    }
    SDL_DestroyRenderer(this->s_renderer);
  }

  Map::~Map() {
    cleanUp();
  }



   } // DespoilerEngine