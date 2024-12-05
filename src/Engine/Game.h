//
// Created by rei on 31.10.24.
//

#ifndef GAME_H
#define GAME_H
#include <SDL_ttf.h>
#include <cstdint>
#include <string>

namespace DespoilerEngine {
inline auto Title = new std::string("Dungeon Despoiler");
inline int SCREEN_WIDTH = 720;
inline int SCREEN_HEIGHT = 480;
inline SDL_Window *MainWindow = SDL_CreateWindow(Title->c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);;
inline SDL_Renderer* renderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

class Game {
public:
    static TTF_Font *font;
    static int init();
    static void run();
    static void close();

private:
    typedef struct
    {
        uint_fast8_t x;
        uint_fast8_t y;
    } vec2ui;

    typedef struct
    {
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

private:
    struct
    {
        vec2i position;
        rect bounds;
        char display_char;
    } player = {};
};

} // ProjectDungeonDespoiler

#endif //GAME_H
