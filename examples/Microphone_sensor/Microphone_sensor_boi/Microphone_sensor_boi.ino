int ledPin=11;
int sensorPin=A0;
int val =0;
int vPins[4]={3,5,6,9};

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  for (int i=0; i<3;i++){
    pinMode(vPins[i], OUTPUT);
  }
  Serial.begin (9600);
   for (int i=0; i<4;i++){
      analogWrite(vPins[i], 0);
    }
    delay(10000);
}
void loop (){
  val =digitalRead(sensorPin);
  Serial.println (val);
  int volume=analogRead(A0);
   Serial.println(volume);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (volume>86) {
    for (int i=0; i<4;i++){
      analogWrite(vPins[i], 175);
    }
    delay(50);
  }
  else {
    for (int i=0; i<4;i++){
      analogWrite(vPins[i], 0);
    }
  }
}
