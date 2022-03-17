#include <Servo.h>
#include "Motor.h"

Servo servo1;

//motor driver pwm pins
#define PWM2A 11  //Left front
#define PWM2B 3   //Left back
#define PWM0A 6   //Right back
#define PWM0B 5   //Right front

//motor driver control pins from shiftregister
#define M4A 0 //Right front forward
#define M2A 1 //Left back forward
#define M1A 2 //Left front forward
#define M1B 3 //Left front backward
#define M2B 4 //Left back backward
#define M3A 5 //Right back forward
#define M4B 6 //Right front backward
#define M3B 7 //Right back backward

motor motorRV (M4A, M4B, PWM0B, 0, 0);
motor motorRA (M3B, M3A, PWM0A, 0, 0);
motor motorLV (M1A, M1B, PWM2A, 0, 0);
motor motorLA (M2A, M2B, PWM2B, 0, 0);

/*
#define RVD M4A
#define RVR M4B

#define RAD M3B
#define RAR M3A

#define LVD M1A
#define LVR M1B

#define LAD M2A
#define LAR M2B
*/


#define trigpin A0
#define echo A1

int pinIrBakken[] = {A5, A4, A3, A2};
String sidesIrBakken[] = {"voor: ", "links: ", "achter: ", "rechts: "};

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
  
/*
  //shiftwrite(LAD, 1);
  //analogWrite(PWM2A, 250);
  
  //shiftwrite(LVD, 1);
  //analogWrite(PWM2B, 250);

  //shiftwrite(RVD, 1);
  //analogWrite(PWM0B, 150);

  //shiftwrite(RAD, 1);
  //analogWrite(PWM0A,250);
*/
}

void loop() {
  // put your main code here, to run repeatedly:
  motorRV.setSpeed(50, forward);
  motorRA.setSpeed(50, forward);
  motorLV.setSpeed(50, forward);
  motorLA.setSpeed(50, forward);

  /*for(int i = 0; i < 4; i++) {
    Serial.print(sidesIrBakken[i]);
    Serial.println(analogRead(pinIrBakken[i]));
    
  }

  Serial.print("\t");
  Serial.print(analogRead(pinIrBakken[3]));

  Serial.print("\t");
  Serial.println(analogRead(pinIrBakken[0]));
  delay(100);

  
   for(int i = 0; i < 180; i++){
    //servo1.write(i);
    Serial.print(distance());
    Serial.println("Cm");
  }
  for(int i = 180; i > 0; i--){
    servo1.write(i);
    Serial.print(distance());
    Serial.println("Cm");
  }*/
}

float distance() {
  deltatime = 0;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  deltatime = pulseIn(echo, HIGH);
  return deltatime * 0.034/2;
}
