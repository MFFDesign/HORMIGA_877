#include "system.h"


const int MotorTerminal = 3;
const int EncenderMotor = 0;
void setup()
{
	pinMode(MotorTerminal,OUTPUT);
}

void loop()
{
	if(PBRead(EncenderMotor) == HIGH)
	{
		delay(100);
		if(PBRead(EncenderMotor) == HIGH)
		{
			digitalWrite(MotorTerminal,HIGH);
		}
	
	else
	{
		digitalWrite(MotorTerminal,LOW);
	}
}