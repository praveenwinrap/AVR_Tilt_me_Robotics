#define F_CPU 16000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */
#include"lcd.h"
#include"adc.h"

void main()
{
DDRB=0xFF;
LCD_Init();
LCD_Clear();
adc_init();

while(1)
{
int x,y,z;
x=getdata(0);
y=getdata(1);
z=getdata(2);

LCD_Command(0x80);    //print x axis value
LCD_String("X=");
LCD_Digit(x);

LCD_Command(0x87);   ////print y axis value
LCD_String("Y=");
LCD_Digit(y);

LCD_Command(0xc0);  //print z axis value 
LCD_String("Z=");
LCD_Digit(z);


_delay_ms(50);
//LCD_Clear();
}
}
