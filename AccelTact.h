/* Aiden and Jonny (Date started= Summer 2018, Date completed 6/19/19): 
 *  Our tactile necklace was created with the goal of allowing a spatially disoriented wearer to be able to better understand his/her position relative to gravity. 
 *  The necklace operates using an accelerometer and gyroscope Arduino microcontroller which transmits data to an Arduino Nano. 
 *  The Nano then interprets the accelerometer/ gyroscope data and converts it into an output in the form of vibrations in the necklace. 
 *  The necklace consists of eight brush motor vibrators that pulsate independently based on the position of the sensor. 
 *  This class is for acquiring accelerometer values to be converted into tactor strength values in a seperate class.
 *  https://github.com/AidenKunkler-Peck/Tactile-Necklace
*/
//Including the libraries used in the code
#include<Wire.h>
#include<Arduino.h>
#ifndef AccelTact_h
#define AccelTact_h
class AccelTact{
	private:
		float oldvalue;//used later in averaging formula
		float newvalue;//used later in averaging formula
		float oldvalueAccelX;//used for averaging accelerometer values in the x-axis (oldvalue and new value averaged to get an approximate accelerometer value) 
		float oldvalueAccelY;//... y-axis
		float oldvalueAccelZ;//... z-axis
		float oldvalueGyroX;//used for averaging gyroscope values in the x-axis (oldvalue and new value averaged to get an approximate gyroscope value) 
		float oldvalueGyroY;//... y-axis
		float oldvalueGyroZ;//... z-axis
		float newvalueAccelX;//used for averaging accelerometer values in the x-axis (oldvalue and new value averaged to get an approximate accelerometer value) 
		float newvalueAccelY;//... y-axis
		float newvalueAccelZ;//... z-axis
		float newvalueGyroX;//used for averaging gyroscope values in the x-axis (oldvalue and new value averaged to get an approximate gyroscope value) 
		float newvalueGyroY;//... y-axis
		float newvalueGyroZ;//... z-axis
		float zerox;//balance point for where the accelerometer is set in the x-axis (where no vibrators are on)
		float zeroy;//... y-axis
		float avgx;//acquire from averaging the old and new values 
		float avgy;//acquire from averaging the old and new values 
		float accx=0; //accelerometer data is non integer values, with decimals
		float accy=0; //data inputted from sensor has x and y axes
		const int maxacc=16500;//Largest input value from accelerometer
		const int vMax=255;//max strength of vibrator is 255, exceeding 255 with overflow, the byte will read the 8 rightmost bits
		const int MPU6050_addr=0x68;
		int16_t AccX,AccY,AccZ,GyroX,GyroY,GyroZ;
		void getValues(); //get acc values
	public:
		void begin (); //initializes the function, this can't be in the constructor
		int getAccel (); //gets the accelerometer values from the sensor
		}
#endif

 