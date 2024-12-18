//
// Created by rei on 12/6/24.
//

#ifndef PROJECTDUNGEONDESPOILER_ENTITY_H
#define PROJECTDUNGEONDESPOILER_ENTITY_H
#include <SDL.h>

namespace DespoilerEngine {

class Entity {
public:
  virtual ~Entity() = default;
  Entity(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst)
      : e_texture(texture), e_src(src), e_dst(dst) {}
  virtual void handleEvent(SDL_Event &e, int &index, bool collision) = 0;
  SDL_Texture* e_texture;
  SDL_Rect e_src, e_dst;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_ENTITY_H
