#include <Servo.h>

Servo motor;

void setup()
{
  motor.attach(2, 1000, 2000);
}

void loop()
{
  motor.write(180);
}
