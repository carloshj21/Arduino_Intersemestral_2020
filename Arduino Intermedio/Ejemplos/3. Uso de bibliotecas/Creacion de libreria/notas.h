
#ifndef notas_h
#define notas_h

#include "Arduino.h"

class notas{
	
	public:
	// Pin para saber donde se encuentra el buzzer
	byte pin;

	// Método para 'tocar' una nota a través del teclado matricial
	void tocarNota(char nota);

}



#endif