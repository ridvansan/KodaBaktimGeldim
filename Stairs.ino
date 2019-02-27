void stepUp(){
  stopAllWheels();
  setFrontServo(90);
  setBackServo(20);
  setFrontWheels(100,100); setTailWheels(100,100);
  delay(1000);
  stopAllWheels();
  setBackServo(180);
  setFrontWheels(100,100); setBackWheels(100,100);
  delay(100);
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
