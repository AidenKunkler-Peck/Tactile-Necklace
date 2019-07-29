/*Jonathan Lam
 https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ 2019/07/16*/

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <UltrasonicTact.h>

//Creates a new UltrasonicTact object
UltrasonicTact::UltrasonicTact() {
}

//Initializes the class, can't always be done at same time as constructor
void UltrasonicTact::begin() {
    //defines pins numbers
    trigPin = 10;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    echoPin = 11;
    //defines variables
    duration = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    distance = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    tactArray[4] = 0;
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication

}

int UltrasonicTact::getDistance() {
     digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
	return distance;
}
