#include <Servo.h>              //Library for use Servo motors
#include <digitalWriteFast.h>   //Library for use digitalWrite and digitalRead methods much faster. 
                                //For more info and download please visit: https://github.com/NicksonYap/digitalWriteFast 

int currentStep = 0; //Step integer for hold the info of which step we are on at.


Servo frontServo;     //Creating servo objects
Servo backServo;

void setup() {
  Serial.begin(9600);//This is for take serial output for debugging. (Causing minor performance leak and should be removed when not needed)
  defineUltrasonic();//Defining the pin numbers and pinModes of Ultrasonic sensors pins.
  servoInitial();    //Sets servos to their initial position.
}


void loop(){
    while(currentStep < 4){
      setMotors('b',255,255);
      delay(300);
      while(distanceMeasure('f')>11){
        setMotors('b',255,255);
    }
    stepUp();
    }

    setMotors('b',255,255);
    delay(500);
    turn(90);

    
      while(distanceMeasure('f')>11){
        setMotors('b',255,255);
    }
    stepUp();

    setMotors('b',255,255);
    delay(700);
    stopMotors('b');
    turn(180);

    
    while(distanceMeasure('b') < 9){    
      setMotors('b',-250,-250);
    }
    stepDown();

    turn(90);

    while(currentStep <= 8){
      
    while(distanceMeasure('b') < 9){  
      setMotors('b',-250,-250);  
    }
    stepDown();
    }

    while(true){
      setMotors('b',-255,-255);
      }

}                                 
