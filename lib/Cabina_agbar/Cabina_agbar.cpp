/* Cabina Multisensorial Agbar v2.6.0
 * 
 * patch1. intervals timer + temporitzacio vent5 i endoftimeline
 * patch2. caracters diferents per start ('s') i stop ('w')
 * patch3. water spray functionality added + water timeline updated
 * patch4. water spray test key added ('d')
 * 
 * v2.5.0 smell spray added (pin 7). code cleaning. Added StopAll() when timeline starts
 * v2.6.0 active-low relays
 * 
 */

#include "Cabina_agbar.h" 
bool debug = false;
/*TODO
//Temps (ms)

//CALOR
long calorI1 = 31000;
long calorF1 = 44000;

long calorI2 = 133000;
long calorF2 = 150000;

//VIBRACIO
long vibrI1 = 21000;
long vibrF1 = 31000;

/*long vibrI2 = 125000;
long vibrF2 = 131000;

long vibrI3 = 176000;
long vibrF3 = 178000;*/

//VENT
/* TODO
long ventI1 = 52000;
long ventI2 = 66000;
long ventF1 = 85000;

long ventI3 = 110000;
long ventI4 = 131000;
long ventF2 = 145000;

long ventI5 = 165000;
long ventF3 = 180000;

*/
//intensitats VENT (0-255)
int intVent1 = 80;
int intVent2 = 50;
int intVent3 = 70;
int intVent4 = 0;
int intVent5 = 255;

/*
long ventI1 = 14000;
long ventFort1 = 60000;
long ventMig1 = 68000;
long ventSuau1 = 73000;
long ventMig2 = 118000;
long ventFort2 = 126000;
long ventF2 = 131000;
*/

/*TODO
//NEBULITZACIO
long nebI1 = -1;
long nebF1 = -1;

long nebI2 = 113500;
long nebF2 = 115500;


//OLOR
long olorI1 = (60*2 + 11)*1000L;
long olorF1 = (60*2 + 13)*1000L;

/*long olorI2 = 101000;
long olorF2 = 106000;*/

//FINAL
//TODO long endOfTimeline = 181000;


//pins

const int heat1Pin = 11;
const int heat2Pin = 12;
const int smellPin = 7;
const int waterPin = 8;
const int vibration1Pin = 5;
const int vibration2Pin = 6;
const int ledPin = 13;
const int sprayPin = 9;

Servo sprayServo;
Servo smellServo;
const int sprayONval = 60;
const int sprayOFFval = 0;

/*
char c;
int start;
long instantInici;
unsigned long tiempo;
*/
//led blink variables
int ledState = LOW;


unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long interval = 200;

void stopAll(){

  if(debug) Serial.println("[Stop All]");

  setHeat(false, false);
  //digitalWrite(heat1Pin, LOW);
  //digitalWrite(heat2Pin, LOW);
  digitalWrite(smellPin, LOW);
  digitalWrite(waterPin, LOW);
  
  setVibration(false);
  //digitalWrite(vibration1Pin, LOW);
  //digitalWrite(vibration2Pin, LOW);
  DmxMaster.write(1, 0);
  sprayServo.write(sprayOFFval);
  smellServo.write(sprayOFFval);

}



void setWaiting(){
  stopAll();
  if(debug) Serial.println("Waiting..");
}


void setHeat(bool stateHeat1, bool stateHeat2){

  digitalWrite(heat1Pin, !stateHeat1);
  digitalWrite(heat2Pin, !stateHeat2);
}

void setHeatON(){
  setHeat(true, true);

}

void setHeatOFF(){
  setHeat(false, false);

}


void setVibration(bool state){ //if there are 2 buttkickers, they act as one
    
  digitalWrite(vibration1Pin, !state);
  digitalWrite(vibration2Pin, !state);
}

void setVibrationON(){ //if there are 2 buttkickers, they act as one
  setVibration(true);
}

void setVibrationOFF(){ //if there are 2 buttkickers, they act as one
  setVibration(false);
}

void setSprayON(){
  sprayServo.write(sprayONval);
}

void setSprayOFF(){
  sprayServo.write(sprayOFFval);
}
void setSmellON(){
  smellServo.write(sprayONval);
}

void setSmellOFF(){
  smellServo.write(sprayOFFval);
}

void setVent5(){
 DmxMaster.write(1, intVent5);
}
void setVent4(){
 DmxMaster.write(1, intVent4);
}
void setVent3(){
 DmxMaster.write(1, intVent3);
}
void setVent2(){
 DmxMaster.write(1, intVent2);
}
void setVent1(){
 DmxMaster.write(1, intVent1);
}
void setVentOFF(){
   DmxMaster.write(1, 0);
}

void setStart(){
    stopAll();
    if(debug) Serial.println("Inici Programa");
    digitalWrite(ledPin, HIGH); 

}

void setD(){
    digitalWrite(ledPin, LOW);
    if(debug) Serial.println("nebI1");
    sprayServo.write(sprayONval);
    smellServo.write(sprayONval);

    delay(2000);

    if(debug) Serial.println("nebF1");
    sprayServo.write(sprayOFFval);
    smellServo.write(sprayOFFval);
    setWaiting();

}

        
void setup_agbar() {

  //Ventilador
  DmxMaster.usePin(3); 
  DmxMaster.maxChannel(4);
  
  pinMode(heat1Pin, OUTPUT); /** Bombeta 1*/
  pinMode(heat2Pin, OUTPUT); /** Bombeta 2*/
  pinMode(smellPin, OUTPUT); /** Olor*/
  pinMode(waterPin, OUTPUT); /** Nebulitzacio */
  pinMode(vibration1Pin, OUTPUT); /** Vibracio 1*/
  pinMode(vibration2Pin, OUTPUT); /** Vibracio 2*/

  sprayServo.attach(sprayPin);
  smellServo.attach(smellPin);
  
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  setWaiting();
}


