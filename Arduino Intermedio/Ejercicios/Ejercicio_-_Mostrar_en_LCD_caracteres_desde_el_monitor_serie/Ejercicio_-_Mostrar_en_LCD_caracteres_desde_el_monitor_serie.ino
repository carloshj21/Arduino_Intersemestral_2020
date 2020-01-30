#include <LiquidCrystal.h>

// (RS,E,d4,d5,d6,d7)
LiquidCrystal miLCD(2,3,4,5,6,7);

char caracter;
byte contador;

void setup() {
  miLCD.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() != 0)
  {
    caracter = Serial.read();
    contador++;
    if(contador == 17){
      miLCD.setCursor(0,1);
    }
    if(contador == 33){
      miLCD.clear();
      contador = 0;
    }
    miLCD.print(caracter);
  }
}
