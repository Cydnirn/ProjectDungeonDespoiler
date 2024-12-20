//
// Created by rei on 12/9/24.
//

#include "Battle.h"

#include "../RandomGenerator.h"
#include <iostream>
#include <utility>

namespace DespoilerEngine {
  BattleScene::BattleScene(SDL_Window *s_window,
                         SDL_Renderer *s_renderer,
                         const int *p_width,
                         const int *p_height,
                         std::shared_ptr<CreatureCollection> creatures,
                         std::shared_ptr<Player> player
                         )
  : Scene(s_window, s_renderer, p_width, p_height),
      BgTextureBattle(nullptr),
      Creatures(std::move(creatures)),
      player(std::move(player)),
      Master(nullptr)
{}

  void BattleScene::init() {
    //Set default values
    selected = 0;c_selected = 0;isPlayer = true, s_menu = true, s_creature = false;
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

  void BattleScene::run(int &state) {
    clear();
    this->render(0,0,BgTextureBattle);
    int screenWidth = *this->getScreenWidth();
    unsigned long creatureCount = Master->getCreatureParticipant().size();
    if(creatureCount == 0){
      return;
    }
    int creatureWidth = screenWidth / static_cast<int>(creatureCount);
    for(size_t i = 0; i < creatureCount; i++){
      SDL_Color color = (i == c_selected && s_creature)  ? SDL_Color{255,0,0,0} : SDL_Color{255,255,255,0};
      int xPos = i * creatureWidth;
      std::string healthStatus = std::to_string(Master->getCreatureParticipant()[i].getHealth()) + "/" + std::to_string(Master->getCreatureParticipant()[i].getMaxHealth());
      this->render(xPos + 15 + Master->getCreatureParticipant()[i].getName().length() * 5, 25, Master->getCreatureParticipant()[i].getName().c_str(), Game::font, color);
      this->render(xPos + 15 + Master->getCreatureParticipant()[i].getName().length() * 5, 50, healthStatus.c_str() , Game::font, color);
      if(i == c_selected){
        SDL_RenderDrawLine(this->s_renderer, xPos, 0, xPos + creatureWidth, 0);
      }
      auto CreatureTexture = loadTexture(Master->getCreatureParticipant()[i].getTexture().c_str());
      this->renderScaled(xPos + 15 + Master->getCreatureParticipant()[i].getName().length() * 5,105,CreatureTexture, 100, 100);
    }
    for(size_t i = 0; i < BattleOptions.size(); i++){
      SDL_Color color = (i == selected)  ? SDL_Color{255,0,0,0} : SDL_Color{255,255,255,0};
      renderText(this->s_renderer, Game::font, BattleOptions[i].text, BattleOptions[i].rect.x, BattleOptions[i].rect.y, color);
      if(i == selected) {
        SDL_RenderDrawLine(this->s_renderer, BattleOptions[i].rect.x, BattleOptions[i].rect.y + BattleOptions[i].rect.h, BattleOptions[i].rect.x + BattleOptions[i].rect.w, BattleOptions[i].rect.y + BattleOptions[i].rect.h);
      }
    }
    renderText(this->s_renderer, Game::font, "Player", 400, 300, {255,255,255,0});
    std::string playerHealth = std::to_string(player->getHealth()) + "/" + std::to_string(player->getMaxHealth());
    renderText(this->s_renderer, Game::font, playerHealth, 400, 350, {255,255,255,0});
    if(!isPlayer){
        SDL_Rect textRect = {400,400, 300, 5};
        for(auto &Creature: Master->getCreatureParticipant()) {
            clearRect(textRect);
            renderText(this->s_renderer,
                             Game::font,
                             Creature.getName() + " turn", 400, 400,
                             {255, 255, 255, 0});
            display();
            SDL_Delay(1500);
            SDL_PumpEvents();
            Master->runBattle(Creature, Master->getPlayerParticipant());
        }
        s_creature = false, s_menu = true;
        isPlayer = true;
    }
    display();
  }

  void BattleScene::handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex)  {
    if(Master->getCreatureParticipant().empty()){
      currentIndex = 1;
      return;
    }
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
          if(s_creature) {
            s_creature = false;
            s_menu = true;
          }
          //currentIndex = 1;
          break;
        case SDLK_RETURN:
        case SDLK_KP_ENTER:
          if(s_menu && selected == 0) {
            s_menu = false;
            s_creature = true;
            break;
          }
          if(s_creature) {
            if(isPlayer){
              Master->runBattle(Master->getPlayerParticipant(), Master->getCreatureParticipant()[c_selected]);
              if(Master->getCreatureParticipant()[c_selected].getHealth() <= 0){
                Master->del_creature(c_selected);
                if(c_selected >= Master->getCreatureParticipant().size()){
                  c_selected = 0;
                }
              }
              isPlayer = false;
            }
            break;
          }
          break;
        case SDLK_UP:
          if(s_menu){
            selected = (selected - 1 + BattleOptions.size()) % BattleOptions.size();
          }
          break;
        case SDLK_DOWN:
          if(s_menu){
            selected = (selected + 1) % BattleOptions.size();
          }
          break;
        case SDLK_RIGHT: //Select Creature
          if(s_creature){
            c_selected = (c_selected + 1) % Master->getCreatureParticipant().size();
          }
          break;
        case SDLK_LEFT: //Select Creature
          if(s_creature){
            c_selected = (c_selected - 1 + Master->getCreatureParticipant().size()) % Master->getCreatureParticipant().size();
          }
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
    if(Master){
      Master->clear();
      Master = nullptr;
    }
  }

  BattleScene::~BattleScene(){
    cleanUp();
  }

} // namespace DespoilerEngine