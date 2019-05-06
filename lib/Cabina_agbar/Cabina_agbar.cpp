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
bool debug = true;

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
long ventI1 = 52000;
long ventI2 = 66000;
long ventF1 = 85000;

long ventI3 = 110000;
long ventI4 = 131000;
long ventF2 = 145000;

long ventI5 = 165000;
long ventF3 = 180000;

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
long endOfTimeline = 181000;


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

char c;
int start;
long instantInici;
unsigned long tiempo;

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

  start = 0;
  stopAll();
  if(debug) Serial.println("Waiting..");
}


void setHeat(bool stateHeat1, bool stateHeat2){

  digitalWrite(heat1Pin, !stateHeat1);
  digitalWrite(heat2Pin, !stateHeat2);
}

void setHeatON(){
  bool stateHeat1 = true ;
  bool stateHeat2 = true ;


  digitalWrite(heat1Pin, !stateHeat1);
  digitalWrite(heat2Pin, !stateHeat2);
}

void setHeatOFF(){
  bool stateHeat1 = false ;
  bool stateHeat2 = false ;


  digitalWrite(heat1Pin, !stateHeat1);
  digitalWrite(heat2Pin, !stateHeat2);
}


void setVibration(bool state){ //if there are 2 buttkickers, they act as one
    
  digitalWrite(vibration1Pin, !state);
  digitalWrite(vibration2Pin, !state);
}

void setVibrationON(){ //if there are 2 buttkickers, they act as one
  bool state = true ;  
  digitalWrite(vibration1Pin, !state);
  digitalWrite(vibration2Pin, !state);
}

void setVibrationOFF(){ //if there are 2 buttkickers, they act as one
  bool state = false ;
  digitalWrite(vibration1Pin, !state);
  digitalWrite(vibration2Pin, !state);
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

void loop_agbar() {
 
  if (Serial.available())  {

     c = Serial.read();
     
     if (c == 's' || c == 'S'){

      stopAll();
      if(debug) Serial.println("Inici Programa");
      digitalWrite(ledPin, HIGH); 
      instantInici = millis();
      start = 1;

    }
    else if (c == 'w' || c == 'W'){

      setWaiting();
    }
    else if (c == 'd' || c == 'D'){

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
  }  

  if (start == 1){
  
         tiempo = (millis() - instantInici); //es guarda el temps transcorregut des de l'inici de l'arduino
        
        //timeline del sistema de calor
        
          if (tiempo >= calorI1 && tiempo <= (calorI1+1)) {
            if(debug) Serial.println("calorI1");
            //digitalWrite(heat1Pin, HIGH);
            //digitalWrite(heat2Pin, HIGH);
            setHeat(true, true);
          }
          
          if (tiempo >= calorF1 && tiempo <= (calorF1+1)) {
            if(debug) Serial.println("calorF1");
            //digitalWrite(heat1Pin, LOW);
            //digitalWrite(heat2Pin, LOW);
            setHeat(false, false);
          }
          
          if (tiempo >= calorI2 && tiempo <= (calorI2+1)) {
            if(debug) Serial.println("calorI2");
            //digitalWrite(heat1Pin, HIGH);
            //digitalWrite(heat2Pin, HIGH);
            setHeat(true, true);
          }
          if (tiempo >= calorF2 && tiempo <= (calorF2+1)) {
            if(debug) Serial.println("calorF2");
            //digitalWrite(heat1Pin, LOW);
            //digitalWrite(heat2Pin, LOW);
            setHeat(false, false);    
          }
          
         //Timeline del sistema de vibracio
         
          if (tiempo >= vibrI1 && tiempo <= (vibrI1+1)) {
            if(debug) Serial.println("vibrI1");
            //digitalWrite(vibration1Pin, HIGH);
            //digitalWrite(vibration2Pin, HIGH);
            setVibration(true);
          }
          
          if (tiempo >= vibrF1 && tiempo <= (vibrF1+1)) {
            if(debug) Serial.println("vibrF1");
            //digitalWrite(vibration1Pin, LOW);
            //digitalWrite(vibration2Pin, LOW);
            setVibration(false);
          }
          /*if (tiempo == vibrI2) {
            if(debug) Serial.println("vibrI2");
            digitalWrite(vibration1Pin, HIGH);
            digitalWrite(vibration2Pin, HIGH);
          }
           if (tiempo == vibrF2) {
            if(debug) Serial.println("vibr F2");
            digitalWrite(vibration1Pin, LOW);
            digitalWrite(vibration2Pin, LOW);
          }
           if (tiempo == vibrI3) {
            if(debug) Serial.println("vibr I3");
            digitalWrite(vibration1Pin, HIGH);
            digitalWrite(vibration2Pin, HIGH);
          }
           if (tiempo == vibrF3) {
            if(debug) Serial.println("vibrF3");
            digitalWrite(vibration1Pin, LOW);
            digitalWrite(vibration2Pin, LOW);

          }  */
          
        // Timeline del sistema de nebulitzacio
        
          if (tiempo >= nebI1 && tiempo <= (nebI1+1)) {
            if(debug) Serial.println("nebI1");
            //digitalWrite(waterPin, HIGH);
            sprayServo.write(sprayONval);
            
          }
          if (tiempo >= nebF1 && tiempo <= (nebF1+1)) {
            if(debug) Serial.println("nebF1");
            //digitalWrite(waterPin, LOW);
            sprayServo.write(sprayOFFval);
          }
          
          
          if (tiempo >= nebI2 && tiempo <= (nebI2+1)) {
            if(debug) Serial.println("nebI2");
            //digitalWrite(waterPin, HIGH);
            sprayServo.write(sprayONval);
          }
          if (tiempo >= nebF2 && tiempo <= (nebF2+1)) {
            if(debug) Serial.println("nebF2");
            digitalWrite(waterPin, LOW);
            sprayServo.write(sprayOFFval);
          }



          
        // Timeline per al sistema de l'olor (smellSpray)

           if (tiempo >= olorI1 && tiempo <= (olorI1+1)) {
            if(debug) Serial.println("olorI1");
            smellServo.write(sprayONval);
            
          }
          if (tiempo >= olorF1 && tiempo <= (olorF1+1)) {
            if(debug) Serial.println("olorF1");
            smellServo.write(sprayOFFval);
          }


          
        // Timeline per al sistema de vent
        
          if (tiempo >= ventI1 && tiempo <= (ventI1+1)) {
            if(debug) Serial.println("ventI1");
            DmxMaster.write(1, intVent1);
          }  

          if (tiempo >= ventI2 && tiempo <= (ventI2+1)) {
            if(debug) Serial.println("ventI2");
            DmxMaster.write(1, intVent2);
          }

          if (tiempo >= ventF1 && tiempo <= (ventF1+1)) {
            if(debug) Serial.println("ventF1");
            DmxMaster.write(1, 0);
          }
          

          if (tiempo >= ventI3 && tiempo <= (ventI3+1)) {
            if(debug) Serial.println("ventI3");
            DmxMaster.write(1, intVent3);
          }  

          if (tiempo >= ventI4 && tiempo <= (ventI4+1)) {
            if(debug) Serial.println("ventI4");
            DmxMaster.write(1, intVent4);
          }

          if (tiempo >= ventF2 && tiempo <= (ventF2+1)) {
            if(debug) Serial.println("ventF2");
            DmxMaster.write(1, 0);
          }


          if (tiempo >= ventI5 && tiempo <= (ventI5+1)) {
            if(debug) Serial.println("ventI5");
            DmxMaster.write(1, intVent5);
          }  

          if (tiempo >= ventF3 && tiempo <= (ventF3+1)) {
            if(debug) Serial.println("ventF3");
            DmxMaster.write(1, 0);
          }



          
          /*if (tiempo == ventFort1) {
            DmxMaster.write(1, 255);
          }
          if (tiempo == ventMig1) {
            DmxMaster.write(1, 200);
          }
          if (tiempo == ventSuau1) {
            DmxMaster.write(1, 150);
          }
          if (tiempo == ventMig2) {
            DmxMaster.write(1, 200);
          }
          if (tiempo == ventFort2) {
            DmxMaster.write(1, 255);
          }
          if (tiempo == ventF2) {
            if(debug) Serial.println("vent F2");
            DmxMaster.write(1, 0);
            
          }*/

          // end of Timeline

          if (tiempo >= endOfTimeline && tiempo <= (endOfTimeline+1)){
            if(debug) Serial.println("The End");
            setWaiting();
          }
  
          
   }
   else{

    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;
  
      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        ledState = HIGH;
     
      } else {
        ledState = LOW;
     
      }
  
      // set the LED with the ledState of the variable:
      digitalWrite(ledPin, ledState);
    }
     
   }
   
}
