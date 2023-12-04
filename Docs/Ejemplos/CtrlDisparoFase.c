#include "Hormiga877.h"
#include "LCD16x2.h"

//LCD Declaration
const char En = 19;
const char RS = 18;
const char RnW = 26;

const char D4 = 20;
const char D5 = 21;
const char D6 = 22;
const char D7 = 23;

char DataROW[8] = {0};
char conter = 0;

char time = 10;

void setup()
{
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    pinMode(13,OUTPUT);
    lcdClear();
    lcdPrint("Hola Mundo");
    PortBTerminalInterrupt(ENABLE);
    pinMode(8,INPUT);
    pinMode(5,OUTPUT);
    digitalWrite(5,LOW);
    lcdSetCursor(2,1);
    lcdPrint("Fase : ");
}

void loop()
{
    lcdSetCursor(2,8);
    PrintIntegerNumber(time,DataROW);
    lcdPrint(DataROW);
    lcdSetCursor(2,13);
    lcdPrint("    ");
    if(PBRead(0))
    {
        if(time >= 100)
        {
            time = 0;
        }
        else
        {
            time++;
        }
    }
    else if(PBRead(1))
    {
        if(time <= 0)
        {
            time = 0;
        }
        else
        {
            time--;
        }
    }
}


void PortBTerminalInterrupt(char Mode)
{
    switch(Mode)
    {
        case ENABLE:
            OPTION_REG = 0b10111111;  //interrupt on RB0  Fallinf Edge
            INTCON = 0b11010000;
            break;
        case DISABLE:
            OPTION_REG = 0xFF;
            INTCON = 0x00;
            break;
    }
}

void __interrupt() ZeroCross(void)
{
    if(INTCONbits.INTF)
    {
        conter++;
        delayMicroseconds(time);
        digitalWrite(5,HIGH);
        __delay_us(500);
        digitalWrite(5,LOW);
        INTCONbits.INTF = 0;
    }
}
