//
// Created by rei on 12/8/24.
//
#include "../Items.h"

namespace DespoilerEngine {
  class [[maybe_unused]] Sword: public Items {
        public:
        Sword() : Items(*this) {};
        ~Sword() = default;
        [[maybe_unused]] Stats baseRequirements = {0, 5, 0, 0};
        [[maybe_unused]] int baseDmg = 10;
        std::string name = "Sword";
  };
}