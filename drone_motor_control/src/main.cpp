#include <Servo.h>
Servo Motor1;
Servo Motor2;//Initializing motors with servo
int button_motor_select ;

void setup() {
  Motor1.attach(9, 1000, 2000); //Pin, min pulse width, max pulse width in microseconds
  Motor2.attach(10, 1000, 2000);

}
void loop() { 
  
}