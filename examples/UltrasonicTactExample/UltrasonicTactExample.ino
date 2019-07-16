/*Jonathan Lam and Aiden
 https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ 2019/07/16*/

//includes the libraries of code necessary to make this one work
#include <Ultrasonic_Tact.h>

//The object used to interfact with the class
Ultrasonic_Tact ultrasonic_tact();

//TODO: EXPLAIN WHAT METHOD DOES
void setup() {
    //sets up the class
    ultrasonic_tact.begin();
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication

}

//TODO: EXPLAIN WHAT METHOD DOES
void loop() {
    // Clears the trigPin
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
    // Prints the distance on the Serial Monitor and prints tact strength values
    Serial.print("Distance: ");
    Serial.println(distance);
    ultrasonic_tact.tactvalues4u(distance, tactArray);
    Serial.print ("tact 1: ");
    Serial.println(tactArray[0]);
    Serial.print ("tact 2: ");
    Serial.println(tactArray[1]);
    Serial.print ("tact 3: ");
    Serial.println(tactArray[2]);
    Serial.print ("tact 4: ");
    Serial.println(tactArray[3]);
    delay(100);

}
