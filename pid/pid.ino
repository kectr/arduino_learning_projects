#include <Kalman.h>
#include <Servo.h>  //ESClerin kontrolü için servo kütüphanesinin eklenmesi



Servo leftMotor;  //sol ve sağ motorun tanımlanması
Servo rightMotor;


// Kalman filtresi için değerler
float timeConstant = 0.01; // Zaman sabiti (dt)
float initialEstimate = 1.0; // Başlangıç tahmin değeri
float initialEstimateError = 0.01; // Başlangıç tahmin hatası
float kp = 1;  //pid algoritması için sabit değerler
float ki = 1;
float kd = 1;
float delta_time = 0 //Bu değerin sensörlerden çekilmesi gerekir

KalmanFilter kalman(timeConstant, initialEstimate, initialEstimateError); // Kalman filtresi girilen 

void setup() {
  leftMotor.write(100)  // motorların çalışması
  rightMotor.write(100)
}

void loop() {
  float gyroMeasurement = readGyroData(); // sensör verisi okunur
  float filteredAngle = kalman.update(gyroMeasurement);     // kalman filtresi ile filtrelenir
  delta_time = 1 //Sensörden gelen veri yazılır
  double pid_x = pid(readGyroData()); //pid hesabı
  spinleftMotors(pid_x); // motor hızlarının ayarı
  spinrightMOtors(-pid_x); 

}

void spinleftMotors(double x){
  leftMotor.write(x);  //Motorların gelen güç değerlerine göre döndürülmesi
}
void spinrightMotors(double x){
  rightMotor.write(x);
}


double pid(double error) {

  double pid_p = error;
  double pid_d = (error - last_error) / delta_time;
  pid_i += error * delta_time;
  
  double control_signal = (kp*pid_p) + (ki*pid_i) + (kd*pid_d);
  last_error = error;
  return control_signal;
}

float readGyroData() {
  // Sensör verilerini burada okunacak ve döndürülecek
  float gyroData = 0.0; // Sadece göstermelik bir değer
  return gyroData;
}

