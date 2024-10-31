//
// Created by rei on 31.10.24.
//

#include "Game.h"

#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <unistd.h>

WINDOW* window;

namespace ProjectDungeonDespoiler {
    int Game::init()
    {
        window = initscr();
        cbreak();
        noecho();
        clear();
        refresh();

        keypad(window, true);
        nodelay(window, true);
        curs_set(0); //Make cursor invisible
        if(!has_colors())
        {
            endwin();
            printf("Error: Terminal does not support color.\n");
            exit(1);
        }

        start_color();
        attron(A_BOLD);
        box(window, 0, 0);
        attroff(A_BOLD);

        return 0;
    }

    void Game::run()
    {
        player.display_char = *"0";
        player.position = {10, 5};
        refresh();
        /* Main game loop */
        bool exit_req = false;

        while(true)
        {
            mvaddch(player.position.y, player.position.x, ' ');
            switch (int in_char = wgetch(window))
            {
                case 'q':
                    exit_req = true;
                    break;
                case KEY_UP:
                case 'w':
                    player.position.y -=1;
                    break;
                case KEY_DOWN:
                case 's':
                    player.position.y += 1;
                    break;
                case KEY_LEFT:
                case 'a':
                    player.position.x -=1;
                    break;
                case KEY_RIGHT:
                case 'd':
                    player.position.x += 1;
                    break;
                default:
                    break;
            }
            mvaddch(player.position.y, player.position.x, player.display_char);
            refresh();
            if (exit_req) break;
            usleep(10000);
        };
    }

    void Game::close()
    {
        endwin();
    }

} // ProjectDungeonDespoiler