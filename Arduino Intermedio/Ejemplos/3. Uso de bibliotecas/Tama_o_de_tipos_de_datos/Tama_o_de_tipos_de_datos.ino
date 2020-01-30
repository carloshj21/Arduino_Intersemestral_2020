int entero;
float flotante;
char caracter;
byte bit;

void setup() {
  Serial.begin(9600);
  Serial.print("Tamaño de un entero: ");
  Serial.println(sizeof(entero));

  Serial.print("Tamaño de un flotante: ");
  Serial.println(sizeof(flotante));

  Serial.print("Tamaño de un caracter: ");
  Serial.println(sizeof(caracter));

  Serial.print("Tamaño de un byte: ");
  Serial.println(sizeof(bit));
}

void loop() {
  // put your main code here, to run repeatedly:

}
