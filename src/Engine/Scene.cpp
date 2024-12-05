//
// Created by rei on 01.11.24.
//
#include "Scene.h"
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "Game.h"

namespace DespoilerEngine
{
  Scene::Scene(const char* p_title, const int p_w, const int p_h, bool newWin)
  {

  }

 Scene::Scene(const std::string &p_title, const int p_w, const int p_h) {

  }


  SDL_Texture *Scene::loadTexture(const char *p_filePath) {
      SDL_Texture* texture = nullptr;
      texture = IMG_LoadTexture(renderer, p_filePath);

      if (texture == nullptr)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

      return texture;
  }

  void Scene::loadIcon(const char *p_filePath) {
    SDL_Surface* icon = nullptr;
    icon = IMG_Load(p_filePath);
    if (icon == nullptr) std::cout <<"Failed to load texture. Error: " << SDL_GetError() << std::endl;

    SDL_SetWindowIcon(MainWindow, icon);
  }

  void Scene::render(Entity &p_entity) const {
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x + (p_entity.getCurrentFrame().w - p_entity.getCurrentFrame().w*p_entity.getScale().x)/2;
    dst.y = p_entity.getPos().y + (p_entity.getCurrentFrame().h - p_entity.getCurrentFrame().h*p_entity.getScale().y)/2;
    dst.w = p_entity.getCurrentFrame().w*p_entity.getScale().x;
    dst.h = p_entity.getCurrentFrame().h*p_entity.getScale().y;

    SDL_RenderCopyEx(renderer, p_entity.getTex(), &src, &dst, p_entity.getAngle(), nullptr, SDL_FLIP_NONE);
  }

  void Scene::render(int x, int y, SDL_Texture *p_tex) const {
    SDL_Rect src;
    src.x = 0;
    src. y = 0;
    //src.w;
    //src.h;

    SDL_QueryTexture(p_tex, nullptr, nullptr, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, p_tex, &src, &dst);
  }

  void Scene::render(TTF_Font* font, std::pmr::vector<TextDisplay> Texts) const {
    for (const auto [text, x, y, color] : Texts) {
      const SDL_Color textColor = color;
      renderText(renderer, font, text, x, y, textColor);
    }
  }


  void Scene::render(float p_x, float p_y, const char *p_text, TTF_Font *font,
                     SDL_Color textColor) const {
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = p_x;
    dst.y = p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
  }

  void Scene::renderCenter(float p_x, float p_y, const char *p_text,
                           TTF_Font *font, SDL_Color textColor) const {
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = SCREEN_WIDTH/2 - src.w/2 + p_x;
    dst.y = SCREEN_HEIGHT/2 - src.h/2 + p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
  }

  void Scene::display() const {
    SDL_RenderPresent(renderer);
  }

}
