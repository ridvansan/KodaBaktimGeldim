#include <L298N.h>       //Implemets the library which eases to use L298N motor driver

#define enL_Front 2      //Defines the pins in use.
#define enR_Front 3
#define enL_Back 4
#define enR_Back 5
#define enL_Tail 7
#define enR_Tail 6

#define inAL_Front A0
#define inBL_Front A1
#define inAR_Front A2
#define inBR_Front A3

#define inAL_Back A4
#define inBL_Back A5
#define inAR_Back A6
#define inBR_Back A7

#define inAL_Tail A10
#define inBL_Tail A11
#define inAR_Tail A8
#define inBR_Tail A9

//Creating objects for each dc motor
L298N motorFrontLeft   (enL_Front,inAL_Front,inBL_Front);
L298N motorFrontRight  (enR_Front,inAR_Front,inBR_Front);
L298N motorBackLeft    (enL_Back,inAL_Back,inBL_Back);
L298N motorBackRight   (enR_Back,inAR_Back,inBR_Back);
L298N motorTailLeft    (enL_Tail,inAL_Tail,inBL_Tail);
L298N motorTailRight   (enR_Tail,inAR_Tail,inBR_Tail);

//This methods set motors velocity and direction (minus velocity to going backward)
void setMotors(char motor,int speedL, int speedR){  //Takes parameters of which motor set will work,speed of left motor and speed of right motor
  if(motor == 'f'){                                 //'f' for front,'b' for back,'t' for tail
    speedL >= 0 ? motorFrontLeft.forward() : motorFrontLeft.backward();    //Setting directions of motors due to sign of velocity (+ for forward)
    speedR >= 0 ? motorFrontRight.forward() : motorFrontRight.backward();
    motorFrontLeft.setSpeed(abs(speedL));                                       //Setting speeds of motors
    motorFrontRight.setSpeed(abs(speedR));
  }
  else if(motor == 'b'){
    speedL >= 0 ? motorBackLeft.forward() : motorBackLeft.backward();
    speedR >= 0 ? motorBackRight.forward() : motorBackRight.backward();
    motorBackLeft.setSpeed(abs(speedL));
    motorBackRight.setSpeed(abs(speedR));
  }
  else if (motor == 't'){
    speedL >= 0 ? motorTailLeft.forward() : motorTailLeft.backward();
    speedR >= 0 ? motorTailRight.forward() : motorTailRight.backward();
    motorTailLeft.setSpeed(abs(speedL));
    motorTailRight.setSpeed(abs(speedR));
  }
}

void turn(int angle){
  setServo(frontServo,90);
  setMotors('b',255,-255);
  delay(angle*9);
  stopAllMotors();
}

//This method stops the motor set which has entered as parameter
void stopMotors(char motor){    //Takes parameter of motor set
  if (motor == 'f'){
    motorFrontLeft.stop();      //Stop left motor
    motorFrontRight.stop();     //Stop right motor
  }
  else if (motor == 'b'){
    motorBackLeft.stop();
    motorBackRight.stop();
  }
  else if (motor == 't'){
    motorTailLeft.stop();
    motorTailRight.stop();
  }
}

void anan(){
  motorFrontRight.backward();
  motorFrontRight.setSpeed(255);
}

//This methods calls stopMotors() function for each motor sets and with that stops all dc motors on the robot
void stopAllMotors(){
  stopMotors('f');
  stopMotors('b');
  stopMotors('t');
}
