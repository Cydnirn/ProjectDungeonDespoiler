//
// Created by rei on 12/5/24.
//

#include "MainMenu.h"
#include "../Game.h"

namespace DespoilerEngine {
SDL_Texture *BgTextureMain;
 MainMenu::MainMenu(const char *p_title, const int p_w, const int p_h)
    : Scene(p_title, p_w, p_h),BgTextureMain(nullptr) {}

MainMenu::MainMenu(const std::string &p_title, const int p_w, const int p_h)
     : Scene(p_title, p_w, p_h), BgTextureMain(nullptr) {}

 void MainMenu::init() {
   main_menu_window->loadIcon("./resources/Textures/icon.jpeg");
   BgTextureMain = main_menu_window->loadTexture("./resources/Textures/background.png");
 }


void MainMenu::run(int &state) const {
       main_menu_window->clear();
       main_menu_window->render(0, 0, BgTextureMain);
       main_menu_window->renderCenter(0, -50, "Dungeon Despoiler", Game::font, {255, 255, 255});
       main_menu_window->renderCenter(0, 25, "Press Enter to start", Game::font, {255, 255, 255});
       main_menu_window->renderCenter(0, 75, "Press Q to quit", Game::font, {255, 255, 255});
       main_menu_window->display();
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
        isRunning = false;
        std::cout << "Quitting" << std::endl;
        break;
      case SDLK_ESCAPE:
        isRunning = false;
        break;
      case SDLK_RETURN:
        case SDLK_KP_ENTER:
        std::cout << currentIndex << std::endl;
        currentIndex += 1;
        clear();

        break;
      default:
        break;
      }
    }
}

void MainMenu::clear() const {
   SDL_RenderClear(renderer);
 }

void MainMenu::cleanUp() const {
   SDL_DestroyRenderer(renderer);
 }



} // DespoilerEngine