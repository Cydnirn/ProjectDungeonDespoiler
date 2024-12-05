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
  ~MainMenu() override = default;
  MainMenu(const char *p_title, int p_w, int p_h);
  MainMenu(const std::string &p_title, int p_w, int p_h);
  void init() override;
  void run(int &state) const override;
  void clear() const override;
  void cleanUp() const override;
  void handleEvents(SDL_Event &event, bool &isRunning,
                    int &currentIndex) const override;

private:
  SDL_Texture *BgTextureMain;
};

inline auto main_menu_window = new MainMenu(*Title,SCREEN_WIDTH, SCREEN_HEIGHT);

} // DespoilerEngine

#endif //MAINMENU_H
