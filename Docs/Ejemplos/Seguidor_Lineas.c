/*
	Lectura de Sensores Infrarrrojos.
	Encender diodos emisores de luz, segun se activen o desactiven
	los sensores infrarrojos.
*/

#include "system.h"

const int LEDA = 13;
const int LEDB = 14;

const int TerminalAMotorA = 5;
const int TerminalBMotorA = 6;

const int TerminalAMotorB = 7;
const int TerminalBMotorB = 8;

const int PWMTerminal = 4;

void setup()
{
	pinMode(LEDA,OUTPUT);
	pinMode(LEDB,OUTPUT);
	digitalWrite(LEDA,LOW);
	digitalWrite(LEDB,LOW);
	
	pinMode(TerminalAMotorA,OUTPUT);
	pinMode(TerminalAMotorB,OUTPUT);
	pinMode(TerminalBMotorA,OUTPUT);
	pinMode(TerminalBMotorB,OUPUT);
	pinMode(PWMTerminal,OUTPUT);
	
}

void loop()
{
	if((LecturaSensorIRA() == HIGH) && (LecturaSensorIRB() == LOW))
	{
		digitalWrite(LEDA,HIGH);
		digitalWrite(TerminalAMotorA,HIGH);
		digitalWrite(TerminalBMotorA,LOW);
		digitalWrite(TerminalAMotorB,LOW);
		digitalWrite(TerminalBMotorB,HIGH);
		analogWrite(TerminalPWM,250);
	}
	else if((LecturaSensorIRA() == LOW) && (LecturaSensorIRB() == HIGH))
	{
		digitalWrite(TerminalAMotorA,LOW);
		digitalWrite(TerminalBMotorA,HIGH);
		digitalWrite(TerminalAMotorB,HIGH);
		digitalWrite(TerminalBMotorB,LOW);
		analogWrite(TerminalPWM,250);
	}
	else if((LecturaSensorIRA() == HIGH) && (LecturaSensorIRB() == HIGH))
	{
		digitalWrite(TerminalAMotorA,HIGH);
		digitalWrite(TerminalBMotorA,LOW);
		digitalWrite(TerminalAMotorB,HIGH);
		digitalWrite(TerminalBMotorB,LOW);
		analogWrite(TerminalPWM,Velocidad);
	}
	else if((LecturaSensorIRA() == LOW) && (LecturaSensorIRB() == LOW))
	{
		digitalWrite(TerminalAMotorA,LOW);
		digitalWrite(TerminalBMotorA,LOW);
		digitalWrite(TerminalAMotorB,LOW);
		digitalWrite(TerminalBMotorB,LOW);
	}
}


char LecturaSensorIRA(void)
{
	int Threshold = 500;
	if(analogRead(0) >= Threshold)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char LecturaSensorIRB(void)
{
	int Threshold = 500;
	if(analogRead(1) >= Threshold)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}