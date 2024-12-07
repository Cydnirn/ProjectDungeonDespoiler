//
// Created by rei on 12/5/24.
//

#ifndef MAP_H
#define MAP_H
#include "../Game.h"
#include "../Player.h"
#include "../Scene.h"
#include <memory>

namespace DespoilerEngine {

class Map final : public Scene{
public:
  ~Map() override;
  Map(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width,
      const int *p_height);
  void init() override;
  void run(int &state) const override;
  void cleanUp() const override;
  void handleEvents(SDL_Event &event, bool &isRunning,
                    int &currentIndex) const override;

private:
  mutable SDL_Texture *BgTextureMain;
  mutable SDL_Texture *p_texture{};
  mutable SDL_Surface *p_img{};
  std::unique_ptr<Player> player;
};

} // DespoilerEngine

#endif //MAP_H
