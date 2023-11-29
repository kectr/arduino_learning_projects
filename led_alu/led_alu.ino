#define red_1 2
#define red_2 3
#define green_1 4
#define green_2 5
#define yellow_1 6
#define yellow_2 7
#define yellow_3 8
#define button_sellect 9
#define button_accept 10
#define led_delay 50

int sum = 0;
int carry = 0;
int led_values[] = {0,0,0,0,0,0,0};
int allclose[] = {0,0,0,0,0,0,0};
int allopen[] = {1,1,1,1,1,1,1};


void display_leds(int listofleds[]){ //display leds by using given array
  for(int i=0;i<7;i++){
    if (listofleds[i]){
      digitalWrite(i+2,1);
    }else{
      digitalWrite(i+2,0);
    }
  }
  delay(led_delay);
}

void blink_leds(int listofleds[],int normallist[]){ //blink given leds 
  display_leds(allclose);
  for(int i=0;i<7;i++){
    if(listofleds[i]){
      digitalWrite(i+2,1);
    }
  }
  delay(led_delay);
  display_leds(allclose);
  display_leds(normallist);
}

void assgn_value(){
  for(int i=0;i<4;i++){
    int x[] = {0,0,0,0,0,0,0};
    x[i] = 1;
    display_leds(allclose);
    blink_leds(x,x);
    blink_leds(x,led_values);
    while (!digitalRead(button_accept)){
      if(digitalRead(button_sellect)){
        while(digitalRead(button_sellect)){}
        led_values[i] = !led_values[i];
        display_leds(led_values);
        for(int x = 0;x<7;x++){
          Serial.println(led_values[x]);
        }
      }
    }
    while(digitalRead(button_accept)){}
  }
}

void sum_of_leds(){
  carry = 0;
  for(int i=2;i<4;i++){
    sum = (led_values[i-2]^led_values[i])^carry;
    carry = (led_values[i-2]&led_values[i])|((led_values[i-2]^led_values[i])&carry);
    led_values[i+2] = sum;
  }
  led_values[6] = carry;
  display_leds(led_values);
}

void setup() {
  // put your setup code here, to run once:
  for (int i=2;i<9;i++){
    pinMode(i,OUTPUT);
  }
  for (int i=9;i<11;i++){
    pinMode(i,INPUT);
  }
  Serial.begin(9600);
  
}



void loop() {
  if (digitalRead(button_accept) && digitalRead(button_sellect)){
    while(digitalRead(button_accept)||digitalRead(button_sellect)){display_leds(allopen);}
    for(int i = 0;i<7;i++){
      led_values[i] = 0;
    }
    display_leds(led_values);
    assgn_value();
    sum_of_leds();

  
  }

}
