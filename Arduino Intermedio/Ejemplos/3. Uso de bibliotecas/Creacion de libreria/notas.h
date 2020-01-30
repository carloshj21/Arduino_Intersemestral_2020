
#ifndef notas_h
#define notas_h

#include "Arduino.h"

class notas{

	public:
	//pin donde se encuentra buzzer
	byte pin;

	notas(byte _pin);
	void tocarNota(char nota);
	
};


#endif