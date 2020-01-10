int pot = A0;   // Entrada analógica 'A0'
int lectura;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(pot);
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  delay(500);
}
