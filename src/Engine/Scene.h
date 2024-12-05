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
  Scene();
  static SDL_Texture *loadTexture(const char *p_filePath);
  static void loadIcon(const char *p_filePath);
  static void render(Entity& p_entity) ;
  void clear() const override;
  void render(int x, int y, SDL_Texture *p_tex) const override;
  void render(TTF_Font *font, std::pmr::vector<TextDisplay> Texts) const override;
  static void render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor) ;
  static void renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor) ;
  static void display() ;
};

}


#endif //SCENE_H
