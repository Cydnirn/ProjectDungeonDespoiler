//
// Created by rei on 12/10/24.
//

#include "BattleMaster.h"
#include <memory>
#include <vector>
#include <memory>
#include "Creature.h"

namespace DespoilerEngine {
  BattleMaster::BattleMaster( std::shared_ptr<Player> player)
    :PlayerParticipant(std::move(player)){}

  std::unique_ptr<BattleMaster> BattleMaster::getInstance(std::shared_ptr<Player> player) {
    return std::make_unique<BattleMaster>(std::move(player));
  }

  void BattleMaster::push_creature(const Creature& creature) {
    if(CreatureParticipant.size() >= 3){
      CreatureParticipant.clear();
    }
    CreatureParticipant.emplace_back(creature);
    for(auto &creatureNew: CreatureParticipant){
      printf("Creature: %s \n", creatureNew.getName().c_str());
    }
  }

  void BattleMaster::init() {
    printf("BattleMaster is initialized \n");
    printf("Player: %s \n", PlayerParticipant->getName().c_str());
  }

  void BattleMaster::runBattle() {
        printf("Battle is running");
  }

  void BattleMaster::runBattle(int &state) {
    printf("Battle is running");
  }

  void BattleMaster::AttackLog() {
    printf("Attack log");
  }

  void BattleMaster::handleEvents(){
  }

  void BattleMaster::clear() {
    printf("BattleMaster is cleared \n");
    CreatureParticipant.clear();
  }

  void BattleMaster::endBattle() {
        printf("Battle has ended");
  }

  BattleMaster::~BattleMaster() {
    printf("BattleMaster is destroyed \n");
    BattleMaster::clear();
  }

} // namespace DespoilerEngine