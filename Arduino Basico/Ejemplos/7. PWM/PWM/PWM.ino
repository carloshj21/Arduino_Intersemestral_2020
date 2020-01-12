int pot = A0;  // Variable para el potenciómetro
int led = 3;  // Pin que puede manejar PWM
int lectura;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  lectura = analogRead(pot);
  lectura = map(lectura,0,1023,0,255);
  analogWrite(led,lectura);
}
