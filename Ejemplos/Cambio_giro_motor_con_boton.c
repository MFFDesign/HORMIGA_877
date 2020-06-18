#include "system.h"


/*
	Declaracion de las constantes del Motor 1.
	Se Usaran los Botones integrados en la placa Hormiga 877.
*/

const int TerminalA = 0;
const int TerminalB = 1;

/*
	Declaracon de botones que controlan el sentido de motor. Valores
	que corresponden a las direcciohnes de los botones Pulsadores.
*/

const int Adelante = 0;
const int Atras = 1;

void setup()
{
	pinMode(TerminalA,OUTPUT);
	pinMode(TerminalB,OUTPUT);
}

void loop()
{
	if(PBRead(Adelante) == HIGH)
	{
		delay(100);
		if(PBRead(Adelante) == HIGH)
		{
			digitalWrite(TerminalA,HIGH)
			digitalWrite(TerminalB,LOW);
			delay(2000);
		}
	}
	else if(PBRead(Atras) == HIGH)
	{
		delay(100);
		if(PBRead(Atras) == HIGH)
		{
			digitalWrite(TerminalA,LOW);
			digitalWrite(TerminalB,HIGH);
			delay(2000);
		}
	}
	else
	{
		digitalWrite(TerminalA,LOW);
		digitalWrite(TerminalB,LOW);
	}
}