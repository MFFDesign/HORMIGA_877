#include "system.h"

const int FocoRojo 		= 12;
const int FocoAmarillo 	= 11;
const int FocoVerde 	= 10;

/*
	Declaracion de todos los tiempos en Segundos que se van a 
	utilizar.
*/

const int TiempoCero = 20;
const int TiempoUno  = 5;
const int TiempoDos  = 5;
const int Tiempotres = 5;
const int TiempoCuatro = 5;
const int TiempoCinco = 5;
const int TiempoSeis = 5;
const int TiempoSiete = 50;
	

void setup()
{
	pinMode(FocoRojo,OUTPUT);
	pinMode(FocoAmarillo,OUTPUT);
	pinMode(FocoVerde,OUTPUT);
}

void loop()
{
	delay(TiempoSiete);
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoVerde,HIGH);
	digitalWrite(FocoAmarillo,LOW);
	delay(TiempoCero);
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoVerde,LOW);
	digitalWrite(FocoAmarillo,HIGH);
	delay(TiempoUno);
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoVerde,LOW);
	digitalWrite(FocoAmarillo,LOW);
	delay(TiempoDos);
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoVerde,LOW);
	digitalWrite(FocoAmarillo,HIGH);
	delay(TiempoTres);
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoVerde,LOW);
	digitalWrite(FocoAmarillo,HIGH);
	delay(TiempoCuatro);
	digitalWrite(FocoRojo,LOW);
	digitalWrite(FocoVerde,LOW);
	digitalWrite(FocoAmarillo,LOW);
	delay(TiempoCinco);
	digitalWrite(FocoRojo,HIGH);
	digitalWrite(FocoVerde,LOW);
	digitalWrite(FocoAmarillo,LOW);
	delay(TiempoSeis);
}