#include <EEPROM.h>

// Se define la estructura
typedef struct trabajador{
  byte edad;          // Número sin signo entre 0 y 255
  char tipoTrabajador;
  byte contrasena;   // Número sin signo entre 0 y 255 
}trabajador;

trabajador Carlos = {19,'A',121};
trabajador Ricardo = {17,'B',109};
trabajador Rafael = {36,'C',153};
trabajador Santiago = {20,'A',207};

byte direccion = 0;

void setup() {
  // Se guardan los 4 trabajadores
  EEPROM.put(direccion,Carlos);
  direccion = direccion + sizeof(trabajador);
  EEPROM.put(direccion,Ricardo);
  direccion = direccion + sizeof(trabajador);
  EEPROM.put(direccion,Rafael);
  direccion = direccion + sizeof(trabajador);
  EEPROM.put(direccion,Santiago);
}

void loop() {
  
}
