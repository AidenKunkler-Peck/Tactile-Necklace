/*Jonathan Lam and Aiden
 https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ 2019/07/16*/

//includes the libraries of code necessary to make this one work
#include <UltrasonicTact.h>

//The object used to interfact with the class
UltrasonicTact ultrasonicTact;

int distance;
int* tactArray;

//TODO: EXPLAIN WHAT METHOD DOES
void setup() {
    //sets up the class
    ultrasonicTact.begin();
    Serial.begin(9600); // Starts the serial communication
}
//TODO: EXPLAIN WHAT METHOD DOES
void loop() {
    distance = ultrasonicTact.getDistance();
    // Prints the distance on the Serial Monitor and prints tact strength values
    Serial.print("Distance: ");
    Serial.println(distance);
}
