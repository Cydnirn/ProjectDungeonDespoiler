//
// Created by rei on 12/4/24.
//

#ifndef MATH_H
#define MATH_H
#include <iostream>

struct Vector2f
{
  Vector2f()
  :x(0.0f), y(0.0f)
  {}

  Vector2f(float p_x, float p_y)
  :x(p_x), y(p_y)
  {}

  float x, y;
};

#endif //MATH_H
