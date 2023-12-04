#include "system.h"

uint8_t LED = 5;

void setup()
{
	pinMode(LED,OUTPUT);
}

void loop()
{
	analogWrite(PWM,128);
	delay(500);
	analogWrite(LED,750);
	delay(500);
}