#define led_1 2
#define led_2 3
#define led_3 4
#define led_4 5
#define led_5 6
#define button 7
#define donensey A0


bool button_bool = false;
int speed = 100;

void flip_button_bool(){
  button_bool = !button_bool;
}

void stopwithinput(int time){
  int i = 0;
  while (i < time){
    i++;
    delay(1);
    if(digitalRead(button)==1){
      flip_button_bool();
      if (button_bool){
        while(digitalRead(button)){}
        while (1){
          if(digitalRead(button)){
            flip_button_bool();
            while(digitalRead(button)){}
            break;
          }
        }
      }
    }
  }
}


void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(button, INPUT);
  pinMode(donensey, INPUT);

}



void loop() {
  speed = analogRead(donensey)/10;
  
  digitalWrite(led_1,1);
  stopwithinput(speed);
  digitalWrite(led_1,0);
  digitalWrite(led_2,1);
  stopwithinput(speed);
  digitalWrite(led_2,0);
  digitalWrite(led_3,1);
  stopwithinput(speed);
  digitalWrite(led_3,0);
  digitalWrite(led_4,1);
  stopwithinput(speed);
  digitalWrite(led_4,0);
  digitalWrite(led_5,1);
  stopwithinput(speed);
  digitalWrite(led_5,0);

}

  
