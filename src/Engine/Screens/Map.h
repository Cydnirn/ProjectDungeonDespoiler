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
      const int *p_height, std::shared_ptr<Player> player);
  void init() override;
  void run(int &state) override;
  void cleanUp() const override;
  void handleEvents(SDL_Event &event, bool &isRunning,
                    int &currentIndex)  override;

private:
  mutable SDL_Texture *BgTextureMain;
  mutable SDL_Texture *p_texture{};
  mutable SDL_Surface *p_img{};
  mutable SDL_Texture *WallTexture{};
  SDL_Rect WallRect{};
  std::shared_ptr<Player> player;
  mutable SDL_Texture *FinishTexture{};


  // Representasi peta
  std::vector<std::vector<int>> mapArray = {
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0},
    {0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,0 ,0 ,0 ,0 ,0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 ,0 ,1 ,1 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 ,0 ,0 ,1 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 2, 0, 1, 0 ,0 ,0 ,1 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 ,0 ,0 ,1 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 ,1 ,1 ,1 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0},
      {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0}
  };

  int tileSize = 25  ; // Ukuran setiap tile (px)
};

} // DespoilerEngine

#endif //MAP_H
