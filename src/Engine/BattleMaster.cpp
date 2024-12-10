//
// Created by rei on 12/10/24.
//

#include "BattleMaster.h"
#include <vector>
#include <memory>
#include "Creature.h"

namespace DespoilerEngine {
  BattleMaster::BattleMaster(std::vector<Creature> creatures, std::shared_ptr<Player> player){
    this->CreatureParticipant = creatures;
    this->PlayerParticipant = std::move(player);
  }

  void BattleMaster::startBattle() {
    printf("Battle has started");
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

  void BattleMaster::handleEvents(SDL_Event &event, bool &isRunning, int &currentIndex) {

  }

  void BattleMaster::clear() {
    printf("BattleMaster is cleared");
  }

  void BattleMaster::endBattle() {
        printf("Battle has ended");
  }

  BattleMaster::~BattleMaster() {
    printf("BattleMaster is destroyed");
    BattleMaster::clear();
  }

} // namespace DespoilerEngine