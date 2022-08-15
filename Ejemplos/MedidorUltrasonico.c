#include "Hormiga877.h"
#include "Ultrasonico.h"
#include <stdio.h>

const char Trigger = 2;
const char Echo = 3;

unsigned int Data = 0;
char SerialData[16] = {0};

void setup(void)
{
    USBegin(Trigger,Echo);
    SerialBegin(9600);
    SerialPrintLn("Sensor UltraSonico");
}

void loop(void)
{
    Data = USRead(Trigger,Echo);
    sprintf(SerialData,"Valor : %u",Data);
    SerialPrintLn(SerialData);
    delay(500);
}
