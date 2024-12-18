//
// Created by rei on 12/6/24.
//

#include "Player.h"
#include "RandomGenerator.h"
#include <SDL_image.h>
#include <iostream>

namespace DespoilerEngine {
  Player::Player(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst)
    : Entity(texture, src, dst),
      Creature("Player",
               "The player",
               {10,10,10,10}) {
    this->e_texture = texture;
    this->e_src = src;
    this->e_dst = dst;
    this->inventory->addItem(Game::ItemsCol->getItem("Sword").name, Game::ItemsCol->getItem("Sword"));
    this->setBaseDamage(this->inventory->get("Sword")->base);
  }

  void Player::handleEvent(SDL_Event &e, int &index, bool collision) {
    // If a key was pressed
    auto state = SDL_GetKeyboardState(nullptr);
    moveUp = (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) > 0;
    moveDown = (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) > 0;
    moveLeft = (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) > 0;
    moveRight = (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) > 0;
    if(e.type == SDL_KEYDOWN){
      bool toBattle = RandomGenerator::generateRandomFloat(1.00, 100.00) < battle_chance;
      if(toBattle) index = 2;
    }
    SDL_Rect prevPos = e_dst;
    std::cout << "Player previous position: " << prevPos.x << ", " << prevPos.y << std::endl;
    if(!collision){
        if(moveUp) e_dst.y -= p_vel;
        if(moveDown) e_dst.y += p_vel;
        if(moveLeft) e_dst.x -= p_vel;
        if(moveRight) e_dst.x += p_vel;
    }else {
        e_dst = prevPos;
    }

    std::cout << "Player position: " << e_dst.x << ", " << e_dst.y << std::endl;
  }

  [[maybe_unused]] std::vector<SDL_Rect>& Player::getColliders() {
    return pColliders;
  }

} // namespace DespoilerEngine