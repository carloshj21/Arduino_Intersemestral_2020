
#include "notas.h"
#include "Arduino.h"

notas::notas(byte _pin){
	//asigno numero de pin a mi atributo 'pin'
	pin = _pin;
	pinMode(pin,OUTPUT);
}

void notas::tocarNota(char nota){
	switch(nota){
		case 'A':
		//La
			//pin de salida, frecuencia, duración (ms)
			tone(pin,1760,100);
		break;

		case 'B':
		//Si
			tone(pin,1975,100);
		break;

		case 'C':
		//Do
			tone(pin,1046,100);
		break;

		case 'D':
		//Re
			tone(pin,1174,100);
		break;

		case 'E':
		//Mi
			tone(pin,1318,100);
		break;

		case 'F':
		//Fa
			tone(pin,1396,100);
		break;
			
		case 'G':
		//Sol
			tone(pin,1567,100);
		break;
	}
}