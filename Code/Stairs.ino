void stepUp(){
  stopMotors('b');
  frontServo.write(180);//lifts the front servo up for it to be ready to enter the ledge
  delay(600);
  setMotors('f',200,200);// Both Motors set to front with the speed/8bit 200
  setMotors('b',255,255);
  delay(120);
  stopAllMotors();
  setServo(backServo,17);
  setMotors('t',255,255);
  setMotors('f',255,255);
  delay(2000);//goes for the whole stairs until the tail touches the ledge
  stopAllMotors();
  setServo(backServo,180);// lifts up the back servo and clear the ledge  
  setMotors('f',200,200);
  setMotors('b',255,255);
  delay(55); // moves a little bit further so that standing wont push the whole thing down 
  stopAllMotors();
  setServo(frontServo,94);//lifts the robot to the standby position for the next step
  delay(1000);
  currentStep++;// step counter adds one to it self
}
void stepDown(){
  stopAllMotors();
  setServo(frontServo,180);//lets the front servo up and the robot to a triangel shape 
  setMotors('b',-255,-255);
  setMotors('f',-200,-200);
  delay(400);// goes back a little bit for the back servo to not have problems extending down
  stopAllMotors();
  setServo(backServo,10); // extends the back servo down to the lower step
  delay(1000);
  setMotors('t',-200,-200);
  setMotors('f',-200,-200);
  while(distanceMeasure('i')<7){// in the previous position robot moves back until the inside sensor sees that the ledge has ended
  }
  setMotors('t',200,200);
  setMotors('f',200,200);
  delay(25);
  stopAllMotors();
  setServo(backServo,170);// lets the back servo to the standby position for the next step 
  delay(1000);
  setMotors('t',-200,-200);
  setMotors('f',-200,-200);
  delay(1100);
  stopAllMotors();
  setServo(frontServo,95);// lifts the robot up to the standby position for the next step
  delay(1000);
  
  
  currentStep++;// step counter adds one to it self
}
