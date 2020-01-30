#include <Key.h>
#include <Keypad.h>
#include <notas.h>  // Se encuentra en la carpeta de creación de librería

const byte filas = 3;
const byte columnas = 3;

byte pinesFilas[filas] = {11,10,9};
byte pinesColumnas[columnas] = {7,6,5};

char teclado [filas][columnas]={
  {'C','D','E'},
  {'F','G','A'},
  {'B','\0','\0'}
};

Keypad piano = Keypad(makeKeymap(teclado),pinesFilas,pinesColumnas,filas,columnas);

// El constructor recibe el pin donde tenemos el buzzer
notas pianista = notas(4);

// Guardamos la tecla que recibimos del teclado matricial 
char nota;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  nota = piano.getKey();
  pianista.tocarNota(nota);
}
