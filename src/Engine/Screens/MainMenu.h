//
// Created by rei on 12/5/24.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include "../Scene.h"
#include "../Game.h"

namespace DespoilerEngine {

class MainMenu final : public Scene {
public:
  ~MainMenu() override;
  MainMenu();
  void init() override;
  void run(int &state) const override;
  void cleanUp() const override;
  void handleEvents(SDL_Event &event, bool &isRunning,
                    int &currentIndex) const override;

private:
  mutable SDL_Texture *BgTextureMain;
};
} // DespoilerEngine

#endif //MAINMENU_H
