//
// Created by rei on 12/5/24.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "Scene.h"
namespace DespoilerEngine {
class ScreenManager {
public:
  void addScreen(Scene *p_screen) ;
  void addScreen(const std::shared_ptr<Scene>& Screen);
  void removeScreen(Scene *p_screen);
  void runScreen(int index) const;
  void handleEvents(SDL_Event &e, bool &isRunning, int &currentIndex) const;
  void clear();
  ~ScreenManager();
private:
  std::vector<std::shared_ptr<Scene>> screens;
};
}
#endif //SCREENMANAGER_H
