/*
    Realizado por: Hernández Juárez Carlos
    Tarea 1: Processing
    Arduino Avanzado
*/

int entrada1 = 7;
int entrada2 = 6;
int enable = 9;

int dato;

void estadoMotor(int estado){
  switch(estado){
    case 1:
      digitalWrite(enable,HIGH);
    break;
    case 2:
      digitalWrite(enable,LOW);
      digitalWrite(entrada1,LOW);
      digitalWrite(entrada2,LOW);
    break;
    case 3:
      digitalWrite(entrada1,LOW);
      digitalWrite(entrada2,HIGH);
    break;
    case 4:
      digitalWrite(entrada1,HIGH);
      digitalWrite(entrada2,LOW);
    break;
  }
}

void setup() {
  pinMode(entrada1,OUTPUT);
  pinMode(entrada2,OUTPUT);
  pinMode(enable,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available() != 0){
    dato = Serial.read();
    estadoMotor(dato);
  }
}
