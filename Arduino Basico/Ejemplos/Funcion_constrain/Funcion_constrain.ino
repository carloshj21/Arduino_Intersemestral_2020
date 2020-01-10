int pot = A0;
int lectura;


void setup() {
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(pot);
  // Restringimos los valores del potenciometro para que solo se encuentren lo sque se encuentren en el rango
  lectura = constrain(lectura,500,1000);   
  Serial.print("Valor leído: ");
  Serial.println(lectura);
  delay(500);
}
