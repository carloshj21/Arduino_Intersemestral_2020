#include <EEPROM.h>

int i = 13270;
float aux = 0;

void setup() {
  Serial.begin(9600);
  
  // write gasta un intento en la vida útil de la memoria EEPROM
  //EEPROM.write(0,254);
  //EEPROM.write(1,136);

  // update hace lo mismo que write sin gastar un intento de la vida útil de EEPROM
  //EEPROM.update(0,254);
  //EEPROM.update(1,136);

  // put graba cualquier tipo de dato en la EEPROM a partir de una dirección
  //EEPROM.put(direccion,valor);

  // get lee un tipo de dato almacenado en la EEPROM a partir de una dirección y lo guarda 
  
  /*for(i=0;i<EEPROM.length();i++){
    Serial.print("Dirección: ");
    Serial.print(i);
    Serial.print("\tDato: ");
    Serial.println(EEPROM.read(i));    
  }*/

  // Grabo un entero a partir de la dirección 0
  //EEPROM.put(0,i);
  // Leo ese entero y lo guardo en aux
  Serial.println(EEPROM.get(0,aux));
  // Imprimo el valor de aux
  Serial.print("Valor de aux: ");
  Serial.println(aux);
}

void loop() {
  // put your main code here, to run repeatedly:

}
