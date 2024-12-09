//
// Created by rei on 12/5/24.
//

#include "Map.h"
#include <SDL_image.h>
#include "memory"

namespace DespoilerEngine {
  Map::Map(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width,
           const int *p_height, std::shared_ptr<Player> player)
      : Scene(p_window, p_renderer, p_width, p_height), BgTextureMain(nullptr), p_texture(nullptr), p_img(nullptr), player(player) {}

  void Map::init() {
    loadIcon("./resources/Textures/icon.ico");
    BgTextureMain = loadTexture("./resources/Textures/background.png");
    }

void Map::run(int &state) const {
  this->clear();
  this->render(0, 0, BgTextureMain);
  this->renderScaled(50, 50, p_texture, 100, 100);
  this->renderCenter(0, -210, "Dungeon Despoiler", Game::font, {255, 255, 255});
  this->render(player);
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