#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);

String package = "a000b000c000d000q";
int joyx;
int joyy;
int signx;
int not_signy;
int not_signx;
int signy;
char ack;

void setup()
{
  xbee.begin(9600);
}

void loop()
{
  joyx = map(analogRead(A0), 0, 1023, -180, 180);
  joyy = map(analogRead(A1), 0, 1023, -180, 180);

  signy = (joyy < 0 ? 1 : 3);
  not_signy = (joyy < 0 ? 3 : 1);
  signx = (joyx < 0 ? 0 : 2);
  not_signx = (joyx < 90 ? 2 : 0);
  joyy = abs(joyy);
  joyx = abs(joyx);

  for (int i = 0; i < 3; i++)
  {
    package[signy * 4 + 3 - i] = (char)(joyy % 10 + 48);
    package[not_signy * 4 + 3 - i] = '0';
    joyy /= 10;
  }

  for (int i = 0; i < 3; i++)
  {
    package[signx * 4 + 3 - i] = (char)(joyx % 10 + 48);
    package[not_signx * 4 + 3 - i] = '0';
    joyx /= 10;
  }

  if (xbee.available())
  {
    xbee.print(package);
    Serial.println(package);

    while (1)
    {
      if (xbee.read() == 'Ü')
      {
        Serial.println("ack");
        break;
      }
    }
  }
}