
// ----------------------------   Inclusión de librerías   --------------------------------------------------------------

// Librerías para sensor de temperatura
#include <DHT.h>
#include <DHT_U.h>
// Librería para teclado matricial
#include <Keypad.h>
// Librería para servomotor
#include <Servo.h>
// Librería para display LCD
#include <LiquidCrystal.h>
// Librería para memoria EEPROM
#include <EEPROM.h>
// Librería para interrupción
#include <TimerOne.h>

// -----------------------   Definición y configuración del teclado matricial   -----------------------------------------
char tecla;
char dato;

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
DHT dht(DHTPIN,DHT11);

// -------------------------------------------------  Variables globales  -----------------------------------------------

int i = 0;
byte direccion = 0;
byte indice = 0;
char clave[4];
char claveNueva[4];

byte contrasenas[2];

byte contrasena_Usu1;
byte contrasena_Usu2;

byte cambio = 0;

// -------------------------------------------------   Función para abrir la puerta   ------------------------------------
void modificarCont(byte direccion){
  int colLCD = 6;
  miLCD.clear();
  miLCD.print("Nueva contrasena");
  tecla = 'S';
  indice = 0;
  while(tecla != 'E'){
    tecla = miTeclado.getKey();
    if(tecla != NO_KEY){
      colLCD = colLCD + 1;
      claveNueva[indice] = tecla;
      indice++;
      miLCD.setCursor(colLCD,1);
      miLCD.print("*");
    }
  }
  if(tecla == 'E'){
    String claveIntro = String(claveNueva);
    byte claveCadena = String(claveIntro).toInt();
    EEPROM.update(direccion,claveCadena);
    miLCD.clear();
    miLCD.setCursor(3,0);
    miLCD.print("Contrasena");
    miLCD.setCursor(3,1);
    miLCD.print("modificada");
    cambio = 1;

    for(i=0;i<2;i++){
      EEPROM.get(direccion,recuperacion);
      contrasenas[i] = recuperacion.contrasena;
      direccion = direccion + sizeof(recuperacion);
    }

    contrasena_Usu1 = contrasenas[0];
    contrasena_Usu2 = contrasenas[1];
    Serial.println(contrasena_Usu1);
    Serial.println(contrasena_Usu2);
  
    delay(2000);
  }
}

void cambiarContrasena(){
  int colLCD = 6;
  indice = 0;
  miLCD.clear();
  miLCD.print("Introducir cont.");
  while(tecla != 'E'){
    tecla = miTeclado.getKey();
    if(tecla != NO_KEY)
    {
      colLCD = colLCD + 1;
      clave[indice] = tecla;
      indice++;
      miLCD.setCursor(colLCD,1);
      miLCD.print("*");
    }
  }
  if(tecla == 'E'){ 
    String claveIntro = String(clave);
    byte claveCadena = String(claveIntro).toInt();
    if(claveCadena == contrasena_Usu1){
      direccion = 0;
      modificarCont(direccion);
    }
    if(claveCadena == contrasena_Usu2){
      direccion = 1;
      modificarCont(direccion);
    }
    if(claveCadena != contrasena_Usu1 && claveCadena != contrasena_Usu2 && cambio == 0){
      miLCD.clear();
      miLCD.setCursor(3,0);
      miLCD.print("Contrasena");
      miLCD.setCursor(3,1);
      miLCD.print("incorrecta");
      delay(2000);
      puerta.write(90);
    }
  }
}

void cerrarPuerta(){
  miLCD.clear();
  miLCD.setCursor(4,0);
  miLCD.print("Abierto");
  miLCD.setCursor(0,1);
  miLCD.print("B - Cerrar puerta");
  while(tecla != 'B'){
    tecla = miTeclado.getKey();
  }
  if(tecla == 'B'){
    miLCD.clear();
    miLCD.setCursor(1,0);
    miLCD.print("Puerta cerrada");
    puerta.write(90);
    delay(2000);
  }
}

void abrirPuerta(){
  int colLCD = 6;
  indice = 0;
  miLCD.clear();
  miLCD.print("Introducir cont.");
  while(tecla != 'E'){
    tecla = miTeclado.getKey();
    if(tecla != NO_KEY)
    {
      colLCD = colLCD + 1;
      clave[indice] = tecla;
      indice++;
      miLCD.setCursor(colLCD,1);
      miLCD.print("*");
    }
  }
  if(tecla == 'E'){
    String claveIntro = String(clave);
    byte claveCadena = String(claveIntro).toInt();
    if(claveCadena == contrasena_Usu1 || claveCadena == contrasena_Usu2){
      puerta.write(0);
      miLCD.clear();
      miLCD.setCursor(3,0);
      miLCD.print("BIENVENIDO");
      delay(2000);
      cerrarPuerta();
    }
    else{
      miLCD.clear();
      miLCD.setCursor(3,0);
      miLCD.print("Contrasena");
      miLCD.setCursor(3,1);
      miLCD.print("incorrecta");
      delay(2000);
      puerta.write(90);
    }
  }
}

void menuInicial(char opcion){
  contrasena_Usu2 = contrasenas[1];
  switch(opcion){
    case 'A':
      abrirPuerta();
    break;
    case 'C':
      cambiarContrasena();
    break;
  }
}

void inicializacion(){
  cambio = 0;
  
  miLCD.setCursor(0,0);
  miLCD.print("A - Abrir puerta");
  miLCD.setCursor(0,1);
  miLCD.print("C - Cambiar cont");
  /*delay(2000);
  float temperatura = dht.readTemperature();  // Leer datos de temperatura
  if(isnan(temperatura)){
    Serial.println("Error de lectura");
  }else{
    miLCD.clear();
    Serial.println("Temperatura");
    miLCD.setCursor(0,0);
    miLCD.print("Temperatura: ");
    miLCD.setCursor(8,1);
    miLCD.print(temperatura);
    miLCD.setCursor(14,1);
    miLCD.print("C");
    delay(1000);
  }*/
  
  tecla = miTeclado.getKey();
  if(tecla != NO_KEY)
  {
    menuInicial(tecla);
  }
}

void setup() {
  Serial.begin(9600);
  dht.begin();  // Inicializar comunicación con el sensor DHT11
  miLCD.begin(16,2);  // Se inicializa el display LCD
  puerta.attach(5);

  for(i=0;i<2;i++){
    EEPROM.get(direccion,recuperacion);
    contrasenas[i] = recuperacion.contrasena;
    direccion = direccion + sizeof(recuperacion);
  }

  contrasena_Usu1 = contrasenas[0];
  contrasena_Usu2 = contrasenas[1];
  Serial.println(contrasena_Usu1);
  Serial.println(contrasena_Usu2);
}

void loop() {
  inicializacion();
  
}
