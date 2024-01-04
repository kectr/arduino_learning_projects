#include <Arduino.h>
#include <Servo.h>

#define rotation_button 4
#define motor_button 3 // defining pins for buttons
#define mode_button 2
// pot is A0

Servo Motor1;
Servo Motor2; // Initializing motors with servo

int motor_select = 0;
int rotation_select = 0; // defining variables for mods
int mode_select = 0;
int potValue;

void button_read(int button, int* variable);
void motors_run();

void setup()
{
  Motor1.attach(9, 1000, 2000); // Pin, min pulse width, max pulse width in microseconds
  Motor2.attach(10, 1000, 2000);
  pinMode(rotation_button, INPUT);
  pinMode(mode_button, INPUT);
  pinMode(motor_button, INPUT);
  Serial.begin(9600);
}

void loop()
{
  button_read(rotation_button, &rotation_select);
  button_read(mode_button, &mode_select);
  button_read(motor_button, &motor_select);
  potValue = analogRead(A0);
  Serial.print(potValue);
  Serial.print("-");
  potValue = map(potValue,0,1023,0,90);
  Serial.print(potValue);
  Serial.print("-");
  Serial.print(mode_select);
  Serial.print("-");
  Serial.print(motor_select);
  Serial.print("-");
  Serial.println(rotation_select);
  
  motors_run();
}

void motors_run(){
  if(mode_select){
    Motor1.write((rotation_select ? +1 : -1)*potValue +85); 
    Motor2.write((rotation_select ? +1 : -1)*potValue +85);  
  }else{
    if(motor_select){
      Motor1.write((rotation_select ? +1 : -1)*potValue +85); 
    }else{
      Motor2.write((rotation_select ? +1 : -1)*potValue +85); 
    }
    
  }
}

void button_read(int button, int* variable) {
  if (digitalRead(button)) {
    while (digitalRead(button)) {}
    *variable = !*variable;
  }
}
