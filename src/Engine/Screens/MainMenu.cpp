//
// Created by rei on 12/5/24.
//

#include "MainMenu.h"

namespace DespoilerEngine {
 MainMenu::MainMenu(SDL_Window* p_window, SDL_Renderer* p_renderer, const int * p_width, const int * p_height)
  : Scene(p_window, p_renderer, p_width, p_height), BgTextureMain(nullptr) {}

void MainMenu::init() {
   loadIcon("./resources/Textures/icon.ico");
   BgTextureMain = loadTexture("./resources/Textures/background.png");
 }


void MainMenu::run(int &state) const {
   clear();
   this->render(0, 0, BgTextureMain);
   this->renderCenter(0, -50, "Dungeon Despoiler", Game::font, {255, 255, 255});
   this->renderCenter(0, 25, "Press Enter to start", Game::font, {255, 255, 255});
   this->renderCenter(0, 75, "Press Q to quit", Game::font, {255, 255, 255});
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
   SDL_DestroyRenderer(this->s_renderer);
 }

MainMenu::~MainMenu() {cleanUp();}



} // DespoilerEngine