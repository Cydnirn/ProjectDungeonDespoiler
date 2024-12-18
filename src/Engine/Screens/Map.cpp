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
    WallRect = {100, 100, 64, 64};
    FinishTexture = loadTexture("./resources/Textures/finish.png");
    if (FinishTexture == nullptr) {
      std::cerr << "Failed to load finish texture: " << SDL_GetError() << std::endl;
      return;
    }

  }

  bool Map::checkCollision(const SDL_Rect a, const SDL_Rect b) {
      if (a.y + a.h <= b.y) return false;
      if (a.y >= b.y + b.h) return false;
      if (a.x + a.w <= b.x) return false;
      if (a.x >= b.x + b.w) return false;
      return true;
  }

void Map::run(int &state) {
  clear();
  this->render(0, 0, BgTextureMain);
    for (size_t row = 0; row < mapArray.size(); ++row) {
      for (size_t col = 0; col < mapArray[row].size(); ++col) {
        SDL_Rect dstRect = {
          static_cast<int>(col * tileSize), // x
          static_cast<int>(row * tileSize), // y
          tileSize,                         // width
          tileSize                          // height
      };

        if (mapArray[row][col] == 1) { // Jika '1', render wall
          this->renderScaled(dstRect.x, dstRect.y, WallTexture, tileSize, tileSize);
        } else if (mapArray[row][col] == 2) { // Jika '2', render finish
          this->renderScaled(dstRect.x, dstRect.y, FinishTexture, tileSize, tileSize);
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
      bool collision = false;
      SDL_Rect playerRect = player->getRect();
      for (size_t row = 0; row < mapArray.size(); ++row) {
          for (size_t col = 0; col < mapArray[row].size(); ++col) {
              SDL_Rect tileRect = {
                      static_cast<int>(col * tileSize), // x
                    static_cast<int>(row * tileSize), // y
                    tileSize - 25,                         // width
                    tileSize - 25                          // height
                };
                if (mapArray[row][col] == 1) {
                    if (checkCollision(playerRect, tileRect)) {
                        collision = false;
                        std::cout << "Collision detected at: (" << tileRect.x << ", " << tileRect.y << ")\n";
                        break;
                    }
                } else if (mapArray[row][col] == 2) {
                    if (checkCollision(playerRect, tileRect)) {
                        currentIndex =0 ;
                        break;
                    }
                }
            }
          if (collision) break;
      }
  player->handleEvent(event, currentIndex, collision);
      collision = false;
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
    if (FinishTexture) {
      SDL_DestroyTexture(FinishTexture);
      FinishTexture = nullptr;
    }

  }

  Map::~Map() {
    cleanUp();
  }



   } // DespoilerEngine