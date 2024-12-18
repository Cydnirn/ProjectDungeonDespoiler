//
// Created by rei on 12/9/24.
//

#ifndef PROJECTDUNGEONDESPOILER_BATTLE_H
#define PROJECTDUNGEONDESPOILER_BATTLE_H
#include "../BattleMaster.h"
#include "../Creature.h"
#include "../CreatureCollection.h"
#include "../Player.h"
#include "../Scene.h"

namespace DespoilerEngine {

class BattleScene final : public Scene {
public:
  ~BattleScene() override;
  BattleScene(SDL_Window *s_window,
              SDL_Renderer *s_renderer,
              const int *p_width,
              const int *p_height,
              std::shared_ptr<CreatureCollection> creatures,
              std::shared_ptr<Player> player);
  void init() override;
  void run(int &state) override;
  void cleanUp() const override;
  void handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex) override;

private:
  int selected = 0, c_selected = 0;
  //s = selected, c = creature
  bool isPlayer = true, s_menu = true, s_creature = false;
  std::vector<MenuOption> BattleOptions = {
    {"Attack", {50, 300, 0, 0}},
    {"Defend", {50, 350, 0, 0}},
    {"Run", {50, 400, 0, 0}}
  };
  mutable SDL_Texture *BgTextureBattle;
  std::shared_ptr<CreatureCollection> Creatures;
  std::shared_ptr<Player> player;
  mutable std::unique_ptr<BattleMaster> Master;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_BATTLE_H
