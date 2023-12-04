#include "system.h"
 
//Paso 1. Defeinir y declarar los estados posibles de la maquina.
enum LED{Encendido, Apagado};
//Paso 2. Declara la Vairable Monitor de la Maquina de Estados.
enum LED Estado;

const int Foco = 13;
const int Boton = 2;

void setup()
{
	pinMode(Foco,OUTPUT);
	pinMode(Boton,INPUT);
	//Paso 3. Declarar el estado inicial de la maquina de estados.
	Estado = Apagado;
}


void loop()
{
	//Describir el funcionamiento de la maquina de estados.
	switch(Estado) //Como argumento ingresamos la variable monitor.
	{
		case Encendido:
			//Proceso a ejecutar en este estado.
			digitalWrite(Foco,HIGH);
			//Colocar la condicon de transiscion para ir a otros estados.
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
			//Proceso a ejecutar en este estado.
			digitalWrite(Foco,LOW);
			//Colocar la condicon de transiscion para ir a otros estados.
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