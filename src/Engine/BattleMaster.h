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
  explicit BattleMaster(std::shared_ptr<Player> player);
  ~BattleMaster();
  static std::unique_ptr<BattleMaster> getInstance(std::shared_ptr<Player> player);
  void init();
  void push_creature(const Creature& creature);
  void del_creature(int index);
  void runBattle(Creature &attacker, std::shared_ptr<Player> &defender);
  void runBattle(std::shared_ptr<Player> &attacker, Creature &defender);
  void clear();

private:
  std::vector<Creature> CreatureParticipant;
  std::shared_ptr<Player> PlayerParticipant;
  uint32_t turn = 0;

public:
  //Getter
  [[nodiscard]] std::vector<Creature>& getCreatureParticipant()  { return CreatureParticipant; };
  [[nodiscard]] std::shared_ptr<Player>& getPlayerParticipant()  { return PlayerParticipant; };
  [[nodiscard]] const uint32_t& getTurn() { return turn; };
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_BATTLEMASTER_H
