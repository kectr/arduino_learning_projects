#include <Arduino.h>

bool starter_1 = true;
bool starter_2 = true;
bool starter_3 = true;
bool starter_4 = true;


bool array_11[256] = {0};
bool array_22[256] = {0};
bool array_33[256] = {0};
bool array_44[256] = {0};

bool wed7_array_11[256] = {0};
bool wed7_array_22[256] = {0};
bool wed7_array_33[256] = {0};
bool wed7_array_44[256] = {0};


const uint8_t cclock = 15;
const uint8_t sclock = 16;
const uint8_t oe = 19; // select it pwm for brightness
const uint8_t A = 18;
const uint8_t B = 17;
const uint8_t data_pin = 14;

void dot_chooser_1();
void dot_chooser_2();
void dot_chooser_3();
void dot_chooser_4();

void array_maker_1 (bool array[]);
void array_maker_2 (bool array[]);
void array_maker_3 (bool array[]);
void array_maker_4 (bool array[]);

void Gazi_ieee();
void wed_7();
void dot_chooser(bool array[],int index);
void dot_chooser_1();
void dot_chooser_2();
void dot_chooser_3();
void dot_chooser_4();


const uint8_t pulsetime_micro = 1;


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
    pinMode(cclock,OUTPUT);
    pinMode(sclock,OUTPUT);
    pinMode(oe,OUTPUT);
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(data_pin,OUTPUT);
    pinMode(13, OUTPUT);
    Serial.println("Start");
    digitalWrite(cclock,0);
    digitalWrite(sclock,0);
    digitalWrite(13,HIGH);
    digitalWrite(A,0);
    digitalWrite(B,0);
    digitalWrite(oe,1);
    screen_clear();
    delay(500);
   

}
  
void loop(){
  
    int i = 0;
    
    while(1){
        i++;
        Gazi_ieee();
        if(i>1000){
            i=0;
            break;
        }
    }
    
    screen_clear();    
    while(1){
        i++;
        wed_7();
        if(i>1000){
            i=0;
            break;
        }
    }
    screen_clear();
    
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
                data_out(screen[row+i_row][column+lap*8]);
            }
        }
    }   
}


void screen_clear(){
    for (int i = 0 ;i<256; i++ ){
        digitalWrite(data_pin,1);
        clock_pulse();
    }
    sclock_pulse();
}


//Just a reminder for bit operations.

byte readBit(byte value, uint8_t position) {
  return (value >> position) & 1;
}


void array_maker_1(bool array[]){
    array[226] = true; 
    array[227] = true;
    array[228] = true;
    array[239] = true;
    array[195] = true;
    array[196] = true;
    array[200] = true;
    array[201] = true;
    array[202] = true;
    array[203] = true;
    array[204] = true;
    array[205] = true;
    array[206] = true;
    array[207] = true;
    array[161] = true;
    array[162] = true;
    array[163] = true;
    array[164] = true;
    array[165] = true;
    array[166] = true;
    array[172] = true;

    array[217+16]= true;
    array[218+16]= true;
    array[219+16]= true;
    array[236] = true;
    
    array[134] = true;
    array[135] = true;
    array[142] = true;
    array[143] = true;

    array[112] = true;
    array[113] = true;
    array[120] = true;
    array[121] = true;

    
    array[85] = true;
    array[84] = true;
    array[83] = true;
    array[82] = true;
    array[81] = true;
    array[80] = true;

    array[88] = true;
    array[89] = true;
    array[90] = true;
    array[91] = true;
    array[92] = true;
    array[93] = true;

    array[85-32] = true;
    array[84-32] = true;
    array[83-32] = true;
    array[82-32] = true;
    array[81-32] = true;
    array[80-32] = true;

    array[88-32] = true;
    array[89-32] = true;
    array[90-32] = true;
    array[91-32] = true;
    array[92-32] = true;
    array[93-32] = true;

    array[85-32-32] = true;
    array[84-32-32] = true;
    array[83-32-32] = true;
    array[82-32-32] = true;
    array[81-32-32] = true;
    array[80-32-32] = true;

    array[88-32-32] = true;
    array[89-32-32] = true;
    array[90-32-32] = true;
    array[91-32-32] = true;
    array[92-32-32] = true;
    array[93-32-32] = true;

    
}
void array_maker_2(bool array[]){
  array[225] = 
    array[229]= true;
    array[239]= true;
    array[217+16]= true;
    array[194] = true;
    array[197] = true;
    array[200] = true;
    array[207] = true;
    array[161] = true;
    array[173] = true;
    array[134] = true;
    array[135] = true;
    array[142] = true;
    array[143] = true;

    array[112] = true;
    array[113] = true;
    array[120] = true;
    array[121] = true;

    array[85] = true;
    array[93] = true;

    array[85-32] = true;
    array[93-32] = true;

    array[85-32-32] = true;
    array[93-32-32] = true;

    for(int i = 0 ; i< 4 ; i++){
      for(int j = 0; j < 8 ; j ++){
        array[240+j-32*i] =true;
      }

    }
    array[144] = false;
    
    

    

    for(int i = 0 ; i< 4 ; i++){
      for(int j = 0; j < 8 ; j ++){
        array[104+j-32*i] =true;
      }

      array[111] = false;

    }

  

    

        

}
void array_maker_3(bool array[]){
    array[230]= true;
    array[217+16]= true;
    array[222+16]= true;
    
    array[193] = true;
    array[198] = true;
    array[200] = true;
    array[207] = true;
    array[162] = true;
    array[174] = true;
    array[134] = true;
    array[135] = true;
    array[142] = true;
    array[143] = true;

    array[112] = true;
    array[113] = true;
    array[120] = true;
    array[121] = true;

    array[85] = true;
    array[93] = true;

    array[85-32] = true;
    array[93-32] = true;

    array[85-32-32] = true;
    array[93-32-32] = true;

    for(int i = 0 ; i< 4 ; i++){
      for(int j = 0; j < 8 ; j ++){
        array[240+j-32*i] =true;
      }

    }
    
    array[144] = false;
    

    for(int i = 0 ; i< 4 ; i++){
      for(int j = 0; j < 8 ; j ++){
        array[104+j-32*i] =true;
      }

    }
    array[111] = false;
 
    
}
void array_maker_4(bool array[]){
    array[231]= true;
   // array[224]= true;
    array[234]= true;
    array[235]= true;
    array[236]= true;
    array[237]= true;
    
    array[192] = true;
    array[199] = true;
    
    array[200] = true;
    array[207] = true;
    array[163] = true;
    array[169] = true;
    array[170] = true;
    array[171] = true;
    array[172] = true;
    array[173] = true;
    array[174] = true;
    array[134] = true;
    array[135] = true;
    array[142] = true;
    array[143] = true;

    array[112] = true;
    array[113] = true;
    array[120] = true;
    array[121] = true;

    array[85] = true;
    array[84] = true;
    array[83] = true;
    array[82] = true;
    array[81] = true;
    array[80] = true;

    array[88] = true;
    array[89] = true;
    array[90] = true;
    array[91] = true;
    array[92] = true;
    array[93] = true;

    array[85-32] = true;
    array[84-32] = true;
    array[83-32] = true;
    array[82-32] = true;
    array[81-32] = true;
    array[80-32] = true;

    array[88-32] = true;
    array[89-32] = true;
    array[90-32] = true;
    array[91-32] = true;
    array[92-32] = true;
    array[93-32] = true;

    array[85-32-32] = true;
    array[84-32-32] = true;
    array[83-32-32] = true;
    array[82-32-32] = true;
    array[81-32-32] = true;
    array[80-32-32] = true;

    array[88-32-32] = true;
    array[89-32-32] = true;
    array[90-32-32] = true;
    array[91-32-32] = true;
    array[92-32-32] = true;
    array[93-32-32] = true;
    
    

}

void wed_array_maker_1(bool array[]){
    array[192-32] = true;
    array[198-32] = true;

    array[200-32] = true;
    array[203-32] = true;
    array[206-32] = true;


    array[99] =
    array[100] =
    array[101] =
    array[102] = 
    array[103] =
    array[106] =
    array[111] = true;

    array[129] =
    array[130] =
    array[131] = 
    array[132] = 
    array[133] = 
    array[134] = true;

    array[137] =
    array[138] = 
    array[139] = 
    array[140] = 
    array[141] = 
    array[142] = true;

    array[71] =
    array[70] =
    array[69] =
    array[68] =
    array[67] =
    array[66] =
    array[65] =
    array[64] = 
    array[74] = true;




}
void wed_array_maker_2(bool array[]){
    array[192-32] = 
    array[195-32] = 
    array[198-32] = 
    array[200-32] = 
    array[203-32] = 
    array[206-32] = true;

    array[98] =
    array[103] = 
    array[106] =
    array[111] = true;

    array[134] = 
    array[142] = true;

    array[71] =
    array[64] = 
    array[75] = true;

    for(int i = 0 ; i< 4 ; i++){
      for(int j = 0; j < 8 ; j ++){
        array[176+j-32*i] =true;
      }

    }

    
}
void wed_array_maker_3(bool array[]){
    array[192-32] = 
    array[195-32] = 
    array[198-32] = 
    array[200-32] = 
    array[203-32] = 
    array[206-32] = true;

    array[98] =
    array[103] = 
    array[106] =
    array[111] = true;

    array[134] = 
    array[142] = true;

    array[64] = 
    array[76] =true;

    for(int i = 0 ; i< 4 ; i++){
      for(int j = 0; j < 8 ; j ++){
        array[176+j-32*i] =true;
      }

    }
}
void wed_array_maker_4(bool array[]){
    array[192-32] = 
    array[195-32] = 
    array[198-32] = true;

    array[201-32] = 
    array[202-32] = 
    array[204-32] = 
    array[205-32] = true;

    array[98] =
    array[103] = 
    array[107] = 
    array[108] = 
    array[109] = 
    array[110] = 
    array[111] = true;

    array[129] =
    array[130] =
    array[131] = 
    array[132] = 
    array[133] = 
    array[134] = true;

    array[137] =
    array[138] = 
    array[139] = 
    array[140] = 
    array[141] = 
    array[142] = true;

    array[65] = 
    array[77] = true;
    
}



void dot_chooser_1(){
    if(starter_1){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  //screen_clear();
  //sclock_pulse();
  for (int i = 255 ; i>=0;i--){
    if (array_11[i]){
          digitalWrite(data_pin,LOW);
    clock_pulse();
    //sclock_pulse();
     }

    else{
     digitalWrite(data_pin,HIGH);
    clock_pulse();
    //sclock_pulse();
     }}
  }
}

void dot_chooser_2(){
    if(starter_2){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  //screen_clear();
  //sclock_pulse();
  for (int i = 255 ; i>=0;i--){
    if (array_22[i]){
          digitalWrite(data_pin,LOW);
    clock_pulse();
    //sclock_pulse();
     }

    else{
     digitalWrite(data_pin,HIGH);
    clock_pulse();
   // sclock_pulse(); 
    }}
  }
}

void dot_chooser_3(){
    if(starter_3){
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  //screen_clear();
  //sclock_pulse();
  for (int i = 255 ; i>=0;i--){
    if (array_33[i]){
          digitalWrite(data_pin,LOW);
    clock_pulse();
    //sclock_pulse();
     }

    else{
     digitalWrite(data_pin,HIGH);
    clock_pulse();
    //sclock_pulse();
     }}
  }
}

void dot_chooser_4(){
    if(starter_4){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  //screen_clear();
  //sclock_pulse();
  for (int i = 255 ; i>=0;i--){
    if (array_44[i]){
          digitalWrite(data_pin,LOW);
    clock_pulse();
    //sclock_pulse();
     }

    else{
     digitalWrite(data_pin,HIGH);
    clock_pulse();
    //sclock_pulse();
     }}
  }
}


void dot_chooser(bool array[],int index){

    switch (index)
    {
    case 1:
        digitalWrite(A,1);
        digitalWrite(B,1);
        break;
    case 2:
        digitalWrite(A,0);
        digitalWrite(B,0);
        break;

    case 3:
        digitalWrite(A,1);
        digitalWrite(B,0);
        break;
    case 4:
        digitalWrite(A,0);
        digitalWrite(B,1);
        break;
    default:
        break;
    }

    for (int i = 255 ; i>=0;i--){
        if (array[i]){
            digitalWrite(data_pin,LOW);
            clock_pulse();
        }else{
            digitalWrite(data_pin,HIGH);
            clock_pulse();
        }
    }
}

void Gazi_ieee(){
    array_maker_1(array_11);
    dot_chooser_1();
    sclock_pulse();
    
    array_maker_2(array_22);
    dot_chooser_2();
    sclock_pulse();

    array_maker_3(array_33);
    dot_chooser_3();
    sclock_pulse();

    array_maker_4(array_44);
    dot_chooser_4();
    sclock_pulse();
}

void wed_7(){
    wed_array_maker_1(wed7_array_11);
    dot_chooser(wed7_array_11,1);
    sclock_pulse();
    
    wed_array_maker_2(wed7_array_22);
    dot_chooser(wed7_array_22,2);
    sclock_pulse();

    wed_array_maker_3(wed7_array_33);
    dot_chooser(wed7_array_33,3);
    sclock_pulse();

    wed_array_maker_4(wed7_array_44);
    dot_chooser(wed7_array_44,4);
    sclock_pulse();
}
