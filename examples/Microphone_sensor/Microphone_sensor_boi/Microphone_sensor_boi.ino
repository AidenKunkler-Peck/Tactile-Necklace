int ledPin=11;
int sensorPin=A0;
int val =0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop (){
  val =digitalRead(sensorPin);
  Serial.println (val);
  int volume=analogRead(A0);
   Serial.println(volume);
 
  // when the sensor detects a signal above the threshold value, LED flashes
  if (volume>86) {
    digitalWrite(ledPin, HIGH);
    //Serial.println("High");
  }
  else {
    digitalWrite(ledPin, LOW);
    //Serial.println("Low");
  }
}
