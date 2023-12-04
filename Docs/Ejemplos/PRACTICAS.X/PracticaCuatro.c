#include "Hormiga877.h"
#include "LCD16x2.h"
#include "PracticaCuatro.h"


void PracticaIV(void)
{
    char MenuB = 0;
    lcdClear();
    lcdPrint("Ctrl. H-Bridge");
    lcdSetCursor(2,1);
    lcdPrint("<CW | RET | CCW>");
    while(MenuB != 1)
    {
        if(!PBRead(0))
        {
            Movimiento(Adelante);
        }
        else if(!PBRead(1))
        {
            MenuB = 1;
        }
        else if(!PBRead(2))
        {
            Movimiento(Atras);
        }
        else
        {
            Movimiento(Detenido);
        }
    }
}


void Movimiento(char Mode)
{
    switch(Mode)
    {
        case Adelante:

            break;
        case Atras:

                break;
        case Detenido:

                break;
    }
}