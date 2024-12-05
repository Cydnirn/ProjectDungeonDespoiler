//
// Created by rei on 01.11.24.
//

#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "Screen.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace DespoilerEngine
{

class Scene : public Screen {
public:
  ~Scene() override = default;
  Scene(const char *p_title, int p_w, int p_h, bool newWindow = true);
  Scene(const std::string &p_title, int p_w, int p_h);
  SDL_Texture *loadTexture(const char *p_filePath) const;
  static void loadIcon(const char *p_filePath);
  void render(Entity& p_entity) const;
  void render(int x, int y, SDL_Texture *p_tex) const override;
  void render(TTF_Font *font, std::pmr::vector<TextDisplay> Texts) const override;
  void render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor) const;
  void renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor) const;
  void display() const;
};

}


#endif //SCENE_H
