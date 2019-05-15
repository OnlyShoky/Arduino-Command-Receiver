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

#include "CabinaSensorial.h" 
bool debug = false;

//intensitats VENT (0-255)
int intVent1 = 50;
int intVent2 = 80;
int intVent3 = 100;
int intVent4 = 150;
int intVent5 = 200;
int intVent6 = 255;

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

//led blink variables
int ledState = LOW;

void stopAll(){

  if(debug) Serial.println("[Stop All]");

  setHeat(false, false);
 
  digitalWrite(smellPin, LOW);
  digitalWrite(waterPin, LOW);
  
  setVibration(false);

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
void setHeatRightON(){
  setHeat(false, true);

}
void setHeatLeftON(){
  setHeat(true, false);

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
void setVent6(){
 DmxMaster.write(1, intVent6);
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



//Servo test
//Spray different angles
void setSpray20(){
  sprayServo.write(20);
}
void setSpray40(){
  sprayServo.write(40);
}
void setSpray60(){
  sprayServo.write(60);
}
void setSpray80(){
  sprayServo.write(80);
}
void setSpray100(){
  sprayServo.write(100);
}
void setSpray120(){
  sprayServo.write(120);
}
void setSpray140(){
  sprayServo.write(140);
}
void setSpray160(){
  sprayServo.write(160);
}
void setSpray180(){
  sprayServo.write(180);
}

//Smell different angles
void setSmell20(){
  smellServo.write(20);
}
void setSmell40(){
  smellServo.write(40);
}
void setSmell60(){
  smellServo.write(60);
}
void setSmell80(){
  smellServo.write(80);
}
void setSmell100(){
  smellServo.write(100);
}
void setSmell120(){
  smellServo.write(120);
}
void setSmell140(){
  smellServo.write(140);
}
void setSmell160(){
  smellServo.write(160);
}
void setSmell180(){
  smellServo.write(180);
}