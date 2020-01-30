#define button 3
#define led 13

int contador;
bool led_state;
bool last_state;

void setup() {
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(contador);
  contador++;
  delay(2000);
  bool estado = digitalRead(button);
  if(estado == LOW && estado != last_state){
    led_state = !led_state;
  }
  digitalWrite(led,led_state);
  last_state = estado;

  /*  Intento

  if(encendido == 0 && digitalRead(boton) == 0){
    digitalWrite(led,HIGH);
    encendido = 1;
    Serial.print("Estado botón: ");
    Serial.println(encendido);
    delay(500);
  }
  if(encendido == 1 && digitalRead(boton) == 0){
    digitalWrite(led,LOW);
    encendido = 0;
    Serial.print("Estado botón: ");
    Serial.println(encendido);
    delay(500);
  }*/
  

  
}
