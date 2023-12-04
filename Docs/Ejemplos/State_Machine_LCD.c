#include "Hormiga877.h"
#include "LCD16x2.h"
//LCD16x2 Declaration
const char RS = 12;
const char RnW = 13;
const char En = 14;

const char D4 = 8;
const char D5 = 9;
const char D6 = 10;
const char D7 = 11;

char FirstROW[16] = {0};
char SecondROW[16] = {0};

enum Estados{Encendido,Apagado};
enum Estados Estado = Apagado;
uint8_t MenuA = 0;

void setup()
{
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    lcdClear();
	lcdSetCursor(1,1);
	lcdPrint("  Carlos Tonche ");
	lcdSetCursor(2,1);
	for(char i=0;i<16;i++)
	{
		lcdWrite('.');
		delay(150);
	}
    lcdClear();
}

void loop()
{
    switch(Estado)
    {
        case Encendido:
            lcdSetCursor(1,1);
            lcdPrint("Press RE0");
            for(char i=0;i<7;i++)
            {
                DisplayShiftRight();
                delay(100);
            }
            delay(100);
            for(char i=0;i<7;i++)
            {
                DisplayShiftLeft();
                delay(100);
            }
            delay(100);
            while(MenuA != 1)
            {
                if(PBRead(0))
                {
                    MenuA = 1;
                }

            }
            Estado = Apagado;
            MenuA = 0;
            lcdClear();
            break;
        case Apagado:
            lcdSetCursor(1,1);
            lcdPrint("Press RE1");
            for(char i=0;i<7;i++)
            {
                DisplayShiftRight();
                delay(100);
            }
            delay(100);
            for(char i=0;i<7;i++)
            {
                DisplayShiftLeft();
                delay(100);
            }
            delay(100);
            while(MenuA != 1)
            {
                if(PBRead(1))
                {
                    MenuA = 1;
                }
            }
            Estado = Encendido;
            MenuA = 0;
            lcdClear();
            break;
    }
}
