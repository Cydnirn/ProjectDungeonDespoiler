//
// Created by rei on 12/5/24.
//

#ifndef SCREEN_H
#define SCREEN_H
#include "Game.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <algorithm>
#include <string>
#include <vector>

namespace DespoilerEngine {

typedef struct TextDisplay {
  const char* text;
  int x;
  int y;
  SDL_Color color;
} TextDisplay;

struct MenuOption{
  std::string text;
  SDL_Rect rect;
};

class Screen {
public:
  virtual ~Screen() = default;
  Screen(SDL_Window* p_window, SDL_Renderer* p_renderer, const int* p_width,
         const int* p_height)
      : s_window(p_window), s_renderer(p_renderer), SCREEN_WIDTH(p_width),
        SCREEN_HEIGHT(p_height) {};
  virtual void handleEvents(SDL_Event& event, bool& isRunning, int& currentIndex) = 0;
  virtual void clear() const = 0;
  virtual void cleanUp() const = 0;
  virtual void init()  = 0;
  virtual void run(int &state) const = 0;
  virtual void render(int x, int y, SDL_Texture* p_tex) const = 0;
  virtual void render(TTF_Font *font,
                      std::pmr::vector<TextDisplay> Texts) const = 0;
  static void renderText(SDL_Renderer *renderer, TTF_Font *font,
                         const std::string &text, const int x, const int y,
                         const SDL_Color color) {
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    const SDL_Rect textRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &textRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  }
  static void renderText(SDL_Renderer *renderer, TTF_Font *font,
                         const std::string &text, const int x, const int y,
                         const SDL_Color color, SDL_Rect* outRect) {
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    //Set Rect
    outRect->x = x;
    outRect->y = y;
    outRect->w = surface->w;
    outRect->h = surface->h;
    SDL_RenderCopy(renderer, texture, nullptr, outRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  }
protected:
  SDL_Window * s_window;
  SDL_Renderer * s_renderer;
  const int * SCREEN_WIDTH;
  const int * SCREEN_HEIGHT;
};
}
#endif //SCREEN_H
