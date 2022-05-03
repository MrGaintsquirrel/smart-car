#include "Bakkensensor.h"
#include "Ultrasonic.h"
#include "car.h"


bakkensensor Bakkensensor;

ultrasonic ultrasonic(A0, A1, 10);

car smartcar;

int Speed = 45;

int irPinLeft = 13;
int irPinRight = 9;

bool ultrasoonflag = 0;

int Direction = 0;
int prioritylist[4] = {0};

unsigned long Time = 0;
unsigned long previousTime = 0;

unsigned long previousTimeDrive = 0;

unsigned long previousTimeUltrasoon = 0;

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

  Time = millis(); // update Time beginning of loop
  
  //check for serial commands
  if(Serial.available() > 0){
    SerialHandler();
  }
  
  //check if distance is less than 10 cm
   if(ultrasonic.getDistance() <= 15 && ultrasoonflag == 0){
      smartcar.Stop();
      prioritylist[0] = getClearside(); // get the clear side of the car and put in the first priority
      ultrasoonflag = 1; // set the ultasoon flag to prevent double measuments
  } if(ultrasoonflag == 1 && Time - previousTimeUltrasoon >= 2000) {
     prioritylist[0] = 6;
     previousTimeUltrasoon = Time;
  }

  if(getDigitalsensors() > 0) {
    prioritylist[1] = getDigitalsensors();
  } else {
    prioritylist[1] = 6;
  }
  


  //update dricetion every 150ms
  if(Time - previousTimeDrive >= 150){
    prioritylist[2] = Bakkensensor.gethighestsensor();

    for(int i = 0; i < 3; i++){
      if(prioritylist[i] != 6) {
        Direction = prioritylist[i];
        break;
      }
    }
    //Serial.println(Direction);
    //change direction based on sensors
    switch(Direction) {
       case 0:
         smartcar.driveforward(Speed);
         Serial.println("forward");
      break;
      case 1:
        //smartcar.driveleft(50);
        smartcar.driveturnleft(Speed);
        Serial.println("left");
      break;
      case 2:
        //smartcar.drivebackward(30);
        smartcar.driveturnleft(Speed);
        Serial.println("left");
      break;
      case 3:
        smartcar.driveturnright(Speed);
        Serial.println("right");
      break;

      default:
        smartcar.Stop();
      break;
    };
    previousTimeDrive = Time;
  }
  if(Time - previousTime >= 5000 && ultrasoonflag == 1){
   ultrasoonflag = 0;
   previousTime = Time;
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
  int angles[] = {10, 180};
  int distance[2] = {0, 0};
  
  for(int i = 0; i < 2; i++){
    ultrasonic.setAngle(angles[i]);
    delay(500);
    distance[i] = ultrasonic.getDistance(); 

  }
  ultrasonic.setAngle(90);
  if(distance[0] > distance[1]){
    return 3;
  }
  else {
    return 2;
  }
}

int getDigitalsensors() {
  if(!digitalRead(irPinLeft)){
    return 3;
  } if(!digitalRead(irPinRight)){
    return 1;
  }
  else {
    return 6;
  }
}
