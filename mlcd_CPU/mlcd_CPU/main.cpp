#include <avr/io.h>
//ATMEGA32
#define F_CPU 8000000UL
#define _CH_LCD_
#define delay 1
#include "C:\Users\ICTP17-Askari\Github\MYLCDLIB\mlcd_CPU\Lib\mlcd.h"
#include "C:\Users\ICTP17-Askari\Github\MYLCDLIB\mlcd_CPU\Lib\mlcd.cpp"

CH_LCD LCD1;


int main(void)
{
	//DDRC = 255;
	LCD1.SetRSPin (ADD(PORTC),ADD(DDRC),0);
	LCD1.SetRWPin (ADD(PORTC),ADD(DDRC),1);
	LCD1.SetEPin  (ADD(PORTC),ADD(DDRC),2);
	LCD1.SetD4Pin (ADD(PORTC),ADD(DDRC),3);
	LCD1.SetD5Pin (ADD(PORTC),ADD(DDRC),4);
	LCD1.SetD6Pin (ADD(PORTC),ADD(DDRC),5);
	LCD1.SetD7Pin (ADD(PORTC),ADD(DDRC),6);
	LCD1.Init();
	

	//LCD1.SendCommand(1,0,0B01001000);//6
	_delay_ms(delay);
	unsigned char charr;
	while(1)
	{
	/*	
	LCD1.SendCommand(1,0,charr);//6
	_delay_ms(250);
	LCD1.SendCommand(1,0,charr);//6
	_delay_ms(250);
	LCD1.SendCommand(1,0,charr);//6
	_delay_ms(250);
	LCD1.SendCommand(0,0,0B00000010);//6
	_delay_ms(250);	
	charr++;
	*/
	}
	
}