int pot = A0;
int led = 7;
int lectura;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  lectura = analogRead(pot);
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  delay(500);
  digitalWrite(led,HIGH);
  delay(lectura);
  digitalWrite(led,LOW);
}
