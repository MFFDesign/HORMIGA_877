/*
	Practica 9. Sensor de Luz y Manejo de Cargas de Corriente
	alterna.
*/

#include "system.h"


const int Sensor = 0;
const int Relevador = 2;
int Threshold = 0;
int Iluminacion = 0;
int ValorMaximo = 500;
int ValorMinimo = 100;


void setup()
{
	pinMode(Relevador,OUTPUT);
}

void loop()
{
	Iluminacion = analogRead(Sensor);
	if(Illuinacion <= ValorMaximo)
	{
		digitalWrite(Relevador,LOW);
	}
	else if(Iluminacion <= ValorMinimo)
	{
		digitalWrite(Relevador,HIGH);
	}
}