//
// Created by rei on 12/5/24.
//

#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
typedef struct TextDisplay {
  const char* text;
  int x;
  int y;
  SDL_Color color;
} TextDisplay;
class Screen {
public:
  virtual ~Screen() = default;
  virtual void handleEvents(SDL_Event& event, bool& isRunning, int& currentIndex) const = 0;
  virtual void clear() const = 0;
  virtual void render(int x, int y, SDL_Texture* p_tex) const = 0;
  virtual void render(TTF_Font *font,
                      std::pmr::vector<TextDisplay> Texts) const = 0;
  static void renderText(SDL_Renderer *renderer, TTF_Font *font,
                  const std::string &text, const int x, const int y,
                  const SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    const SDL_Rect textRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &textRect);
  }
};

class ScreenLoader {
  public:
    std::vector<Screen*> screens;
    void addScreen(Screen *p_screen) {
      screens.push_back(p_screen);
    }
    void removeScreen(Screen *p_screen) {
      std::erase(screens, p_screen);
    }
};
#endif //SCREEN_H
