/*
	Lectura de Sensores Infrarrrojos.
	Encender diodos emisores de luz, segun se activen o desactiven
	los sensores infrarrojos.
*/

#include "system.h"

const int LEDA = 13;
const int LEDB = 14;

void setup()
{
	pinMode(LEDA,OUTPUT);
	pinMode(LEDB,OUTPUT);
	digitalWrite(LEDA,LOW);
	digitalWrite(LEDB,LOW);
}

void loop()
{
	if(LecturaSensorIRA() == HIGH)
	{
		digitalWrite(LEDA,HIGH);
	}
	else
	{
		digitalWrite(LEDA,LOW);
	}
	if(LecturaSensorIRB() == HIGH)
	{
		digitalWrite(LEDB,HIGH);
	}
	else
	{
		digitalWrite(LEDB,LOW);
	}
}


char LecturaSensorIRA(void)
{
	int Threshold = 500;
	if(analogRead(0) >= Threshold)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char LecturaSensorIRB(void)
{
	int Threshold = 500;
	if(analogRead(1) >= Threshold)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}