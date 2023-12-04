#include "Hormiga877.h"
#include "LCD16x2.h"
#include "PracticaCuatro.h"

//Main State Machine
enum Practicas{PracticaCuatro, PracticaCinco, PracticaSeis};
enum Practicas Practica = PracticaCinco;
char MenuA = 0;

//LCD PinOut Declaration
const char RS = 18;
const char En = 19;
const char RnW = 0;
const char D4 = 20;
const char D5 = 21;
const char D6 = 22;
const char D7 = 23;


void setup()
{
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    lcdClear();
    lcdPrint("Ing. Carlos T.  ");
    delay(1000);
    lcdClear();
    lcdSetCursor(2,1);
    for(char i=0;i<=15;i++)
    {
        lcdWrite('.');
        delay(20);
    }
    lcdClear();
}

void loop()
{
    switch(Practica)
    {
        case PracticaCuatro:
            lcdClear();
            lcdPrint("Practica 4");
            while(MenuA != 1)
            {
                if(!PBRead(0))
                {
                    MenuA = 1;
                    Practica = PracticaSeis;
                }
                else if(!PBRead(1))
                {
                    PracticaIV();
                    MenuA = 1;
                }
                else if(!PBRead(2))
                {
                    MenuA = 1;
                    Practica = PracticaCinco;
                }
            }
            MenuA = 0;
            break;
        case PracticaCinco:
            lcdClear();
            lcdPrint("Practica 5");
            while(MenuA != 1)
            {
                if(!PBRead(0))
                {
                    MenuA = 1;
                    Practica = PracticaCuatro;
                }
                else if(!PBRead(1))
                {
                    
                }
                else if(!PBRead(2))
                {
                    MenuA = 1;
                    Practica = PracticaSeis;
                }
            }
            MenuA = 0;
            break;
        case PracticaSeis:
             lcdClear();
            lcdPrint("Practica 6");
            while(MenuA != 1)
            {
                if(!PBRead(0))
                {
                    MenuA = 1;
                    Practica = PracticaCinco;
                }
                else if(!PBRead(1))
                {
                    
                }
                else if(!PBRead(2))
                {
                    MenuA = 1;
                    Practica = PracticaCuatro;
                }
            }
            MenuA = 0;
            break;
    }
}
