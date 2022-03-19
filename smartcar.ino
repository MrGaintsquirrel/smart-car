#include "Bakkensensor.h"
#include "Ultrasonic.h"
#include "car.h"


bakkensensor Bakkensensor;

ultrasonic ultrasonic(A0, A1, 10);

car smartcar;

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
  Serial.println(ultrasonic.getDistance());

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
