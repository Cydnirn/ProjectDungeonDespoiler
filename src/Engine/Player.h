//
// Created by rei on 12/6/24.
//

#ifndef PROJECTDUNGEONDESPOILER_PLAYER_H
#define PROJECTDUNGEONDESPOILER_PLAYER_H

#include "Creature.h"
#include "Entity.h"
#include "Game.h"
#include "Inventory.h"
#include "Stats.h"
#include <SDL.h>
#include <memory>
#include <vector>

namespace DespoilerEngine {

class Player final : public Entity, public Creature {
public:
  Player(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
  ~Player() override = default;
  static const int p_Width = 25;
  static const int p_Height = 25;
  const float battle_chance = 2.0;

  // Velocity of the player
  static const int p_vel = 5;

  //Getter
  [[nodiscard]] SDL_Rect getRect() const { return e_dst; }

  void handleEvent(SDL_Event &e, int &index, bool &collision) override;
  [[maybe_unused]] std::vector<SDL_Rect>& getColliders();
  std::shared_ptr<Items> Weapon;


private:
  bool moveLeft = false;
  bool moveRight = false;
  bool moveUp = false;
  bool moveDown = false;
  std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>();
  int health = 10 * this->getStats().vigor;


  std::vector<SDL_Rect> pColliders;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_PLAYER_H
