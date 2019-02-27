#define trigPin  A0
#define echoPin  A1
#define trigPin2  A7
#define echoPin2  A6
#define trigPin3  A12
#define echoPin3  A13

void defineUltrasonic() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT);
}

int mesafeOlcOn() {
  //ULTRASONİK
  digitalWriteFast(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWriteFast(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWriteFast(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  /*Serial.print("distance");
  Serial.println(distance);*/
  stat++;
  total += distance;
  if(stat == 5){
    cm = total/5;
    stat = 0;
    total =0;
    return cm;
  }
  return 0;
}

int mesafeOlcArka() {
  //ULTRASONİK
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  /*Serial.print("distance");
  Serial.println(distance);*/
  stat2++;
  total2 += distance;
  if(stat2 == 3){
    cm2 = total2/3;
    stat2 = 0;
    total2 =0;
    return cm2;
  }
  return 0;
}
int mesafeOlcInis() {
  //ULTRASONİK
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  /* Serial.print("distance");
  Serial.println(distance);*/
  stat3++;
  total3 += distance;
  if(stat3 == 3){
    cm3 = total3/3;
    stat3 = 0;
    total3 =0;
    return cm3;
  }
  return 0;
}
