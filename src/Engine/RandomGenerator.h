//
// Created by rei on 12/8/24.
//

#ifndef PROJECTDUNGEONDESPOILER_RANDOMGENERATOR_H
#define PROJECTDUNGEONDESPOILER_RANDOMGENERATOR_H

namespace DespoilerEngine {

class RandomGenerator {
public:
  static int generateRandomNumber(int min, int max);
  static float generateRandomFloat(float min, float max);
  static bool generateRandomBool();
  static bool generateRandomBool(float probability);
};

} // namespace DespoilerEngine

#endif // PROJECTDUNGEONDESPOILER_RANDOMGENERATOR_H
