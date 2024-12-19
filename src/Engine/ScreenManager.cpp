//
// Created by rei on 18.11.24.
//

#include "ScreenManager.h"
#include "Screens/MainMenu.h"
#include "Screens/Map.h"

namespace DespoilerEngine {

  ScreenManager::~ScreenManager() {
    clear();
  }

void ScreenManager::addScreen(const std::shared_ptr<Scene>& Screen) {
    screens.emplace_back(Screen);
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

} // DespoilerEngine