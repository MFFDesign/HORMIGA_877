#include <stdio.h>
#include "system.h"
#include "Keypad4x4.h"
#include "LCD16x2.h"
#include "AD9850.h"

//AD9850 Module Constants
#define RESETAD 		24
#define WORD_CLK  	25
#define FQ_UPDATE	26
#define AD0 		16
#define AD1			17
#define AD2			18
#define AD3			19
#define AD4			20
#define AD5			21
#define AD6			22
#define AD7			23

//Keypad Declaration
unsigned int values[4][4] = {
    {677,516,487,455},
    {637,424,384,338},
    {582,281,218,143},
    {544,181,100,2}
};
char Teclas[4][4] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'},
};
char Tecla = NO_KEY;

//LCD16x2 Declaration
const char RS = 12;
const char RnW = 13;
const char En = 14;

const char D4 = 8;
const char D5 = 9;
const char D6 = 10;
const char D7 = 11;

char FirstROW[16];
char SecondROW[16];
//Nivel de operacion 1
enum Operacion{Apagado,Encendido,Configuracion,Remoto};
enum Operacion Estado;
unsigned int MenuA = 0;
char DataPort[8] = {16,17,18,19,20,21,22,23};
char DDSCLK = 25;
char DDSFQ_UPDATE = 26;
char DDSRST = 24;
void setup(void)
{
	lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    analogKeypadBegin(0,values,Teclas);
    //DDSBegin(DataPort,DDSCLK,DDSFQ_UPDATE,DDSRST);
	lcdClear();
	lcdSetCursor(1,1);
	lcdPrint("  DDS  FG  V1.0 ");
	lcdSetCursor(2,1);
	for(char i=0;i<16;i++)
	{
		lcdWrite('.');
		delay(150);
	}
	Estado = Apagado;
	delay(250);
    lcdClear();
    lcdSetCursor(1,1);
    pinMode(8,OUTPUT);
    while(MenuA != 1)
    {
        lcdPrint("digitalWrite(ON)");
        digitalWrite(25,HIGH);
        delay(500);
        lcdClear();
        lcdPrint("digitalWrite(OF)");
        digitalWrite(25,LOW);
        delay(500);
        lcdClear();
    }
}

void loop(void)
{
    switch(Estado)
	{
		case Apagado:
			lcdClear();
			lcdSetCursor(2,1);
			lcdPrint(" 'A'  to  Start ");
			while(MenuA != 1)
			{
                digitalWrite(DDSCLK,HIGH);
				Tecla = analogKeypadRead();
				if(Tecla == 'A')
				{
					MenuA = 1;
				}
				if(Tecla != NO_KEY)
				{
					lcdSetCursor(1,1);
					lcdWrite(Tecla);
					delay(250);
					lcdClear();
				}
                digitalWrite(DDSCLK,LOW);
			}
			MenuA = 0;
			Estado = Configuracion;
		break;
		case Encendido:
			while(MenuA != 1)
			{
				
			}
		break;
		case Configuracion:
            lcdClear();
            lcdSetCursor(1,1);
			lcdPrint(" Configuracion. ");
			lcdSetCursor(2,1);
			lcdPrint(" 'A'  to Return ");
			while(MenuA != 1)
			{
				Tecla = analogKeypadRead();
				if(Tecla == 'A')
				{
					MenuA = 1;
				}
				if(Tecla != NO_KEY)
				{
					lcdSetCursor(1,1);
					lcdWrite(Tecla);
					delay(250);
					lcdClear();
				}
			}
			MenuA = 0;
			Estado = Apagado;
		break;
		case Remoto:
			while(MenuA != 1)
			{
				
			}
		break;
	}
}

void test1(void)
{
//    switch(Estado)
//	{
//		case Apagado:
//			lcdClear();
//			lcdSetCursor(2,1);
//			lcdPrint(" 'A'  to  Start ");
//			while(MenuA != 1)
//			{
//				Tecla = analogKeypadRead();
//				if(Tecla == 'A')
//				{
//					MenuA = 1;
//				}
//				if(Tecla != NO_KEY)
//				{
//					lcdSetCursor(1,1);
//					lcdWrite(Tecla);
//					delay(250);
//					lcdClear();
//				}
//			}
//			MenuA = 0;
//			Estado = Configuracion;
//		break;
//		case Encendido:
//			while(MenuA != 1)
//			{
//				
//			}
//		break;
//		case Configuracion:
//			while(MenuA != 1)
//			{
//				MenuA = 1;
//			}
//			MenuA = 0;
//			Estado = Apagado;
//		break;
//		case Remoto:
//			while(MenuA != 1)
//			{
//				
//			}
//		break;
//	}
}