#include "Motor.h"

motor::motor(int forwardPin, int backwardsPin, int speedControlPin, int speedOffsetforward, int speedOffsetbackwards){
  _forwardPin = forwardPin;
  _backwardsPin = backwardsPin;
  _speedControlPin = speedControlPin;
  _speedOffsetforward = speedOffsetforward;
  _speedOffsetbackwards = speedOffsetbackwards;

  pinMode(speedControlPin, OUTPUT);
}

void motor::setSpeed(int speedPercentage, Direction direction){
  
  unsigned int pwmValue = map(speedPercentage, 0, 100, 0, 255);

  switch(direction) {
    case forward:
     motorShield.writeShiftRegisterPin(_backwardsPin, 0);
     motorShield.writeShiftRegisterPin(_forwardPin, 1);
     pwmValue =  pwmValue - _speedOffsetforward;
     break;

    case backwards:
      motorShield.writeShiftRegisterPin(_forwardPin, 0);
      motorShield.writeShiftRegisterPin(_backwardsPin, 1);
      pwmValue =  pwmValue - _speedOffsetbackwards;
      break;
  }
  analogWrite(_speedControlPin, pwmValue);
}

void motor::Stop(){
   motorShield.writeShiftRegisterPin(_backwardsPin, 0);
   motorShield.writeShiftRegisterPin(_forwardPin, 0);
}
