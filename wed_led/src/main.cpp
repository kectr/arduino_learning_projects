#include <Arduino.h>

//Define

const uint8_t data_pin = 5;
const uint8_t clock = 4;
const uint8_t sclock = 3;
const uint8_t oe = 2;
const uint8_t A = 6;
const uint8_t B = 7;



const uint8_t pulsetime_micro = 100;
const uint8_t rowNumber = 16;
const uint8_t columnNumber = 64;

uint8_t screen[rowNumber*columnNumber/8] = {0xff};

//Declarations
void clock_pulse();
void data_out(uint8_t data_pin,uint8_t data);
void rows_out(uint8_t first_index);


void setup() {
    //Pinmodes are to be worked later.
    pinMode(data_pin,OUTPUT);
    pinMode(clock,OUTPUT);
    digitalWrite(clock,0);   
    pinMode(sclock,OUTPUT);
    digitalWrite(sclock,0);   
    pinMode(oe,OUTPUT);
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT); 
    
}   

void loop() {
    digital
    clock_pulse();
}


//Functions

//From Byte to bit
byte readBit(uint8_t value, uint8_t position) {
  return (value >> position) & 1;
}

//Making some pulse on clock pin.
void clock_pulse(){
    delayMicroseconds(pulsetime_micro);
    digitalWrite(clock,1);
    delayMicroseconds(pulsetime_micro);
    digitalWrite(clock,0);
    
}


//Puts some data ( ex : 0xff ) to pin by shifting every bit and usind & operator.
void data_out(uint8_t data){
    for(uint8_t i = 7;i>=0;i--){
        digitalWrite(data_pin,(data,i));
        clock_pulse();
    }   
}

