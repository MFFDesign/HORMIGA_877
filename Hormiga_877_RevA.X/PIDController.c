#include "Hormiga877.h"
#include "PIDController.h"


struct Controller{
    double Kp;
    double Ki;
    double Kd;
    char SampleT;
    unsigned int TotalEvents;
}PID;

void PIDSetSampleTime(char dt)
{
    OPTION_REG &= 0xD7;
    TMR0IF = 0;
    TMR0 = 0xFF - dt;
    PID.SampleT = dt;
}

unsigned int EventCounter(void)
{
    while(!TMR0IF);
    TMR0IF = 0;
    TMR0 = 0xFF - PID.SampleT;
    PID.TotalEvents++;
    return PID.TotalEvents;
}
