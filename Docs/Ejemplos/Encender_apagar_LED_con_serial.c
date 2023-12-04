/*
	Enviar mediante la Hormiga 877 la Frase Hola Mundo, usando
	la comunicacion serial, cada 500 milisegundos.
*/

#include "system.h"


char data = '0';
const int LED = 13;

void setup()
{
	pinMode(LED,OUTPUT);
	SerialBegin(9600);
}

void loop()
{
	data = SerialRead();
	if(data = 'a')
	{
		digitalWrite(LED,HIGH);
	}
	else if(data == 's')
	{
		digitalWrite(LED,LOW);
	}
}