#include <Servo.h>

Servo motor;

void initializeMotor()
{
  motor.attach(2, 1000, 2000);
}

void spinMotor(int speed)
{
  motor.write(speed); 
}

void setup() {
  pinMode(2,OUTPUT);
  initializeMotor();
}

void loop() {
  spinMotor(100);
}
