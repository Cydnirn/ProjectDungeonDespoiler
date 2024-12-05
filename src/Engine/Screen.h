//
// Created by rei on 12/5/24.
//

#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>
#include <vector>
class screen {
public:
  virtual ~screen() = default;
  virtual void handleEvents(SDL_Event& event, bool& isRunning, int& currentIndex) const = 0;
};

class ScreenLoader {
  public:
    std::vector<screen*> screens;
    void addScreen(screen *p_screen) {
      screens.push_back(p_screen);
    }
    void removeScreen(screen *p_screen) {
      std::erase(screens, p_screen);
    }
};
#endif //SCREEN_H
