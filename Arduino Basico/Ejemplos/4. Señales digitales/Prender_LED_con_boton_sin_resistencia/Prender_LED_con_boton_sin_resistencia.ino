int led = 4;
int boton = 8;
int estadoBoton;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT_PULLUP);
}

void loop() {
  
  estadoBoton = digitalRead(boton);

  if(estadoBoton == 0){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
