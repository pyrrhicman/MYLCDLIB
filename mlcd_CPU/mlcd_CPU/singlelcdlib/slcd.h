#ifndef CH_LCD
#define CH_LCD
#define ADD(X) _SFR_IO_ADDR(X)

class CH_LCD
{
	uint8_t RS_PORT , RS_DDR , RS_Bit ;
	uint8_t RW_PORT , RW_DDR , RW_Bit ;
	uint8_t E_PORT  , E_DDR  , E_Bit  ;

	uint8_t D4_PORT , D4_DDR , D4_Bit ;
	uint8_t D5_PORT , D5_DDR , D5_Bit ;
	uint8_t D6_PORT , D6_DDR , D6_Bit ;
	uint8_t D7_PORT , D7_DDR , D7_Bit ;
	uint8_t User_Defined_Character ;

	public:
	CH_LCD ();
	
	void SetRSPin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { RS_PORT = ADD_PORT ; RS_DDR = ADD_DDR ; RS_Bit = Bit ; }
	void SetRWPin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { RW_PORT = ADD_PORT ; RW_DDR = ADD_DDR ; RW_Bit = Bit ; }
	void SetEPin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { E_PORT = ADD_PORT ; E_DDR = ADD_DDR ; E_Bit = Bit ; }
	void SetD4Pin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { D4_PORT = ADD_PORT ; D4_DDR = ADD_DDR ; D4_Bit = Bit ; }
	void SetD5Pin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { D5_PORT = ADD_PORT ; D5_DDR = ADD_DDR ; D5_Bit = Bit ; }
	void SetD6Pin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { D6_PORT = ADD_PORT ; D6_DDR = ADD_DDR ; D6_Bit = Bit ; }
	void SetD7Pin(uint8_t ADD_PORT , uint8_t ADD_DDR , uint8_t Bit) { D7_PORT = ADD_PORT ; D7_DDR = ADD_DDR ; D7_Bit = Bit ; }
	void SendCommand(uint8_t,uint8_t,uint8_t);									//forms data ready to send to 74HC164
	void Init();																//Initializes LCD
	void SendChar(uint8_t);
	void SendString(const char*);
	void CursorMode(int);
	void SendInteger(unsigned int);
	void SendDouble(double,int);
	void Home();
	void Clear();
	void Goto(int, int);
};

#endif
