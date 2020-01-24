int led = 8;
char estado;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    estado = Serial.read();

    if(estado == 'y' || estado == 'Y'){
      digitalWrite(led,LOW);
    }
    else if(estado == 'n' || estado == 'N'){
      digitalWrite(led,HIGH);
    }
  }
}
