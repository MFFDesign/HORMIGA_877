#include "system.h"

/*
	SEguidor de Lineas Basico Usando Dos Sensores de Linea.
*/
const int TerminalAMotor = 2;
const int TerminalBMotor = 3;

const int SensorIzquierdo = 6;
const int SensorDerecho = 5;
const int PinVelocidad = 4;
int Velocidad = 500;


void setup(void)
{
	pinMode(TerminalAMotor,OUTPUT);
	pinMode(TerminalBMotor,OUTPUT);
	pinMode(SensorDerecho,INPUT);
	pinMode(SensorIzquierdo,INPUT);
}

void loop(void)
{
	if((digitalRead(SensorDerecho) == HIGH) && (digitalRead(SensorIzquierdo) == HIGH))
	{
		//Adelante
		digitalWrite(TerminalAMotor,HIGH);
		digitalWrite(TerminalBMotor,HIGH);
		analogWrite(PinVelocidad,Velocidad);
	}
	else if((digitalRead(SensorDerecho) == LOW) && (digitalRead(SensorIzquierdo) == HIGH))
	{
		//Izquierdo
		digitalWrite(TerminalAMotor,HIGH);
		digitalWrite(TerminalBMotor,LOW);
		analogWrite(PinVelocidad,Velocidad);
	}
	else if((digitalRead(SensorDerecho) == HIGH) && (digitalRead(SensorIzquierdo) == LOW))
	{
		//Derecho
		digitalWrite(TerminalAMotor,LOW);
		digitalWrite(TerminalBMotor,HIGH);
		analogWrite(PinVelocidad,Velocidad);
	}
	else if((digitalRead(SensorDerecho) == LOW) && (digitalRead(SensorIzquierdo) == LOW))
	{
		//Detener
		digitalWrite(TerminalAMotor,LOW);
		digitalWrite(TerminalBMotor,LOW);
		analogWrite(PinVelocidad,0);
	}
}