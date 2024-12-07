//
// Created by rei on 01.11.24.
//
#include "Scene.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

namespace DespoilerEngine
{
  Scene::Scene(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width,
             const int *p_height)
    : Screen(p_window, p_renderer,p_width,p_height) {}

SDL_Texture *Scene::loadTexture(const char *p_filePath) const {
      SDL_Texture* texture = nullptr;
      texture = IMG_LoadTexture(this->s_renderer, p_filePath);

      if (texture == nullptr)
        std::cerr << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

      return texture;
  }

  void Scene::loadIcon(const char *p_filePath) const {
    SDL_Surface* icon = nullptr;
    icon = IMG_Load(p_filePath);
    if (icon == nullptr) std::cout <<"Failed to load texture. Error: " << SDL_GetError() << std::endl;

    SDL_SetWindowIcon(this->s_window, icon);
    SDL_FreeSurface(icon);
  }

  void Scene::render(Entity &entity) const {
    SDL_RenderCopy(this->s_renderer, entity.e_texture, &entity.e_src, &entity.e_dst);
  }
  

  void Scene::render(int x, int y, SDL_Texture *p_tex) const {
    static int tex_w = 0;
    static int tex_h = 0;

    if (tex_w == 0 && tex_h == 0) {
      SDL_QueryTexture(p_tex, nullptr, nullptr, &tex_w, &tex_h);
    }
    SDL_Rect src;
    src.x = 0;
    src. y = 0;
    src.w = tex_w;
    src.h = tex_h;

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(this->s_renderer, p_tex, &src, &dst);
  }

  void Scene::render(TTF_Font* font, std::pmr::vector<TextDisplay> Texts) const {
    for (const auto [text, x, y, color] : Texts) {
      const SDL_Color textColor = color;
      renderText(this->s_renderer, font, text, x, y, textColor);
    }
  }


  void Scene::render(const float p_x, const float p_y, const char *p_text, TTF_Font *font,
                     const SDL_Color textColor) const {
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    if (!surfaceMessage) {
      std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
      return;
    }
    SDL_Texture* message = SDL_CreateTextureFromSurface(this->s_renderer, surfaceMessage);
    if (!message) {
      std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
      SDL_FreeSurface(surfaceMessage);
      return;
    }


    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = static_cast<int>(p_x);
    dst.y = static_cast<int>(p_y);
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(this->s_renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
  }

  void Scene::renderCenter(const float p_x, const float p_y, const char *p_text,
                           TTF_Font *font, const SDL_Color textColor) const {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid( font, p_text, textColor);
    if (!surfaceMessage) {
      std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
      return;
    }
    SDL_Texture* message = SDL_CreateTextureFromSurface(this->s_renderer, surfaceMessage);
    if (!message) {
      std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
      SDL_FreeSurface(surfaceMessage);
      return;
    }

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = *this->SCREEN_WIDTH / 2 - src.w/2 + p_x;
    dst.y = *this->SCREEN_HEIGHT/2 - src.h/2 + p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(this->s_renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
  }

  void Scene::clear() const {
    SDL_SetRenderDrawColor(this->s_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->s_renderer);
  }


  void Scene::display() const {
    SDL_RenderPresent(this->s_renderer);
  }

}
