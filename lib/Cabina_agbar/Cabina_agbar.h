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
void setHeatRightON();
void setHeatLeftON();
void setSprayON();
void setSprayOFF();
void setSmellON();
void setSmellOFF();
void setVent6();
void setVent5();
void setVent4(); 
void setVent3();
void setVent2();
void setVent1();
void setVentOFF();
void setup_agbar();
void loop_agbar();
void setStart();
void setD();

//Spray different angles
void setSpray20();
void setSpray40();
void setSpray60();
void setSpray80();
void setSpray100();
void setSpray120();
void setSpray140();
void setSpray160();
void setSpray180();
//Smell different angles
void setSmell20();
void setSmell40();
void setSmell60();
void setSmell80();
void setSmell100();
void setSmell120();
void setSmell140();
void setSmell160();
void setSmell180();




#endif
