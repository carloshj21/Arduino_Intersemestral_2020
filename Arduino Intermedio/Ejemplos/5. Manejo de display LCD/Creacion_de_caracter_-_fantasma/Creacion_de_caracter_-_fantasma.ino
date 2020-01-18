#include <LiquidCrystal.h>

// (RS,E,d4,d5,d6,d7)
LiquidCrystal miLCD(2,3,4,5,6,7);

byte fantasma[8] = {
  B00000,
  B00000,
  B01110,
  B10101,
  B11111,
  B11111,
  B11111,
  B10101
};

byte rock[8] = {
  B10010,
  B10010,
  B11110,
  B11110,
  B11111,
  B11110,
  B01100,
  B01100
};

byte carita[8] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

// Manera rápida
byte bomba[8]={0,6,4,14,31,31,31,14};

void setup() {
  miLCD.begin(16,2);

  // Creación de los caracteres
  miLCD.createChar(0,fantasma);
  miLCD.createChar(1,rock);
  miLCD.createChar(2,carita);
  miLCD.createChar(3,bomba);
  
  // Imopresión de los caracteres
  miLCD.setCursor(7,0);
  miLCD.write(byte(0));
  miLCD.setCursor(1,0);
  miLCD.write(byte(1));
  miLCD.setCursor(15,0);
  miLCD.write(byte(2));
  miLCD.setCursor(11,1);
  miLCD.write(byte(3));
}

void loop() {
  // put your main code here, to run repeatedly:

}
