#include "MPU9250.h"

MPU9250 mpu; // You can also use MPU9255 as is

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  delay(500);
  mpu.setup(0x68);  // change to your own address
  
  calibration();
  Serial.println("---------------------");
  Serial.println("Calibration completed");
  Serial.println("---------------------");
  delay(500);
}

void loop()
{
  if (mpu.update())
  {
    Serial.print("Yaw: ");
    Serial.print((mpu.getYaw()));

    Serial.print("  Pitch: ");
    Serial.print((mpu.getPitch()));
    
    Serial.print("  Roll: ");
    Serial.println((mpu.getRoll()));
  }
}
