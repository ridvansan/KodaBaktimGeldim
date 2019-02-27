#include <Servo.h>

Servo frontServo;
Servo backServo;

void servoInitial() {
  backServo.write(180);
  frontServo.write(180);
  frontServo.attach(12);
  backServo.attach(11);

  delay(1000);
}



void setFrontServo(int angle) {
  int initialAngle = frontServo.read();
  if (initialAngle > angle) {
    for (int i = angle ; initialAngle >= angle; i++) {
      frontServo.write(i);
      delay(10);
    }
  }
  else {
    for (int i = initialAngle ; initialAngle < angle; i++) {
      frontServo.write(i);
      delay(10);
    }
  }
}

void setBackServo(int angle) {
  int initialAngle = backServo.read();
  if (initialAngle > angle) {
    for (int i = angle ; initialAngle >= angle; i++) {
      backServo.write(i);
      delay(10);
    }
  }
  else {
    for (int i = initialAngle ; initialAngle < angle; i++) {
      backServo.write(i);
      delay(10);
    }
  }
}
