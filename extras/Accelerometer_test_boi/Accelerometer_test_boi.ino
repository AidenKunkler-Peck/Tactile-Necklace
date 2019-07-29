#include<Wire.h>//test

const int MPU6050_addr=0x68;

int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;



void getValues(){

  Wire.beginTransmission(MPU6050_addr);

  Wire.write(0x3B);

  Wire.endTransmission(false);

  Wire.requestFrom(MPU6050_addr,14,true);  

  AccX=Wire.read()<<8|Wire.read();

  AccY=Wire.read()<<8|Wire.read();

  AccZ=Wire.read()<<8|Wire.read();

  Temp=Wire.read()<<8|Wire.read();

  GyroX=Wire.read()<<8|Wire.read();

  GyroY=Wire.read()<<8|Wire.read();

  GyroZ=Wire.read()<<8|Wire.read();

}



void setup() {

Wire.begin();

  Wire.beginTransmission(MPU6050_addr);

  Wire.write(0x6B);

  Wire.write(0);

  Wire.endTransmission(true);

  Serial.begin(9600);

}



void loop() {

getValues();

AccX = AccX;

AccY = AccY;

AccZ = AccZ;

GyroX = GyroX;

GyroY = GyroY;

GyroZ = GyroZ;

Temp = Temp;



Serial.print("Accel X :");

Serial.println(AccX);

Serial.print("Accel Y :");

Serial.println(AccY);

Serial.print("Accel Z :");

Serial.println(AccZ);

Serial.print("Gyro X :");

Serial.println(GyroX);

Serial.print("Gyro Y :");

Serial.println(GyroY);

Serial.print("Gyro Z :");

Serial.println(GyroZ);

Serial.print("Temp :");

Serial.println(Temp/340.00+19.53);

delay(500);

}
