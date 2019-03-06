#include <L298N.h>

#define enL_Front 1
#define enR_Front 1
#define enL_Back 1
#define enR_Back 1
#define enL_Tail 1
#define enR_Tail 1

#define inAL_Front 1
#define inBL_Front 1
#define inAR_Front 1
#define inBR_Front 1

#define inAL_Back 1
#define inBL_Back 1
#define inAR_Back 1
#define inBR_Back 1

#define inAL_Tail 1
#define inBL_Tail 1
#define inAR_Tail 1
#define inBR_Tail 1

L298N motorFrontLeft   (enL_Front,inAL_Front,inBL_Front);
L298N motorFrontRight  (enR_Front,inAR_Front,inBR_Front);
L298N motorBackLeft    (enL_Back,inAL_Back,inBL_Back);
L298N motorBackRight   (enR_Back,inAR_Back,inBR_Back);
L298N motorTailLeft    (enL_Tail,inAL_Tail,inBL_Tail);
L298N motorTailRight   (enR_Tail,inAR_Tail,inBR_Tail);

void setMotors(char motor,int speedL, int speedR){
  if(motor == 'f'){
    speedL >= 0 ? motorFrontLeft.forward() : motorFrontLeft.backward();
    speedR >= 0 ? motorFrontRight.forward() : motorFrontRight.backward();
    motorFrontLeft.setSpeed(speedL);
    motorFrontRight.setSpeed(speedR);
  }
  else if(motor == 'b'){
    speedL >= 0 ? motorBackLeft.forward(): motorBackLeft.backward();
    speedR >= 0 ? motorBackRight.forward(): motorBackRight.backward();
    motorBackLeft.setSpeed(speedL);
    motorBackRight.setSpeed(speedR);
  }
  else if (motor == 't'){
    speedL >= 0 ? motorTailLeft.forward(): motorTailLeft.backward();
    speedR >= 0 ? motorTailRight.forward(): motorTailRight.backward();
    motorTailLeft.setSpeed(speedL);
    motorTailRight.setSpeed(speedR);
  }
}
void stopMotors(char motor){
  if (motor == 'f'){
    motorFrontLeft.stop();
    motorFrontRight.stop();
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

void stopAllMotors(){
  stopMotors('f');
  stopMotors('b');
  stopMotors('t');
}
