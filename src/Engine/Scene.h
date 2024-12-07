//
// Created by rei on 01.11.24.
//

#ifndef SCENE_H
#define SCENE_H

#include "Screen.h"
#include "Entity.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace DespoilerEngine
{

class Scene : public Screen {
public:
  ~Scene() override = default;
  Scene(SDL_Window* p_window, SDL_Renderer* p_renderer, const int* p_width, const int* p_height);
  SDL_Texture *loadTexture(const char *p_filePath) const;
  void loadIcon(const char *p_filePath) const;
  void clear() const override;
  void render(Entity& entity) const;
  void render(int x, int y, SDL_Texture *p_tex) const override;
  void render(TTF_Font *font, std::pmr::vector<TextDisplay> Texts) const override;
  void render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor) const;
  void renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor) const;
  void display() const;
};

}


#endif //SCENE_H
