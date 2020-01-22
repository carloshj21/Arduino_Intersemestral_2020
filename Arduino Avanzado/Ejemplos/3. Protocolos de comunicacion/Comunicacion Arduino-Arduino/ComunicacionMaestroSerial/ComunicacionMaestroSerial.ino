#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char d = Serial.read();
    if(d == 'a'){
      Wire.beginTransmission(0x20);
      Wire.write("El mensaje es A");
      Wire.endTransmission();
    }
    else{
      if(d != '\n'){
        Wire.beginTransmission(0x20);
        Wire.write("El mensaje no es A");
        Wire.endTransmission();
      }
    }
  }
  delay(1000);
}
