/*
	Temporizador Descendente
*/

#include "system.h"

#define SegmentoA 2
#define SegmentoB 3
#define SegmentoC 4
#define SegmentoD 5
#define SegmentoE 6
#define SegmentoF 7
#define SegmentoG 8

const int Display[7] = { SegmentoA,
						 SegmentoB,
						 SegmentoC,
						 SegmentoD,
						 SegmentoE,
						 SegmentoF,
						 SegmentoG};


const int Alarma = 9;
int CuentaAtras = 9;
int counter = 0;

enum TimerSoftware{Idle, Timer};
enum State;

void setup()
{
	for(int i=0;i<7;i++)
	{
		pinMode(Display[i],OUTPUT);
	}
	pinMode(Alarma,OUTPUT);
	state = Idle;
	delay(500);
	
}

void loop()
{
	switch(State)
	{
		case Idle:
			Numero(CuentaAtras);
			if(PBRead(0) == HIGH)
			{
				delay(100);
				if(PBRead(0) == HIGH)
				{
					State = Timer;
				}
			}
		break;
		case Timer:
			while(CuentaAtras > 0)
			{
				Numero(CuentaAtras);
				delay(1000);
				CuentaAtras--;
			}
			digitalWrite(Alarma,HIGH);
			CuentaAtras = 9;
			if(PBRead(1) == HIGH)
			{
				delay(100);
				if(PBRead(1) == HIGH)
				{
					digitalWrite(Alarma,LOW);
					State = Idle;
				}
			}
		break;
	}
}


void Numero(int number)
{
	switch(number)
	{
		case 0:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,HIGH);
			digitalWrite(SegmentoF,HIGH);
			digitalWrite(SegmentoG,LOW);
		break;
		case 1:
			digitalWrite(SegmentoA,LOW);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,LOW);
			digitalWrite(SegmentoE,LOW);
			digitalWrite(SegmentoF,LOW);
			digitalWrite(SegmentoG,LOW);
		break;
		case 2:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,LOW);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,HIGH);
			digitalWrite(SegmentoF,LOW);
			digitalWrite(SegmentoG,HIGH);
		break;
		case 3:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,LOW);
			digitalWrite(SegmentoF,LOW);
			digitalWrite(SegmentoG,HIGH);
		break;
		case 4:
			digitalWrite(SegmentoA,LOW);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,LOW);
			digitalWrite(SegmentoE,LOW);
			digitalWrite(SegmentoF,HIGH);
			digitalWrite(SegmentoG,HIGH);
		break;
		case 5:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,LOW);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,LOW);
			digitalWrite(SegmentoF,HIGH);
			digitalWrite(SegmentoG,HIGH);
		break;
		case 6:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,LOW);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,HIGH);
			digitalWrite(SegmentoF,HIGH);
			digitalWrite(SegmentoG,HIGH);
		break;
		case 7:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,LOW);
			digitalWrite(SegmentoE,LOW);
			digitalWrite(SegmentoF,LOW);
			digitalWrite(SegmentoG,LOW);
		break;
		case 8:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,HIGH);
			digitalWrite(SegmentoF,HIGH);
			digitalWrite(SegmentoG,HIGH);
		break;
		case 9:
			digitalWrite(SegmentoA,HIGH);
			digitalWrite(SegmentoB,HIGH);
			digitalWrite(SegmentoC,HIGH);
			digitalWrite(SegmentoD,HIGH);
			digitalWrite(SegmentoE,LOW);
			digitalWrite(SegmentoF,HIGH);
			digitalWrite(SegmentoG,HIGH);
		break;
	}
}