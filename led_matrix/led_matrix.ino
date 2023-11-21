#define buton 13

void led_wd(int i, int j, int duration = 1);
void multiple_led_wd(int duration, int duration_for_all);

int leds[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
int y[2] = {2, 3};
int x[4] = {4, 5, 6, 7}; //y+ ,x -
int speed_of_game = 400;
int caracter_place = 0;



void game_over() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      leds[i][j] = 0;
    }
  }
  multiple_led_wd(1, 300);
}

struct Caracter {
  int place = (leds[0][0] == 1 ? 0 : 1);

  int jump() {
    if (leds[0][1] == 1 && leds[0][0] == 1) {
      game_over();
      return 1;
    }
    leds[0][0] = !leds[0][0];
    leds[0][1] = !leds[0][1];
    place = (leds[0][0] == 1 ? 0 : 1);
  }
};

void move_game() {
  if (leds[1][caracter_place]) {
    game_over();
  } else {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        leds[i][j] == 0;
        if (i == 0 && j != caracter_place) {
          continue;
        } else {
          leds[i - 1][j] == 1;
        }
      }
    }
  }
}

void x_check() {
  for (int x = 2; x < 4; x++) {
    for (int y = 4; y < 8; y++) {
      led_wd(x, y, 100);
    }
  }
}

void y_check() {
  for (int y = 4; y < 8; y++) {
    for (int x = 2; x < 4; x++) {
      led_wd(x, y, 100);
    }
  }
}

void barier_creat() {
  int x;
  int y;
  x = 3;
  y = random(0, 1);
  leds[x][y] = 1;
}



void jump() {
  leds[0][0] = !leds[0][0];
  leds[0][1] = !leds[0][1];
  caracter_place = (leds[0][0] == 1 ? 0 : 1);
}

void button(int duration) {
  for (int i = 0; i < duration; i++) {
    delay(1);
    if (digitalRead(button)) {
      while(digitalRead(buton)){}
      jump();

    }
  }

}


void led_wd(int i, int j, int duration = 1) {
  digitalWrite(x[i], 1);
  digitalWrite(y[j], 0);
  delay(duration);
  digitalWrite(x[i], 0);
  digitalWrite(y[j], 1);
}

void multiple_led_wd(int duration, int duration_for_all) {
  for (int t = 0; t < duration_for_all; t++) {
    delay(1);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 2; j++) {
        if (leds[i][j]) {
          led_wd(i, j, duration);
        }
      }
    }
  }
}





void setup() {
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(13, INPUT);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  Serial.begin(9600);
  x_check();
  y_check();
  game_over();
}

void loop() {
  
  
  

}
