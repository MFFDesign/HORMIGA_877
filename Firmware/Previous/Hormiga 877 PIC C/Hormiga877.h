#include <16F877A.h>
#device ADC=10
#use delay(crystal=8000000)
#include <lcd.c>
#use delay (clock=8000000)
#define LCD_RS_PIN      PIN_D1                                   
#define LCD_RW_PIN      PIN_D2 
#define LCD_ENABLE_PIN  PIN_D3 
#define LCD_DATA4       PIN_D4                                    
#define LCD_DATA5       PIN_D5                                    
#define LCD_DATA6       PIN_D6                           
#define LCD_DATA7       PIN_D7

#define HIGH 0x01
#define LOW 0x00
#define OUTPUT 0x00
#define INPUT 0x01
//Function Aplications
char AnalogKeypadRead(unsigned int channel);
void proceso(void);
//////////
void setup(void);
void loop(void);
void ConfiguracionInicial(void);
void pinMode(unsigned int pin,unsigned int direction);
void digitalWrite(unsigned int pin, unsigned int value);
void pinMode(unsigned int pin,unsigned int direction);
unsigned int digitalRead(unsigned int pin);
unsigned int PBRead(unsigned int button, unsigned int invert);
int analogWrite(unsigned int channel, unsigned int value);
unsigned int analogRead(unsigned int channel);
int main(void)
{
   ConfiguracionInicial();
   setup();
   while(1)
   {
      loop();
   }
   return 0;
}
unsigned int digitalRead(unsigned int pin)
{
   switch(pin)
   {
      case 0:
         return input_state(PIN_C7); 
      break;
      case 1:
         return input_state(PIN_C6);
      break;
      case 2:
         return input_state(PIN_C5);
      break;
      case 3:
         return input_state(PIN_C4);
      break;
      case 4:
         return input_state(PIN_C3);
      break;
      case 5:
         return input_state(PIN_C2);
      break;
      case 6:
         return input_state(PIN_C1);
      break;
      case 7:
         return input_state(PIN_C0);
      break;
      case 8:
         return input_state(PIN_B0);
      break;
      case 9:
         return input_state(PIN_B1);
      break;
      case 10:
         return input_state(PIN_B2);
      break;
      case 11:
         return input_state(PIN_B3);
      break;
      case 12:
         return input_state(PIN_B4);
      break;
      case 13:
         return input_state(PIN_B5);
      break;
      case 14:
         return input_state(PIN_B6);
      break;
      case 15:
         return input_state(PIN_B7);
      break;
      case 16:
         return input_state(PIN_D0);
      break;
      case 17:
         return input_state(PIN_D1);
      break;
      case 18:
         return input_state(PIN_D2);
      break;
      case 19:
         return input_state(PIN_D3);
      break;
      case 20:
         return input_state(PIN_D4);
      break;
      case 21:
         return input_state(PIN_D5);
      break;
      case 22:
         return input_state(PIN_D6);
      break;
      case 23:
         return input_state(PIN_D7);
      break;
      case 24:
         return input_state(PIN_A4);
      break;
   }
}

unsigned int PBRead(unsigned int button, unsigned int invert = 0) // PBRead(<Numero de Boton>, <OPCIONAL 1 si es necesario invertir la señal>)
{
   int state;
   switch(button)
   {
      case 0:
         state = input_state(PIN_E0); 
      break;
      case 1:
         state = input_state(PIN_E1);
      break;
      case 2:
         state = input_state(PIN_E2);
      break;
   }
   if(invert){
      return !state;
   } else{
      return state;
   }
}

void pinMode(unsigned int pin,unsigned int direction)
{
   switch(pin)
   {
      case 0:
         if(direction)
         {
            output_float(PIN_C7);
         }
         else
         {
            output_drive(PIN_C7);
         }
      break;
      case 1:
         if(direction)
         {
            output_float(PIN_C6);
         }
         else
         {
            output_drive(PIN_C6);
         }
      break;
      case 2:
         if(direction)
         {
            output_float(PIN_C5);
         }
         else
         {
            output_drive(PIN_C5);
         }
      break;
      case 3:
         if(direction)
         {
            output_float(PIN_C4);
         }
         else
         {
            output_drive(PIN_C4);
         }
      break;
      case 4:
         if(direction)
         {
            output_float(PIN_C3);
         }
         else
         {
            output_drive(PIN_C3);
         }
      break;
      case 5:
         if(direction)
         {
            output_float(PIN_C2);
         }
         else
         {
            output_drive(PIN_C2);
         }
      break;
      case 6:
         if(direction)
         {
            output_float(PIN_C1);
         }
         else
         {
            output_drive(PIN_C1);
         }
      break;
      case 7:
         if(direction)
         {
            output_float(PIN_C0);
         }
         else
         {
            output_drive(PIN_C0);
         }
      break;
      case 8:
         if(direction)
         {
            output_float(PIN_B0);
         }
         else
         {
            output_drive(PIN_B0);
         }
      break;
      case 9:
         if(direction)
         {
            output_float(PIN_B1);
         }
         else
         {
            output_drive(PIN_B1);
         }
      break;
      case 10:
         if(direction)
         {
            output_float(PIN_B2);
         }
         else
         {
            output_drive(PIN_B2);
         }
      break;
      case 11:
         if(direction)
         {
            output_float(PIN_B3);
         }
         else
         {
            output_drive(PIN_B3);
         }
      break;
      case 12:
         if(direction)
         {
            output_float(PIN_B4);
         }
         else
         {
            output_drive(PIN_B4);
         }
      break;
      case 13:
         if(direction)
         {
            output_float(PIN_B5);
         }
         else
         {
            output_drive(PIN_B5);
         }
      break;
      case 14:
         if(direction)
         {
            output_float(PIN_B6);
         }
         else
         {
            output_drive(PIN_B6);
         }
      break;
      case 15:
         if(direction)
         {
            output_float(PIN_B7);
         }
         else
         {
            output_drive(PIN_B7);
         }
      break;
      case 16:
         if(direction)
         {
            output_float(PIN_D0);
         }
         else
         {
            output_drive(PIN_D0);
         }
      break;
      case 17:
         if(direction)
         {
            output_float(PIN_D1);
         }
         else
         {
            output_drive(PIN_D1);
         }
      break;
      case 18:
         if(direction)
         {
            output_float(PIN_D2);
         }
         else
         {
            output_drive(PIN_D2);
         }
      break;
      case 19:
         if(direction)
         {
            output_float(PIN_D3);
         }
         else
         {
            output_drive(PIN_D3);
         }
      break;
      case 20:
         if(direction)
         {
            output_float(PIN_D4);
         }
         else
         {
            output_drive(PIN_D4);
         }
      break;
      case 21:
         if(direction)
         {
            output_float(PIN_D5);
         }
         else
         {
            output_drive(PIN_D5);
         }
      break;
      case 22:
         if(direction)
         {
            output_float(PIN_D6);
         }
         else
         {
            output_drive(PIN_D6);
         }
      break;
      case 23:
         if(direction)
         {
            output_float(PIN_D7);
         }
         else
         {
            output_drive(PIN_D7);
         }
      break;
      case 24:
         if(direction)
         {
            output_float(PIN_A4);
         }
         else
         {
            output_drive(PIN_A4);
         }
      break;
   }
}
void digitalWrite(unsigned int pin, unsigned int value)
{
   switch(pin)
   {
      case 0:
         if(value)
         {
            output_high(PIN_C7);
         }
         else
         {
            output_low(PIN_C7);
         }
         
      break;
      case 1:
         if(value)
         {
            output_high(PIN_C6);
         }
         else
         {
            output_low(PIN_C6);
         }
         
      break;
      case 2:
         if(value)
         {
            output_high(PIN_C5);
         }
         else
         {
            output_low(PIN_C5);
         }
         
      break;
      case 3:
         if(value)
         {
            output_high(PIN_C4);
         }
         else
         {
            output_low(PIN_C4);
         }
         
      break;
      case 4:
         if(value)
         {
            output_high(PIN_C3);
         }
         else
         {
            output_low(PIN_C3);
         }
         
      break;
      case 5:
         if(value)
         {
            output_high(PIN_C2);
         }
         else
         {
            output_low(PIN_C2);
         }
         
      break;
      case 6:
         if(value)
         {
            output_high(PIN_C1);
         }
         else
         {
            output_low(PIN_C1);
         }
         
      break;
      case 7:
         if(value)
         {
            output_high(PIN_C0);
         }
         else
         {
            output_low(PIN_C0);
         }
         
      break;
      case 8:
         if(value)
         {
            output_high(PIN_B0);
         }
         else
         {
            output_low(PIN_B0);
         }
         
      break;
      case 9:
         if(value)
         {
            output_high(PIN_B1);
         }
         else
         {
            output_low(PIN_B1);
         }
         
      break;
      case 10:
         if(value)
         {
            output_high(PIN_B2);
         }
         else
         {
            output_low(PIN_B2);
         }
           
      break;
      case 11:
         if(value)
         {
            output_high(PIN_B3);
         }
         else
         {
            output_low(PIN_B3);
         }
         
      break;
      case 12:
         if(value)
         {
            output_high(PIN_B4);
         }
         else
         {
            output_low(PIN_B4);
         }
         
      break;
      case 13:
         if(value)
         {
            output_high(PIN_B5);
         }
         else
         {
            output_low(PIN_B5);
         }
         
      break;
      case 14:
         if(value)
         {
            output_high(PIN_B6);
         }
         else
         {
            output_low(PIN_B6);
         }
         
      break;
      case 15:
         if(value)
         {
            output_high(PIN_B7);
         }
         else
         {
            output_low(PIN_B7);
         }
         
      break;
      case 16:
         if(value)
         {
            output_high(PIN_D0);
         }
         else
         {
            output_low(PIN_D0);
         }
         
      break;
      case 17:
         if(value)
         {
            output_high(PIN_D1);
         }
         else
         {
            output_low(PIN_D1);
         }
         
      break;
      case 18:
         if(value)
         {
            output_high(PIN_D2);
         }
         else
         {
            output_low(PIN_D2);
         }
         
      break;
      case 19:
         if(value)
         {
            output_high(PIN_D3);
         }
         else
         {
            output_low(PIN_D3);
         }
         
      break;
      case 20:
         if(value)
         {
            output_high(PIN_D4);
         }
         else
         {
            output_low(PIN_D4);
         }
         
      break;
      case 21:
         if(value)
         {
            output_high(PIN_D5);
         }
         else
         {
            output_low(PIN_D5);
         }
         
      break;
      case 22:
         if(value)
         {
            output_high(PIN_D6);
         }
         else
         {
            output_low(PIN_D6);
         }
         
      break;
      case 23:
         if(value)
         {
            output_high(PIN_D7);
         }
         else
         {
            output_low(PIN_D7);
         }
         
      break;
      case 24:
         if(value)
         {
            output_high(PIN_A4);
         }
         else
         {
            output_low(PIN_A4);
         }
         
      break;
   }
}
int analogWrite(unsigned int channel, unsigned int value)
{
   switch(channel)
   {
      case 5:
         set_pwm1_duty(value);
         return 1;
      break;
      case 6:
         set_pwm2_duty(value);
           return 1;
      break;
      default:
         return -1;
      break;
   }
}
unsigned int analogRead(unsigned int channel)
{
   switch(channel)
   {
      case 0:
         set_adc_channel(0);
         return read_adc();
      break;
      case 1:
         set_adc_channel(1);
         return read_adc();
      break;
      case 2:
         set_adc_channel(2);
         return read_adc();
      break;
      case 3:
         set_adc_channel(3);
         return read_adc();
      break;
      case 4:
         set_adc_channel(5);
         return read_adc();
      break;
   }
}
void ConfiguracionInicial(void)
{
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
   setup_adc(ADC_CLOCK_DIV_32);
   set_tris_e(0x07);
   set_tris_a(0x3F);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   set_pwm2_duty(0);
   set_pwm1_duty(0);
   setup_timer_2(T2_DIV_BY_16, 250, 1);
}

