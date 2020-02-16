#include <SoftwareSerial.h>

int Rx = 7;  // Conectado al Tx del módulo
int Tx = 6;  // Conectado al Rx del módulo

// Creamos nuestro objeto diciéndole qué pines vamos a usar para la comunicación serial
SoftwareSerial blue = SoftwareSerial(Rx,Tx);

void setup() {
  Serial.begin(9600);
  blue.begin(38400);  // Para el modo configuración

  // ADDR:  98d3,51,fd7498
}

void loop() {
  if(blue.available() > 0){
    Serial.write(blue.read());
  }

  if(Serial.available() > 0){
    blue.write(Serial.read());
  }
}
