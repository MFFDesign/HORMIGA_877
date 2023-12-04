#include "Hormiga877.h"
#include "Stepper.h"

struct Stepper{
    char Step;
    char Dir;
    char Enable;
}StepDriver;

struct VProfile{
    unsigned int VFinal;
    unsigned int TAccel;
    char TWait;
    unsigned long TotalSteps;
}Profile;

//Funciona muy bien.
void StepperExconBegin(char Step, char Dir, char Enable)
{
    StepDriver.Step = Step;
    StepDriver.Dir = Dir;
    StepDriver.Enable = Enable;
    pinMode(StepDriver.Step,OUTPUT);
    digitalWrite(StepDriver.Step,LOW);
    pinMode(StepDriver.Dir,OUTPUT);
    digitalWrite(StepDriver.Dir,LOW);
    pinMode(StepDriver.Enable,OUTPUT);
    digitalWrite(StepDriver.Enable,HIGH);
}
//Funciona Muy bien
void HardwareDelay(unsigned char mode, unsigned char time) 
{
    switch(mode)
    {
        case TEnable:
            TMR0 &= 0x00;
            TMR0IF = 0;
            OPTION_REG &= 0xD7;
            Profile.TWait = time;
            break;
        case TDisable:
            OPTION_REG = 0xFF;
            TMR0 &= 0x00;
            TMR0IF = 0;
            break;
    }
}

void MoveStepperHWD(unsigned int Steps, char Dir) //Funciona muy bien.
{
    unsigned int Counter = 0;
    switch(Dir)
    {
        case FWD:
            digitalWrite(StepDriver.Dir,HIGH);
            digitalWrite(StepDriver.Enable,LOW);
            TMR0 = 0xFF - Profile.TWait;
            while(Counter != Steps)
            {
                digitalWrite(StepDriver.Step,HIGH);
                while(!TMR0IF);
                digitalWrite(StepDriver.Step,LOW);
                //__delay_us(250);
                TMR0IF = 0;
                TMR0 = 0xFF - Profile.TWait;
                Counter++;
            }
            digitalWrite(StepDriver.Enable,HIGH);
            break;
        case REV:
            digitalWrite(StepDriver.Dir,LOW);
            digitalWrite(StepDriver.Enable,LOW);
            TMR0 = 0xFF - Profile.TWait;
            while(Counter != Steps)
            {
                digitalWrite(StepDriver.Step,HIGH);
                while(!TMR0IF);
                digitalWrite(StepDriver.Step,LOW);
                __delay_us(250);
                TMR0IF = 0;
                TMR0 = 0xFF - Profile.TWait;
                Counter++;
            }
            digitalWrite(StepDriver.Enable,HIGH);
            break;
    }
}

void MotorEnable(void) //FUnciona sin problemas
{
    digitalWrite(StepDriver.Enable,LOW);
}

void MotorDisable(void) //Funciona sin problemas
{
    digitalWrite(StepDriver.Enable,HIGH);
}
void ResetStepsCount(void)
{
    Profile.TotalSteps = 0;
}
unsigned long StepMove(char Dir, unsigned int dt)  //Funciona muy lento
{
    digitalWrite(StepDriver.Step,Dir);
    digitalWrite(StepDriver.Step,HIGH);
    __delay_us(250);
    delayMicroseconds(dt);
    digitalWrite(StepDriver.Step,LOW);
    __delay_us(250);
    Profile.TotalSteps++;
    return Profile.TotalSteps;
}


unsigned int MoveStepper(unsigned int Steps, char Dir) //Funciona sin problemas
{
    if(Dir == FWD)
    {
        digitalWrite(StepDriver.Dir,LOW);
        digitalWrite(StepDriver.Enable,LOW);
        for(unsigned int i=0;i<=Steps;i++)
        {
            if(i < 800)
            {
                digitalWrite(StepDriver.Step,HIGH);
                __delay_us(500);
                digitalWrite(StepDriver.Step,LOW);
                __delay_us(500); 
            }
            else
            {
                digitalWrite(StepDriver.Step,HIGH);
                __delay_us(250);
                digitalWrite(StepDriver.Step,LOW);
                __delay_us(250);
            }
        }
        digitalWrite(StepDriver.Enable,HIGH);
        
    }
    else if(Dir == REV)
    {
        digitalWrite(StepDriver.Dir,HIGH);
        digitalWrite(StepDriver.Enable,LOW);
        for(unsigned int i=0;i<=Steps;i++)
        {
            if(i < 800)
            {
                digitalWrite(StepDriver.Step,HIGH);
                __delay_us(500);
                digitalWrite(StepDriver.Step,LOW);
                __delay_us(500); 
            }
            else
            {
                digitalWrite(StepDriver.Step,HIGH);
                __delay_us(250);
                digitalWrite(StepDriver.Step,LOW);
                __delay_us(250);
            }
        }
        digitalWrite(StepDriver.Enable,HIGH);
    }
    else
    {
        digitalWrite(StepDriver.Enable,HIGH);
        digitalWrite(StepDriver.Step,LOW);
    }
    return Steps;
}
 void AccelStepping(unsigned int Steps, char Direccion, unsigned int VMax, unsigned int Vmin,unsigned int First, unsigned int Second)
 {
	unsigned int x=0;
	unsigned int AccelSteps = 0;
	digitalWrite(StepDriver.Dir,Direccion);
	digitalWrite(StepDriver.Enable,LOW);
	AccelSteps =(unsigned int)((Vmin - VMax) / First);
	for(x = Vmin; x > VMax; x--) //Aceleracion del Motor
	{
		for(unsigned int i=0; i < AccelSteps; i++) 
		{
			digitalWrite(StepDriver.Step, HIGH);
			__delay_us(250);
			delayMicroseconds(x);
			digitalWrite(StepDriver.Step, LOW);
			__delay_us(250);
		}
	}
	AccelSteps = Second - First;
	for (x = 0; x < AccelSteps; x++) //Velocidad Constante
	{
		digitalWrite(StepDriver.Step, HIGH);
		__delay_us(250);
		delayMicroseconds(VMax);
		digitalWrite(StepDriver.Step, LOW);
		__delay_us(250);
	}
	AccelSteps = (int)((Vmin - VMax) / (Steps - Second));
	for (x = VMax; x < Vmin; x++) //Desaceleracion
	{
		for (unsigned int i = 0; i < AccelSteps; i++) 
		{
			digitalWrite(StepDriver.Step, HIGH);
			__delay_us(250);
			delayMicroseconds(x);
			digitalWrite(StepDriver.Step, LOW);
			__delay_us(250);
		}
	}
	digitalWrite(StepDriver.Enable,LOW);
 }

//LA funcion VelProfile no se ejecuta correctamenta, un fork anterior en arduino
//la ejecutaba correctamnte, falla el procesador aparentemente.
void VelProfile(unsigned long Steps, char Dir, unsigned int Vi, unsigned int Vf, unsigned long *StepsOut)
{
    unsigned int FirstPoint = 0;
    unsigned int SecondPoint = 0;
    unsigned int TimeSet = 0;
    digitalWrite(StepDriver.Dir,Dir);
    digitalWrite(StepDriver.Enable,LOW);
    FirstPoint = (unsigned long)(Steps / 10);
    SecondPoint = (unsigned long) (FirstPoint * 9);
    for(unsigned long i=0;i<=Steps;i++)
    {
        if(i <= FirstPoint)
        {
            TimeSet = (unsigned int)(( Steps * ((Vf - Vi) / FirstPoint)) + Vi);
            
        }
        else if((i > FirstPoint) && (i <= SecondPoint))
        {
            TimeSet = Vf;
        }
        else if((i>SecondPoint) &&(i<= Steps))
        {
            TimeSet = (unsigned int)(((((Vi - Vf)/(i - SecondPoint))*(Steps-SecondPoint))+Vf));
        }
        digitalWrite(StepDriver.Step,HIGH);
        __delay_us(250);
        delayMicroseconds(TimeSet);
        digitalWrite(StepDriver.Step,LOW);
        __delay_us(250);
        StepsOut++;
    }
    
}

//Funcion Inompleta.
unsigned int AccelProfile(const int ni, const int n)
{
  double FirstPoint = 0;
  double SecondPoint = 0;
  int Vmax = 700;//350;//0.0002;
  int Vmin = 1000;//1100;//0.00115;
  FirstPoint = ni / 4;
  SecondPoint = 3* FirstPoint;
  if((n >=0) && (n <= FirstPoint))
  {
    return(unsigned int)(( n * ((Vmax - Vmin) / FirstPoint)) + Vmin);
  }
  else if((n > FirstPoint) && (n <= SecondPoint))
  {
    return (unsigned int)(Vmax);
  }
  else if((n > SecondPoint) && (n <= ni))
  {
    return (unsigned int)(((((Vmin - Vmax)/(ni - SecondPoint))*(n-SecondPoint))+Vmax));
  }
  else
  {
    return (unsigned int)(Vmin);
  }
}
