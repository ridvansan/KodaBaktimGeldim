void stepUp(){
  stopAllWheels();
  setFrontServo(90);
  setBackServo(20);
  setMotors('f',100,100); setMotors('t',100,100);
  delay(1000);
  stopAllWheels();
  setBackServo(180);
  setMotors('b',100,100);setMotors('b',100,100);
  delay(1000);
  setFrontServo(90);
}

void stepDown(){
  stopAllWheels();
  setBackServo(20);
  setFrontWheels(100,100); setBackWheels(100,100);
  while(mesafeOlcInis() < 7){
  }
  stopAllWheels();
  setBackServo(180);
  setFrontServo(90);
}
