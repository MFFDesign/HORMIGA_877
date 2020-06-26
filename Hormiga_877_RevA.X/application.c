#include "system.h"

void setup() 
{
	pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
}


void loop()
{
    analogWrite(6,200);
    analogWrite(5,200);
    delay(100);
    analogWrite(6,500);
    analogWrite(5,500);
    delay(100);
}