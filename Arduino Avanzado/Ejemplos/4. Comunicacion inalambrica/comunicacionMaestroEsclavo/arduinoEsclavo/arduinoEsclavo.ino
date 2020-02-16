// Código para Arduino esclavo
#include <Servo.h>
#include <SoftwareSerial.h>

int Rx = 7;
int Tx = 6;

SoftwareSerial esclavo(Rx,Tx);
Servo miServo;

void setup() {
  esclavo.begin(9600);
  Serial.begin(9600);
  miServo.attach(2);
}

void loop() {
  if(esclavo.available() > 0){
    int dato = esclavo.read();
    miServo.write(dato);
    Serial.println(dato);
  }
}
