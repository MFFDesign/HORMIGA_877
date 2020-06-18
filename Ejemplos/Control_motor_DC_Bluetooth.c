/*
	Control de Motor de Corriente Continua mediante comunicacion
	Serial.
*/

#include "system.h"

const int TerminalAMotorA = 2;
const int TerminalBMotorA = 3;

const int TerminalAMotorB = 6;
const int TerminalBMotorB = 5;

const int TerminalPWM = 4;
char data = '0';

void setup()
{
	pinMode(TerminalAMotorA,OUTPUT);
	pinMode(TerminalAMotorB,OUTPUT);
	pinMode(TerminalBMotorA,OUTPUT);
	pinMode(TerminalBMotorB,OUTPUT);
	pinMode(TerminalPWM,OUTPUT);
	
	SerialBegin(9600);
	Detener();
}

void loop()
{
	data = SerialRead();
	switch(data)
	{
		case 'w':
			Adelante(500);
		break;
		case 'a':
			GiroIzquierda(500);
		break;
		case 's':
			Atras(500);
		break;
		case 'd':
			GiroDerecha(500);
		break;
		case 'e':
			Detener();
		break;
	}
}


void Adelante(int Velocidad)
{
	digitalWrite(TerminalAMotorA,HIGH);
	digitalWrite(TerminalBMotorA,LOW);
	digitalWrite(TerminalAMotorB,HIGH);
	digitalWrite(TerminalBMotorB,LOW);
	analogWrite(TerminalPWM,Velocidad);
}

void Atras(int Velocidad)
{
	digitalWrite(TerminalAMotorA,LOW);
	digitalWrite(TerminalBMotorA,HIGH);
	digitalWrite(TerminalAMotorB,LOW);
	digitalWrite(TerminalBMotorB,HIGH);
	analogWrite(TerminalPWM,Velocidad);
}

void GiroIzquierda(int Velocidad)
{
	digitalWrite(TerminalAMotorA,HIGH);
	digitalWrite(TerminalBMotorA,LOW);
	digitalWrite(TerminalAMotorB,LOW);
	digitalWrite(TerminalBMotorB,HIGH);
	analogWrite(TerminalPWM,Velocidad);
}

void GiroDerecha(int Velocidad)
{
	digitalWrite(TerminalAMotorA,LOW);
	digitalWrite(TerminalBMotorA,HIGH);
	digitalWrite(TerminalAMotorB,HIGH);
	digitalWrite(TerminalBMotorB,LOW);
	analogWrite(TerminalPWM,Velocidad);
}

void Detener(void)
{
	digitalWrite(TerminalAMotorA,LOW);
	digitalWrite(TerminalBMotorA,LOW);
	digitalWrite(TerminalAMotorB,LOW);
	digitalWrite(TerminalBMotorB,LOW);
}