// Programa para Arduino maestro

#include <Wire.h>

void setup() {
  Wire.begin();  // No se reciben parámetros porque es maestro
}

void loop() {
  Wire.beginTransmission(0x20);
  Wire.write("El mensaje es: Hola esclavo");
  Wire.endTransmission();
  delay(1000);
}
