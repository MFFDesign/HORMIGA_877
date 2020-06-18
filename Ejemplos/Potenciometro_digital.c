#include "system.h"

const int EntradaAnalogica = 0;
int DatoAnalogico = 0;

const int SalidaAnalogica = 4;
const int ValorAnalogicoSalida = 0;

void setup()
{
	pinMode(SalidaAnalogica,OUTPUT);
}

void loop()
{
	DatoAnalogico = analogRead(EntradaAnalogica);
	ValorAnalogicoSalida = rescale(DatoAnalogico,0,1023,0,1000);
	analogWrite(SalidaAnalogica,ValorAnalogicoSalida);
	delay(250);
}