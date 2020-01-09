int led;    // Variable que definirá los pines de los LEDs
int tiempo = 500;   // Variable que representa el tiempo en milisegundos que los LEDs permanecerán prendidos

void setup() {
  // Se configuran los pines 7,8,9,10 y 11 como de salida
  for(led=7;led<12;led++)
  {
    pinMode(led,OUTPUT);
  }
}

void loop() {
  if(tiempo > 0){    // Condición para que se ejecute la sucesión
    for(led=11;led>6;led--)   // Ciclo que logra prender los 5 LEDs que componen el circuito
    {
      digitalWrite(led,HIGH);  // Se enciende el LED
      delay(tiempo);    // Temporizador
      digitalWrite(led,LOW);   // Se apaga el LED
    }
    tiempo = tiempo-40;    // Se reduce el tiempo durante el que los LEDs permanecen encendidos
  }else{
    tiempo = 500;    // De no cumplirse la condición del if, se restablece el tiempo inicial
  }
}
