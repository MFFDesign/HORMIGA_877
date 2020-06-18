/*
	Enviar mediante la Hormiga 877 la Frase Hola Mundo, usando
	la comunicacion serial, cada 500 milisegundos.
*/

#include "system.h"

void setup()
{
	SerialBegin(9600);
}

void loop()
{
	SerialPrintln("Hola");
	delay(500);
	SerialPrintln("Mundo");
}