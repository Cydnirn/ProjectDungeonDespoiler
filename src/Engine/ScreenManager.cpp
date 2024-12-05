//
// Created by rei on 18.11.24.
//

#include "ScreenManager.h"

namespace DespoilerEngine {

  ScreenManager::~ScreenManager() {
    clear();
  }

void ScreenManager::addScreen(Scene *p_screen) {
   screens.emplace_back(p_screen);
  }

void ScreenManager::addScreen(const std::shared_ptr<Scene>& p_screen) {
    screens.push_back(p_screen);
  }

void ScreenManager::removeScreen(Scene *p_screen) {
    std::erase_if(screens, [p_screen](const std::shared_ptr<Scene> &screen) {
    return screen.get() == p_screen;
  });
  }
void ScreenManager::runScreen(int index) const {
    screens[index]->init();
    screens[index]->run(index);
  }
void ScreenManager::handleEvents(SDL_Event &e, bool &isRunning, int &currentIndex) const {
    screens[currentIndex]->handleEvents(e, isRunning, currentIndex);
  }
void ScreenManager::clear() {
    screens.clear();
    SDL_DestroyRenderer(renderer.get());
    SDL_DestroyWindow(MainWindow.get());
  }
} // DespoilerEngine