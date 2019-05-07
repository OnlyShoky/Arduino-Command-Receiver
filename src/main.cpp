#ifdef MAINtest1

#include <Cabina_agbar.h> 
#include <SerialCommand.h>


SerialCommand sCmd;




void setup() {
  setup_agbar(); 
  sCmd.addCommand("Stopall",stopAll);
  sCmd.addCommand("sHeatON",setHeatON);
  sCmd.addCommand("sHeatOFF",setHeatOFF);
  sCmd.addCommand("sVibrationON",setVibrationON);
  sCmd.addCommand("sVibrationOFF",setVibrationOFF);
  sCmd.addCommand("sWaiting",setWaiting);
  sCmd.addCommand("sSprayON",setSprayON);
  sCmd.addCommand("sSprayOFF",setSprayOFF);
  sCmd.addCommand("sSmellON",setSmellON);
  sCmd.addCommand("sSmellOFF",setSmellOFF);
  sCmd.addCommand("sVent5",setVent5);
  sCmd.addCommand("sVent4",setVent4);
  sCmd.addCommand("sVent3",setVent3);
  sCmd.addCommand("sVent2",setVent2);
  sCmd.addCommand("sVent1",setVent1);
  sCmd.addCommand("sVentOFF",setVentOFF);

}

// the loop routine runs over and over again forever:
void loop() {

  if (Serial.available() > 0){
    sCmd.readSerial();
  }

  loop_agbar();
  
  

  

}


#endif



#ifdef MAIN1
#include <Arduino.h>

#include <SoftwareSerial.h>
#include <SerialCommand.h>
#include <LinkedList.h>
#include <Cabina_agbar.h>



SerialCommand sCmd;

int pin6 = 6;   // choose the input pin (for a pushbutton)
int pin5 = 5;   // choose the input pin (for a pushbutton)
int pin4 = 4;   // choose the input pin (for a pushbutton)
int pin2 = 2;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
// the setup routine runs once when you press reset:

LinkedList<String> CommandList = LinkedList<String>();


void GreenLedON () {
 digitalWrite(pin4,HIGH);
}

void GreenLedOFF () {
 digitalWrite(pin4,LOW);
}

void LedON () {
 digitalWrite(pin4,HIGH);
}

void LedOFF () {
 digitalWrite(pin4,LOW);
}

void YellowLedON () {
 digitalWrite(pin5,HIGH);
}

void YellowLedOFF () {
 digitalWrite(pin5,LOW);
}

void RedLedON () {
 digitalWrite(pin6,HIGH);

}

void RedLedOFF () {
 digitalWrite(pin6,LOW);

}

void Wait500(){
  delay(500);
}

void Wait1000(){
  delay(1000);
}

void Show1(){
  val ++ ;
  Serial.println("Show"+String(val));
  RedLedON () ; 
  delay(1000);
  RedLedOFF();
  delay(1000);
  YellowLedON();
  delay(1000);
  RedLedON();
  delay(1000);
  YellowLedOFF();
  delay(1000);
  RedLedOFF();
  delay(1000);
  GreenLedON();
  delay(500);
  GreenLedOFF();
  delay(500);

}






void setup() {
  pinMode(pin2, INPUT);    // declare pushbutton as input
  pinMode(pin4, OUTPUT);    // declare pushbutton as output
  pinMode(pin5, OUTPUT);    // declare pushbutton as output
  pinMode(pin6, OUTPUT);    // declare pushbutton as output

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  while (!Serial); 
 
 // Add all the commands that we want to do
  sCmd.addCommand("GreenLedON",GreenLedON);
  sCmd.addCommand("GreenLedOFF",GreenLedOFF);
  sCmd.addCommand("YellowLedON",YellowLedON);
  sCmd.addCommand("YellowLedOFF",YellowLedOFF);
  sCmd.addCommand("RedLedON",RedLedON);
  sCmd.addCommand("RedLedOFF",RedLedOFF);
  sCmd.addCommand("Show1",Show1);
  sCmd.addCommand("Wait500",Wait500);
  sCmd.addCommand("Wait1000",Wait1000);

}



// the loop routine runs over and over again forever:
void loop() {

  
  if (Serial.available() > 0){
    sCmd.readSerial();
  }
  
  

}

#endif

#ifdef MAIN2

#include <Arduino.h>

#include <SoftwareSerial.h>
#include <SerialCommand.h>
#include <LinkedList.h>

SerialCommand sCmd;

int pin6 = 6;   // choose the input pin (for a pushbutton)
int pin5 = 5;   // choose the input pin (for a pushbutton)
int pin4 = 4;   // choose the input pin (for a pushbutton)
int pin2 = 2;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
// the setup routine runs once when you press reset:

LinkedList<String> CommandList = LinkedList<String>();


void GreenLedON () {
 digitalWrite(pin4,HIGH);
}

void GreenLedOFF () {
 digitalWrite(pin4,LOW);
}

void LedON () {
 digitalWrite(pin4,HIGH);
}

void LedOFF () {
 digitalWrite(pin4,LOW);
}

void YellowLedON () {
 digitalWrite(pin5,HIGH);
}

void YellowLedOFF () {
 digitalWrite(pin5,LOW);
}

void RedLedON () {
 digitalWrite(pin6,HIGH);
}

void RedLedOFF () {
 digitalWrite(pin6,LOW);
}

void Show1(){
  val ++ ;
  Serial.println("Show"+String(val));
  RedLedON () ; 
  delay(1000);
  RedLedOFF();
  delay(1000);
  YellowLedON();
  delay(1000);
  RedLedON();
  delay(1000);
  YellowLedOFF();
  delay(1000);
  RedLedOFF();
  delay(1000);
  GreenLedON();
  delay(500);
  GreenLedOFF();
  delay(500);

}

void Wait500(){
  delay(500);
}

void Wait1000(){
  delay(1000);
}






void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(pin2, INPUT);    // declare pushbutton as input
  pinMode(pin4, OUTPUT);    // declare pushbutton as output
  pinMode(pin5, OUTPUT);    // declare pushbutton as output
  pinMode(pin6, OUTPUT);    // declare pushbutton as output

  Serial.begin(9600);
  while (!Serial); 
 
  sCmd.addCommand("1",GreenLedON);
  sCmd.addCommand("2",GreenLedOFF);
  sCmd.addCommand("3",YellowLedON);
  sCmd.addCommand("4",YellowLedOFF);
  sCmd.addCommand("5",RedLedON);
  sCmd.addCommand("6",RedLedOFF);
  sCmd.addCommand("7",Show1);
  sCmd.addCommand("8",Wait500);
  sCmd.addCommand("9",Wait1000);



  

}

//holiwis 
//YO !


// the loop routine runs over and over again forever:
void loop() {

  
  if (Serial.available() > 0){
    sCmd.readSerial();
  } 

}


#endif


