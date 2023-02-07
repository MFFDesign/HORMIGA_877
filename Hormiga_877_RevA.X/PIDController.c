#include "Hormiga877.h"
#include "PIDController.h"


struct Controller{
    double Kp;
    double Ki;
    double Kd;
    char SampleT;
    unsigned int TotalEvents;
    double Error;
    double LastError;
    double ErrorAcum;
    double LastInput;
    double I;
    double P;
    double D;
    double AccionControl;
}PID;

void PIDSetSampleTime(char dt)
{
    OPTION_REG &= 0xD7;
    TMR0IF = 0;
    TMR0 = 0xFF - dt;
    PID.SampleT = dt;
}

void SetProportionalTune(double value)
{
    PID.Kp = value;
}

void SetIntegralTune(double value)
{
    PID.Ki = value;
}

void SetDerivativeTune(double value)
{
    PID.Kd = value;
}

unsigned char AccionControl(double SetPoint, double Feedback, double dt)
{
    PID.Error = SetPoint - Feedback;
    PID.ErrorAcum += PID.Error;
    PID.P = PID.Kp * PID.Error;
    PID.I = PID.Ki * PID.ErrorAcum;
    PID.D = PID.Kd * ((PID.Error - PID.LastError) / dt);
    PID.AccionControl = PID.P + PID.I + PID.D;
    return (char)PID.AccionControl;
}

unsigned int EventCounters(void)
{
    while(!TMR0IF);
    TMR0IF = 0;
    TMR0 = 0xFF - PID.SampleT;
    PID.TotalEvents++;
    return PID.TotalEvents;
}
