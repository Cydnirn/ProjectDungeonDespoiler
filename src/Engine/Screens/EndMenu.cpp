//
// Created by rei on 12/19/24.
//

#include "EndMenu.h"

namespace DespoilerEngine {
    EndMenu::EndMenu(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width, const int *p_height) :
    Scene(p_window, p_renderer, p_width, p_height), BgTextureMain(nullptr){}

    void EndMenu::init() {
        loadIcon("./resources/Textures/icon.ico");
        BgTextureMain = loadTexture("./resources/Textures/background.png");
    }

    void EndMenu::run(int &state){
        clear();
        render(0,0,BgTextureMain);
        renderCenter(0,0,"You Win!", Game::font, {255,255,255,0});
        renderCenter(0,50,"Press Q or Escape to quit.", Game::font, {255,255,255,0});
        display();
    }

    void EndMenu::handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex) {
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        if(event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym) {
                case SDLK_q:
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }
    }

    void EndMenu::cleanUp() const {
        if(BgTextureMain){
            SDL_DestroyTexture(BgTextureMain);
            BgTextureMain = nullptr;
        }
        SDL_DestroyRenderer(this->s_renderer);
    }

    EndMenu::~EndMenu(){
        cleanUp();
    }


} // DespoilerEngine