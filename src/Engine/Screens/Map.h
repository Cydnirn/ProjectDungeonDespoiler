//
// Created by rei on 12/5/24.
//

#ifndef MAP_H
#define MAP_H
#include "../Scene.h"
#include "../Game.h"

namespace DespoilerEngine {

class Map final : public Scene{
public:
  ~Map() override;
  Map();
  void init() override;
  void run(int &state) const override;
  void cleanUp() const override;
  void handleEvents(SDL_Event &event, bool &isRunning,
                    int &currentIndex) const override;

private:
  mutable SDL_Texture *BgTextureMain;
};

} // DespoilerEngine

#endif //MAP_H
