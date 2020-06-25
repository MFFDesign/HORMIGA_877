#include "system.h"

unsigned int Boton = 2;
unsigned int LED = 13;

void setup()
{
	pinMode(LED,OUTPUT);
	pinMode(Boton,INPUT);
}


void loop()
{
	if((PBRead(0) == HIGH) || (digitalRead(Boton) == HIGH))
	{
		digitalWrite(LED,HIGH);
	}
	else
	{
		digitalWrite(LED,LOW);
	}
	
}