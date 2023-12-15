#include <Arduino.h>

const uint8_t clock = 8;
const uint8_t sclock = 9;
const uint8_t oe = 9; // select it pwm for brightness
const uint8_t A = 3;
const uint8_t B = 2;
const int8_t data_pin = 10;


const uint8_t pulsetime_micro = 10;


const uint8_t rowNumber = 16; 
const uint8_t columnNumber = 64;
uint8_t screen[rowNumber][columnNumber] = {1}; //clear screen is all ones



void clock_pulse();
void sclock_pulse();
void data_out(uint8_t data);
void rows_out(int i_row);
void screen_clear();




void setup() {
    Serial.begin(9600);
    pinMode(clock,OUTPUT);
    pinMode(sclock,OUTPUT);
    pinMode(oe,OUTPUT);
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(data_pin,OUTPUT);
    Serial.println("Start");
    digitalWrite(clock,0);
    digitalWrite(sclock,0);
    digitalWrite(A,0);
    digitalWrite(B,1);
    screen_clear();
    delay(500);
    for(int row = 0;row<16;row++){
        for(int column; column<32;column++){
            screen[row][column] = 0;

        }
        for(int column = 32; column<64;column++){
            screen[row][column] = 1;

        }
        

    }

}
  
void loop(){
    rows_out(0);

}

void clock_pulse(){
    
    delayMicroseconds(pulsetime_micro);
    digitalWrite(clock,1);
    
    delayMicroseconds(pulsetime_micro);
    digitalWrite(clock,0);
}

void sclock_pulse(){

    delayMicroseconds(pulsetime_micro);
    digitalWrite(sclock,1);

    delayMicroseconds(pulsetime_micro);
    digitalWrite(sclock,0);
}

void data_out(uint8_t data){
    digitalWrite(data_pin,data&1);
    clock_pulse();
}

void rows_out(int i_row){
    
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
    default:
        break;
    }
    

    for(int lap = 0;lap<8;lap++){
        for(int column = 0; column<8;column ++){
            for(int row = 12; row >=0 ; row-=4){
                data_out(screen[row][column+lap*8]);
            }
        }
    }   
}




void screen_clear(){
    for (int i = 0 ;i<256; i++ ){
        data_out(1);
    }
}

void change_dot(uint8_t index){
    
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



///////screen arayinin tek boyutlu yapmalıyım çünkü herhangibir data için gerekli olan bilginin konumunun bir kare içerisine alınıp hesaplanması ve bu hesaba göre içeri bir şey yazdırılması işlemi için gerekli olan verileri iki boyulu arayde işlemek sıkıntılı olabiliyor.

