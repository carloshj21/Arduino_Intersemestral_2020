/*
  Realizado por: Hernández Juárez Carlos

  Proyecto final de Arduino Básico: Máquina expendedora

  13 de enero de 2019
*/

// Pin del sensor de herradura
int herradura = 8;

// Pines del display de 7 segmentos
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;

// Pin para el buzzer
int buzzer = 16; 

// Pines de los LEDs
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;

// Pines de los botones
int boton1 = 13;
int boton2 = 19;
int boton3 = 18;
int boton4 = 17;

// Contadores
int i;

// Variable que almacenará el número que se desplegará en el display
int numero = 0;

// Variables para el estado de cada botón
int estadoBoton1;
int estadoBoton2;
int estadoBoton3;
int estadoBoton4;

// Función para mostrar en el display el dígito que se indique
void display(int num)
{
  switch(num)
  {
    case 0: 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,0);
     break;
    case 1: 
      digitalWrite(a,0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
     break;
     case 2: 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,0);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,0);
      digitalWrite(g,1);
     break;
     case 3: 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,1);
     break;
     case 4: 
      digitalWrite(a,0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case 5: 
      digitalWrite(a,1);
      digitalWrite(b,0);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case 6: 
      digitalWrite(a,1);
      digitalWrite(b,0);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case 7: 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
     break;
     case 8: 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case 9: 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
  }
}

void moneda(){  // Función para el proceso de insertar una moneda a la máquina
  if(digitalRead(herradura) == LOW)
  {
    numero = numero + 1;  // Aumenta el contador si se ha insertado una moneda
    if(numero > 9)  // Condición para asegurar que el número máximo de monedas que se pueden ingresar es 9
    {
      numero = 9;
    }
    // Sonido para confirmar que se introdujo la moneda 
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    display(numero);
    delay(500);
  }
}

// Función que verifica, para cada uno de los productos, si el número de monedas introducidas es suficiente para comprarlo
void verificar(){
  // Producto 1 = $1
  if(numero >= 1){
    digitalWrite(led1,HIGH);
  }
  if(estadoBoton1 == 0 && numero < 1){
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
  }
  if(estadoBoton1 == 0 && numero >= 1){
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(led1,LOW);
    numero = 0;
  }

  // Producto 2 = $3
  if(numero >= 3){
    digitalWrite(led2,HIGH);
  }
  if(estadoBoton2 == 0 && numero < 3){
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
  }
  if(estadoBoton2 == 0 && numero >= 3){
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(led2,LOW);
    numero = 0;
  }

  // Producto 3 = $5
  if(numero >= 5){
    digitalWrite(led3,HIGH);
  }
  if(estadoBoton3 == 0 && numero < 5){
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
  }
  if(estadoBoton3 == 0 && numero >= 5){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(led3,LOW);
    numero = 0;
  }

  // Producto 4 = $8
  if(numero >= 8){
    digitalWrite(led4,HIGH);
  }
  if(estadoBoton4 == 0 && numero < 8){
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
  }
  if(estadoBoton4 == 0 && numero >= 8){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(led4,LOW);
    numero = 0;
  }
}

void setup() {
  // Declaración de tipo de pines
  pinMode(herradura,INPUT);
  for(i=1;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }
  for(i=9;i<13;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(boton1,INPUT_PULLUP);
  pinMode(boton2,INPUT_PULLUP);
  pinMode(boton3,INPUT_PULLUP);
  pinMode(boton4,INPUT_PULLUP);

  pinMode(buzzer,OUTPUT);

}

void loop() {
  // Se leen y guardan los estados de los botones
  estadoBoton1 = digitalRead(boton1); 
  estadoBoton2 = digitalRead(boton2); 
  estadoBoton3 = digitalRead(boton3); 
  estadoBoton4 = digitalRead(boton4);
  
  display(numero);  // Se muestra el 0 en el display al iniciar
  moneda();  // Se manda llamar a la función moneda
  verificar();  // SE llama a la función verificar
}
