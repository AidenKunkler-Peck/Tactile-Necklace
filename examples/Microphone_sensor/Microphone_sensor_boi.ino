int ledPin=11;
int sensorPin=3;
boolean val =0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop (){
  val =digitalRead(sensorPin);
  Serial.println (val);
  Serial.println(analogRead(A0));
  int volume=analogRead(A0);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (volume>16) {
    digitalWrite(ledPin, HIGH);
    //Serial.println("High");
  }
  else {
    digitalWrite(ledPin, LOW);
    //Serial.println("Low");
  }
}
