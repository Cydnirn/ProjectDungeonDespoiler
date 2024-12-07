//
// Created by rei on 31.10.24.
//

#ifndef GAME_H
#define GAME_H
#include <SDL_ttf.h>
#include <cstdint>
#include <vector>

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

    static void loadCreature();

public:
    typedef struct rect
    {
        vec2i offset;
        vec2i bounds;
        [[nodiscard]] uint_fast16_t top() const {return  offset.y;}
        [[nodiscard]] uint_fast16_t bottom() const {return offset.y + bounds.y;}
        [[nodiscard]] uint_fast16_t left() const {return offset.x;}
        [[nodiscard]] uint_fast16_t right() const {return offset.x + bounds.x;}

        [[nodiscard]] uint_fast16_t width() const {return bounds.x;}
        [[nodiscard]] uint_fast16_t height() const {return bounds.y;}

        [[nodiscard]] bool contains (const vec2i a) const{return (a.x >= offset.x && a.x < right()) &&
            (a.y >= offset.y && a.y < bottom());}
    } rect;

};

} // ProjectDungeonDespoiler

#endif //GAME_H
