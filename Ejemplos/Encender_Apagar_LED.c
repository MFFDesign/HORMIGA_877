#include "system.h"


const int Led = 13;	// Declaracion de la Variable "Led" con valor
					// inicial de 13 que corresponde al diodo LED
					// o diodo emisor de luz integrado en la placa
					//Hormiga 877.
void setup()
{
	pinMode(Led,OUTPUT);	//Se Configura la terminal 13 de la 
							//Placa Hormiga 877 como salida digital
							// ccapaz de poder represewntar dos estados
							// difrentes: Encendido o Apagado, es decir,
							//generar en la terminal 13 correpondiente un 
							//valor de Voltaje de 5V para encendido y un valor
							// de voltaje de 0V para apagado, correspondiendo
							//respectivamente a un 1 Logico, y un 0 Logico.
							// 5V para 1 Logico, 0V para 0 Logico.
							//Esta Expresion es Equivalente a escribir:
							//"digitalWrite(13,OUTPUT);
							//La Palabra "OUTPUT" en el idioma ingles significa
							// "Salida".
}

void loop()
{
	digitalWrite(Led,HIGH);	//Procedimiento que Permite escribir un valor de 1 Logico (5V)
							// a la terminal 13 de la placa Hormiga 877 siendo la palabra en
							//Idioma Ingles  "HIGH" sinonimo de 1 Logico o 5V; es equivalente
							// a escribr "digitalWrite(13,1)".
	delay(500);				//Retardo en Milisegundos, es decir, permite a la salida retener el 
							// el valor de 5V en la salida durante 0.5 segundos o Medio segundo.
	digitalWrite(Led,LOW);	//Procedimiento que permite escribir un valor de 0 Logico (0V)
							//a la terminal 13 de la placa Hormiga 877 siendo la palabra en 
							//idioma ingles "LOW" sinonimo  de 0 Logico 0 0Volt, es equivalente 
							// a escribir "digitalWrite(13,0)".
	delay(500);				// Retardo de Medio segundo que evita modificar el valor de 0 Logico en 
							//la terminal 13 de la placa Hormiga 877 hasta que no halla pasado el tiempo
							// programado en la funcion de retardo.
	/* Una vez que se halla compilado y cargado el software en la placa Hormiga 877 se debe de observar como 
	   el diodo emisor de luz de la placa enciende y apaga, siendo la grafica siguiente una aproximacion de ello
	   --------------------------------------------------------------------------------------------------------
	   Valor del Diodo
									|
		Encendido (5V) / 1 Logico	+           ____________
									|           |           |           |
									|           |           |           |
									|           |           |           | 
									|           |           |           |
									|           |           |           |
									|           |           |           |
		Apagado (0V) / 0 Logico     +___________|           |___________|
									|___________________________________________________________________\  Tiempo
												|			|			|			|			|		/
}