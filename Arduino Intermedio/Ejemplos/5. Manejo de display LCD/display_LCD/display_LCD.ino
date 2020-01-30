#include <LiquidCrystal.h>

// (RS,E,d4,d5,d6,d7)
LiquidCrystal miLCD(2,3,4,5,6,7);

void setup() {
  /// begin(columnas,filas)
  miLCD.begin(16,2);
  
  miLCD.print("Hola Mundo");
  miLCD.write("!");
  miLCD.cursor();
  
}

void loop() {
  // setCursor(columna,fila);
  miLCD.setCursor(0,1);
  
  // blink muestra el cursor parpadeando
  //miLCD.blink();

  miLCD.print(millis()/1000);
}
