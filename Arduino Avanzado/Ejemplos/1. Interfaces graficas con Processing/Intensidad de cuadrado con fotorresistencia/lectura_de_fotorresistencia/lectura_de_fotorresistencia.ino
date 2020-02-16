int ldr = A0;
int lectura;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(ldr);
  lectura = lectura / 4;
  Serial.write(lectura);
}
