#include <stdio.h>
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
unsigned int Vector[3] = {4,8,11};

unsigned int *VectorAddress;

void setup()
{
    VectorAddress = &Vector[0];
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    lcdClear();
    for(int i=0;i<3;i++)
    {
        lcdClear();
        lcdSetCursor(1,1);
        sprintf(FirstROW,"DIR :%u",VectorAddress);
        lcdPrint(FirstROW);
        sprintf(SecondROW,"VAL:%u",*VectorAddress);
        lcdSetCursor(2,1);
        lcdPrint(SecondROW);
        delay(1000);
        VectorAddress++;// +1 increment on address of the vector variable
    }
}

void loop()
{
    
}