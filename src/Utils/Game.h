//
// Created by rei on 31.10.24.
//

#ifndef GAME_H
#define GAME_H
#include <cstdint>

namespace ProjectDungeonDespoiler {

class Game {

public:
    static int init();
    void run();
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

    struct
    {
        vec2i position;
        char display_char;
    } player = {};
};

} // ProjectDungeonDespoiler

#endif //GAME_H
