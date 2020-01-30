#include <EEPROM.h>

// Definición de una estructura

typedef struct empleado{  // typedef permite asignar un alias a una estructura
  int contrasena;  // 2 bytes
  char tipoEmpleado;   // 1 byte
  // La estructura 'pesa' 3 bytes
}empleado;

// Se crea una estructura empleado de nombre Carlos, inicializando sus valores
empleado Carlos = {1203,'A'};
// Se crean 2 empleados más para guardarlos
empleado Ricardo = {3333,'B'};
empleado Santiago = {1212,'C'};


//empleado recuperacion;

int i;
byte direccion = 0;
int valor;

void setup() {
  Serial.begin(9600);

  // Se guardan 3 empleados
  EEPROM.put(direccion,Carlos);
  direccion = direccion + sizeof(empleado);
  EEPROM.put(direccion,Ricardo);
  direccion = direccion + sizeof(empleado);
  EEPROM.put(direccion,Santiago);
  
  /* Recuperar datos anteriormente guardados
   
  Serial.println("Empleado antes de recuperación: \n");
  Serial.print("Contraseña: ");
  Serial.println(recuperacion.contrasena);
  Serial.print("Tipo de empleado: ");
  Serial.println(recuperacion.tipoEmpleado);

  EEPROM.get(direccion,recuperacion);
  Serial.println("\nSe recuperan los datos de la EEPROM\n");
  Serial.print("Contraseña: ");
  Serial.println(recuperacion.contrasena);
  Serial.print("Tipo de empleado: ");
  Serial.println(recuperacion.tipoEmpleado);*/
  
  //EEPROM.put(direccion,Carlos);
}

void loop() {
  // put your main code here, to run repeatedly:

}
