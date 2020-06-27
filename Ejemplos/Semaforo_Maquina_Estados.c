#include "system.h"

/*
	Semaforo con Maquina de Estados
*/

enum Semaforo{Verde,Amarillo,Rojo};
enum Semaforo Status;

const int FocoVerde = 2;
const int FocoRojo = 3;
const int FocoAmarillo = 4;

void setup()
{
	pinMode(FocoAmarillo,OUTPUT);
	pinMode(FocoRojo,OUTPUT);
	pinMode(FocoVerde,OUTPUT);
	
	Status = Rojo;
}


void loop()
{
	switch(Status)
	{
		case Verde:
			digitalWrite(FocoAmarillo,LOW);
			digitalWrite(FocoRojo,LOW);
			digitalWrite(FocoVerde,HIGH);
			delay(500);
			for(int i=0;i<5;i++)
			{
				digitalWrite(FocoVerde,HIGH);
				delay(100);
				digitalWrite(FocoVerde,LOW);
				delay(100);
			}
			Status = Amarillo;
		break;
		case Amarillo:
			for(int i=0;i<5;i++)
			{
				digitalWrite(FocoAmarillo,HIGH);
				delay(200);
				digitalWrite(FocoAmarillo,LOW);
				delay(200);
			}
			Status = Rojo;
		break;
		case Rojo:
			digitalWrite(FocoAmarillo,LOW);
			digitalWrite(FocoRojo,HIGH);
			digitalWrite(FocoVerde,LOW);
			delay(500);
			Status = Verde;
		break;
	}
}