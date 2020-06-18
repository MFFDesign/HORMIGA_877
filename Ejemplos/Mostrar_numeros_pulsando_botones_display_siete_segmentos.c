/*
	Deslegar la Numeracion del 0 al 9 en un display de siete
	segmentos.
	
	Practica basada en un display de 7 Segmentos catodo Comun.
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


int counter = 0;
void setup()
{
	for(int i=0;i<7;i++)
	{
		pinMode(Display[i],OUTPUT);
	}
	delay(500);
	
}

void loop()
{
	Numero(counter);
	if(PBRead(0) == HIGH)
	{
		delay(100);
		if(PBRead(0) == HIGH)
		{
			if(counter > 9)
			{
				counter = 9;
			}
			else
			{
				counter++;
			}
		}
	}
	else if(PBRead(1) == HIGH)
	{
		delay(100);
		if(PBRead(1) == HIGH)
		{
			if(counter <= 0)
			{
				counter = 0;
			}
			else
			{
				counter--;
			}
		}
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