#include <EEPROM.h>

// Debe instalarse la librería Keypad de Mark Stanley y Alexander Brevig
#include <Key.h>
#include <Keypad.h>

char tecla;
char clave[4];
byte indice = 0;

int i;
byte direccion = 0;

byte contrasenas[2];

byte contrasena_Usu1;
byte contrasena_Usu2;

const byte filas = 4;
const byte columnas = 4;

// Matriz que describe al teclado
char teclado [filas][columnas] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[filas] = {13,12,11,10};
byte pinesColumnas[columnas] = {9,8,7,6};

Keypad miTeclado = Keypad(makeKeymap(teclado),pinesFilas,pinesColumnas,filas,columnas);

typedef struct usuario{
  byte contrasena;
}usuario;

usuario recuperacion;

void setup() {
  Serial.begin(9600);

  for(i=0;i<2;i++){
    EEPROM.get(direccion,recuperacion);
    contrasenas[i] = recuperacion.contrasena;
    direccion = direccion + sizeof(recuperacion);
  }

  contrasena_Usu1 = contrasenas[0];
  contrasena_Usu2 = contrasenas[1];
}

void loop() {
  tecla = miTeclado.getKey();
  if(tecla != NO_KEY)
  {
    clave[indice] = tecla;
    indice++;
    //Serial.print(tecla);
    Serial.print('*');
  }

  String claveIntro = String(clave);
  int claveCadena = String(claveIntro).toInt();
  if(indice == 3){
    if(claveCadena == contrasena_Usu1 || claveCadena == contrasena_Usu2){
      Serial.println(" Correcta");
    }
    else{
      Serial.println(" Incorrecta");
    }
    indice = 0;
  }
}
