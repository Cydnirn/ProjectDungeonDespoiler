//
// Created by rei on 12/10/24.
//

#include "BattleMaster.h"
#include "Creature.h"
#include "RandomGenerator.h"
#include <memory>
#include <vector>

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

  void BattleMaster::init() {}

  void BattleMaster::del_creature(int index) {
    CreatureParticipant.erase(CreatureParticipant.begin() + index);
  }

  void BattleMaster::runBattle(Creature &attacker, std::shared_ptr<Player> &defender) {
        int damage = attacker.getBaseDamage();
        bool critical = RandomGenerator::generateRandomNumber(1, 100) < attacker.getBaseCritical();
        if(critical){
          damage *= attacker.getStats().strength;
        }
        bool missed = RandomGenerator::generateRandomNumber(1, 100) < (defender->getStats().agility - attacker.getStats().agility);
        if(missed){
          damage = 0;
        }
        defender->setHealth(defender->getHealth() - damage);
  }

  void BattleMaster::runBattle(std::shared_ptr<Player> &attacker, DespoilerEngine::Creature &defender) {
        int damage = attacker->getBaseDamage();
        bool critical = RandomGenerator::generateRandomNumber(1, 100) < attacker->getBaseCritical();
        if(critical){
          damage *= attacker->getStats().strength;
        }
        bool missed = RandomGenerator::generateRandomNumber(1, 100) < (defender.getStats().agility - attacker->getStats().agility);
        if(missed){
          damage = 0;
        }
        defender.setHealth(defender.getHealth() - damage);
  }


  void BattleMaster::clear() {
    CreatureParticipant.clear();
  }


  BattleMaster::~BattleMaster() {
    BattleMaster::clear();
  }

} // namespace DespoilerEngine