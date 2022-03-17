#include <arduino.h>
#include <Servo.h>

class ultrasonic {
  public:

  ultrasonic(int trigPin, int echoPin, int servoPin); // Sets trigger and echo pin
  void init(); // initializes servo
  float getDistance(); // Retruns distance measured
  void setAngle(int degree);


  private:
  
  int _trigPin, _echoPin, _servoPin;
  unsigned long _timedurration;

  Servo ultrasonicservo;
  
};
