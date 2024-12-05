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
  Scene::Scene()
  = default;


  SDL_Texture *Scene::loadTexture(const char *p_filePath) {
      SDL_Texture* texture = nullptr;
      texture = IMG_LoadTexture(renderer.get(), p_filePath);

      if (texture == nullptr)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

      return texture;
  }

  void Scene::loadIcon(const char *p_filePath) {
    SDL_Surface* icon = nullptr;
    icon = IMG_Load(p_filePath);
    if (icon == nullptr) std::cout <<"Failed to load texture. Error: " << SDL_GetError() << std::endl;

    SDL_SetWindowIcon(MainWindow.get(), icon);
  }

  void Scene::render(Entity &p_entity) {
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

    SDL_RenderCopyEx(renderer.get(), p_entity.getTex(), &src, &dst, p_entity.getAngle(), nullptr, SDL_FLIP_NONE);
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

    SDL_RenderCopy(renderer.get(), p_tex, &src, &dst);
  }

  void Scene::render(TTF_Font* font, std::pmr::vector<TextDisplay> Texts) const {
    for (const auto [text, x, y, color] : Texts) {
      const SDL_Color textColor = color;
      renderText(renderer.get(), font, text, x, y, textColor);
    }
  }


  void Scene::render(const float p_x, const float p_y, const char *p_text, TTF_Font *font,
                     const SDL_Color textColor) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    if (!surfaceMessage) {
      std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
      return;
    }
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer.get(), surfaceMessage);
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
    dst.x = p_x;
    dst.y = p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer.get(), message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
  }

  void Scene::renderCenter(const float p_x, const float p_y, const char *p_text,
                           TTF_Font *font, const SDL_Color textColor) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid( font, p_text, textColor);
    if (!surfaceMessage) {
      std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
      return;
    }
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer.get(), surfaceMessage);
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
    dst.x = SCREEN_WIDTH/2 - src.w/2 + p_x;
    dst.y = SCREEN_HEIGHT/2 - src.h/2 + p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer.get(), message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
  }

  void Scene::clear() const {
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(renderer.get());
  }


  void Scene::display() {
    SDL_RenderPresent(renderer.get());
  }

}
