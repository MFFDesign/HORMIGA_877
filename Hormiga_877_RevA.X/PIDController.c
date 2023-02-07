#include "Hormiga877.h"
#include "PIDController.h"


struct Controller{
    double Kp;
    double Ki;
    double Kd;
    double dtC;
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

double map(double data, double X2, double X1, double Y2, double Y1)
{
    double m = (Y2 - Y1) / (X2 - X1);
    return (m * data) - (m * X1) + Y1;
}


void SetSampleTime(char dt)
{
    OPTION_REG &= 0xD7;
    TMR0IF = 0;
    TMR0 = 0xFF - dt;
    PID.SampleT = dt;
    PID.dtC = PID.SampleT * 0.000051;
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

double AccionControl(double SetPoint, double Feedback)
{
    PID.Error = SetPoint - Feedback;
    PID.ErrorAcum += (PID.Error * PID.dtC) ;
    PID.P = PID.Kp * PID.Error;
    PID.I = PID.Ki * PID.ErrorAcum;
    PID.D = PID.Kd * ((PID.Error - PID.LastError) / PID.dtC);
    PID.AccionControl = PID.P + PID.I + PID.D;
    return PID.AccionControl;
}

unsigned int EventCounter(void)
{
    while(!TMR0IF);
    TMR0IF = 0;
    TMR0 = 0xFF - PID.SampleT;
    PID.TotalEvents++;
    return PID.TotalEvents;
}
