#include <Servo.h>

// Declaro mi objeto para servo
Servo miServo;

int pot = A5;

int i;
int lectura;

void setup() {
  miServo.attach(7);
}

void loop() {
  lectura = analogRead(pot);
  lectura = map(lectura,0,1023,0,180);
  miServo.write(lectura);
}
