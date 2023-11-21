float deger;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() { 
  deger = analogRead(A0)/1023.0*5.0;
  // put your main code here, to run repeatedly:
  Serial.println(deger);
}
