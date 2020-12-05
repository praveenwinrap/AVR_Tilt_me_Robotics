#define F_CPU 16000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */
#include"adc.h"  //adc init ,getdata
#include"uart.h" 

void main()
{
DDRB=0b11111111;
uart_init();
adc_init();

while(1)
{
int x,y,z;
x=getdata(0);
y=getdata(1);
z=getdata(2);


uart_string("X:");
uart_num(x);
uart_string(" Y:");
uart_num(y);
uart_string(" Z:");
uart_num(z);

uart_char('\n');
_delay_ms(50);
}
}
