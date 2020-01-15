#include <Key.h>
#include <Keypad.h>

char tecla;
float numero;
float numero1 = NULL;
float numero2 = NULL;
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

void operacion(float num1, float num2, char op){
  float resultado;
  switch(op)
  {
    case '+':
      resultado = num1 + num2;
      Serial.println(resultado,0);
    break;
    case '-':
      resultado = num1 - num2;
      Serial.println(resultado,0);
    break;
    case '*':
      resultado = num1 * num2;
      Serial.println(resultado,0);
    break;
    case '/':
      if(num2 == 0){
        Serial.println("Error: no se puede dividir entre cero");
      }else{
        resultado = num1 / num2;
        Serial.println(resultado,2);
      }
    break;
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
      numero = String(tecla).toFloat();
      numero2 = numero;
      //Serial.print("Número 2: ");
      Serial.print(numero2,0);
    }
    if(numero1 != NULL && numero2 == NULL && operador == NULL){
      operador = tecla;
      //Serial.print("Operador: ");
      Serial.print(operador);
    }
    if(numero1 == NULL && numero2 == NULL && operador == NULL){
      numero = String(tecla).toFloat();
      numero1 = numero;
      //Serial.print("Número 1: ");
      Serial.print(numero1,0);
    }
    if(tecla == '='){
      Serial.print("=");
      operacion(numero1,numero2,operador);
      delay(1000);
      Serial.println("Presione * en el teclado para realizar otra operación");
    }
    if(tecla == 'C'){
      Serial.println("-------------------------------------------------------- ");
      numero1 = NULL;
      numero2 = NULL;
      operador = NULL;
    }
  }
}
