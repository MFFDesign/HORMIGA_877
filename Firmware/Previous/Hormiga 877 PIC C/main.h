#include <16F877A.h>
#device ADC=16
#use delay(crystal=8000000)

#define HIGH 0x01
#define LOW 0x00
#define OUTPUT 0x00
#define INPUT 0x01

void setup(void);
void loop(void);
void ConfiguracionInicial(void);
unsigned int pinMode(unsigned int pin, unsigned int direction);
void digitalWrite(unsigned int pin, unsigned int value);
