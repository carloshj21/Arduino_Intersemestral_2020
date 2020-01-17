byte edoPuerto;

void setup() {
  // Configuración de puertos
  // 0 - entradas  ;  1 - salidas
  DDRB = B11111111;
  DDRC = B11110000;
}

void loop() {
  edoPuerto = PINC;
  PORTB = edoPuerto;
}
