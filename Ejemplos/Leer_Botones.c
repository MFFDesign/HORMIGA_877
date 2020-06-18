#include "system.h"

const int Boton = 0;
const int Led = 13;
void setup()
{
	pinMode(Led,OUTPUT);
	/*
		Procedimiento que permite configurar las terminal 13 de
		la placa Hormiga 877 que posee un diodo Led Integrado, la
		palabra "OUTPUT", configura la terminal como Salida, capaz
		de representar dos valores diferentes, 1 Logico (5V) y 
		0 Logico (0V).
	*/
	/*
		La placa Hormiga 877 posee 3 Botones integrados en los
		procedimientoos PBRead( int NumeroBoton) que por defecto
		estan configurados como Entradas, de modo  que ya no es 
		necesario configurarlos como entradas.
	*/
}

void loop()
{
	if(PBRead(Boton) == HIGH)
	{
		digitalWrite(Led,HIGH);
	}
	else
	{
		digitalWrite(Led,LOW);
	}
	/*
		La toma de desicion se realiza mediante la instruccion
		IF - ELSE, el cual posee como argumento  una condicion
		que si resulta cierta se ejecuta el codigo contenido en 
		las dos llaves que abren y cierran, en caso de ser falsa
		se ejcute la parte de ELSE.
	*/
}