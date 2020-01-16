/*
    Realizado por: Hernández Juárez Carlos
    Tarea 2: Calculadora con teclado matricial

    Arduino Intermedio

*/

// Librería para poder utilizar el teclado matricial
#include <Key.h>
#include <Keypad.h>

char tecla;  // Variable para guaradar lo que se recibe del teclado
float numero;  // Lo que se va a operar
float numero1 = NULL;  // Variable del primer número introducido
float numero2 = NULL;  // Variable del segundo número introducido
char operador = NULL;  // Variable del operador que se aplicará a los números introducidos

// Filas y columnas del teclado
const byte filas = 4;
const byte columnas = 4;

// Matriz que describe al teclado
char teclado [filas][columnas] ={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

// Se definen los pines a los cuales está conectado el teclado
byte pinesFilas[filas] = {11,10,9,8};
byte pinesColumnas[columnas] = {7,6,5,4};

Keypad miTeclado = Keypad(makeKeymap(teclado),pinesFilas,pinesColumnas,filas,columnas);

// Función que realiza la operación
void operacion(float num1, float num2, char op){
  float resultado;  // Variable que guardará el resultado de la operación
  switch(op)  // Abarca las 4 posibilidades de operador
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
      // Se considera la división entre 0
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
  Serial.begin(9600);  // Se abre la comunicación serial
}

void loop() {
  tecla = miTeclado.getKey();  // Se guarda lo que el usuario pulsó en el teclado
  if(tecla != NO_KEY)
  {
    // Condiciones para saber cuál es el número 1, el número 2 y el operador
    if(numero1 != NULL && numero2 == NULL && operador != NULL){
      numero = String(tecla).toFloat();  // Se convierte el caracter recibido en un flotante
      numero2 = numero;
      Serial.print(numero2,0);  // Se muestra el numero sin decimales
    }
    if(numero1 != NULL && numero2 == NULL && operador == NULL){
      operador = tecla;
      Serial.print(operador);
    }
    if(numero1 == NULL && numero2 == NULL && operador == NULL){
      numero = String(tecla).toFloat();  // Se convierte el caracter recibido en un flotante
      numero1 = numero;
      Serial.print(numero1,0); // Se muestra el numero sin decimales
    }
    if(tecla == '='){
      Serial.print("=");
      operacion(numero1,numero2,operador); // LLamada a función operacion
      delay(1000);
      Serial.println("Presione * en el teclado para realizar otra operación"); // Mensaje para saber si se hará otra operación
    }
    if(tecla == 'C'){
      Serial.println("-------------------------------------------------------- ");  // Línea para diferenciar una operación de otra
      // Se restablecen los valores para que pueda realizarse otra operación
      numero1 = NULL;
      numero2 = NULL;
      operador = NULL;
    }
  }
}
