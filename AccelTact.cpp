/* Aiden and Jonny (Date started= Summer 2018, Date completed 6/19/19): 
 *  Our tactile necklace was created with the goal of allowing a spatially disoriented wearer to be able to better understand his/her position relative to gravity. 
 *  The necklace operates using an accelerometer and gyroscope Arduino microcontroller which transmits data to an Arduino Nano. 
 *  The Nano then interprets the accelerometer/ gyroscope data and converts it into an output in the form of vibrations in the necklace. 
 *  The necklace consists of eight brush motor vibrators that pulsate independently based on the position of the sensor. 
 *  https://github.com/AidenKunkler-Peck/Tactile-Necklace
 TO DO: allow pins to be any number 
*/

//Including the libraries used in the code
#include<Wire.h>
#include <AccelTact.h>
#define NUMSAMPLES 150
//constructor to create a AccelTact object
void AccelTact::begin() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  getValues(); //get acc values
  average();
  zerox=oldvalueAccelX;
  zeroy=oldvalueAccelY;
  delay(500);
  Serial.println("Accelerometer Initialized");
}
int AccelTact:: getAccel(int axisNum){ //gets the acceleration values from the sensor
  getValues(); //get acc values
  average();
  if (axisNum == 0){
  	return AccX;
  }
 else if (axisNum == 1){
 	return AccY;
 }
 else if(axisNum == 2){
 	return AccZ;
 }
  }
//Beginning communication with the accelerometer/gyroscopre Arduino "Wire.beginTransmission"
void AccelTact::getValues(){
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);  
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
}

//averaging function that creates more reliable accel values to be returned in getValues
void AccelTact::average(){
  oldvalueAccelX = AccX;//setting acquired AccX value to oldvalueAccelX to be used in averaging
  oldvalueAccelY = AccY;
  oldvalueAccelZ = AccZ;
  oldvalueGyroX = GyroX;
  oldvalueGyroY = GyroY;
  oldvalueGyroZ = GyroZ;
  for(int avg = 0;avg < 50;avg++){//for loop for averaging (averaged 50 times)
    getValues();//get values again and name them new values to be used in averaging 
    newvalueAccelX = AccX;
    newvalueAccelY = AccY;
    newvalueAccelZ = AccZ;
    newvalueGyroX = GyroX;
    newvalueGyroY = GyroY;
    newvalueGyroZ = GyroZ;
    oldvalueAccelX = (oldvalueAccelX + newvalueAccelX)/2;//averaging old and new values to get a more accurate reading of the accelerometer and gyroscope data
    oldvalueAccelY = (oldvalueAccelY + newvalueAccelY)/2;
    oldvalueAccelZ = (oldvalueAccelZ + newvalueAccelZ)/2;
    oldvalueGyroX = (oldvalueGyroX + newvalueGyroX)/2;
    oldvalueGyroY = (oldvalueGyroY + newvalueGyroY)/2;
    oldvalueGyroZ = (oldvalueGyroZ + newvalueGyroZ)/2;
  }
  }