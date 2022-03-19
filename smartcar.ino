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
  
}
