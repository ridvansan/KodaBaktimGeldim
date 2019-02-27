#include <digitalWriteFast.h>



float duration;
int distance;
int stat = 0;
int total = 0;
int stat2 = 0;
int total2 = 0;
int stat3 = 0;
int total3 = 0;
int cm,cm2,cm3,x;




int basamak = 0; //NORMALİ SIFIR

void setup() {
  Serial.begin(9600);
  defineDCMotors();
  defineUltrasonic();
  servoInitial();
  
}


void loop(){
  
}
