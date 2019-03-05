// ÖN (1)
#define enL_Front 1
#define enR_Front 1
#define enL_Back 1
#define enR_Back 1
#define enL_Tail 1
#define enR_Tail 1

#define inAL_Front 1
#define inBL_Front 1
#define inAL_Front 1
#define inBR_Front 1

#define inAL_Back 1
#define inBL_Back 1
#define inAL_Back 1
#define inBR_Back 1

#define inAL_Tail 1
#define inBL_Tail 1
#define inAL_Tail 1
#define inBR_Tail 1



void defineDCMotors() {
  pinModeFast(enL_Front, OUTPUT);
  pinModeFast(enR_Front, OUTPUT);
  pinModeFast(enL_Back, OUTPUT);
  pinModeFast(enR_Back, OUTPUT);
  pinModeFast(enL_Tail, OUTPUT);
  pinModeFast(enR_Tail, OUTPUT);

  pinModeFast(inAL_Front, OUTPUT);
  pinModeFast(inAR_Front, OUTPUT);
  pinModeFast(inBL_Front, OUTPUT);
  pinModeFast(inBR_Front, OUTPUT);

  pinModeFast(inAL_Back, OUTPUT);
  pinModeFast(inAR_Back, OUTPUT);
  pinModeFast(inBL_Back, OUTPUT);
  pinModeFast(inBR_Back, OUTPUT);

  pinModeFast(inAL_Tail, OUTPUT);
  pinModeFast(inAR_Tail, OUTPUT);
  pinModeFast(inBL_Tail, OUTPUT);
  pinModeFast(inBR_Tail, OUTPUT);
}
void setMotors(char motor,int speedL, int speedR) {
  if(motor == 'f'){
  if (speedR > 0) {
    digitalWriteFast (inAR_Front, LOW);
    digitalWriteFast (inBR_Front, HIGH);
    analogWrite(enR_Front, speedR);
  }
  else {
    digitalWriteFast(inAR_Front, HIGH);
    digitalWriteFast(inBR_Front, LOW);
    analogWrite(enR_Front, speedR);
  }
  if (speedL > 0) {
    digitalWriteFast (inAL_Front, LOW);
    digitalWriteFast (inBL_Front, HIGH);
    analogWrite(enL_Front, speedL);
  }
  else {
    digitalWriteFast(inAL_Front, HIGH);
    digitalWriteFast(inBL_Front, LOW);
    analogWrite(enL_Front, speedL);
  }
  }
  if(motor == 'b'){
  if (speedR > 0) {
    digitalWriteFast (inAR_Back, LOW);
    digitalWriteFast (inBR_Back, HIGH);
    analogWrite(enR_Back, speedR);
  }
  else {
    digitalWriteFast(inAR_Back, HIGH);
    digitalWriteFast(inBR_Back, LOW);
    analogWrite(enR_Back, speedR);
  }
  if (speedL > 0) {
    digitalWriteFast (inAL_Back, LOW);
    digitalWriteFast (inBL_Back, HIGH);
    analogWrite(enL_Back, speedL);
  }
  else {
    digitalWriteFast(inAL_Back, HIGH);
    digitalWriteFast(inBL_Back, LOW);
    analogWrite(enL_Back, speedL);
  }
  }
  if(motor == 't'){
  if (speedR > 0) {
    digitalWriteFast (inAR_Tail, LOW);
    digitalWriteFast (inBR_Tail, HIGH);
    analogWrite(enR_Tail, speedR);
  }
  else {
    digitalWriteFast(inAR_Tail, HIGH);
    digitalWriteFast(inBR_Tail, LOW);
    analogWrite(enR_Tail, speedR);
  }
  if (speedL > 0) {
    digitalWriteFast (inAL_Tail, LOW);
    digitalWriteFast (inBL_Tail, HIGH);
    analogWrite(enL_Tail, speedL);
  }
  else {
    digitalWriteFast(inAL_Tail, HIGH);
    digitalWriteFast(inBL_Tail, LOW);
    analogWrite(enL_Tail, speedL);
  }
  }

}

void setFrontWheels(int speedL, int speedR) {
  if (speedR > 0) {
    digitalWriteFast (inAR_Back, HIGH);
    digitalWriteFast (inBL_Back, LOW);
    analogWrite(enL_Back, speedR);
  }
  else {
    digitalWriteFast (inAR_Back, LOW);
    digitalWriteFast (inBL_Back, HIGH);
    analogWrite(enL_Back, speedR);

  }
  if (speedL > 0) {
    digitalWriteFast (inAL_Back, LOW);
    digitalWriteFast (on_4, HIGH);
    analogWrite(enR_Back, speedL);
  }
  else {
    digitalWriteFast (inAL_Back, HIGH);
    digitalWriteFast (on_4, LOW);
    analogWrite(enR_Back, speedL);
  }
}

void setTailWheels(int speedL , int speedR) {
  if (speedR > 0) {
    digitalWriteFast(kol_1, LOW);
    digitalWriteFast(kol_2, HIGH);
    analogWrite(kol_hiz1, speedR);
  }
  else {
    digitalWriteFast(kol_1, HIGH);
    digitalWriteFast(kol_2, LOW);
    analogWrite(kol_hiz1, speedR);
  }
  if (speedL > 0) {
    digitalWriteFast(kol_3, HIGH);
    digitalWriteFast(kol_4, LOW);
    analogWrite(kol_hiz2, speedL);
  }
  else {
    digitalWriteFast(kol_3, LOW);
    digitalWriteFast(kol_4, HIGH);
    analogWrite(kol_hiz2, speedL);
  }
}

void stopAllWheels() {
  stopBackWheels();
  stopFrontWheels();
  stopTailWheels();
}

void stopFrontWheels() {
  digitalWriteFast(inAL_Front, HIGH);
  digitalWriteFast(inAR_Front, HIGH);
  digitalWriteFast(inBL_Front, HIGH);
  digitalWriteFast(inBR_Front, HIGH);
}

void stopBackWheels() {
  digitalWriteFast(inAL_Back, HIGH);
  digitalWriteFast(inAR_Back, HIGH);
  digitalWriteFast(inBL_Back, HIGH);
  digitalWriteFast(inBR_Back, HIGH);
}

void stopTailWheels() {
  digitalWriteFast(inAL_Tail, HIGH);
  digitalWriteFast(inAR_Tail, HIGH);
  digitalWriteFast(inBL_Tail, HIGH);
  digitalWriteFast(inBR_Tail, HIGH);
}
