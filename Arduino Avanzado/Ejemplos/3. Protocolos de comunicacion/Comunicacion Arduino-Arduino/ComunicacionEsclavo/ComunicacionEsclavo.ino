// Programa para Arduino Esclavo

#include <Wire.h>

void setup() {
  Wire.begin(0x20);  // Dirección del esclavo
  Wire.onReceive(llamada);  // Registra la función de interrupción cuando llega un mensaje
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void llamada(){
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println(" ");
}
