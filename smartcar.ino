#include "Bakkensensor.h"
#include "Ultrasonic.h"
#include "car.h"


bakkensensor Bakkensensor;

ultrasonic ultrasonic(A0, A1, 10);

car smartcar;

int irPinLeft = 13;
int irPinRight = 9;

int Direction = 0;

unsigned long Time = 0;
unsigned long previousTime = 0;

typedef struct commandstruct{
  char commandName;
  void (*function)();
};

struct commandstruct command[7];

void driveforward(){
  smartcar.driveforward(50);
}

void driveleft(){
  smartcar.driveleft(50);
}

void driveright(){
  smartcar.driveright(50);
}

void drivebackward(){
  smartcar.drivebackward(50);
}

void Stop(){
  smartcar.Stop();
}

void Turnleft(){
  smartcar.driveturnleft(50);
}

void Turnright(){
  smartcar.driveturnright(50);
}


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  ultrasonic.init();

  pinMode(DIR_CLK, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(DIR_SER, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(irPinLeft, INPUT);
  pinMode(irPinRight, INPUT);

  digitalWrite(7, LOW);
  //smartcar.driveforward(50);

  command[0].commandName = 'F';
  command[0].function = &driveforward;

  command[1].commandName = 'A';
  command[1].function = &driveleft;

  command[2].commandName = 'R';
  command[2].function = &driveright;

  command[3].commandName = 'B';
  command[3].function = &drivebackward;

  command[4].commandName = 'C';
  command[4].function = &Stop;

  command[5].commandName = 'E';
  command[5].function = &Turnleft;

  command[6].commandName = 'D';
  command[6].function = &Turnright;

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(ultrasonic.getDistance());

  Time = millis();
  
  //check for serial commands
  if(Serial.available() > 0){
    SerialHandler();
  }

  int sensorid = 5;
  
  //check if distance is less than 10 cm
  if(ultrasonic.getDistance() <= 10){
    smartcar.Stop();
    sensorid = getClearside();
  }

  //update dricetion ecery 150ms
  if(Time - previousTime >= 150){
    Direction = Bakkensensor.gethighestsensor();
    //Serial.println(ultrasonic.getDistance());
    //Serial.println(Bakkensensor.getSensorValue(0));
    //change direction based on sensors
    switch(Direction) {
       case 0:
         smartcar.driveforward(30);
      break;
      case 1:
        //smartcar.driveleft(50);
        smartcar.driveturnleft(30);
      break;
      case 2:
        //smartcar.drivebackward(30);
        smartcar.driveturnleft(30);
      break;
      case 3:
        smartcar.driveturnright(30);
      break;

      default:
        smartcar.Stop();
      break;
    };
  }
}

void SerialHandler() {
  int receive;
  
  receive = Serial.read();

  Serial.println((char)receive);
  
  for(int i = 0; i <= 6; i++){
    if(strcmp((char)receive, command[i].commandName) == 0){
      (*command[i].function)();
      //break;
    }
  }
}

int getClearside(){
  int angles[] = {0, 180};
  int distance[2] = 0;
  
  for(int i = 0; i < 2; i++){
    ultrasonic.setAngle(angles[i]);
    distance[i] = ultrasonic.getDistance();
  }
  if(distance[0] > distance[1]){
    return 2;
  }
  else {
    return 3;
  }
}

