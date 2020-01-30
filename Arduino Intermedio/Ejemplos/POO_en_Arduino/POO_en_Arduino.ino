int estadoLed = LOW;

// Clase
class Estudiante{
  // Atributos
  public:
  long numeroCuenta;
  float promedio;
  String carrera;
  float creditos;

  // Constructor
  Estudiante(long _numeroCuenta, String _carrera){
    numeroCuenta = _numeroCuenta;
    carrera = _carrera;
    Serial.println("Creando objeto de la clase estudiante");
  }

  // Métodos
  void programar(){
    Serial.println("Estoy programando");
  }
  void comer(){
    Serial.println("Estoy comiendo");
  }

  void prenderLed(int pinLed){
    if(estadoLed == HIGH){
      Serial.println("El LED ya está prendido");
    }
    else{
      estadoLed = HIGH;
      digitalWrite(pinLed,estadoLed);
    }
  }

  void apagarLed(int pinLed){
    if(estadoLed == LOW){
      Serial.println("El LED ya está apagado");
    }
    else{
      estadoLed = LOW;
      digitalWrite(pinLed,estadoLed);
    }
  }
  
};  // Punto y coma al terminar de definir la clase


// Creamos objeto de tipo estudiante
Estudiante Carlos = Estudiante(316262165,"Ingeniería Mecatrónica");

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
  Serial.print("Mi número de cuenta es: ");
  Serial.println(Carlos.numeroCuenta);
  Serial.print("Mi carrera es: ");
  Serial.println(Carlos.carrera);

  Carlos.programar();
  Carlos.comer();

  Carlos.prenderLed(13);
  delay(3000);
  Carlos.prenderLed(13);
  delay(3000);
  Carlos.apagarLed(13);
  delay(3000);
  Carlos.apagarLed(13);
}

void loop() {
  
}
