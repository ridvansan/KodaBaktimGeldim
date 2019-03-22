void stepUp(){
  setServo(frontServo,90);
  setServo(backServo,17);
  setMotors('t',100,100);
  setMotors('f',100,100);
  delay(1000);
  stopAllMotors();
  setServo(backServo,180);
  setMotors('f',100,100);
  setMotors('b',100,100);
  delay(200);
  stopAllMotors();
  setServo(frontServo,180); 
}

void stepDown(){
  
}
