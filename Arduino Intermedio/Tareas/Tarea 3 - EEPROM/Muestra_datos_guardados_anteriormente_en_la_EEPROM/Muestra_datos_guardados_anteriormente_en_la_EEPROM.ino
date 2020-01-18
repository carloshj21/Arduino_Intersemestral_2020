#include <EEPROM.h>

int i;
byte direccion = 0;

typedef struct trabajador{
  byte edad;          // Número sin signo entre 0 y 255
  char tipoTrabajador;
  byte contrasena;   // Número sin signo entre 0 y 255 
}trabajador;

trabajador recuperacion;

void setup() {
  Serial.begin(9600);
  
  // Para visualizar los datos anteriormente escritos en la EEPROM
  for(i=0;i<3;i++){
    EEPROM.get(direccion,recuperacion);
    Serial.print("Edad: ");
    Serial.println(recuperacion.edad);
    Serial.print("Tipo de trabajador: ");
    Serial.println(recuperacion.tipoTrabajador);
    Serial.print("Contraseña: ");
    Serial.println(recuperacion.contrasena);
    Serial.println("\n");
    direccion = direccion + sizeof(recuperacion);
  }
}

void loop() {

}
