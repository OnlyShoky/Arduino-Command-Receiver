// Verificar que el numero de comandos añadidos con sCmd.add es lo suficiente grande ,sino cambiarlo a SerialCommand.h y aumentarlo
// Siempre tener una function Start y Stop , y añadir-los 
// No hacer funciones que se bloquen o con delay , porque hace freezear todo

#ifdef MAINtest1

#include <Cabina_agbar.h> 
#include <SerialCommand.h>


SerialCommand sCmd;

//Method that will do all we want on the begining
void Start(){
  setStart();

}

//Method that turn off al the system that can be turned on , on the execution
void Stop(){
  stopAll();
}


void setup() {
  setup_agbar(); 
  //Maintain this two commands , because unity will use them when we click start or stop , so if they are missing the program will not work
  sCmd.addCommand("Start",Start);
  sCmd.addCommand("Stop",Stop);

  // Add all the commands that we want to do
  sCmd.addCommand("sHeatRON",setHeatRightON);
  sCmd.addCommand("sHeatLON",setHeatLeftON);
  sCmd.addCommand("sHeatON",setHeatON);
  sCmd.addCommand("sHeatOFF",setHeatOFF);
  sCmd.addCommand("sVibrON",setVibrationON);
  sCmd.addCommand("sVibrOFF",setVibrationOFF);
  sCmd.addCommand("sVentOFF",setVentOFF);
  sCmd.addCommand("sWaiting",setWaiting);
  sCmd.addCommand("sSprayON",setSprayON);
  sCmd.addCommand("sSprayOFF",setSprayOFF);
  sCmd.addCommand("sSmellON",setSmellON);
  sCmd.addCommand("sSmellOFF",setSmellOFF);
  sCmd.addCommand("sVent6",setVent6);
  sCmd.addCommand("sVent5",setVent5);
  sCmd.addCommand("sVent4",setVent4);
  sCmd.addCommand("sVent3",setVent3);
  sCmd.addCommand("sVent2",setVent2);
  sCmd.addCommand("sVent1",setVent1);
  sCmd.addCommand("sVentOFF",setVentOFF);
  sCmd.addCommand("setD",setD);

//Servos
  sCmd.addCommand("sSpray20",setSpray20);
  sCmd.addCommand("sSpray40",setSpray40);
  sCmd.addCommand("sSpray60",setSpray60);
  sCmd.addCommand("sSpray80",setSpray80);
  sCmd.addCommand("sSpray100",setSpray100);
  sCmd.addCommand("sSpray120",setSpray120);
  sCmd.addCommand("sSpray140",setSpray140);
  sCmd.addCommand("sSpray160",setSpray160);
  sCmd.addCommand("sSpray180",setSpray180);

  sCmd.addCommand("sSmell20",setSmell20);
  sCmd.addCommand("sSmell40",setSmell40);
  sCmd.addCommand("sSmell60",setSmell60);
  sCmd.addCommand("sSmell80",setSmell80);
  sCmd.addCommand("sSmell100",setSmell100);
  sCmd.addCommand("sSmell120",setSmell120);
  sCmd.addCommand("sSmell140",setSmell140);
  sCmd.addCommand("sSmell160",setSmell160);
  sCmd.addCommand("sSmell180",setSmell180);




  

}

// the loop routine runs over and over again forever:
void loop() {

  if (Serial.available() > 0){
    sCmd.readSerial();
  }

  //loop_agbar();
    


}


#endif



#ifdef MAIN1
#include <Arduino.h>

#include <SoftwareSerial.h>
#include <SerialCommand.h>
#include <LinkedList.h>
#include <Cabina_agbar.h>



SerialCommand sCmd;
int pin9 = 9;   // choose the input pin (for a pushbutton)
int pin6 = 6;   // choose the input pin (for a pushbutton)
int pin5 = 5;   // choose the input pin (for a pushbutton)
int pin4 = 4;   // choose the input pin (for a pushbutton)
int pin2 = 2;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
// the setup routine runs once when you press reset:

LinkedList<String> CommandList = LinkedList<String>();
Servo servoMotor ;

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

void servo20(){
  servoMotor.write(20);
}
void servo40(){
  servoMotor.write(40);
}
void servo60(){
  servoMotor.write(60);
}
void servo80(){
  servoMotor.write(80);
}
void servo100(){
  servoMotor.write(100);
}
void servo120(){
  servoMotor.write(120);
}
void servo140(){
  servoMotor.write(140);
}
void servo160(){
  servoMotor.write(160);
}
void servo180(){
  servoMotor.write(180);
}

void servoOFF(){
  servoMotor.write(0);
}


//Method that will do all we want on the begining
void Start(){
  RedLedON ();
  YellowLedON();
  GreenLedON();
  delay(200);
  RedLedOFF();
  YellowLedOFF();
  GreenLedOFF();
}

//Method that turn off al the system that can be turned on , on the execution
void Stop(){
  RedLedOFF();
  YellowLedOFF();
  GreenLedOFF();
  servoOFF();
}






void setup() {
  servoMotor.attach(pin9);
  pinMode(pin2, INPUT);    // declare pushbutton as input
  pinMode(pin4, OUTPUT);    // declare pushbutton as output
  pinMode(pin5, OUTPUT);    // declare pushbutton as output
  pinMode(pin6, OUTPUT);    // declare pushbutton as output

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  while (!Serial); 
 

  //Maintain this two commands , because unity will use them when we click start or stop , so if they are missing the program will not work
  sCmd.addCommand("Start",Start);
  sCmd.addCommand("Stop",Stop);

 // Add all the commands that we want to do
  sCmd.addCommand("GreenLedON",GreenLedON);
  sCmd.addCommand("GreenLedOFF",GreenLedOFF);
  sCmd.addCommand("YellowLedON",YellowLedON);
  sCmd.addCommand("YellowLedOFF",YellowLedOFF);
  sCmd.addCommand("RedLedON",RedLedON);
  sCmd.addCommand("RedLedOFF",RedLedOFF);
  sCmd.addCommand("Wait500",Wait500);
  sCmd.addCommand("Wait1000",Wait1000);
  sCmd.addCommand("servoOFF",servoOFF);
  sCmd.addCommand("servo20",servo20);
  sCmd.addCommand("servo40",servo40);
  sCmd.addCommand("servo60",servo60);
  sCmd.addCommand("servo80",servo80);
  sCmd.addCommand("servo100",servo100);
  sCmd.addCommand("servo120",servo120);
  sCmd.addCommand("servo140",servo140);
  sCmd.addCommand("servo160",servo160);
  sCmd.addCommand("servo180",servo180);

}



// the loop routine runs over and over again forever:
void loop() {

  if (Serial.available() > 0){
    sCmd.readSerial();
  }
}

#endif
