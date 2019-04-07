#include <Servo.h>              //Library for use Servo motors

#include <digitalWriteFast.h>   //Library for use digitalWrite and digitalRead methods much faster. 
                                //For more info and download please visit: https://github.com/NicksonYap/digitalWriteFast 

int step = 0;         //Step integer for hold the info of which step we are on at.

Servo frontServo;     //Creating servo objects
Servo backServo;

void setup() {
  Serial.begin(9600);//This is for take serial output for debugging. (Causing minor performance leak and should be removed when not needed)
  defineUltrasonic();//Defining the pin numbers and pinModes of Ultrasonic sensors pins.
  servoInitial();    //Sets servos to their initial position.
}


void loop(){
  setMotors('b',100,100);
  while(distanceMeasure('f')>13){
    
  }
  stepUp();
    
  
   

}                                 
