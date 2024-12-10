//
// Created by rei on 12/6/24.
//

#ifndef PROJECTDUNGEONDESPOILER_PLAYER_H
#define PROJECTDUNGEONDESPOILER_PLAYER_H

#include "Entity.h"
#include <SDL.h>
#include <vector>
namespace DespoilerEngine {

class Player final : public Entity {
public:
  Player(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
  static const int p_Width = 50;
  static const int p_Height = 50;


  // Velocity of the player
  static const int p_vel = 5;

  void handleEvent(SDL_Event &e) override;
  [[maybe_unused]] std::vector<SDL_Rect>& getColliders();

private:
  bool moveLeft = false;
  bool moveRight = false;
  bool moveUp = false;
  bool moveDown = false;

  std::vector<SDL_Rect> pColliders;

};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_PLAYER_H
