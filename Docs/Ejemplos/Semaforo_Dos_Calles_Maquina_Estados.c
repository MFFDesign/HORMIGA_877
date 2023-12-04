#include "system.h"

enum Semaforo{Verde,Amarillo,Rojo}; //Paso 1
enum Semaforo Estado;

const int FocoAmarillo = 2;
const int FocoRojo = 3;
const int FocoVerde = 4;

const int FocoBAmarillo = 5;
const int FocoBRojo = 6;
const int FocoBVerde = 7;

void setup()
{
	pinMode(FocoVerde,OUTPUT);
	pinMode(FocoAmarillo,OUTPUT);
	pinMode(FocoRojo,OUTPUT);
	
	pinMode(FocoBVerde,OUTPUT);
	pinMode(FocoBAmarillo,OUTPUT);
	pinMode(FocoBRojo,OUTPUT);
	
	digitalWrite(FocoBRojo,LOW);
	digitalWrite(FocoBAmarillo,LOW);
	digitalWrite(FocoBVerde,LOW);
	
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoAmarillo,LOW);
	digitalWrite(FocoVerde,LOW);
	
	Estado = Rojo;
	
}


void loop()
{
	switch(Estado)
	{
		case Verde:
			digitalWrite(FocoRojo,LOW);
			digitalWrite(FocoBRojo,HIGH);
			digitalWrite(FocoAmarillo,LOW);
			digitalWrite(FocoVerde,HIGH);
			delay(1000);
			
			for(int i=0,i<5;i++)
			{
				digitalWrite(FocoVerde,HIGH);
				digitalWrite(FocoBAmarillo,HIGH);
				delay(250);
				digitalWrite(FocoVerde,LOW);
				digitalWrite(FocoBAmarillo,LOW);
				delay(250);
			}
			Estado = Amarillo;
		break;
		case Amarillo:
			digitalWrite(FocoBRojo,HIGH);
			for(int i=0,i<5;i++)
			{
				digitalWrite(FocoAmarillo,HIGH);
				delay(250);
				digitalWrite(FocoAmarillo,LOW);
				delay(250);
			}
			delay(100);
			Estado = Rojo;
		break;
		case Rojo:
			digitalWrite(FocoRojo,HIGH);
			digitalWrite(FocoBVerde,HIGH);
			digitalWrite(FocoAmarillo,LOW);
			digitalWrite(FocoVerde,LOW);
			for(int i=0,i<5;i++)
			{
				digitalWrite(FocoBVerde,HIGH);
				delay(250);
				digitalWrite(FocoBVerde,LOW);
				delay(250);
			}
			delay(1000);
			Estado = Verde;
		break;
	}
}