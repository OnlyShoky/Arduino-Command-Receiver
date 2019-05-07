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
void setSprayON();
void setSprayOFF();
void setSmellON();
void setSmellOFF();
void setVent5();
void setVent4(); 
void setVent3();
void setVent2();
void setVent1();
void setVentOFF();
void setup_agbar();
void loop_agbar();




#endif
