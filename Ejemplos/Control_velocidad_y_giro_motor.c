#include "system.h"

int Velocidad = 0;
/*
	Practica 8. Motor de Corriente DIrecta, control de giro con potenciometro digital.
*/

const int Potenciometro = 0;
const int TerminalA = 2;
const int TerminalB = 3;
const int TerminalPWM = 4;

int ValorAnalogico = 0;
const int Adelante = 0;
const int Atras = 1;
const int Detener = 2;



void setup()
{
	pinMode(TerminalA,OUTPUT);
	pinMode(TerminalB,OUTPUT);
	pinMode(TerminalPWM,OUTPUT);
	
	pinMode(Adelante, OUTPUT);
	pinMode(Atras,OUTPUT);
	pinMode(Detener,OUTPUT);
	
}

void loop()
{
	if(PBRead(Adelante) == HIGH)
	{
		delay(100);
		if(PBRead(Adelante) == HIGH)
		{
			digitalWrite(TerminalA,HIGH);
			digitalWrite(TerminalB,HIGH);
			ValorAnalogico = analogRead(0);
			Velocidad = rescale(ValorAnalogico,0,1023,0,1000);
			analogWrite(TerminalPWM,Velocidad);
		}
	}
	else if(PBRead(Atras) == HIGH)
	{
		delay(100);
		if(PBRead(Atras) == HIGH)
		{
			digitalWrite(TerminalA,LOW);
			digitalWrite(TerminalB,LOW);
			ValorAnalogico = analogRead(0);
			Velocidad = rescale(ValorAnalogico,0,1023,0,1000);
			analogWrite(TerminalPWM,Velocidad);
		}
	}
	else if(PBRead(Detener) == HIGH)
	{
		analogWrite(TerminalPWM,0);
	}
	
}