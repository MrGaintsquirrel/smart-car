#include "Motorshield.h"

void motorShield::writeShiftRegisterPin(int pin, bool value){

  static uint8_t data = 0b00000000; // Stores current pin states even after function is closed

  data |= value << (pin); // Shift 0 or 1 to specified pin

  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DIR_SER, DIR_CLK, MSBFIRST, data); // Shiftes data into shiftregister
  digitalWrite(DIR_LATCH, HIGH);
}
