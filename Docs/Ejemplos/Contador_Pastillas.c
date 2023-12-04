#include <stdio.h>
#include "system.h"
#include "Keypad4x4.h"
#include "LCD16x2.h"
#include "Contadora_Pastillas.h"

//Declaraciones para teclado Matricial.

unsigned int values[4][4] = {
    {677,516,487,455},
    {637,424,384,338},
    {582,281,218,143},
    {544,181,100,2}
};

char Teclas[4][4] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'},
};
char Tecla = NO_KEY;

//Declaracion de terminales de LCDDeclarados en Proteus
const char RS = 2;
const char RnW = 12;
const char En = 3;

const char D4 = 7;
const char D5 = 6;
const char D6 = 5;
const char D7 = 4;

char FirstROW[16];
char SecondROW[16];

unsigned int ADCChannel = 0;


//Variables de la Maquina  //Declarados En Proteus
const char MotorPastillas = 10;
const char Banda = 11;
const char Alarma = 13;
const char IndicadorPastillas = 9;
const char SensorPastillas = 24; // Input Terminal for TMR 0
const char SensorCajas = 8;


//Variables de Control de flujo de programa.

unsigned int Latch = 0;
unsigned int LatchB = 0;
unsigned int LatchC = 0;

//Adquisison de Numeros de Pastillas.
char DataStorage[2] = {0,0};
uint8_t counter = 0;
uint8_t Number = 0;
unsigned int ContadorPastillasGlobal = 0;
uint8_t PastillasActuales = 0;
uint8_t CajasCompletas = 0;

//Declaracion de Maquinas de Estados.
enum MaquinaEstados{Encendido,Apagado};
enum MaquinaEstados Estado = Apagado;

enum ContadorPastillas{Paro,Arranque,Configuracion}; //overall operation of Marble counter Machine.
enum ContadorPastillas Modo; // Variable for mode Operation of Marble counter MAchine

enum Operacion{MoverCaja,ContarPastillas};
enum Operacion Paso;

void setup() 
{
    lcdBegin(RS,En,RnW,D4,D5,D6,D7);
    analogKeypadBegin(ADCChannel,values,Teclas);
    IOConfiguration();
    ContadorBegin();
    lcdClear();
	lcdSetCursor(1,1);
	lcdPrint(" EQUIPO  CodePa ");
	lcdSetCursor(2,1);
	for(char i=0;i<16;i++)
	{
		lcdWrite('.');
		delay(100);
	}
	lcdClear();
	lcdSetCursor(1,1);
	lcdPrint("     3B IEE     ");
    lcdSetCursor(2,1);
	for(char j=0;j<16;j++)
	{
		lcdWrite('.');
		delay(100);
	}
	delay(250);
}


void loop()
{
    switch(Estado)
    {
        case Apagado:
            lcdClear();
            lcdSetCursor(2,1);
            lcdPrint(" 'A'  to  Start ");
            while(Latch != 1)
            {
                Tecla = analogKeypadRead();
                if(Tecla == 'A')
                {
                    Latch = 1;
                }
            }
            Latch = 0;
            Estado = Encendido;
            break;
        case Encendido:
            lcdClear();
            Modo = Paro;
            while(Latch != 1)
            {
                switch(Modo)
                {
                    case Paro:
                        lcdSetCursor(1,1);
                        lcdPrint(" * --> Configur ");
                        lcdSetCursor(2,1);
                        lcdPrint(" # ---> Apagar  ");
                        Contador(RST);
                        while(LatchB != 1)
                        {
                            Tecla = analogKeypadRead();
                            if(Tecla == '*')
                            {
                                Modo = Configuracion;
                                LatchB = 1;
                            }
                            else if(Tecla == '#')
                            {
                                Modo = Paro;
                                LatchB = 1;
                                Latch = 1;
                            }
                        }
                        counter = 0;
                        lcdClear();
                        LatchB = 0;
                        break;
                    case Arranque:
                        lcdPrint("Modo Arranque");
                        delay(100);
                        lcdClear();
                        lcdSetCursor(1,1);
                        sprintf(FirstROW,"PE:%i  TPC:%i",Number,ContadorPastillasGlobal);
                        lcdPrint(FirstROW);
                        lcdSetCursor(2,1);
                        sprintf(SecondROW,"iMC:%i    Box:%i",PastillasActuales,CajasCompletas);
                        lcdPrint(SecondROW);
                        Paso = MoverCaja;
                        while(LatchB != 1)
                        {
                            switch(Paso)
                            {
                                case MoverCaja:
                                    digitalWrite(Banda,HIGH);
                                    digitalWrite(MotorPastillas,LOW);
                                    while(LatchC != 1)
                                    {
                                        Contador(RST);
                                        if(digitalRead(SensorCajas) == HIGH)
                                        {
                                            delay(250);
                                            if(digitalRead(SensorCajas) == HIGH)
                                            {
                                                LatchC = 1;
                                                digitalWrite(Banda,LOW);
                                                digitalWrite(MotorPastillas,LOW);
                                            }
                                        }
                                        Tecla = analogKeypadRead();
                                        if(Tecla == '#')
                                        {
                                            digitalWrite(Banda,LOW);
                                            LatchC = 1;
                                            LatchB = 1;
                                            Modo = Paro;
                                        }
                                        else if(Tecla == '*')
                                        {
                                            digitalWrite(Banda,LOW);
                                            LatchC = 1;
                                            LatchB = 1;
                                            Modo = Configuracion;
                                        }
                                    }
                                    LatchC = 0;
                                    Paso = ContarPastillas;
                                    break;
                                case ContarPastillas:
                                    digitalWrite(MotorPastillas,HIGH);
                                    digitalWrite(Banda,LOW);
                                    lcdClear();
                                    while(LatchC != 1)
                                    {
                                        PastillasActuales = Contador(CNT);
                                        Tecla = analogKeypadRead();
                                        if(PastillasActuales >= Number)
                                        {
                                            digitalWrite(MotorPastillas,LOW);
                                            CajasCompletas++;
                                            ContadorPastillasGlobal += PastillasActuales;
                                            PastillasActuales = 0;
                                            Paso = MoverCaja;
                                            Contador(RST);
                                            LatchC = 1;
                                        }
                                        else if(Tecla == '#')
                                        {
                                            digitalWrite(MotorPastillas,LOW);
                                            Contador(RST);
                                            Number = 0;
                                            CajasCompletas = 0;
                                            Paso = MoverCaja;
                                            LatchC = 1;
                                            LatchB = 1;
                                            Modo = Paro;

                                        }
                                        else if(Tecla == '*')
                                        {
                                            digitalWrite(MotorPastillas,LOW);
                                            Contador(RST);
                                            Number = 0;
                                            CajasCompletas = 0;
                                            Paso = MoverCaja;
                                            LatchC = 1;
                                            LatchB = 1;
                                            Modo = Configuracion;
                                        }
                                        lcdSetCursor(1,1);
                                        sprintf(FirstROW,"MQ:%i  TMC:%i",Number,ContadorPastillasGlobal);
                                        lcdPrint(FirstROW);
                                        lcdSetCursor(2,1);
                                        sprintf(SecondROW,"MC:%i    Box:%u",PastillasActuales,CajasCompletas);
                                        lcdPrint(SecondROW);
                                    }
                                    LatchC = 0;
                                    PastillasActuales = 0;
                                    break;
                            }
                        }
                        Number = 0;
                        counter = 0;
                        lcdClear();
                        LatchB = 0;
                        break;
                    case Configuracion:
                        lcdSetCursor(1,1);
                        lcdPrint("Cant.  Pastillas");
                        while(LatchB != 1)
                        {
                            Tecla = KeypadRead();
								if((Tecla != NO_KEY) & (Tecla != '#') & (Tecla != '*'))
								{
									if(counter < 2)
									{
										lcdSetCursor(2,1);
										DataStorage[counter] = Tecla - 48;
										Number = (DataStorage[0] * 10) + DataStorage[1];
										sprintf(SecondROW,"%i Pastillas",Number);
										lcdPrint(SecondROW);
                                        counter++;
									}
									else
									{
										lcdSetCursor(2,1);
                                        lcdPrint("                ");
										counter = 0;
									}
								}
								else if(Tecla == '#')
								{
									Modo = Paro;
									LatchB = 1;
								}
								else if(Tecla == '*')
								{
									Modo = Arranque;
									LatchB = 1;
								}
                        }
                        Number = (DataStorage[0] * 10) + DataStorage[1];
                        lcdClear();
                        LatchC = 0;
                        LatchB = 0;
                        Modo = Arranque;
                        break;
                }
            }
            lcdClear();
            Latch = 0;
            Estado = Apagado;
            break;
    }
}

void IOConfiguration(void)
{
    pinMode(Banda,OUTPUT);
    pinMode(MotorPastillas,OUTPUT);
    pinMode(IndicadorPastillas,OUTPUT);
    pinMode(Alarma,OUTPUT);
    pinMode(SensorPastillas,INPUT);
    pinMode(SensorCajas,INPUT);
    
    
    digitalWrite(MotorPastillas,LOW);
    digitalWrite(Banda,LOW);
	digitalWrite(Alarma,LOW);
	digitalWrite(IndicadorPastillas,LOW);
}


uint8_t Contador(char mode)
{
    if(mode == CNT)
	{
		return TMR0;
	}
	else if(mode == RST)
	{
		TMR0 = 0;
		return 0;
	}
}

void ContadorBegin(void)
{
	OPTION_REGbits.T0CS = 1;
	OPTION_REGbits.T0SE = 0;
	OPTION_REGbits.PSA = 1;
	OPTION_REGbits.PS2 = 0;
	OPTION_REGbits.PS1 = 0;
	OPTION_REGbits.PS0 = 0;
}