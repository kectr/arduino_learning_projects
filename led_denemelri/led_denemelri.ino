int y[2] = {2, 3};
int x[4] = {4, 5, 6, 7}; //y+ ,x -
int len_x = 4;
int len_y = 2;
int xtype = 0;
int ytype = 1;
int leds[4][2];


void slide_screen() {
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      if(i!=0){
        leds[i-1][j] = leds[i][j];
      } 
    }
  }
  leds[3] = {0,0};s
}

void display_screen(int t) {
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      if (leds[i][j]) {
        display_led(i, j, t);
      } else {
        delay(2*t);
      }
    }
  }
}

void prepare_pins() {
  for (int i = 0; i < len_x; i++) {
    pinMode(x[i], OUTPUT);
  }
  for (int j = 0; j < len_y; j++) {
    pinMode(y[j], OUTPUT);
  }
  for (int j = 0; j < len_y; j++) {
    digitalWrite(y[j], !ytype);
  }
  for (int i = 0; i < len_x; i++) {
    digitalWrite(x[i], !xtype);
  }
}

void display_led(int i, int j,int t) {
  digitalWrite(x[i], 0);
  digitalWrite(y[j], 1);
  delay(t);
  digitalWrite(x[i], 1);
  digitalWrite(y[j], 0);
  delay(t);
}


void setup() {
  prepare_pins();
  leds[3][0] = 1;
  display_screen(100);
  delay(200);
  slide_screen();
  delay(200);
  display_screen(100);
}

void loop() {
  
}
