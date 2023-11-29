//3x3 led matris için kontrol kodu
int x[3] = {2,3,4}; //Satırlar için pin sabitleri(aynı sutun + kısımlar paralel bağlanmalı)(+ olduğunda çalışır)
int y[3] = {5,6,7}; //Sutunlar için pin sabitleri(aynı satir - kısımlar paralel bağlanmalı)(- olduğunda çalışır)


float deger;//A0 analog read için değişken

void delayed_led(int i,int j,int dly){
  digitalWrite(x[i],1);
  digitalWrite(y[j],0);
  delay(dly);
  digitalWrite(x[i],0);
  digitalWrite(y[j],1);

}

void setup() {

  Serial.begin(9600);

  for(int i=0;i<3;i++){

    pinMode(x[i],OUTPUT);
    pinMode(y[i],OUTPUT);

  }

}

void loop() {
  digitalWrite(y[0],1);
  digitalWrite(y[1],1);
  digitalWrite(y[2],1);

  for(int i =0;i<3;i++){
    for(int j=0;j<3;j++){
      delayed_led(i,j,200);
    }
  }

  for(int i =2;i>=0;i--){
    for(int j=2;j>=0;j--){
      delayed_led(i,j,200);
    }
  }

  for(int i =0;i<3;i++){
    for(int j=0;j<3;j++){
      delayed_led(j,i,200);
    }
  }

  for(int i =2;i>=0;i--){
    for(int j=2;j>=0;j--){
      delayed_led(j,i,200);
    }
  }
  


  
  deger = analogRead(A0)/1023.0*5.0;
  Serial.println(deger);
}
