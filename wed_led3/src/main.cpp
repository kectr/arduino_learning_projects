#include <Arduino.h>


const uint8_t clock = 2;
const uint8_t sclock = 3;
const uint8_t oe = 4; // select it pwm for brightness
const uint8_t A = 5;
const uint8_t B = 6;
const int8_t data_pin = 7;


const uint8_t pulsetime_micro = 1000;


const uint8_t rowNumber = 16; 
const uint8_t columnNumber = 64;
uint8_t screen[rowNumber][columnNumber] = {1}; //clear screen is all ones


void clock_pulse();
void sclock_pulse();
void data_out(uint8_t data);
void rows_out(uint8_t i_row);
void screen_out();




void setup() {
    pinMode(clock,OUTPUT);
    pinMode(sclock,OUTPUT);
    pinMode(oe,OUTPUT);
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(data_pin,OUTPUT);

    analogWrite(oe,255);//brighness (0-255)

}
  

void loop() {

}


void clock_pulse(){
    digitalWrite(clock,1);
    delayMicroseconds(pulsetime_micro);
    digitalWrite(clock,0);
    delayMicroseconds(pulsetime_micro);
}

void sclock_pulse(){
    digitalWrite(sclock,1);
    delayMicroseconds(pulsetime_micro);
    digitalWrite(sclock,0);
    delayMicroseconds(pulsetime_micro);
}

void data_out(uint8_t data){
    digitalWrite(data_pin,data);
    clock_pulse();
}

void rows_out(uint8_t i_row){

    switch (i_row)
    {
    case 0:
        digitalWrite(A,0);
        digitalWrite(B,0);
        break;
    case 1:
        digitalWrite(A,1);
        digitalWrite(B,0);
        break;

    case 2:
        digitalWrite(A,0);
        digitalWrite(B,1);
        break;
    case 3:
        digitalWrite(A,1);
        digitalWrite(B,1);
        break;
    }

    for(uint8_t laps = 0; laps <8 ; laps ++){
        for(uint8_t row_index = i_row + 12 ; row_index >=0 ; row_index-=4){
            for(uint8_t bit_index = 0; bit_index <8 ; bit_index ++){
                    data_out(screen[row_index][laps*8+bit_index]);
                }
        }
    }

    sclock_pulse();
}

void screen_out(){
    for(uint8_t i_row = 0; i_row<4 ; i_row ++){
        rows_out(i_row);
    }
}

void screen_clear(uint8_t data){
    for(uint8_t i = 0; i < rowNumber; i++){
        for(uint8_t j = 0 ; j < columnNumber ; j ++ ){
            screen[i][j] = data;
        }
    }
}



void draw_horizantal_line(uint8_t row, uint8_t start_column, uint8_t finish_column, uint8_t data){
    if(start_column>finish_column){
        uint8_t temp = start_column;
        start_column = finish_column;
        finish_column = temp;
    }
    for(;start_column<=finish_column;start_column ++){
        screen[row][start_column] = data;
    }
}

void draw_vertical_line(uint8_t column, uint8_t start_row, uint8_t finish_row, uint8_t data){
    if(start_row>finish_row){
        uint8_t temp = start_row;
        start_row = finish_row;
        finish_row = temp;
    }
    for(;start_row<=finish_row;start_row ++){
        screen[start_row][column] = data;
    }
}

void draw_rectangle(uint8_t x1,uint8_t x2,uint8_t y1,uint8_t y2,uint8_t data){
    draw_horizantal_line(y1,x1,x2,data);
    draw_horizantal_line(y2,x1,x2,data);
    draw_vertical_line(x1,y1,y2,data);
    draw_vertical_line(x2,y1,y2,data);
}

//Just a reminder for bit operations.

byte readBit(byte value, uint8_t position) {
  return (value >> position) & 1;
}


void draw_shape(uint8_t data[],uint8_t top_right_x,uint8_t top_right_y,uint8_t height,uint8_t width){
    for(uint8_t x = 0; x<width;x++){
        for(uint8_t y = 0 ; y < height ;y++){
            screen[top_right_y + y][top_right_x + x] = readBit(data[y],x);
        }
    }
}

void calculate_start_cordinates(uint8_t ){

}


///////screen arayinin tek boyutlu yapmalıyım çünkü herhangibir data için gerekli olan bilginin konumunun bir kare içerisine alınıp hesaplanması ve bu hesaba göre içeri bir şey yazdırılması işlemi için gerekli olan verileri iki boyulu arayde işlemek sıkıntılı olabiliyor.

