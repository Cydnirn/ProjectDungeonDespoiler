//
// Created by rei on 31.10.24.
//

#ifndef GAME_H
#define GAME_H
#include <cstdint>
#include <ncurses.h>

namespace ProjectDungeonDespoiler {

class Game {

public:
    static int init();
    void run();
    static void close();

private:
    static void drawBox(WINDOW* window, int pos_y = 0, int pos_x = 0, bool refresh = true);
    static void enableKeyBlockInput(WINDOW* window);

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

public:
    typedef struct
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
