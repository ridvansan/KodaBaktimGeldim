// ÖN (1)
const int enL_Front = 2;//beyaz
const int enR_Front = 3;//sarı
const int inR_Front = 22;//mor SAĞ
const int inBL_Front = 23;//gri
const int inAL_Front = 24;//yesil SOL
const int on_4 = 25;//mavi
//ARKA (2)
const int enR_Back = 4;//mor
const int enL_Back = 5;//mavi
const int inAR_Back = 26;//siyah SAĞ
const int inBR_Back = 27;//yeşil
const int inAL_Back = 28;//sarı SOL
const int inBL_Back = 29;//mor
//KOL (3)
const int kol_hiz1 = 6;//siyah
const int kol_hiz2 = 7;//gri
const int kol_1 = 30;//beyaz SAĞ
const int kol_2 = 31;//mavi
const int kol_3 = 32;//turuncu SOLW
const int kol_4 = 33;//yeşil

void defineDCMotors() {
  pinModeFast(enL_Front, OUTPUT);
  pinModeFast(inR_Front, OUTPUT);
  pinModeFast(inBL_Front, OUTPUT);
  pinModeFast(enR_Front, OUTPUT);
  pinModeFast(inAL_Front, OUTPUT);
  pinModeFast(on_4, OUTPUT);
  pinModeFast(enR_Back, OUTPUT);
  pinModeFast(enL_Back, OUTPUT);
  pinModeFast(inAR_Back, OUTPUT);
  pinModeFast(inBR_Back, OUTPUT);
  pinModeFast(inAL_Back, OUTPUT);
  pinModeFast(inBL_Back, OUTPUT);
  pinModeFast(kol_hiz1, OUTPUT);
  pinModeFast(kol_hiz2, OUTPUT);
  pinModeFast(kol_1, OUTPUT);
  pinModeFast(kol_2, OUTPUT);
  pinModeFast(kol_3, OUTPUT);
  pinModeFast(kol_4, OUTPUT);
}
void setBackWheels(int speedL, int speedR) {
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

void stopAllWheels(){
  stopBackWheels();
  stopFrontWheels();
  stopTailWheels();
}

void stopFrontWheels() {
  digitalWriteFast(inAR_Back, HIGH);
  digitalWriteFast(inBL_Back, HIGH);
  digitalWriteFast(inAL_Back, HIGH);
  digitalWriteFast(on_4, HIGH);
}

void stopBackWheels() {
  digitalWriteFast (inAR_Back, HIGH);
  digitalWriteFast (inBR_Back, HIGH);
  digitalWriteFast (inAL_Back, HIGH);
  digitalWriteFast (inBL_Back, HIGH);
}

void stopTailWheels() {
  digitalWriteFast(kol_1, HIGH);
  digitalWriteFast(kol_2, HIGH);
  digitalWriteFast(kol_3, HIGH);
  digitalWriteFast(kol_4, HIGH);
}
