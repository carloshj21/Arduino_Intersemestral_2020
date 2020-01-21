#include <Servo.h>

Servo miServo;

int grado;

void setup() {
  Serial.begin(9600);
  miServo.attach(4);
}

void loop() {
  if(Serial.available() > 0){
    grado = Serial.read();
    miServo.write(grado);
  }
}
