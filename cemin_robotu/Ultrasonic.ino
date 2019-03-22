#define trigPinFront   9
#define echoPinFront   8
#define trigPinBack    A7
#define echoPinBack    A6
#define trigPinInside  A12
#define echoPinInside  A13

//This method defines pins input for echo pins and output for trig pins of 3 ultrasonic sensors.
void defineUltrasonic() {
  pinModeFast(trigPinFront, OUTPUT);
  pinModeFast(echoPinFront, INPUT);
  
  pinModeFast(trigPinBack, OUTPUT);
  pinModeFast(echoPinBack, INPUT);
  
  pinModeFast(trigPinInside, OUTPUT);
  pinModeFast(echoPinInside, INPUT);
}

//This methods returns distance the one of the ultrasonic sensors sees.
int distanceMeasure(char sensor) { //Takes parameter of sensor ('f' for front,'b' for back,'i' for inside)
  int trigPin;                     //Declaring the pins 
  int echoPin;
  int duration;
  if(sensor == 'f'){               //Changing pins due to target sensor.
    trigPin = trigPinFront;
    echoPin = echoPinFront;
  }
  else if(sensor == 'b'){
    trigPin = trigPinBack;
    echoPin = echoPinBack;
  }
  else if(sensor == 'i'){
    trigPin = trigPinInside;
    echoPin = echoPinInside;
  }
  digitalWriteFast(trigPin, LOW);     //Default ultrasonic sensor usage but in here DigitalWriteFast library has used because of to get better performance
  delayMicroseconds(2);               //with faster writing speed.
  digitalWriteFast(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWriteFast(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  //Measures the come back duration of sound which is trig pin sent and writes it to duration as miliseconds. 
  return (duration * 0.034 / 2);      //Converts the duration to distance with multiply it with speed of sound at normal conditions and returns it. 
}
