#include <stdio.h>
#include "system.h"
#include "LCD16x2.h"
#include "AD9850.h"

char Tecla = 0;

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
//DDS Module
char DDSCLK = 2;
char DDSFQ_UPDATE = 3;
char DDSRST = 4;
//Nivel de operacion 1
enum Operacion{Apagado,Encendido,Configuracion,Remoto};
enum Operacion Estado;
unsigned int MenuA = 0;
// Frequency Variable Set
uint8_t FreqNumber[5] = {0};
uint16_t Frequency = 0;
uint8_t CellCounter = 0;

void setup(void)
{
	lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    DDSBegin(DPORTD,DDSCLK,DDSFQ_UPDATE,DDSRST);
    SerialBegin(9600);
    PWMStop();
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
                if(SerialAvailable()>=0)
                {
                    Tecla = SerialRead();
                    if(Tecla == 'A')
                    {
                        MenuA = 1;
                    }
                }
			}
			MenuA = 0;
			Estado = Configuracion;
		break;
		case Encendido:
            lcdClear();
            lcdSetCursor(1,1);
            lcdPrint(SecondROW);
            SetFreq(Frequency);
			while(MenuA != 1)
			{
                if(SerialAvailable() >= 0)
                {
                    Tecla = SerialRead();
                    if(Tecla == 'A')
                    {
                        MenuA = 1;
                    }
                }
			}
            MenuA = 0;
            Estado = Apagado;
		break;
		case Configuracion:
            lcdClear();
            lcdSetCursor(1,1);
			lcdPrint("SetFreq:     A<-");
			lcdSetCursor(2,1);
			while(MenuA != 1)
			{
                if(SerialAvailable() >= 0)
                {
                    Tecla = SerialRead();
                    if(Tecla == 'A')
                    {
                        MenuA = 1;
                    }
                    if(IsNumber(Tecla) == 1)
                    {
                        if(CellCounter < 5)
                        {
                            FreqNumber[CellCounter] = Tecla - 48;
                            lcdSetCursor(2,1+CellCounter);
                            lcdWrite(Tecla);
                            CellCounter++;
                        }
                        else
                        {
                            lcdSetCursor(2,1);
                            FreqNumber[0] = 0;
                            FreqNumber[1] = 0;
                            FreqNumber[2] = 0;
                            FreqNumber[3] = 0;
                            FreqNumber[4] = 0;
                            Frequency = 0;
                            lcdPrint("                ");
                            CellCounter = 0;
                        }
                    }
                }
			}
            CellCounter = 0;
            Frequency = (FreqNumber[0] * 10000) + (FreqNumber[1] * 1000) + (FreqNumber[2] * 100) + (FreqNumber[3] * 10) + FreqNumber[4];
            sprintf(SecondROW,"Fo = %u Hz",Frequency);
			MenuA = 0;
			Estado = Encendido;
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

unsigned int SetFreq(unsigned int Freq)
{
	unsigned int UpLimit = 1015;
	unsigned int DwnLimit = 680;
	unsigned int UpFreq = 3681;
	unsigned int DwnFreq = 2769;
	
	if(Freq >= UpFreq)
	{
		Freq = UpFreq;
		Freq = rescale(Freq,DwnFreq,UpFreq,DwnLimit,UpLimit);
		return Freq;
	}
	else if(Freq <= DwnFreq)
	{
		Freq = DwnFreq;
		Freq = rescale(Freq,DwnFreq,UpFreq,DwnLimit,UpLimit);
		return Freq;
	}
	else
	{
		Freq = rescale(Freq,DwnFreq,UpFreq,DwnLimit,UpLimit);
		return Freq;
	}
}