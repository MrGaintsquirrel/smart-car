#include <arduino.h>

class ultrasonic {
 
  
  public:

  ultrasonic(int trigPin, int echoPin);
  float getDistance();


  private:

  int _trigPin, _echoPin;
  
};
