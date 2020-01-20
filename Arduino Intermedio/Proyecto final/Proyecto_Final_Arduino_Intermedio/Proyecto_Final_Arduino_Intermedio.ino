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
DHT dht(DHTPIN,DHT11);

int i = 0;
byte direccion = 0;
byte contrasena;
byte contr [3];
String contra;

void abrirPuerta(){
  miLCD.clear();
  miLCD.print("Introducir cont.");
  for(i=0;i<3;i++){
    tecla = miTeclado.getKey();
    delay(500);
    Serial.println(tecla);
    contr[i] = tecla;
  }
  for(i=0;i<3;i++){
    Serial.println(contr[i]);
  }
  puerta.write(0);
  delay(5000);
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

  float temperatura = dht.readTemperature();  // Leer datos de temperatura
  if(isnan(temperatura)){
    Serial.println("Error de lectura");
  }else{
    delay(5000);
    miLCD.clear();
    Serial.println("Temperatura");
    miLCD.setCursor(0,0);
    miLCD.print("Temperatura: ");
    miLCD.setCursor(8,1);
    miLCD.print(temperatura);
    miLCD.setCursor(14,1);
    miLCD.print("C");
    delay(3000);
  }
  puerta.write(90);
  
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
  
}

void loop() {
  inicializacion();
  
  /*if(tecla != NO_KEY)
  {
    Serial.println(tecla);
    if(tecla == 'A'){
      miLCD.clear();
      miLCD.print("Introducir cont.");
      contrasena = miTeclado.getKey();
      if(contrasena != NO_KEY){
        Serial.println(contrasena);
      }
      delay(5000);
    }
  }*/
}
