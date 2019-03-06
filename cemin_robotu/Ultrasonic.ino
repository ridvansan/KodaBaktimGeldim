#define trigPinFront   A0
#define echoPinFront   A1
#define trigPinBack    A7
#define echoPinBack    A6
#define trigPinInside  A12
#define echoPinInside  A13

void defineUltrasonic() {
  pinModeFast(trigPinFront, OUTPUT);
  pinModeFast(echoPinFront, INPUT);
  pinModeFast(trigPinBack, OUTPUT);
  pinModeFast(echoPinBack, INPUT);
  pinModeFast(trigPinInside, OUTPUT);
  pinModeFast(echoPinInside, INPUT);
}

int distanceMeasure(char sensor) {
  int trigPin;
  int echoPin;
  int duration;
  if(sensor == 'f'){
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
  digitalWriteFast(trigPin, LOW);
  delayMicroseconds(2);
  digitalWriteFast(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWriteFast(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034 / 2);
}
