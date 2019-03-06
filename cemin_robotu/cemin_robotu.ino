#include <Servo.h>
#include <digitalWriteFast.h>

int basamak = 0;

void setup() {
  Serial.begin(9600);
  defineUltrasonic();
  servoInitial();
  
}


void loop(){
  
}
