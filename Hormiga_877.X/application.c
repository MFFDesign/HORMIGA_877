#include "system.h"

const int LED = 13;
char state = 0;
char data[4];
void setup()
{
    state = SerialBegin(9600);
    pinMode(LED,OUTPUT);
    digitalWrite(LED,state);
    for(char i=0;i<256;i++)
    {
        SerialPrint(";");
        SerialPrintLn(i);
        
    }
}


void loop()
{
    SerialPrintLn("HI");
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
}