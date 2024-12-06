//
// Created by rei on 12/5/24.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "Scene.h"
#include "vector"
#include <memory>
namespace DespoilerEngine {
class ScreenManager {
public:
  ~ScreenManager();
  ScreenManager() = default;
  [[maybe_unused]] void addScreen(const std::shared_ptr<Scene>& Screen);
  template <typename T>
  void addScreen(T* p_screen);
  [[maybe_unused]] void removeScreen(Scene *p_screen);
  void runScreen(int index) const;
  void handleEvents(SDL_Event &e, bool &isRunning, int &currentIndex) const;
  void clear();
private:
  std::vector<std::shared_ptr<Scene>> screens;
};
}
#endif //SCREENMANAGER_H
