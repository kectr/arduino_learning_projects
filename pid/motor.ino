#include <Servo.h>  //ESClerin kontrolü için servo kütüphanesinin eklenmesi

Servo leftMotor;  //sol ve sağ motorun tanımlanması
Servo rightMotor;




void spinleftMotors(unsigned double){
  leftMotor.write();  //Motorların gelen güç değerlerine göre döndürülmesi
}
void spinrightMotors(unsigned double){
  rightMotor.write();
}

void stopMotors(){  //Motorları durdur
  leftMotor.write(0);
  rightMotor.write(0);
}
