#define F_CPU 16000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */
#include"adc.h"
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

uart_num(x);
uart_string(" ");
uart_num(y);
uart_string(" ");
uart_num(z);

uart_char('\n');
if(y>80 && y < 95)
{
	PORTB=0b00001010; //forward
	//uart_string("forward");
}
else if(y>110 && y<125)
{
	PORTB=0b00000101; //back
//	uart_string("back");
}

else if(x>110 && x<130)
{
	PORTB=0b00001000; //left
	//uart_string("left");
}

else if(x>80 && x <95)
{
	PORTB=0b00000010; //right
	//uart_string("Right");
}
else{
	PORTB=0b00000000; //stop
}


_delay_ms(50);
}
}
