int pot = A0;
int ledAmarillo = 7;
int ledNaranja = 8;
int ledRojo = 9;
int lectura;

void setup() {
  Serial.begin(9600);
  pinMode(ledAmarillo,OUTPUT);
  pinMode(ledNaranja,OUTPUT);
  pinMode(ledRojo,OUTPUT);
}

void loop() {
  lectura = analogRead(pot);
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  //delay(500);
  if(lectura >= 0 && lectura<341)
  {
    digitalWrite(ledAmarillo,HIGH);
    digitalWrite(ledNaranja,LOW);
    digitalWrite(ledRojo,LOW);
  }
  if(lectura >= 341 && lectura<682)
  {
    digitalWrite(ledAmarillo,LOW);
    digitalWrite(ledNaranja,HIGH);
    digitalWrite(ledRojo,LOW);
  }
  if(lectura >= 682 && lectura<=1023)
  {
    digitalWrite(ledAmarillo,LOW);
    digitalWrite(ledNaranja,LOW);
    digitalWrite(ledRojo,HIGH);
  }
}
