#include <SoftwareSerial.h>

int Rx = 7;
int Tx = 6;

SoftwareSerial maestro(Rx,Tx);

void setup() {
  Serial.begin(9600);
  maestro.begin(9600);
}

void loop() {
  int pot = analogRead(A0);
  pot = map(pot,0,1023,0,180);
  Serial.println(pot);
  maestro.write(pot);
  delay(100);
}
