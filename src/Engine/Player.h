//
// Created by rei on 12/6/24.
//

#ifndef PROJECTDUNGEONDESPOILER_PLAYER_H
#define PROJECTDUNGEONDESPOILER_PLAYER_H

#include "Entity.h"
#include "Inventory.h"
#include "Game.h"
#include "Stats.h"
#include <SDL.h>
#include <memory>
#include <vector>

namespace DespoilerEngine {

class Player final : public Entity {
public:
  Player(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
  static const int p_Width = 50;
  static const int p_Height = 50;


  // Velocity of the player
  static const int p_vel = 10;

  void handleEvent(SDL_Event &e) override;
  [[maybe_unused]] std::vector<SDL_Rect>& getColliders();
  std::shared_ptr<Items> Weapon;

private:
  bool moveLeft = false;
  bool moveRight = false;
  bool moveUp = false;
  bool moveDown = false;

  Stats stats{10, 10, 10, 10};
  std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>();
  int health = 10 * stats.vigor;


  std::vector<SDL_Rect> pColliders;

};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_PLAYER_H
