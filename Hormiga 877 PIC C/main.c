#include <Hormiga877.h>
#define NO_KEY 'n'

//Tareas :
/*
   1. Buscar constantes de ADC para cada una de las teclas del Keypad.
*/
char key = '0';
enum MaquinaEstados{Configuracion, Ejecucion,ConfiguracionDos};
MaquinaEstados Estado;

int ValorMaximo = 0;
int ValorMinimo = 0;

unsigned int Casillas[3] = {0,0,0}; //{Unidades,Decenas,Centenas}
unsigned int Valor = 0; // almacenara el numero final ingresado por KP.
unsigned int Contador = 0; //contara las casillas del vector;


int i=0;
void setup(void)
{
   Estado = Configuracion;
   lcd_init();
   delay_ms(100);
   lcd_gotoxy(1,1);
   lcd_putc("Hola");
   lcd_gotoxy(2,1);
   for(i=0;i<16;i++)
   {
      lcd_putc(".");
      lcd_gotoxy(2,i);
   }
   delay_ms(100);
}

            

void loop(void)
{
   switch(Estado)
   {
      case Configuracion:
         while(Contador <=2)
         {
            key = AnalogKeypadRead(0);
            if(key != NO_KEY)
            {
               Casillas[Contador] = key - 48;
               Contador++;
               //Dibujar el Numero
               
            }
            else if(key == 'A') //Boton Acknoledge
            {
               Contador = 3;
            }
            else if(key == 'B') //Boton Backspace
            {
               Contador = 0;
            }
         }
         Contador = 0;
         ValorMaximo = Casillas[0] + (Casillas[1] * 10) + (Casillas[2] * 100);
         Estado = ConfiguracionDos;
      break;
      case ConfiguracionDos:
         while(Contador <=2)
         {
            key = AnalogKeypadRead(0);
            if(key != NO_KEY)
            {
               Casillas[Contador] = key - 48;
               Contador++;
            }
            else if(key == 'A') //Boton Acknoledge
            {
               Contador = 3;
            }
            else if(key == 'B') //Boton Backspace
            {
               Contador = 0;
            }
         }
         Contador = 0;
         ValorMinimo = Casillas[0] + (Casillas[1] * 10) + (Casillas[2] * 100);
         Estado = Ejecucion;
      break;
      case Ejecucion:
         key = AnalogKeypadRead(0);
         proceso();
         if(key != NO_KEY)
         {
            if(key == 'A')
            {
               Estado = Configuracion;
            }
            else if(key == 'B')
            {
               Estado = ConfiguracionDos;
            }
            else
            {
               Estado = Ejecucion;
            }
         }
         else
         {
            Estado = Ejecucion;
         }
      break;
   }
}

void proceso(void)
{
   
}
char AnalogKeypadRead(unsigned int channel)
{
   unsigned int data;
   data = analogRead(channel);
   switch(data)
   {
      case 1:
         return 'A';
      break;
      case 2:
         return 'B';
      break;
      case 3:
         return 'C';
      break;
      case 4:
         return 'D';
      break;
      case 557:
         return '*';
      break;
      case 6:
         return '#';
      break;
      case 7:
         return '0';
      break;
      case 8:
         return '1';
      break;
      case 9:
         return '2';
      break;
      case 10:
         return '3';
      break;
      case 11:
         return '4';
      break;
      case 12:
         return '5';
      break;
      case 13:
         return '6';
      break;
      case 14:
         return '7';
      break;
      case 15:
         return '8';
      break;
      case 16:
         return '9';
      break;
      case 1023:
         return NO_KEY;
      break;
      default:
         return NO_KEY;
      break;
   }
}
