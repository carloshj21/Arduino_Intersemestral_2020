int boton = 2;

void setup() {
  pinMode(boton,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(boton) == HIGH){
    Serial.write(1);
  }
  else{
    Serial.write(0);
  }
}
