#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#define address 0x68
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
float TotalACC, TotalGYRO, TA;
float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
int buzzer = 3;
int pot = A0;
float sense;

void setup()
{
    Serial.begin(115200);
    pinMode(buzzer, OUTPUT);
    Wire.begin();
    Wire.beginTransmission(address);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
}

void loop()
{
    sense = analogRead(pot);
    sense = map(sense, 0, 1023, 100, 150);

    Wire.beginTransmission(address);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(address, 14, true);
    AcX = Wire.read() << 8 | Wire.read();
    AcY = Wire.read() << 8 | Wire.read();
    AcZ = Wire.read() << 8 | Wire.read();
    Tmp = Wire.read() << 8 | Wire.read();
    GyX = Wire.read() << 8 | Wire.read();
    GyY = Wire.read() << 8 | Wire.read();
    GyZ = Wire.read() << 8 | Wire.read();

    accX = AcX / 16384.0;
    accY = AcY / 16384.0;
    accZ = AcZ / 16384.0;

    TotalACC = sqrt(accX * accX + accY * accY + accZ * accZ);
    TotalGYRO = sqrt(GyX * GyX + GyY * GyY + GyZ * GyZ);
    TA = sense / 100;
    Serial.print("Sense : ");
    Serial.print(TA);
    Serial.print("  TotalACC: ");
    Serial.print(TotalACC);
    Serial.print("  TotalGYRO: ");
    Serial.println(TotalGYRO);

    if (TotalACC > TA)
    {
        digitalWrite(buzzer, HIGH);
        delay(1500);
    }
    else
    {
        digitalWrite(buzzer, LOW);
    }

    delay(20);
}