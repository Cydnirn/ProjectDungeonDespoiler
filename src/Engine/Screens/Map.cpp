//
// Created by rei on 12/5/24.
//

#include "Map.h"
#include <SDL_image.h>

#include "memory"
#include <iostream>
#include <utility>

namespace DespoilerEngine {
  Map::Map(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width,
           const int *p_height, std::shared_ptr<Player> player)
      : Scene(p_window, p_renderer, p_width, p_height), BgTextureMain(nullptr), p_texture(nullptr), p_img(nullptr), player(std::move(player)) {}

  void Map::init() {
    loadIcon("./resources/Textures/icon.ico");
    BgTextureMain = loadTexture("./resources/Textures/background.png");
    WallTexture = loadTexture("./resources/Textures/wall.png");
    if (WallTexture == nullptr) {
      std::cerr << "Failed to load wall texture: " << SDL_GetError() << std::endl;
      return;
    }

    // Set posisi dan ukuran wall (contoh).
    WallRect = {100, 100, 64, 64}; // x, y, width, height
  }

void Map::run(int &state) const {
  clear();
  this->render(0, 0, BgTextureMain);
    for (size_t row = 0; row < mapArray.size(); ++row) {
      for (size_t col = 0; col < mapArray[row].size(); ++col) {
        if (mapArray[row][col] == 1) { // Jika '1', render wall
          SDL_Rect dstRect = {
            static_cast<int>(col * tileSize), // x
            static_cast<int>(row * tileSize), // y
            tileSize,                         // width
            tileSize                          // height
        };
          this->renderScaled(dstRect.x, dstRect.y, WallTexture,25,25);
        }
      }
    }
  this->renderScaled(50, 50, p_texture, 250, 250);
  this->renderCenter(0, -210, "Dungeon Despoiler", Game::font, {255, 255, 255});
  this->render(player);
  display();
}

void Map::handleEvents(SDL_Event &event, bool &isRunning,
                          int &currentIndex)  {
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
        break;
      case SDLK_RETURN:
      case SDLK_KP_ENTER:
        currentIndex = 2;
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
    if(WallTexture){
      SDL_DestroyTexture(WallTexture);
      WallTexture = nullptr;
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