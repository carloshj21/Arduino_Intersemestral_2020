/*
    Realizado por: Hernández Juárez Carlos
    Proyecto final Arduino Intermedio
    Prototipo de Puerta Inteligente
*/

#include <EEPROM.h>

// Se define la estructura
typedef struct usuario{
  byte contrasena;   // Número sin signo entre 0 y 255 
}usuario;

usuario Carlos = {121};
usuario Ricardo = {109};

byte direccion = 0;

void setup() {
  // Se guardan los 2 usuarios
  EEPROM.put(direccion,Carlos);
  direccion = direccion + sizeof(usuario);
  EEPROM.put(direccion,Ricardo);
}

void loop() {
  
}
