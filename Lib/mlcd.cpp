#include "mlcd.h"
# ifdef _CH_LCD_


CH_LCD :: CH_LCD ()
{
	RS_PORT = 0x1B ; RS_DDR = 0x1A ; RS_Bit = 0 ;
	RW_PORT = 0x1B ; RW_DDR = 0x1A ; RW_Bit = 1 ;
	E_PORT = 0x1B ; E_DDR = 0x1A ; E_Bit  = 2 ;

	D4_PORT = 0x1B ; D4_DDR = 0x1A ; D4_Bit = 3 ;
	D5_PORT = 0x1B ; D5_DDR = 0x1A ; D5_Bit = 4 ;
	D6_PORT = 0x1B ; D6_DDR = 0x1A ; D6_Bit = 5 ;
	D7_PORT = 0x1B ; D7_DDR = 0x1A ; D7_Bit = 6 ;	
}

void CH_LCD :: Init()//Initializes LCD
{
	_delay_ms(15);

	/////////////////////////////	SETTING DDR		///////////////////////////
	_SFR_IO8(D4_PORT) &= ~(1<<D4_Bit) ; // THESE 5 IS GOING TO TURN D4,D5,D6,D7,EN To INPUT
	_SFR_IO8(D5_PORT) &= ~(1<<D5_Bit) ;
	_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit) ;
	_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit) ;
	_SFR_IO8(E_PORT)  &= ~(1<<E_Bit);
	//D4  D5  D6  D7	SETTING DDR
	//0   0   0   0
	
	_SFR_IO8(D4_DDR)  |= 1<<D4_Bit ;
	_SFR_IO8(D5_DDR)  |= 1<<D5_Bit ;
	_SFR_IO8(D6_DDR)  |= 1<<D6_Bit ;
	_SFR_IO8(D7_DDR)  |= 1<<D7_Bit ;
	_SFR_IO8(E_DDR)   |= 1<<E_Bit  ;
	_SFR_IO8(RS_DDR)  |= 1<<RS_Bit ;
	_SFR_IO8(RW_DDR)  |= 1<<RW_Bit ;
	//D4  D5  D6  D7  E  RS  RW			SETTING DDR
	//1   1   1	  1   1  1   1
	/////////////////////////////	SETTING DDR	DONE	///////////////////////////




	_SFR_IO8(D4_PORT) |=   1<<D4_Bit ;
	_SFR_IO8(D5_PORT) |=   1<<D5_Bit ;
	_SFR_IO8(E_PORT)  |=   1<<E_Bit  ;
	_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit);
	_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit);
	_SFR_IO8(RS_PORT) &= ~(1<<RS_Bit);
	_SFR_IO8(RW_PORT) &= ~(1<<RW_Bit);
	
	//D4  D5  D6  D7  E  RS  RW
	//1   1   0	  0   1  0   0
	
	_delay_ms(1);
	_SFR_IO8(E_PORT)  &= ~(1<<E_Bit) ; // All other bits untouched and E = 0
	_delay_ms(1);
	
	_SFR_IO8(D4_PORT) |=   1<<D4_Bit ;
	_SFR_IO8(D5_PORT) |=   1<<D5_Bit ;
	_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit); // All other bits untouched and D6 = 0
	_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit);
	_SFR_IO8(E_PORT)  |=  (1<<E_Bit) ;
	_SFR_IO8(RS_PORT) &= ~(1<<RS_Bit);
	_SFR_IO8(RW_PORT) &= ~(1<<RW_Bit);
	
	//D4  D5  D6  D7  E  RS  RW
	//1   1   0	  0   1  0   0
	_delay_ms(1);
	_SFR_IO8(E_PORT)  &= ~(1<<E_Bit) ; // All other bits untouched and E = 0
	_delay_ms(1);
	
	_SFR_IO8(D4_PORT) &= ~(1<<D4_Bit);
	_SFR_IO8(D5_PORT) |=   1<<D5_Bit ;
	_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit);
	_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit);
	_SFR_IO8(E_PORT)  |=   1<<E_Bit  ;
	_SFR_IO8(RS_PORT) &= ~(1<<RS_Bit);
	_SFR_IO8(RW_PORT) &= ~(1<<RW_Bit);
	//D4  D5  D6  D7  E  RS  RW
	//0   1   0	  0   1  1   1
	_delay_ms(1);
	_SFR_IO8(E_PORT)  &=~(1<<E_Bit);  // All other bits untouched and E = 0
	_delay_ms(1);
	
	//SendCommand(40);
	//SendCommand(12);
	//Clr();
}

void CH_LCD :: SendCommand(uint8_t rs_Bit,uint8_t rw_Bit,uint8_t command)	//Sends Command to LCD
{	
	uint8_t lcd_D0 = command & (1<<0);
	uint8_t lcd_D1 = command & (1<<1);
	uint8_t lcd_D2 = command & (1<<2);
	uint8_t lcd_D3 = command & (1<<3);
	uint8_t lcd_D4 = command & (1<<4);
	uint8_t lcd_D5 = command & (1<<5);
	uint8_t lcd_D6 = command & (1<<6);
	uint8_t lcd_D7 = command & (1<<7);


// FIRST MSB BITS SENDING
	if (rs_Bit) _SFR_IO8(RS_PORT) |=   1<<RS_Bit ;
	else		_SFR_IO8(RS_PORT) &= ~(1<<RS_Bit);
	
	if (rw_Bit) _SFR_IO8(RW_PORT) |=   1<<RW_Bit ;
	else		_SFR_IO8(RW_PORT) &= ~(1<<RW_Bit);
	
	if (lcd_D7) _SFR_IO8(D7_PORT) |=   1<<D7_Bit ;	
	else		_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit);	

	if (lcd_D6) _SFR_IO8(D6_PORT) |=   1<<D6_Bit ;
	else		_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit);
	
	if (lcd_D5) _SFR_IO8(D5_PORT) |=   1<<D5_Bit ;
	else		_SFR_IO8(D5_PORT) &= ~(1<<D5_Bit);
	
	if (lcd_D4) _SFR_IO8(D4_PORT) |=   1<<D4_Bit ;
	else		_SFR_IO8(D4_PORT) &= ~(1<<D4_Bit);

	//SENDING
	_SFR_IO8(E_PORT)  |=   1<<E_Bit  ;
	_delay_ms(1);
	_SFR_IO8(E_PORT)  &=~(1<<E_Bit);  // All other bits untouched and E = 0
	_delay_ms(1);
	
	
// SECEND LSB BITS SENDING
if (lcd_D3) _SFR_IO8(D7_PORT) |=   1<<D7_Bit ;
else		_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit);

if (lcd_D2) _SFR_IO8(D6_PORT) |=   1<<D6_Bit ;
else		_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit);

if (lcd_D1) _SFR_IO8(D5_PORT) |=   1<<D5_Bit ;
else		_SFR_IO8(D5_PORT) &= ~(1<<D5_Bit);

if (lcd_D0) _SFR_IO8(D4_PORT) |=   1<<D4_Bit ;
else		_SFR_IO8(D4_PORT) &= ~(1<<D4_Bit);

//SENDING
_SFR_IO8(E_PORT)  |=   1<<E_Bit  ;
_delay_ms(1);
_SFR_IO8(E_PORT)  &=~(1<<E_Bit);  // All other bits untouched and E = 0
_delay_ms(1);

	
	
	
	
	
	
	
	_SFR_IO8(D4_PORT) |=   1<<D4_Bit ;
	_SFR_IO8(D5_PORT) |=   1<<D5_Bit ;
	_SFR_IO8(D6_PORT) &= ~(1<<D6_Bit);
	_SFR_IO8(D7_PORT) &= ~(1<<D7_Bit);
	
	_SFR_IO8(RS_PORT) &= ~(1<<RS_Bit);
	_SFR_IO8(RW_PORT) &= ~(1<<RW_Bit);
	_SFR_IO8(E_PORT)  |=   1<<E_Bit  ;



	/*
	CMD = 0  0  0  0  0  0  0  0  EVERY BIT IS A PIN TO SWITCH
	      X  X  RS RW D7 D6 D5 D4
	*/
	


}



# endif