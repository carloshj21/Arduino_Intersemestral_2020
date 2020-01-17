#include <EEPROM.h>

int i;
byte direccion = 0;
int valor;

void setup() {
  //  Para grabar los datos en la EEPROM
   
  /*for(i=0;i<11;i++){
    EEPROM.put(direccion,i);
    direccion = direccion + sizeof(int);
  }*/

  Serial.begin(9600);

  // Para visualizar los datos anteriormente escritos en la EEPROM
  
  for(i=0;i<11;i++){
    Serial.println(EEPROM.get(direccion,valor));
    direccion = direccion + sizeof(int);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
