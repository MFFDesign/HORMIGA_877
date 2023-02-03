#include "Hormiga877.h"
#include "LCD16x2.h"
#include "PIDController.h"
#include <stdio.h>
//LCD Terminals
const char RS = 20;
const char EN = 21;
const char RnW = 25;
const char D4 = 16;
const char D5 = 17;
const char D6 = 18;
const char D7 = 19;
char ScreenROW[16] = {0};

unsigned int Now = 0;
unsigned int Last = 0;
unsigned int dTime = 0;

unsigned int dt = 0;
void setup() 
{
    lcdBegin(RS,EN,RnW,D4,D5,D6,D7);
    lcdSetCursor(1,1);
    lcdPrint("PID Control Test");
    PIDSetSampleTime(127);
    lcdSetCursor(2,1);
}


void loop()
{
    Now = EventCounter();
    dTime = Now - Last;
    if(dTime >= 153)
    {
        dt++;
        sprintf(ScreenROW,"Time = %u",dt);
        lcdPrint(ScreenROW);
    }
    Last = Now;
}