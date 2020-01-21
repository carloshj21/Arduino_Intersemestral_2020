// ----------------------------   Inclusión de librerías   --------------------------------------------------------------

// Librerías para sensor de temperatura
//#include <DHT.h>
//#include <DHT_U.h>
// Librería para teclado matricial
#include <Keypad.h>
// Librería para servomotor
#include <Servo.h>
// Librería para display LCD
#include <LiquidCrystal.h>
// Librería para memoria EEPROM
#include <EEPROM.h>

// -----------------------   Definición y configuración del teclado matricial   -----------------------------------------
char tecla;

const byte filas = 4;
const byte columnas = 4;

// Matriz que describe al teclado
char teclado [filas][columnas] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','E','D'}
};

byte pinesFilas[filas] = {13,12,11,10};
byte pinesColumnas[columnas] = {9,8,7,6};

Keypad miTeclado = Keypad(makeKeymap(teclado),pinesFilas,pinesColumnas,filas,columnas);

// ------------------------------------   Definición del display LCD   ------------------------------------------------
// (RS,E,d4,d5,d6,d7)
LiquidCrystal miLCD(14,15,16,17,18,19);

// --------------------------------   Declaración del servomotor para la puerta   -------------------------------------
// Declaro mi objeto para servo
Servo puerta;

// -----------------   Se define la estructura para los usuarios que están guardados en la EEPROM   -------------------
typedef struct usuario{
  byte contrasena;
}usuario;

// ---   Se crea un usuario que lleva por nombre recuperación el cual será utilizado para leer los datos de la EEPROM   ---
usuario recuperacion;

// ---------------------------------   Se define al sensor de temperatura DHT11   -------------------------------------
#define DHTPIN 3
//DHT dht(DHTPIN,DHT11);

// -------------------------------------------------  Variables globales  -----------------------------------------------

int i = 0;
byte direccion = 0;
char clave[4];
byte indice = 0;

byte contrasenas[2];

byte contrasena_Usu1;
byte contrasena_Usu2;

// -------------------------------------------------   Función para abrir la puerta   ------------------------------------
void abrirPuerta(){
  int colLCD = 6;
  Serial.print("colLCD: ");
  Serial.println(colLCD);
  miLCD.clear();
  miLCD.print("Introducir cont.");
  Serial.println("Introduzca su contraseña: ");
  while(tecla != 'E'){
    tecla = miTeclado.getKey();
    if(tecla != NO_KEY)
    {
      colLCD = colLCD + 1;
      clave[indice] = tecla;
      indice++;
      Serial.print(tecla);
      Serial.print('*');
      Serial.print("colLCD: ");
      Serial.println(colLCD);
      miLCD.setCursor(colLCD,1);
      miLCD.print("*");
    }
    //Serial.println("No enter");
  }
  if(tecla == 'E'){
    String claveIntro = String(clave);
    int claveCadena = String(claveIntro).toInt();
    if(claveCadena == contrasena_Usu1 || claveCadena == contrasena_Usu2){
      Serial.println(" Correcta");
      puerta.write(0);
    }
    else{
      Serial.println(" Incorrecta");
      puerta.write(90);
    }
  }
}

void menuInicial(char opcion){
  switch(opcion){
    case 'A':
      abrirPuerta();
    break;
    case 'C':
    break;
  }
}

void inicializacion(){
  
  miLCD.setCursor(0,0);
  miLCD.print("A - Abrir puerta");
  miLCD.setCursor(0,1);
  miLCD.print("C - Cambiar cont");
  
  tecla = miTeclado.getKey();
  if(tecla != NO_KEY)
  {
    menuInicial(tecla);
  }
}



void setup() {
  Serial.begin(9600);
//  dht.begin();  // Inicializar comunicación con el sensor DHT11
  miLCD.begin(16,2);  // Se inicializa el display LCD
  puerta.attach(5);

  for(i=0;i<2;i++){
    EEPROM.get(direccion,recuperacion);
    contrasenas[i] = recuperacion.contrasena;
    direccion = direccion + sizeof(recuperacion);
  }

  contrasena_Usu1 = contrasenas[0];
  contrasena_Usu2 = contrasenas[1];
}

void loop() {
  inicializacion();
}
