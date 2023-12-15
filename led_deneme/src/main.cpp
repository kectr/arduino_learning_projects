#include <Arduino.h>

// Define pin connections
#define DATA_PIN 2   // Connect this to the data pin of your shift register
#define CLOCK_PIN 3  // Connect this to the clock pin of your shift register
#define LATCH_PIN 4  // Connect this to the latch pin of your shift register
#define MODULE_ENABLE_PIN 5

#define NUMBER_OF_MODULES 1  // Number of P10 modules in series
#define MODULE_WIDTH 16  // Width of each P10 module
#define MODULE_HEIGHT 64  // Height of each P10 module

// Define the display buffer
byte displayBuffer[NUMBER_OF_MODULES * MODULE_WIDTH];

const byte font[] PROGMEM = {
  // Font data here (8x8 pixel patterns for ASCII characters)
};

void displayText(const char* text);
void clearDisplayBuffer();
void displayBufferOnModules();

void setup() {
  // Set up the shift register pins
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  // Initialize the display buffer
  clearDisplayBuffer();
}

void loop() {
  displayText("IEEE WED ");
}

void displayText(const char* text) {
  // Clear the display buffer
  clearDisplayBuffer();

  // Populate the display buffer with the text
  int offset = 0;
  for (int i = 0; text[i] != '\0'; ++i) {
    char character = text[i];
    int patternIndex = character - ' ';
    if (patternIndex >= 0 && patternIndex < 96) {
      for (int j = 0; j < 8; ++j) {
        displayBuffer[offset + j] = pgm_read_byte_near(font + patternIndex * 8 + j);
      }
      offset += 8;
    }
  }

  // Display the buffer on the P10 modules
  displayBufferOnModules();
  delay(2000);  // Display the text for 2 seconds, adjust as needed
}

void clearDisplayBuffer() {
  memset(displayBuffer, 0, sizeof(displayBuffer));
}4

void displayBufferOnModules() {
  for (int module = 0; module < NUMBER_OF_MODULES; ++module) {
    digitalWrite(LATCH_PIN, LOW);

    // Send the data to the shift register
    for (int i = MODULE_WIDTH - 1; i >= 0; --i) {
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, displayBuffer[module * MODULE_WIDTH + i]);
    }

    digitalWrite(LATCH_PIN, HIGH);

    // Enable the module
    // You may need additional logic to control the module enabling/disabling based on your P10 module
    // This example assumes common anode displays where HIGH is off and LOW is on
    digitalWrite(MODULE_ENABLE_PIN, LOW);
  }
}

// Font data (you can replace this with your own font)
#include <avr/pgmspace.h>

const byte font[] PROGMEM = {
  // Font data here (8x8 pixel patterns for ASCII characters)
};