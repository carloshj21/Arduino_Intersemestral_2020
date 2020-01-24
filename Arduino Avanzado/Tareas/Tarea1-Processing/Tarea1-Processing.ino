int entrada1 = 7;
int entrada2 = 6;
int enable = 9;

char dato;

void estadoMotor(char estado){
  switch(estado){
    case 'p':
      digitalWrite(enable,HIGH);
      Serial.println("Prendido");
    break;
    case 'a':
      digitalWrite(enable,LOW);
      Serial.println("Apagado");
    break;
    case 'i':
      Serial.println("Girando izquierda");
      digitalWrite(entrada1,LOW);
      digitalWrite(entrada2,HIGH);
    break;
    case 'd':
      Serial.println("Girando derecha");
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
