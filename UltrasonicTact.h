/*Jonathan Lam
 https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ 2019/07/16*/

//sets up the UltrasonicTact Header file
#ifndef UltrasonicTact_h
#define UltrasonicTact_h

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <UltrasonicTact.h>
#include <Arduino.h>

class UltrasonicTact{
  private:
    //defines pins numbers
    int trigPin;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int echoPin;
    //defines variables
    long duration;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int distance;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int tactArray[4];
    //TODO: EXPLAIN WHAT METHOD DOES
    void clearTacts(int* tactArray);
  public:
    //Creates a new UltrasonicTact object
    UltrasonicTact();
    //Initializes the class, can't always be done at same time as constructor
    void begin();
    //TODO: EXPLAIN WHAT METHOD DOES
    int* tactvalues4u(int distance);
	//acquires distance value
	int getDistance();
};
#endif
