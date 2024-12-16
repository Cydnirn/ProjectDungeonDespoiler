//
// Created by rei on 12/9/24.
//

#include "Battle.h"
#include "../Game.h"
#include "../RandomGenerator.h"
#include "../BattleMaster.h"

namespace DespoilerEngine {
  BattleScene::BattleScene(SDL_Window *s_window,
                         SDL_Renderer *s_renderer,
                         const int *p_width,
                         const int *p_height,
                         std::shared_ptr<CreatureCollection> creatures,
                         std::shared_ptr<Player> player
                         )
  : Scene(s_window, s_renderer, p_width, p_height),
      BgTextureBattle(nullptr), Creatures(creatures), player(player){}

  void BattleScene::init() {
    loadIcon("./resources/Textures/icon.ico");
    BgTextureBattle = loadTexture("./resources/Textures/background.png");
    //Generate number of creature spawned
    int numCreatures = RandomGenerator::generateRandomNumber(1, 3);
    for(int i = 0; i < numCreatures; i++)
          CreaturesBattle.emplace_back(Creatures->spawnRandomCreature());
    Master = BattleMaster::getInstance(CreaturesBattle, player);
  }

  void BattleScene::run(int &state) const{
    clear();
    this->render(0,0,BgTextureBattle);
    this->renderCenter(0, 0, "This is a battle scene", Game::font, {255,255,255, 0});
    for(size_t i = 0; i < BattleOptions.size(); i++){
      SDL_Color color = (i == selected)  ? SDL_Color{255,0,0,0} : SDL_Color{255,255,255,0};
      this->renderText(this->s_renderer, Game::font, BattleOptions[i].text, BattleOptions[i].rect.x, BattleOptions[i].rect.y, color);
      if(i == selected) {
        SDL_RenderDrawLine(this->s_renderer, BattleOptions[i].rect.x, BattleOptions[i].rect.y + BattleOptions[i].rect.h, BattleOptions[i].rect.x + BattleOptions[i].rect.w, BattleOptions[i].rect.y + BattleOptions[i].rect.h);
      }
    }
    display();
  }

  void BattleScene::handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex)  {
    Master->handleEvents();
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
        case SDLK_UP:
          selected = (selected - 1 + BattleOptions.size()) % BattleOptions.size();
          break;
        case SDLK_DOWN:
          selected = (selected + 1) % BattleOptions.size();
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