//
// Created by rei on 18.11.24.
//

#include "ScreenManager.h"
#include "Screens/MainMenu.h"
#include "Screens/Map.h"

namespace DespoilerEngine {

  ScreenManager::~ScreenManager() {
    printf("ScreenManager destroyed");
    clear();
  }

  [[maybe_unused]] void ScreenManager::addScreen(const std::shared_ptr<Scene>& Screen) {
    screens.emplace_back(Screen);
  }



template <typename T>
  void ScreenManager::addScreen(T *p_screen) {
    screens.emplace_back(p_screen);
  }

  [[maybe_unused]] void ScreenManager::removeScreen(Scene *p_screen) {
    std::erase_if(screens, [p_screen](const std::shared_ptr<Scene> &screen) {
    return screen.get() == p_screen;
  });
  }

  void ScreenManager::initializeScreen(int index) const {
    screens[index]->init();
  }
void ScreenManager::runScreen(int index) const {
    screens[index]->run(index);
  }
void ScreenManager::handleEvents(SDL_Event &e, bool &isRunning, int &currentIndex) const {
    screens[currentIndex]->handleEvents(e, isRunning, currentIndex);
  }
void ScreenManager::clear() {
    screens.clear();
  }

  template void ScreenManager::addScreen<MainMenu>(MainMenu* screen);
  template void ScreenManager::addScreen<Map>(Map* screen);
} // DespoilerEngine