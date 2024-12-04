//
// Created by rei on 12/4/24.
//
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.h"
#ifndef ENTITY_H
#define ENTITY_H

namespace DespoilerEngine {

class Entity {
public:
  Entity(Vector2f p_pos, SDL_Texture* p_tex);
  Vector2f& getPos()
  {
    return pos;
  }
  float getAngle()
  {
    return angle;
  }
  Vector2f getScale()
  {
    return scale;
  }
  void setPos(float x, float y);
  void setScale(float w, float h);
  void setAngle(float angle);
  SDL_Texture *getTex() const;
  static void update(double deltaTime);
  SDL_Rect getCurrentFrame() const;
private:
  Vector2f pos;
  float angle = 0;
  Vector2f scale = Vector2f(1, 1);
  SDL_Rect currentFrame{};
  SDL_Texture* tex;
};

} // DespoilerEngine

#endif //ENTITY_H
