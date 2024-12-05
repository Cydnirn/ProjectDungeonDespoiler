//
// Created by rei on 12/5/24.
//

#include "Map.h"

namespace DespoilerEngine {
  Map::Map()
    : BgTextureMain(nullptr) {}

  void Map::init() {
        loadIcon("./resources/Textures/icon.ico");
        BgTextureMain = loadTexture("./resources/Textures/background.png");
  }

void Map::run(int &state) const {
  this->clear();
  this->render(0, 0, BgTextureMain);
  renderCenter(0, -50, "Dungeon Despoiler", Game::font, {255, 255, 255});
  renderCenter(0, 25, "This is a map", Game::font, {255, 255, 255});
  display();
}

void Map::handleEvents(SDL_Event &event, bool &isRunning,
                          int &currentIndex) const {
    if (event.type == SDL_QUIT)
    {
      isRunning = false;
    }
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
    {
      switch (event.key.keysym.sym)
      {
      case SDLK_q:
      case SDLK_ESCAPE:
        isRunning = false;
        break;
      case SDLK_BACKSPACE:
        currentIndex -= 1;
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
    SDL_DestroyRenderer(renderer.get());
  }

  Map::~Map() {
    cleanUp();
  }



   } // DespoilerEngine