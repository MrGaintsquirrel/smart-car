#include "bakkensensor.h"
      
Bakkensenosor(){
    int max = int_min;
    int max_i = 0;


      for(int i = 0; i < 4; i++) {
        if( pinIrBakken[i] > max){
          max = pinIrBakken[i];
          Max_i = i;
          
          
        }
  }
}
