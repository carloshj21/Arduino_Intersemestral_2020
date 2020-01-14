#define button 3
#define led 13

int contador;
bool led_state = 0;
bool last_state;

void setup() {
  attachInterrupt(digitalPinToInterrupt(3),prende,FALLING);  // Para hacer la interrupción
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(contador);
  contador++;
  delay(2000);
}

void prende(){
  led_state = !led_state;
  digitalWrite(led,led_state);
}

