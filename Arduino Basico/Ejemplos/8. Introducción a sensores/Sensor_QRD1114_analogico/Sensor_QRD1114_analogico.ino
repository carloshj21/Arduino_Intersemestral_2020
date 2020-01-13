int qrd = A0;  // Lectura digital
int led = 3;  // Salida digital
int lectura;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(qrd);
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  delay(500);
}
