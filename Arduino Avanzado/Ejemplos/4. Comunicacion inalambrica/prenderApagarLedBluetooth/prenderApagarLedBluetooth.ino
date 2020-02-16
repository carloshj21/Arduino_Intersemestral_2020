#include <SoftwareSerial.h>

int Rx = 7;  // Conectado al Tx del módulo
int Tx = 6;  // Conectado al Rx del módulo

// Creamos nuestro objeto diciéndole qué pines vamos a usar para la comunicación serial
SoftwareSerial blue = SoftwareSerial(Rx,Tx);

char dato;

void setup() {
  Serial.begin(9600);
  blue.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  if(blue.available() > 0){
    dato = blue.read();

    if(dato == 'p'){
      digitalWrite(13,HIGH);
    }
    else if(dato == 'a'){
      digitalWrite(13,LOW);
    }
    else{
      blue.print("Letra inválida");
    }
  }
}
