#include <Arduino.h>

//Define
#define data0 2
#define clock 5
#define reset 6
#define oe 7


const uint8_t pulsetime_micro = 10;
const uint8_t rowNumber = 16;
const uint8_t columnNumber = 64;
const uint8_t oe_delay_micro = 255;

uint8_t screen[128] = {0x00};

//Declarations
void clock_pulse();
void output_enable();
void data_out(uint8_t data_pin,uint8_t data);
void list_out(uint8_t data_pin,uint8_t data_list[],uint8_t data_last_index);
void row_out(uint8_t data_pin, uint8_t screen_list[], uint8_t row_index);
void screen_out(uint8_t data_pin,uint8_t screen_list[]);


void setup() {
    //Pinmodes are to be worked later.
    
}   

void loop() {


}

//Functions

//Making some pulse on clock pin.
void clock_pulse(){
    digitalWrite(clock,1);
    delayMicroseconds(pulsetime_micro);
    digitalWrite(clock,0);
    delayMicroseconds(pulsetime_micro);
}

//Not sure about how it works still in progress.
void output_enable(){
    digitalWrite(oe,1);
    delayMicroseconds(oe_delay_micro);
    digitalWrite(oe,0);
}

//Just a reminder for bit operations.
/*
byte readBit(byte value, uint8_t position) {
  return (value >> position) & 1;
}
*/

//Puts some data ( ex : 0xff ) to pin by shifting every bit and usind & operator.
void data_out(uint8_t data_pin,uint8_t data){
    uint8_t i = 0;
    for(;i<8;i++){
        digitalWrite(data_pin,(data&1));
        clock_pulse();
        data >>= 1;
    }
}

//Puts list to pin by using data_out function.
void list_out(uint8_t data_pin,uint8_t data_list[],uint8_t data_last_index){
    for(;data_last_index >= 0;data_last_index--){
        data_out(data_pin,data_list[data_last_index]);
    }
}

//Trying to export row data with list_out func. Row data includes row info and pixel data. Funciton will be configurated after led formation of led panel. 
void row_out(uint8_t data_pin, uint8_t screen_list[], uint8_t row_index){
    uint8_t row_info[2] = {0x00,0x00};

    /*
    if(row_index<8){
        row_info[1] = 0x01;
        row_info[1]<<=row_index;
    }else{
        row_info[0] = 0x01;
        row_info[0]<<=(row_index-8);
    }
    */

    uint8_t i = row_index/8;
    uint8_t j = row_index%8;
    row_info[i] = 0x01;
    row_info[i]<<=j;
    uint8_t list_last_index = columnNumber/16-1;
    uint8_t list_index = row_index*columnNumber+columnNumber/16;
    
    list_out(data_pin,&screen_list[list_index],list_last_index);//puts data (columNnumber/16 comes from 2 panel form,normaly it has to be 8)
    list_out(data_pin,row_info,1);//puts row info
    list_out(data_pin,&screen_list[list_index-columnNumber/16],list_last_index);
    list_out(data_pin,row_info,1);
}

//Printing screen to led by use of row_out function.(Respected to 1/4 scan ???)
void screen_out(uint8_t data_pin,uint8_t screen_list[]){
    uint8_t row = 0;
    for(;row<4;row++){
        for(uint8_t i = 0;i<4;i++){
            row_out(data_pin,screen_list,row+i);
        }
        output_enable();
    }
}


