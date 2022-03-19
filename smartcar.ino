#include "Bakkensensor.h"
#include "Ultrasonic.h"
#include "car.h"


bakkensensor Bakkensensor;

ultrasonic ultrasonic(A0, A1, 10);

car smartcar;

unsigned long Time = 0;
unsigned long previousTime = 0;

enum state {
  searching = 0,
  found = 1,
} _State;

int Stopflag = 0;

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
  // put your main code here, to run repeatedly:
  //Serial.println(ultrasonic.getDistance());

  Time = millis();
  int sensorid = 5;

  if(Time - previousTime >= 50){
    if(Bakkensensor.getSensorValue(Bakkensensor.gethighestsensor()) > 15) { // Check if sensor is above threshold to make sure it is the target
      sensorid = Bakkensensor.gethighestsensor();
    }
  }

  if(sensorid == 0){ // Drive forwards if the target is in front
     _State = found;
     if(Stopflag == 0){
      smartcar.driveforward(50);
     }
     if(Time - previousTime >= 2000 && _State == found){
      Stopflag = 1;
      smartcar.Stop();
     }
   } else{
    _State = searching;
   }
   
   if(_State == searching && Time - previousTime <= 2000) {
     smartcar.driveturnright(40);
   }
   if(_State == searching && Time - previousTime >= 2000) {
      smartcar.driveleft(50);
      if(Time - previousTime >= 4000){
        previousTime = Time;
    }
   }

/*
  smartcar.driveforward(50);
  delay(5000);
  smartcar.drivebackward(50);
  delay(5000);
  smartcar.driveleft(50);
  delay(5000);
  smartcar.driveright(50);
  delay(5000);
  smartcar.driveturnright(50);
  delay(5000);
  smartcar.driveturnleft(50);
  delay(5000);
  */
}
