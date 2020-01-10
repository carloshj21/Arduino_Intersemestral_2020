// Se definen los pines de los 7 segmentos del display
int a = 7;
int b = 8;
int c = 9;
int d = 10;
int e = 11;
int f = 12;
int g = 13;

// Se definen los pines a los que se concetan los botones de decremento e incremento
int incre = 6;
int decre = 5;

// Variables donde se almacenará el estado del botón: si fue presionado o no
int estadoIncre;
int estadoDecre;

// Variable que almacenará el némero que se desplegará en el display
int numero = 0;

// Variables para los ciclos for
int i;
int num;


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

void setup() {
  // Se definen los pines de los segmentos del display como pines de salida
  for(i=7;i<14;i++)
  {
    pinMode(i,OUTPUT); 
  }
  pinMode(incre,INPUT_PULLUP);  // Se define el pin del botón de incremento como de entrada
  pinMode(decre,INPUT_PULLUP);  // Se define el pin del botón de decremento como de entrada
}

void loop() {
  display(numero);  // Se muestra el 0 en el display al iniciar
  estadoIncre = digitalRead(incre);   // Se lee el estado del botón para incrementar
  estadoDecre = digitalRead(decre);   // Se lee el estado del botón para decrementar
  
  if(estadoIncre == 0)  // Condición si se presiona el botón para incrementar
  {
    numero = numero + 1;  // Se incrementa la variable numero
    if(numero == 10)   // Condición para asegurar que si en el display aparece un 9, al incrementar aparezca un 0
    {
      numero = 0;
    }
    display(numero);   // Se muestra en el display el número ya con el incremento
    delay(500);   // Retraso para poder observar el cambio
  }
  
  if(estadoDecre == 0)   // Condición si se presiona el botón para decrementar
  {
    numero = numero - 1;   // Se decrementa la variable numero
    if(numero == -1)   // Condición para asegurar que si en el display aparece un 0, al decrementar aparezca un 9
    {
      numero = 9;
    }
    display(numero);   // Se muestra en el display el número ya con el incremento
    delay(500);   // Retraso para poder observar el cambio
  }
}
