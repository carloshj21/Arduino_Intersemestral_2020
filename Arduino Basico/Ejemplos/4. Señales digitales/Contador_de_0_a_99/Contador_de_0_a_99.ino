int a = 7;
int b = 8;
int c = 9;
int d = 10;
int e = 11;
int f = 12;
int g = 13;

int i;
int j;

//Salidas digitales que permite el paso de corriente o no al transistor
int decenas = 5;
int unidades = 6;   

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

void setup() {
  for(i=5;i<14;i++)
  {
    pinMode(i,OUTPUT); 
  }
}

void loop() {
  for(i=0;i<=9;i++)   // Ciclo para mostrar las decenas
  {
    for(j=0;j<=500;j++)  // Ciclo para mostrar las unidades
    {
      digitalWrite(unidades,HIGH);   // Activamos el display de unidades
      digitalWrite(decenas,LOW);
      display(j/50);
      delay(10);
      digitalWrite(unidades,LOW);   // Activamos el display de unidades
      digitalWrite(decenas,HIGH);
      display(i);
      delay(10);
    }
  }
  
  
}
