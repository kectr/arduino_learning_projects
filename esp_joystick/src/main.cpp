#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial xbee(16,17); 

#define xpin 34
#define ypin 35

char package[16];
int joyx;
int joyy;

void setup() {
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  xbee.begin(9600);
}

void loop() {
  
  for(int i = 0;i<100;i++){
    xbee.write(package);
  }
}