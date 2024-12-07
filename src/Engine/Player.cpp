//
// Created by rei on 12/6/24.
//

#include "Player.h"
#include <SDL_image.h>
#include <iostream>

namespace DespoilerEngine {
  Player::Player(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst, SDL_Renderer *p_renderer): Entity(texture, src, dst), pRenderer(p_renderer) {
    this->e_texture = texture;
    this->e_src = src;
    this->e_dst = dst;
  }

  void Player::handleEvent(SDL_Event &e) {
    // If a key was pressed
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
              e_dst.y -= p_vel;
              break;
            case SDLK_DOWN:
            case SDLK_s:
              e_dst.y += p_vel;
              break;
            case SDLK_LEFT:
            case SDLK_a:
              e_dst.x -= p_vel;
              break;
            case SDLK_RIGHT:
            case SDLK_d:
              e_dst.x += p_vel;
              break;
        }
    }
  }

  [[maybe_unused]] std::vector<SDL_Rect>& Player::getColliders() {
    return pColliders;
  }

} // namespace DespoilerEngine