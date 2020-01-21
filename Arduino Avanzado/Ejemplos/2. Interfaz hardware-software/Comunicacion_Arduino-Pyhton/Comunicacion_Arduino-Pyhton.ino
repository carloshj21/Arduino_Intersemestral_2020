int led = 2;

// Para leer lso datos de python
char opcion;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    opcion = Serial.read();

    if(opcion == 'p'){
      digitalWrite(led,HIGH);
    }
    if(opcion == 'a'){
      digitalWrite(led,LOW);
    }
  }
}
