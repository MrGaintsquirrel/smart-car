#include "Bakkensensor.h"

int pinIrBakken[] = {A5, A4, A3, A2};

int Bakkensensor::gethighestsensor(){
    int max = 0;
    int max_i = 0;
    
      for(int i = 0; i < 4; i++) {
        if(analogRead(pinIrBakken[i]) > max){
          max = analogRead(pinIrBakken[i]);
          max_i = i;
        }
      }
      return max_i;
}
