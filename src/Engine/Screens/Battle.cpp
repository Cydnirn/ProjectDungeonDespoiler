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
      BgTextureBattle(nullptr), Creatures(creatures), player(player), Master(nullptr){}

  void BattleScene::init() {
    loadIcon("./resources/Textures/icon.ico");
    BgTextureBattle = loadTexture("./resources/Textures/background.png");
    //Generate number of creature spawned
    if(!Master){
      Master = BattleMaster::getInstance(player);
      Master->init();
    }
    int numCreatures = RandomGenerator::generateRandomNumber(1, 3);
    for(int i = 0; i < numCreatures; i++){
          Master->push_creature(Creatures->spawnRandomCreature());
    }
  }

  void BattleScene::run(int &state) const{
    clear();
    this->render(0,0,BgTextureBattle);
    int creatureCount = Master->getCreatureParticipant().size();
    int screenWidth = *this->getScreenWidth();
    int screenHeight = *this->getScreenHeight();
    int creatureWidth = screenWidth / creatureCount;
    for(size_t i = 0; i < creatureCount; i++){
      int xPos = i * creatureWidth;
      std::string healthStatus = std::to_string(Master->getCreatureParticipant()[i].getHealth()) + "/" + std::to_string(Master->getCreatureParticipant()[i].getMaxHealth());
      this->render(xPos + 15 + Master->getCreatureParticipant()[i].getName().length() * 5, 25, Master->getCreatureParticipant()[i].getName().c_str(), Game::font, {255,255,255, 0});
      this->render(xPos + 15 + Master->getCreatureParticipant()[i].getName().length() * 5, 50, healthStatus.c_str() , Game::font, {255,255,255, 0});
    }
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
          Master->clear();
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
    if(Master){
      Master->clear();
      Master = nullptr;
    }
  }

  BattleScene::~BattleScene(){
    cleanUp();
  }

} // namespace DespoilerEngine