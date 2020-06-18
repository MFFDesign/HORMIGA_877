#include "system.h"

const int EntradaAnalogica = 0;
const int SalidaDigital = 0;
const int Threshold = 250;
int DatoAnalogico = 0;

void setup()
{
	pinMode(SalidaDigital,OUTPUT);
}

void loop()
{
	DatoAnalogico = analogRead(EntradaAnalogica);
	if(DatoAnalogico >= Threshold)
	{
		digitalWrite(SalidaDigital,HIGH);
	}
	else
	{
		digitalWrite(SalidaDigital,LOW);
	}
}