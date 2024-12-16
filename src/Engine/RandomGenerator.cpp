//
// Created by rei on 12/8/24.
//

#include "RandomGenerator.h"
#include <random>

namespace DespoilerEngine {
int RandomGenerator::generateRandomNumber(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}
float RandomGenerator::generateRandomFloat(float min, float max) { return 0; }
bool RandomGenerator::generateRandomBool() { return false; }
bool RandomGenerator::generateRandomBool(float probability) { return false; }

} // namespace DespoilerEngine