//
// Created by rei on 12/10/24.
//

#ifndef PROJECTDUNGEONDESPOILER_BATTLEMASTER_H
#define PROJECTDUNGEONDESPOILER_BATTLEMASTER_H
#pragma once
#include <vector>
#include "Creature.h"
#include "Player.h"
#include <memory>

namespace DespoilerEngine {

class BattleMaster {
public:
  BattleMaster(std::vector<Creature> creatures, std::shared_ptr<Player> player);
  ~BattleMaster();
  void startBattle();
  void endBattle();
  void runBattle();
  void runBattle(int &state);
  void AttackLog();
  void handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex);
  void clear();
private:
  std::vector<Creature> CreatureParticipant;
  std::shared_ptr<Player> PlayerParticipant;
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_BATTLEMASTER_H
