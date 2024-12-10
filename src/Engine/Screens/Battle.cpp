//
// Created by rei on 12/9/24.
//

#include "Battle.h"

namespace DespoilerEngine {
  BattleScene::BattleScene(SDL_Window *s_window, SDL_Renderer *s_renderer, const int *p_width, const int *p_height)
  : Scene(s_window, s_renderer, p_width, p_height){}

  void BattleScene::init() {
    loadIcon("./resources/Textures/icon.ico");
    BgTextureBattle = loadTexture("./resources/Textures/background.png");
  }

  void BattleScene::run(int &state) const{
    clear();
    this->render(0,0,BgTextureBattle);
    this->renderCenter(0, 0, "This is a battle scene", Game::font, {255,255,255, 0});
    display();
  }

  void BattleScene::handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex) const {
    if(event.type == SDL_QUIT){
      isRunning = false;
    }
    if(event.type == SDL_KEYDOWN){
      switch (event.key.keysym.sym) {
        case SDLK_q:
        case SDLK_ESCAPE:
          isRunning = false;
          break;
        case SDLK_BACKSPACE:
          currentIndex = 1;
          break;
        default:
          break;
      }
    }
  }

  void BattleScene::cleanUp() const {
    if(BgTextureBattle){
      SDL_DestroyTexture(BgTextureBattle);
      BgTextureBattle = nullptr;
    }
    SDL_DestroyRenderer(this->s_renderer);
  }

  BattleScene::~BattleScene(){
    cleanUp();
  }

} // namespace DespoilerEngine