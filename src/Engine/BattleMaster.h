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
  BattleMaster(std::shared_ptr<Player> player);
  ~BattleMaster();
  static std::unique_ptr<BattleMaster> getInstance(std::shared_ptr<Player> player);
  void init();
  void push_creature(const Creature& creature);
  void endBattle();
  void runBattle();
  void runBattle(int &state);
  void AttackLog();
  void handleEvents();
  void clear();

private:
  std::vector<Creature> CreatureParticipant;
  std::shared_ptr<Player> PlayerParticipant;
  uint32_t turn = 0;

public:
  //Getter
  [[nodiscard]] const std::vector<Creature>& getCreatureParticipant() const { return CreatureParticipant; };
  [[nodiscard]] const std::shared_ptr<Player>& getPlayerParticipant() const { return PlayerParticipant; };
  [[nodiscard]] const uint32_t& getTurn() const { return turn; };
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_BATTLEMASTER_H
