//
// Created by rei on 12/5/24.
//

#include "MainMenu.h"
#include "../Game.h"

namespace DespoilerEngine {
SDL_Texture *BgTextureMain;
 MainMenu::MainMenu()
    : BgTextureMain(nullptr) {}

 void MainMenu::init() {
   loadIcon("./resources/Textures/icon.ico");
   BgTextureMain = loadTexture("./resources/Textures/background.png");
 }


void MainMenu::run(int &state) const {
       clear();
       this->render(0, 0, BgTextureMain);
       renderCenter(0, -50, "Dungeon Despoiler", Game::font, {255, 255, 255});
       renderCenter(0, 25, "Press Enter to start", Game::font, {255, 255, 255});
       renderCenter(0, 75, "Press Q to quit", Game::font, {255, 255, 255});
       display();
 }


void MainMenu::handleEvents(SDL_Event &event, bool &isRunning,
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
      case SDLK_RETURN:
        case SDLK_KP_ENTER:
        currentIndex += 1;
        break;
      default:
        break;
      }
    }
}

void MainMenu::cleanUp() const {
   if (BgTextureMain) {
     SDL_DestroyTexture(BgTextureMain);
     BgTextureMain = nullptr;
   }
   SDL_DestroyRenderer(renderer.get());
 }

MainMenu::~MainMenu() {cleanUp();}



} // DespoilerEngine