#include <arduino.h>
#include "Motorshield.h"

enum Direction {
  forward = 0,
  backwards = 1,
};

class motor {
  
  public:
  
  motor(int forwardPin, int backwardsPin, int speedControlPin, int speedOffsetforward, int speedOffsetbackwards);
  void setSpeed(int speedPercentage, Direction direction);
  void Stop();

  private:
  int _forwardPin, _backwardsPin, _speedControlPin, _speedOffsetforward, _speedOffsetbackwards;

  motorShield motorShield;
  
};
