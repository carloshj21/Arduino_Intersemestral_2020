#include <Key.h>
#include <Keypad.h>

char tecla;
int numero;
int numero1 = NULL;
int numero2 = NULL;
char operador = NULL;

const byte filas = 4;
const byte columnas = 4;

// Matriz que describe al teclado
char teclado [filas][columnas] ={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte pinesFilas[filas] = {11,10,9,8};
byte pinesColumnas[columnas] = {7,6,5,4};

Keypad miTeclado = Keypad(makeKeymap(teclado),pinesFilas,pinesColumnas,filas,columnas);

int operacion(int num1, int num2, char op){
  int resultado;
  switch(op){
    case '+':
      resultado = num1 + num2;
    break;
    return resultado; 
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  tecla = miTeclado.getKey();
  if(tecla != NO_KEY)
  {
    if(numero1 != NULL && numero2 == NULL && operador != NULL){
      numero = String(tecla).toInt();
      numero2 = numero;
      Serial.print("Número 2: ");
      Serial.println(numero2);
    }
    if(numero1 != NULL && numero2 == NULL && operador == NULL){
      operador = tecla;
      Serial.print("Operador: ");
      Serial.println(operador);
    }
    if(numero1 == NULL && numero2 == NULL && operador == NULL){
      numero = String(tecla).toInt();
      numero1 = numero;
      Serial.print("Número 1: ");
      Serial.println(numero1);
    }
    if(tecla == '='){
      Serial.println(operacion(numero1,numero2,operador));
    }
  }
}
