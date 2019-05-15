// Verificar que el numero de comandos añadidos con sCmd.add es lo suficiente grande ,sino cambiarlo a SerialCommand.h y aumentarlo
// Siempre tener una function Start y Stop , y añadir-los 
// No hacer funciones que se bloquen o con delay , porque hacen freezear todo

#ifdef MAIN1

#include <CabinaSensorial.h> 
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

