#include <stdio.h>
#include "Hormiga877.h"
#include "LCDI2C.h"
#include "I2CNumberIO.h"

void I2CPrintNumber(float number, char *DataVector)
{
    unsigned int BufferNumber = (int)number;
    unsigned int Buffer = 0;
    DataVector[0] = (int)((BufferNumber - Buffer)/1000);
    Buffer =(DataVector[0] * 1000);
    DataVector[0] += 48;
    DataVector[1] = (int)((BufferNumber - Buffer)/100);
    Buffer += (DataVector[1] * 100);
    DataVector[1] += 48;
    DataVector[2] = (int)((BufferNumber - Buffer)/10);
    Buffer += (DataVector[2] * 10);
    DataVector[2] += 48;
    DataVector[3] = (int)((BufferNumber - Buffer));
    DataVector[3] += 48;
    DataVector[4] = 0x2E;
    //Calculo de Parte Fraccional
    BufferNumber = (number - (int)number) * 1000;
    Buffer = 0;
    DataVector[5] = (int)((BufferNumber - Buffer)/100);
    Buffer += DataVector[5] * 100;
    DataVector[5] += 48;
    DataVector[6] = (int)((BufferNumber - Buffer)/10);
    Buffer += DataVector[6] * 10;
    DataVector[6] += 48;
    DataVector[7] = (int)((BufferNumber - Buffer));
    DataVector[7] += 48;
    for(char i=0;i<8;i++)
    {
        DataVector[i] = DataVector[i+1];
    }
}

void I2CShowNumber(float number, float resolution, char *DataVector)
{
    //Data Vector = {UnidadesMillas,Centenas, Decenas, Unidades, dp, Decimas,Centesimas,Milesimas}
    unsigned int PteEntera = 0;
    unsigned int PteFraccion = 0;
    char UnidadesMillar = 0;
    char Centenas = 0;
    char Decenas = 0;
    char Unidades = 0;
    char Decimas = 0;
    char Centesimas = 0;
    char Milesimas = 0;
    float buffer = 0;
    PteEntera = (int)number;
    PteFraccion = (number - PteEntera) / resolution;
    UnidadesMillar = (int)(PteEntera/1000);
    Centenas = (int)((PteEntera - (UnidadesMillar * 1000))/100);
    Decenas =(int)( (PteEntera - (UnidadesMillar * 1000) - (Centenas *100)) / 10);
    Unidades = (int)(PteEntera - (UnidadesMillar *1000) - (Centenas *100) - (Decenas * 10)); 
    Decimas = (int)(PteFraccion/100);
    Centesimas = (int)(PteFraccion - (Decimas * 100))/10;
    Milesimas = (int)(PteFraccion - (Decimas*100) - (Centesimas * 10));
    DataVector[0] = UnidadesMillar + 48;
    DataVector[1] = Centenas + 48;
    DataVector[2] = Decenas + 48;
    DataVector[3] = Unidades + 48;
    DataVector[4] = 0x2E;
    DataVector[5] = Decimas + 48;
    DataVector[6] = Centesimas + 48;
    DataVector[7] = Milesimas + 48;
}

unsigned int I2CParteEntera(float number )
{
    return (int)number;
}

unsigned int I2CParteFraccional(float number, float resolution)
{
    float buffer = 0;
    buffer =(number - (int) number) / resolution; 
    return buffer;
}

double I2CMakeDoubleNumber(char row, char col)
{
    double VarValue = 0;
    char Done = 0;
    char counter = 0;
    while(Done < 3)
    {
        LCDSetCursor(row,(col + 8 - Done));
        LCDWrite(counter+48);
        if(!PBRead(0))
        {
            if(counter >= 9)
            {
                counter = 9;
            }
            else
            {
                counter++;
            }
        }
        else if(!PBRead(1))
        {
            switch(Done)
            {
                case 0:
                    VarValue += (counter * 0.001);
                    break;
                case 1:
                    VarValue += (counter * 0.01);
                    break;
                case 2:
                    VarValue += (counter * 0.1);
                    break;
            }
            Done++;
        }
        else if(!PBRead(2))
        {
            if(counter <= 0)
            {
                counter = 0;
            }
            else 
            {
                counter--;
            }
        }
    }
    Done = 0;
    LCDSetCursor(row,col + 5);
    LCDWrite(0x2E);
    while(Done < 4)
    {
        LCDSetCursor(row,(col + 4 - Done));
        LCDWrite(counter+48);
        if(!PBRead(0))
        {
            if(counter >= 9)
            {
                counter = 9;
            }
            else
            {
                counter++;
            }
        }
        else if(!PBRead(1))
        {
            switch(Done)
            {
                case 0:
                    VarValue += counter;
                    break;
                case 1:
                    VarValue += (counter * 10);
                    break;
                case 2:
                    VarValue += (counter *100);
                    break;
                case 3:
                    VarValue += (counter * 1000);
                    break;
            }
             Done++;
        }
        else if(!PBRead(2))
        {
            if(counter <= 0)
            {
                counter = 0;
            }
            else
            {
                counter--;
            }
        }
    }
    return VarValue;
}

unsigned int I2CMakeIntegerNumber(char row, char col)
{
    char Done = 0;
    unsigned int VarValue = 0;
    char counter = 0;
    while(Done <= 2)
    {
        LCDSetCursor(row,(col + 3 -Done));
        LCDWrite(counter+48);
        if(PBRead(0))
        {
            if(counter >= 9)
            {
                counter = 9;
            }
            else
            {
                counter++;
            }
        }
        else if(PBRead(1))
        {
            if(Done == 0)
            {
                VarValue += counter;
            }
            else if(Done == 1)
            {
                VarValue += (counter * 10);
            }
            else if(Done == 2)
            {
                VarValue += (counter * 100);
            }
            else if(Done == 3)
            {
                VarValue += (counter * 10000);
            }
            Done++;
        }
        else if(PBRead(2))
        {
            if(counter <= 0)
            {
                counter = 0;
            }
            else
            {
                counter--;
            }
        }
    }
    return VarValue;
}


char I2CMakeByteNumber(char row, char col)
{
    char Number[3] = {0};
    char counter = 0;
    char positions = 3;
    char Done = 0;
    while(Done <  positions)
    {
        LCDSetCursor(row,(col + positions - Done));
        LCDWrite(counter+48);
        if(PBRead(0))
        {
            if(counter >= 9)
            {
                counter = 9;
            }
            else 
            {
                counter++;
            }
        }
        else if(PBRead(1))
        {
                Number[Done] = counter;
                Done++;
        }
        else if(PBRead(2))
        {
            if(counter <= 0)
            {
                counter = 0;
            }
            else
            {
                counter--;
            }
        }
    }
    if(Number[2] >= 2)
    {
        Number[2] = 2;
        if(Number[1] >= 5)
        {
            Number[1] = 5;
            if(Number[0] >= 5)
            {
                Number[0] = 5;
            }
        }
    }
    return Number[0] + (Number[1] * 10) + (Number[2] * 100);
}


char I2CCaseSelector(char *Vector, char SizeValues, char row, char col)
{
    char counter = 0;
    char buffer[4] = {0};
    char Done = 0;
    while(Done != 1)
    {
        if(PBRead(0))
        {
            if(counter >= (SizeValues - 1))
            {
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        else if(PBRead(1))
        {
            Done = 1;
        }
        else if(PBRead(2))
        {
            if(counter == 0)
            {
                counter = SizeValues - 1;
            }
            else
            {
                counter--;
            }
        }
        LCDSetCursor(row,col);
        sprintf(buffer,"%u",Vector[counter]);
        LCDPrint(buffer);
    }
    return Vector[counter];
}