int entrada1 = 7;
int entrada2 = 6;
int enable = 9;
int pot = A0;

int lectura;

void setup() {
  pinMode(entrada1,OUTPUT);
  pinMode(entrada2,OUTPUT);
  pinMode(enable,OUTPUT);

  digitalWrite(enable,HIGH);
}

void loop() {

  lectura = analogRead(pot);
  lectura = map(lectura,0,1023,0,255);
  
  digitalWrite(entrada1,LOW);
  analogWrite(entrada2,lectura);

  //digitalWrite(enable,LOW);
}
