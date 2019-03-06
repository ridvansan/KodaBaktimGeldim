

Servo frontServo;
Servo backServo;

void servoInitial() {
  backServo.write(180);
  frontServo.write(180);
  frontServo.attach(12);
  backServo.attach(11);

  delay(1000);
}



void setServo(Servo servo,int angle) {
  int initialAngle = servo.read();
  if (initialAngle > angle) {
    for (int i = angle ; initialAngle >= angle; i++) {
      servo.write(i);
      delay(10);
    }
  }
  else {
    for (int i = initialAngle ; initialAngle < angle; i++) {
      servo.write(i);
      delay(10);
    }
  }
}
