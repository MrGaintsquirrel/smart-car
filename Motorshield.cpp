#include "Motorshield.h"

void motorShield::writeShiftRegisterPin(int pin, int Value){

  static int data = 0b00000000; // Stores current pin states even after function is closed
  uint8_t example;

  example |= (1 << pin);
  example = ~example;
  if(Value == 1) {
  data |= (Value << pin); // Shift 0 or 1 to specified pin
  } else {
    data &= example;
  }

  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DIR_SER, DIR_CLK, MSBFIRST, data); // Shiftes data into shiftregister
  digitalWrite(DIR_LATCH, HIGH);
}
