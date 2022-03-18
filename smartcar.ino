#include <Servo.h>

//#include "Motor.h"
#include "Bakkensensor.h"
#include "Ultrasonic.h"
#include "car.h"

Servo servo1;

bakkensensor Bakkensensor;

ultrasonic ultrasonic(A0, A1, 10);
car smartcar;

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

/*
motor motorRV (M4A, M4B, PWM0B, 0, 0);
motor motorRA (M3B, M3A, PWM0A, 0, 0);
motor motorLV (M1A, M1B, PWM2A, 50, 0);
motor motorLA (M2A, M2B, PWM2B, 0, 0);

*/
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

//int pinIrBakken[] = {A5, A4, A3, A2};
//String sidesIrBakken[] = {"voor: ", "links: ", "achter: ", "rechts: "};

unsigned long deltatime = 0;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  ultrasonic.init();

  pinMode(DIR_CLK, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(DIR_SER, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(7, LOW);
}

void loop() {
  //Serial.println(ultrasonic.getDistance());

  // put your main code here, to run repeatedly:

  smartcar.driveforward(50);
  delay(5000);
  smartcar.drivebackward(50);
  delay(5000);
  smartcar.driveleft(50);
  delay(5000);
  smartcar.driveright(50);
  delay(5000);
  
  
/*  smartcar.driveleft(50);
  delay(1000);
  smartcar.Stop();*/
}
  /*
  motorRV.setSpeed(50, forward);
  motorRA.setSpeed(50, forward);
  motorLV.setSpeed(50, forward);
  motorLA.setSpeed(50, forward);

  for(int i = 0; i < 4; i++) {
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

