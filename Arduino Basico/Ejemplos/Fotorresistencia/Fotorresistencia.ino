int ldr = A5;
int lectura;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(ldr);
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  delay(500);
}
