#include <TimerOne.h>  // Para interrupciones cada cierto tiempo

int led = 13;
int edoLed = LOW;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  // Definimos tiempo de interrupción en microsegundos
  Timer1.initialize(500000);
  // Qué hace la interrupción
  Timer1.attachInterrupt(parpadeo);
}

void parpadeo(){
  if(edoLed == LOW){
    edoLed = HIGH;
  }
  else{
    edoLed = LOW;
  }
  digitalWrite(led,edoLed);
}

void loop() {
  // put your main code here, to run repeatedly:

}
