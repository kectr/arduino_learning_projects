#include <Arduino.h>

const uint8_t cclock = 10;
const uint8_t sclock = 11;
const uint8_t oe = 7; // select it pwm for brightness
const uint8_t A = 8;
const uint8_t B = 9;
const uint8_t data_pin = 12;

const uint8_t rowNumber = 16;
const uint8_t columnNumber = 64;
byte screen[16*64/8];



//declarations
byte readBit(byte value, uint8_t position);
void clock_pulse();
void sclock_pulse();
void data_out(byte data);
void rows_out(uint8_t index);
void screen_out();
void screen_clear();
void write_to_cordinate(uint8_t row,uint8_t column,byte data);
void draw_array(uint8_t array[],int array_row,int array_column,int row,int column);


uint8_t sekil[] =
{
0x00, 0x02, 0x42, 0x40, 0x20, 0x20, 0x04, 0x04
};





void setup() {
    pinMode(cclock,OUTPUT);
    pinMode(sclock,OUTPUT);
    pinMode(oe,OUTPUT);
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(data_pin,OUTPUT);
    digitalWrite(cclock,0);
    digitalWrite(sclock,0);
    digitalWrite(A,0);
    digitalWrite(B,0);
    digitalWrite(oe,1);
    screen_clear();
}

void loop() {
    screen_clear();
    screen_out();
    //draw_array(sekil,8,1,0,0);
}

//functions
byte readBit(byte value, uint8_t position) {
  return (value >> position) & 1;
}

void clock_pulse(){
    
    delayMicroseconds(pulsetime_micro);
    digitalWrite(cclock,1);
    
    delayMicroseconds(pulsetime_micro);
    digitalWrite(cclock,0);
}

void sclock_pulse(){
    delayMicroseconds(pulsetime_micro);
    digitalWrite(sclock,1);

    delayMicroseconds(pulsetime_micro);
    digitalWrite(sclock,0);
}

void data_out(byte data){
    digitalWrite(data_pin,!(data&1));
    clock_pulse();
    
}

void rows_out(uint8_t index){
    switch (index)
    {
    case 0:
        digitalWrite(A,1);
        digitalWrite(B,1);
        break;
    case 1:
        digitalWrite(A,0);
        digitalWrite(B,0);
        break;

    case 2:
        digitalWrite(A,1);
        digitalWrite(B,0);
        break;
    case 3:
        digitalWrite(A,0);
        digitalWrite(B,1);
        break;
    default:
        break;
    }

    for(int lap = 0 ; lap<8;lap++){
        for(int row = 12 + index;row>=0;row-=4){
            for(int j = 7;j>=0;j--){
                data_out(readBit(screen[row+16*lap],j));
            }
        }
    }
    sclock_pulse();

}

void screen_out(){
    rows_out(0);
    rows_out(1);
    rows_out(2);
    rows_out(3);
}

void screen_clear(){
    for(int x = 0 ; x<128 ;x++){
        screen[x] = 0x00;
    }
}

void write_to_cordinate(uint8_t row,uint8_t column,byte data){
    bitWrite(screen[row + 16*(column/8)],7-column%8,data);
}

void draw_array(uint8_t array[],int array_row,int array_len_in_bytes,int row,int column){
    for(int i = 0;i<array_row;i++){
        for(int j = 0 ; j<array_len_in_bytes*8;j++){
            write_to_cordinate(row+i,column+j,readBit(array[(j/8)+i*array_len_in_bytes],7-j%8));
        }
    }
}


