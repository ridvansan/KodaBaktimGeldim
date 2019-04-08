
//This methods sets Servos positions at beginning
void servoInitial() {                              
  frontServo.attach(10);                            //Simply attches servo pin and servo object
  backServo.attach(11);
  setServo(backServo,170);                          //Setting servos to their initial position
  setServo(frontServo,80);
  delay(1000);                                      //Delay for testing
}


//This method sets Servos Degree.
void setServo(Servo servo,int angle) {              //This mathod takes parameter of the name of Servo Object and target angle
  int initialAngle = servo.read();                  //This line read servos position at beginning degree.
  if (initialAngle > angle) {                       //This if block check servos target angle and initial angle and compares them
    for (int i = initialAngle ; i >= angle; i--) {  //If target angle is bigger than initial this decreases servos angle one by one. 
      servo.write(i);
      delay(10);
      
    }

  }
  else {                                            //Basically the opposite of the if statement
    for (int i = initialAngle ; i < angle; i++) {
      servo.write(i);
      delay(10);
    }
  }
  servo.write(angle);                               // Writing the target angle
}
