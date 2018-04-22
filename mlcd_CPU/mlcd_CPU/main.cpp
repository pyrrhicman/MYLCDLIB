#include <avr/io.h>
//ATMEGA32
#define F_CPU 8000000UL
#define _CH_LCD_

#include "D:\GitHub\MYLCDLIB\Lib\mlcd.cpp"
#include "D:\GitHub\MYLCDLIB\Lib\mlcd.h"

CH_LCD LCD1;


int main(void)
{
	LCD1.SetRSPin (ADD(PORTA),ADD(DDRA),0);
	LCD1.SetRWPin (ADD(PORTA),ADD(DDRA),1);
	LCD1.SetEPin  (ADD(PORTA),ADD(DDRA),7);
	LCD1.SetD4Pin (ADD(PORTA),ADD(DDRA),3);
	LCD1.SetD5Pin (ADD(PORTA),ADD(DDRA),4);
	LCD1.SetD6Pin (ADD(PORTA),ADD(DDRA),5);
	LCD1.SetD7Pin (ADD(PORTA),ADD(DDRA),6);
	LCD1.Init();
	
	
}