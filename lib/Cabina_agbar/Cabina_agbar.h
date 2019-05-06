#ifndef Cabina_agbar_h
#define Cabina_agbar_h

#include <Servo.h>

#include <DmxMaster.h>
#include <Arduino.h>




  



void stopAll();
void setWaiting();
void setHeat(bool stateHeat1, bool stateHeat2);
void setHeatON();
void setHeatOFF();
void setVibration(bool state);
void setVibrationON();
void setVibrationOFF();
void setup_agbar();
void loop_agbar();




#endif
