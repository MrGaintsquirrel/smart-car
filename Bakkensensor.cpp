#include "Bakkensensor.h"

int Bakkensensor::gethighestsensor(){
    int max = 0;
    int max_i = 0;
    
      for(int i = 0; i < 4; i++) {
        if( pinIrBakken[i] > max){
          max = pinIrBakken[i];
          max_i = i;
        }
      }
      return max_i;
}
