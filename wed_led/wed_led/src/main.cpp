#include <Arduino.h>

//Define
#define data0 2
#define data1 3
#define data2 4
#define data3 5
#define clock 5
#define reset 6

#define button_u 7
#define button_d 8
#define button_r 9
#define button_l 10
#define button_m 11

#define buzzer 12

#define pulsetime_micro 10

const uint8_t rowNumber = 16;
const uint8_t columnNumber = 64;


//Declarations
void clock_pulse();
void data_out_from_pin(uint8_t data_pin,uint8_t data);
void list_out(uint8_t data_pin,uint8_t list[]);


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

//Just a reminder for bit operations.
/*
byte readBit(byte value, uint8_t position) {
  return (value >> position) & 1;
}
*/

//Puts some data to pin by shifting every bit and usind & operator.
void data_out_from_pin(uint8_t data_pin,uint8_t data){
    uint8_t i = 0;
    for(;i<8;i++){
        digitalWrite(data_pin,(data&1));
        clock_pulse();
        data >>= 1;
    }
}

//Puts list to pin by using data_out_from_pin function.
void list_out(uint8_t data_pin,uint8_t list[],uint8_t last_index_of_list){
    for(;last_index_of_list >= 0;last_index_of_list--){
        data_out_from_pin(data_pin,list[last_index_of_list]);
    }
}

/*
Puting list with 1/4 scan rate 
it means putting 1/4 of screen at same time
Using list_out function for this operation
Puting data through at the number of pins such as 1/4 of row number.
*/

/*
uint8_t *find_row_info(uint8_t row){
    uint8_t *listofinfo[2] = {0x00};
    
    
}

//Putting row_data[10] into data pin to put 1 row to screen with using list_out function.First 2 element is row info.


void screen_row_out(uint8_t data_pin,uint8_t row,uint8_t data[]){
    uint8_t row_data[10];
    
    



}
*/

