#include <SoftwareSerial.h>

int Rx = 6;  // Conectado al Tx del módulo
int Tx = 5;  // Conectado al Rx del módulo

// Creamos nuestro objeto diciéndole qué pines vamos a usar para la comunicación serial
SoftwareSerial blue = SoftwareSerial(Rx,Tx);

char dato;

int a = 7;
int b = 8;
int c = 9;
int d = 10;
int e = 11;
int f = 12;
int g = 13;

int i;
char num;

void display(char num)
{
  switch(num)
  {
    case '0': 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,0);
     break;
    case '1': 
      digitalWrite(a,0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
     break;
     case '2': 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,0);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,0);
      digitalWrite(g,1);
     break;
     case '3': 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,1);
     break;
     case '4': 
      digitalWrite(a,0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case '5': 
      digitalWrite(a,1);
      digitalWrite(b,0);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case '6': 
      digitalWrite(a,1);
      digitalWrite(b,0);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case '7': 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
     break;
     case '8': 
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,1);
     break;
     case '9': 
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

void setup() {
  Serial.begin(9600);
  blue.begin(9600);
  for(i=7;i<14;i++)
  {
    pinMode(i,OUTPUT); 
  }
  display('0');
}

void loop() {
  if(blue.available() > 0){
    dato = blue.read();
    display(dato);
  }
}
