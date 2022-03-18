#include "Motor.h"

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



class car {
  public:

  void driveforward(int Speed);
  void drivebackward(int Speed);
  void driveright(int Speed);
  void driveleft(int Speed);
  void Stop();

  private:


  
};
