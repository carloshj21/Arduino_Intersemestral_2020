// Debe instalarse la librería Keypad de Mark Stanley y Alexander Brevig
#include <Key.h>
#include <Keypad.h>

char tecla;

const byte filas = 4;
const byte columnas = 4;

// Matriz que describe al teclado
char teclado [filas][columnas] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[filas] = {11,10,9,8};
byte pinesColumnas[columnas] = {7,6,5,4};

Keypad miTeclado = Keypad(makeKeymap(teclado),pinesFilas,pinesColumnas,filas,columnas);

void setup() {
  Serial.begin(9600);
}

void loop() {
  tecla = miTeclado.getKey();
  if(tecla != NO_KEY)
  {
    Serial.println(tecla);
  }
}
