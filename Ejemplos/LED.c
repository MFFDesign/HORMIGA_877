#include "Hormiga877.h"
#include "LCD16x2.h"
#include "LED.h"

//LCD Declaration
const char En = 19;
const char RS = 18;
const char RnW = 26;

const char D4 = 20;
const char D5 = 21;
const char D6 = 22;
const char D7 = 23;

char conter = 0;

void setup()
{
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    pinMode(13,OUTPUT);
    lcdClear();
    lcdPrint("Hola Mundo");
    PortBTerminalInterrupt(ENABLE);
    pinMode(8,INPUT);
        lcdSetCursor(2,1);
    lcdPrint("Contador : ");
}

void loop()
{
    lcdSetCursor(2,12);
    lcdWrite(conter + 48);
    if(conter >= 9)
    {
        conter = 0;
    }
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
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
            INTCONbits.INTF = 0;
    }
}