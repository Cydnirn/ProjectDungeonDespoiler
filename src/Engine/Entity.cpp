//
// Created by rei on 12/4/24.
//

#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>

namespace DespoilerEngine {
  Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
  :pos(p_pos), tex(p_tex)
  {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
    SDL_QueryTexture(p_tex, nullptr, nullptr, &currentFrame.w, &currentFrame.h);
  }

  SDL_Texture* Entity::getTex() const {
    return tex;
  }

  void Entity::update(double deltaTime)
  {

  }

  void Entity::setPos(float x, float y)
  {
    pos.x = x;
    pos.y = y;
  }

  void Entity::setAngle(float p_angle)
  {
    angle = p_angle;
  }

  void Entity::setScale(float w, float h)
  {
    scale.x = w;
    scale.y = h;
  }

  SDL_Rect Entity::getCurrentFrame() const {
    return currentFrame;
  }
} // DespoilerEngine