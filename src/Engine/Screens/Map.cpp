//
// Created by rei on 12/5/24.
//

#include "Map.h"

namespace DespoilerEngine {
  Map::Map(const char *p_title, int p_w, int p_h)
    : Scene(p_title, p_w, p_h, false), BgTextureMain(nullptr) {}
  Map::Map(const std::string &p_title, int p_w, int p_h)
       : Scene(p_title.c_str(), p_w, p_h, false), BgTextureMain(nullptr) {}

  void Map::init() {
        map_window->loadIcon("./resources/Textures/icon.jpeg");
        BgTextureMain = map_window->loadTexture("./resources/Textures/background.png");
  }

void Map::run(int &state) const {
  map_window->clear();
  map_window->render(0, 0, BgTextureMain);
  map_window->renderCenter(0, -50, "Dungeon Despoiler", Game::font, {255, 255, 255});
  map_window->renderCenter(0, 25, "This is a map", Game::font, {255, 255, 255});
  map_window->display();
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
        isRunning = false;
        std::cout << "Quitting" << std::endl;
        break;
      case SDLK_ESCAPE:
        isRunning = false;
        break;
      default:
        break;
      }
    }
  }

  void Map::clear() const {
    SDL_RenderClear(renderer);
  }

  void Map::cleanUp() const {
    SDL_DestroyRenderer(renderer);
  }



   } // DespoilerEngine