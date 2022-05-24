#include "Ultrasonic.h"

ultrasonic::ultrasonic(int trigPin, int echoPin, int servoPin){
  _trigPin = trigPin; // Stores trigger pin to private variable
  _echoPin = echoPin; // Stores echo pin to private variable
  _servoPin = servoPin; // Stores servo pin to private variable

  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

void ultrasonic::init(){
  ultrasonicservo.attach(_servoPin);
}

float ultrasonic::getDistance() {
  //float speedofsound = 0;
  
  _timedurration = 0;
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  _timedurration = pulseIn(_echoPin, HIGH);

 // speedofsound = (331.3*sqrt(1+(20/273.15)))/10000; // calculate speed of sound in 20 degree temperature. devide  by 10000 to go from m/s to cm/s
  
  return _timedurration*speedofsound/2;
}

void ultrasonic::setAngle(int degree){
  ultrasonicservo.write(degree);
}
