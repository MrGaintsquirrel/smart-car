#include <Servo.h>

Servo servo1;

//motor driver pwm pins
#define PWM2A 11
#define PWM2B 3
#define PWM0A 6
#define PWM0B 5

//motor driver control pins
#define M4A 0
#define M2A 1
#define M1A 2
#define M1B 3
#define M2B 4
#define M3A 5
#define M4B 6
#define M3B 7

#define RVD M4A
#define RVR M4B

#define RAD M3B
#define RAR M3A

#define LVD M1A
#define LVR M1B

#define LAD M2A
#define LAR M2B

//shift register
#define DIR_CLK 4
#define DIR_EN 7
#define DIR_LATCH 12
#define DIR_SER 8

#define trigpin A0
#define echo A1

unsigned long deltatime = 0;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  pinMode(trigpin, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(DIR_CLK, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(DIR_SER, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(7, LOW);
  
  servo1.attach(10);

  shiftwrite(LAD, 1);
  analogWrite(PWM2A, 250);
  
  shiftwrite(LVD, 1);
  analogWrite(PWM2B, 250);

  shiftwrite(RVD, 1);
  analogWrite(PWM0B, 250);

  shiftwrite(RAD, 1);
  analogWrite(PWM0A,250);

}

void loop() {
  // put your main code here, to run repeatedly:

  
    for(int i = 0; i < 180; i++){
    servo1.write(i);
    Serial.print(distance());
    Serial.println("Cm");
  }
  for(int i = 180; i > 0; i--){
    servo1.write(i);
    Serial.print(distance());
    Serial.println("Cm");
  }
}

float distance() {
  deltatime = 0;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  deltatime = pulseIn(echo, HIGH);
  return deltatime * 0.034/2;
}


void shiftwrite(int pin, bool Value){

  static uint8_t data = 0b00000000;

  data |= Value << (pin);
  Serial.println(data);

  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DIR_SER, DIR_CLK, MSBFIRST, data);
  digitalWrite(DIR_LATCH, HIGH);
}

