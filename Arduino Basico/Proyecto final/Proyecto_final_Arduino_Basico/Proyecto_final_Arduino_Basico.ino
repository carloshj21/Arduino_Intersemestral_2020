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

// Pi para el buzzer
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

// Variable que almacenará el némero que se desplegará en el display
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

void moneda(){
  if(digitalRead(herradura) == LOW)
  {
    numero = numero + 1;
    if(numero > 9)
    {
      numero = 9;
    }
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    display(numero);
    delay(1000);
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
  
  /*estadoBoton1 = digitalRead(boton1); 
  estadoBoton2 = digitalRead(boton2); 
  estadoBoton3 = digitalRead(boton3); 
  estadoBoton4 = digitalRead(boton4);*/

  display(numero);  // Se muestra el 0 en el display al iniciar
  moneda();
  
  /*if(estadoBoton1 == 0)
  {
    digitalWrite(led1,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
  }
  if(estadoBoton2 == 0)
  {
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
  }
  if(estadoBoton3 == 0)
  {
    digitalWrite(led3,HIGH);
    delay(1000);
    digitalWrite(led3,LOW);
  }
  if(estadoBoton4 == 0)
  {
    digitalWrite(led4,HIGH);
    delay(1000);
    digitalWrite(led4,LOW);
  }*/

  // Buzzer
  /*digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);*/
  
  // Display
  
  /*for(i=0;i<10;i++)
  {
    display(i);
    delay(200); 
  }*/

}
