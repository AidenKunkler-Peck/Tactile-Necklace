/* Aiden and Jonny (Date started= Summer 2018, Date completed 6/19/19): 
 *  Our tactile necklace was created with the goal of allowing a spatially disoriented wearer to be able to better understand his/her position relative to gravity. 
 *  The necklace operates using an accelerometer and gyroscope Arduino microcontroller which transmits data to an Arduino Nano. 
 *  The Nano then interprets the accelerometer/ gyroscope data and converts it into an output in the form of vibrations in the necklace. 
 *  The necklace consists of eight brush motor vibrators that pulsate independently based on the position of the sensor. 
 *  https://github.com/AidenKunkler-Peck/Tactile-Necklace
*/
//Including the libraries used in the code
#include <AccelTact.h>
//establishing Global Variables
AccelTact myNecklace;
//runs once, gets the necklace ready
void setup() {
  //<-- This symbol causes the computer to ignore the code to the right of it.
  myNecklace.begin());//initializes communication with the Arduino
}
//runs forever
void loop() {
  int accel=mynecklace.getacceleration
}
