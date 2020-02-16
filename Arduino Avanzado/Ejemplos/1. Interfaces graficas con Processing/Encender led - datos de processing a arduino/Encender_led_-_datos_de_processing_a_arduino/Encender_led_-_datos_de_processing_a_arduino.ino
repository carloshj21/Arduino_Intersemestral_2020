char opcion;
int pinLed = 2;

void setup() {
  pinMode(pinLed,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    opcion = Serial.read();

    if(opcion == 'h'){
      digitalWrite(pinLed,HIGH);
    }
    else{
     digitalWrite(pinLed,LOW);
    }
  }
}
