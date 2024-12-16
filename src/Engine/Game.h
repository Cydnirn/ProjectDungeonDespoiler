//
// Created by rei on 31.10.24.
//

#ifndef GAME_H
#define GAME_H
#include <SDL_ttf.h>
#include <cstdint>
#include <vector>
#include <memory>
#include "ItemsCollection.h"

namespace DespoilerEngine {
class Game {
public:
    Game();
    ~Game() {
        printf("Game is destroyed");
    };
    SDL_Window* MainWindow{};
    SDL_Renderer* s_renderer{};
    int SCREEN_WIDTH{};
    int SCREEN_HEIGHT{};
    int fps{};
    int desiredDelta{}; //Desired time b/w frames
    static std::shared_ptr<ItemsCollection> ItemsCol;
    static TTF_Font *font;
    int init();
    void run() const;
    void close() const;
    static bool checkCollision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>&b);

private:
    typedef struct
    {
        uint_fast8_t x;
        uint_fast8_t y;
    } vec2ui;

    typedef struct {
      int_fast8_t x;
      int_fast8_t y;
    } vec2i;

    void loadEssentials();


};

} // ProjectDungeonDespoiler

#endif //GAME_H
