#include <avr/io.h>
//ATMEGA32
#define F_CPU 8000000UL
#define _CH_LCD_
#define delay 10
#include "D:\GitHub\MYLCDLIB\Lib\mlcd.cpp"
#include "D:\GitHub\MYLCDLIB\Lib\mlcd.h"

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
	
	//PORTC=255;
	//_delay_ms(2000);
	//PORTC = 0;
	//_delay_ms(2000);	
	LCD1.SendCommand(0,0,0B00100000);//3
	_delay_ms(delay);
	LCD1.SendCommand(0,0,0B00001110);//4
	_delay_ms(delay);
	LCD1.SendCommand(0,0,0B00000110);//5
	_delay_ms(delay);
	LCD1.SendCommand(1,0,0B01001000);//6
	_delay_ms(delay);
	//LCD1.SendCommand(1,0,0B01001001);//7
	//_delay_ms(delay);
	while(1){
			LCD1.SendCommand(1,0,0B01001000);//6
			_delay_ms(1000);
		
		}
}