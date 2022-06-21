#include "Bakkensensor.h"


int bakkensensor::gethighestsensor(){
    int max = 0;
    int max_id = 0;
    
      for(int i = 0; i < 4; i++) {
        if(analogRead(pinIrBakken[i]) > max){ // Check if current sensor value is higher than previous measured
          max = analogRead(pinIrBakken[i]); // Store highest value
          max_id = i; // Store sensor id in return variable
        }
      }
      return max_id;
}

int bakkensensor::gethighestsensor_run(){
    int max = 0;
    int max_id = 0;
    
      for(int i = 0; i < 4; i++) {
        if(analogRead(pinIrBakken[i]) > max){ // Check if current sensor value is higher than previous measured
          max = analogRead(pinIrBakken[i]); // Store highest value
          max_id = i; // Store sensor id in return variable
        }
      }
      if(max_id == 0){
        return 2;
      } if(max_id == 3){
        return 0;
      } if(max_id == 1){
        return 2;
      } if(max_id == 2){
        return 1;
      }
}

int bakkensensor::getSensorValue(int sensorId) {
  return analogRead(pinIrBakken[sensorId]);
}
