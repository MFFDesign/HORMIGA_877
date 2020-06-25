#include "system.h"

/* Paso 1. Delcarar los estado de la maquina de estados.*/
enum Maquina{Encendido, Apagado};
/*Paso 2. declarar variable que  gaurdara cada estado.*/
Maquina Estado;

const int LED = 13;
const int Boton = 2;

void setup()
{
	pinMode(LED,OUTPUT);
	pinMode(Boton,INPUT);
	/*Paso 3. asignar estado por defecto*/
	Estado = Apagado;
}


void loop()
{
	/**Implementar la maquina de estados.*/
	switch(Estado)
	{
		case Encendido:
			//Colocar un proceso;
			//Colocar una transicion.
			digitalWrite(LED,HIGH);
			if(digitalRead(Boton) == HIGH)
			{
				delay(50);
				if(digitalRead(Boton) == HIGH)
				{
					Estado = Apagado;
				}
				else
				{
					Estado = Encendido;
				}
			}
			else
			{
				Estado = Encendido;
			}
		break;
		case Apagado:
			//Colocar un proceso;
			//Colocar una transicion.
			digitalWrite(LED,LOW);
			if(digitalRead(Boton) == HIGH)
			{
				delay(50);
				if(digitalRead(Boton) == HIGH)
				{
					Estado = Encendido;
				}
				else
				{
					Estado = Apagado;
				}
			}
			else
			{
				Estado = Apagado;
			}
		break;
	}
	
}