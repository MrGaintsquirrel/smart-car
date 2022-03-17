#include <arduino.h>
#include "Motorshield.h"

enum Direction {
  forward = 0,
  backwards = 1,
};

class motor {
  
  public:
  
  motor(int forwardPin, int backwardsPin, int speedControlPin, int speedOffsetforward, int speedOffsetbackwards); // gives basic parameters to motor object
  void setSpeed(int speedPercentage, Direction direction); // Set motor speed and direction
  void Stop(); // brake

  private:
  int _forwardPin, _backwardsPin, _speedControlPin, _speedOffsetforward, _speedOffsetbackwards; // Internal variables

  motorShield motorShield;
  
};
