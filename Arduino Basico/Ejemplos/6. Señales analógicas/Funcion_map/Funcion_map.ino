int pot = A0;
int lectura;


void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(pot);
  // Hacemos que la lectura varie proporcionalmente en un nuevo rango
  lectura = map(lectura,0,1023,500,1000);   
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  delay(500);
}
