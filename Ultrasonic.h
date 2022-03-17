#include <arduino.h>

class ultrasonic {
  public:

  ultrasonic(int trigPin, int echoPin); // Sets trigger and echo pin
  float getDistance(); // Retruns distance measured


  private:

  int _trigPin, _echoPin;
  
};
