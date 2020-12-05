#define F_CPU 16000000UL
#include<avr/io.h>
#include <util/delay.h> 
#include "uart.h"
#include "adc.h"
void main()
{
    DDRB=0b00001111;
	 uart_init(); //115200	bits/sec
	 adc_init();								
	_delay_ms(100);
	PORTB=0b00000001;
 while(1)
  {
    int x,y,z;
	x=getdata(0);
	y=getdata(1);
	z=getdata(2);

	uart_num(x);
	uart_char('\t');
	uart_num(y);
	uart_char('\t');
	uart_num(z);
	uart_char('\n');

	_delay_ms(100);
	
}
}
