int y[2] = { 4, 5 };
int x[2] = { 2, 3 };  //y+ ,x -
const int len_x = sizeof(x) / sizeof(x[0]);
const int len_y = sizeof(y) / sizeof(y[0]);
const int xtype = 1;
const int ytype = !xtype;
int leds[len_x][len_x];


void slide_screen() {
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      if (i != 0) {
        leds[i - 1][j] = leds[i][j];
      }
    }
  }
}


void display_screen(int t) {
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      if (leds[i][j] == 1) {
        display_led(i, j, t);
      } else {
        digitalWrite(x[i], !xtype);
        digitalWrite(y[j], !ytype);
        delay(2 * t);
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

void display_led(int i, int j, int t) {
  digitalWrite(x[i], xtype);
  digitalWrite(y[j], ytype);
  delay(t);
  digitalWrite(x[i], !xtype);
  digitalWrite(y[j], !ytype);
  delay(t);
}


void setup() {
  prepare_pins();
  leds[1, 1];
  display_screen(100);
  slide_screen();
  display_screen(100);
}

void loop() {
}
