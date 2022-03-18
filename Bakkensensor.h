#include <arduino.h>
  
class bakkensensor {
  public:
  
  int gethighestsensor(); //Returns the sensor id with the highest value

  private:
  
  int pinIrBakken[4] = {A5, A4, A3, A2}; // Bakkensensor pin array {voor, Links, Achter, Rechts}

  
};
