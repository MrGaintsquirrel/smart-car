#include "Motorshield.h"

void motorShield::writeShiftRegisterPin(int pin, bool value){

  static uint8_t data = 0b00000000;

  data |= value << (pin);

  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DIR_SER, DIR_CLK, MSBFIRST, data);
  digitalWrite(DIR_LATCH, HIGH);
}
