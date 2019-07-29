/* Aiden and Jonny (Date started= Summer 2018, Date completed 6/19/19): 
 *  Our tactile necklace was created with the goal of allowing a spatially disoriented wearer to be able to better understand his/her position relative to gravity. 
 *  The necklace operates using an accelerometer and gyroscope Arduino microcontroller which transmits data to an Arduino Nano. 
 *  The Nano then interprets the accelerometer/ gyroscope data and converts it into an output in the form of vibrations in the necklace. 
 *  The necklace consists of eight brush motor vibrators that pulsate independently based on the position of the sensor. 
 *  https://github.com/AidenKunkler-Peck/Tactile-Necklace
 TO DO: allow pins to be any number 
*/

//Including the libraries used in the code
#include <SoftPWM.h>
#include<Wire.h>
#include <TactNecklace.h>
#define NUMSAMPLES 150
//constructor to create a TactNecklace object
void TactNecklace::begin(int* vPins, int numPins) {
  // put your setup code here, to run once:
  SoftPWMBegin();
  Serial.println(numPins);
  delay(500);
  Serial.print("Tactile Necklace Initialized");
  this ->numPins=numPins;
  this ->vPins=vPins;
}
//turns all vibrators on and then off to simulate a pulsation
void TactNecklace::pulse (){
   for(int i=0; i<numPins; i++){
    SoftPWMSet(vPins[i],255);
   }
  delay(125);
  for(int i=0; i<numPins; i++){
    SoftPWMSet(vPins[i],0);
   }
  delay(125);
}
//turns on each tactor individually then turns that same tactor off so that the vibrators turn on in a circle
void TactNecklace::circle (){
  for(int i=0; i<numPins; i++){
    SoftPWMSet(vPins[i],255);
    delay(125);
    SoftPWMSet(vPins[i],0);
  }
}
//acquires acceleration values and sends it to the vibrator pins which determines the strength of the vibration
void TactNecklace::  sendVibration(int accX, int accY){

  tactValues(accX,accY, myValues);//sets accelerometer and gyroscope data to pins for vibrators
  for (int i=0; i<=numPins; i++) {//sets each accelerometer value to the designated pin (1-8)
    SoftPWMSet(vPins[i], scaler(myValues[i]));
  }
//for troubleshooting in the serial monitor
  for(int i=0;i<numPins;i++){
    Serial.print("tact ");
    Serial.print(i);
    Serial.print("= ");
    Serial.println(scaler(myValues[i]));
  }
}
//want your min to be 34 because it is at the point where it first starts to be noticeable, max is lower than 255 because that is the maximum vibration strength we deemed necessary
//  needed to lower vibration strength even lower because voltage was increased from 5V to 7.4, so the new numbers are 69% of original numbers
int TactNecklace::scaler(float input){
  if (input<30){
     return (0);
  }
  else {
    return (50+(130*(input/255)));
  }
}
//tactValues=acquiring the vibrator strength values from the accelerometer/gyroscope Arduino
//myValues=formula for converting Arduino acceleroemter/gyroscope values to output tactor strength values (each tactor has a seperate formula specific to the desired output of each vibrator relative to the orientation of the Arduino)
//"if"/"else if"=if the conditions of the "if" function are met then the code within the function is carried out, if the conditions are not met the next "else if" function is evaluated
void TactNecklace::tactValues(float accX, float accY, int* myValues){
  clearTacts(myValues);
  if (accY<0 && accX>0){
     myValues[0]=(abs(accY)/64)+30;
     myValues[1]=sqrt(pow(accX,2)+pow(accY,2))/64;
     myValues[2]=(accX)/64;  
  }
  else if (accY<0 && accX<0){
    myValues[2]=abs(accX)/64;
    myValues[3]=sqrt(pow(accX,2)+pow(accY,2))/64;
    myValues[3]=sqrt(pow(accX,2)+pow(accY,2))/64;
    myValues[4]=abs(accY/64)+30;
  }
  else if (accY>0 && accX<0){
    myValues[4]=(abs(accY)/64)+30;
    myValues[5]=sqrt(pow(accX,2)+pow(accY,2))/64;
    myValues[6]=abs(accX)/64;  
  }
  else if (accY>0 && accX>0){
    myValues[0]=(accY/64)+30;  
    myValues[6]=abs(accX)/64;
    myValues[7]=sqrt(pow(accX,2)+pow(accY,2))/64;
  }
}
//TODO: EXPLAIN WHAT METHOD DOES
int* TactNecklace::tactvalues4u(int distance) {
    clearTacts(myValues);
    if (75 <= distance && distance <= 100) {
      myValues[0] = ((9 * (100 - distance)) + 30);
    
    if (50 <= distance && distance <= 75) {
      myValues[0]=255;
      myValues[1] = (9 * (75 - distance) + 30);
      myValues[2] = (9 * (75 - distance) + 30);
    }
    if (25 <= distance && distance <= 50) {
      for (int i = 0; i < 3; i++) {
      myValues[i] = 255;
      }
      myValues[3] = (9 * (50 - distance) + 30);
    }
    if (distance <= 25) {
      for (int i = 0; i < 4; i++) {
      myValues[i] = 255;
      }
    }
	return myValues;
	}
}

//TODO: EXPLAIN WHAT METHOD DOES
void TactNecklace::clearTacts(int* myValues) {
    for (int i = 0; i < 4; i++) {
      myValues[i] = 0;
    }

}

