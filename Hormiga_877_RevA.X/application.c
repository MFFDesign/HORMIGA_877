#include "Hormiga877.h"
#include "LCD16x2.h"
#include "Timers.h"

const int RS=20;
const int En  =21;
const int RnW=0;
const int D4=16;
const int D5=17;
const int D6=18;
const int D7=19;
const int led=12;
void setup() 
{
    TimerCeroBegin(COUNTERRISE,256);
	lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    lcdClear();
    lcdPrint("Prueba  4");
}


void loop()
{
    digitalWrite(led,HIGH);
    while (!TMR0IF)
    {
        digitalWrite(led,HIGH);
        TMR0IF=0;
    }
        
}