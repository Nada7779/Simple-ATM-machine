

#include "app.h"

//********************************************************************************************************************************************
uint8_t str1[pan_num]={null},str2[pin_num]={null},check=null;
uint8_t arr_pan[pan_len]={null};
char arr_pin[pin_num]={null};
uint8_t add =ad, add2=ad2;
//********************************************************************************************************************************************
void CARD_PROGRAMMING_MODE(void)
{
   // PAN SEND AND RECIEVE
   uint8_t panRecieved=null_ch;
   char *pan;
   while (panRecieved==null_ch)
   {
	 // CHECK PAN CONDITION
	 for (uint8_t i = null ; i<pan_len ; i++)
	 {
			   arr_pan[i]=null;
	 }
	  
	  USART_Transmit_string ("Please Enter Card PAN:");
	 pan = USART_receive_string(arr_pan);
	if (arr_pan[pan_len] == null && arr_pan[pan_len_min1]!= null) 
	{
	 panRecieved=true_char;
	 	 for (int y=null;y<pan_len;y++)
	 	 {
		 	 if (arr_pan[y]<zero_asci || arr_pan[y]>nine_asci) 
			  {
				  USART_transmit(new_line);  
				  panRecieved=null_ch;
			  }
	 	 }
		  
	}
	 if (panRecieved==null_ch) USART_Transmit_string ("Wrong PAN ");
   }
   char arr_pan[pan_num]={null};
	  for (int i=null;i<pan_len;i++)
	  {
		  arr_pan[i]=pan[i];
	  }
	// PIN RECIEVE AND SEND
	uint8_t pinRecieved=null_ch;
	char *pin;
	while (pinRecieved==null_ch)
	{
	// PIN RECIEVE 
	unsigned char arr_pin[pin_len_plus3]={null};
	unsigned char arr_npin[pin_len_plus3]={null};
	USART_Transmit_string ("Please Enter New PIN:");
	pin =  USART_receive_string(arr_pin);
	
	// CONFIRM PIN RECIEVE
	USART_Transmit_string ("Please Confirm New PIN:");
	char *new_pin = USART_receive_string(arr_npin);
   
   // CHECK PIN CONDITION
	if (arr_pin[pin_len] == null && arr_pin[pin_len_min1]!= null) 
	{
	 pinRecieved='1';
	 	 for (int y=null;y<pin_len;y++)
	 	 {
		 	 if (arr_pin[y]<zero_asci || arr_pin[y]>nine_asci) 
			  {
				  USART_transmit(new_line);  
				  pinRecieved='0'; 
			  }
			 
	 	 }
	}

	// CHECK PIN CONFIRMATION
		uint8_t npin = *(new_pin);
		uint8_t pin_in = *(pin);
		int c=null;
		for (c=null;c<pin_len;c++)
		{
			if ((*(new_pin+c)) != (*(pin+c)) ) 
			{ 
				pinRecieved='0';
			}
		}
		if (pinRecieved=='0') USART_Transmit_string ("Wrong PIN "); 	 
	}
	 
	   for (int i=null;i<pin_len;i++)
	   {
		   arr_pin[i]=pin[i];
	   }	   

	EEPROM_Write_WithSize(arr_pan,&add,pan_len); //--- pan sent to EEPROM
	_delay_ms(100);
	//--- pan receive to EEPROM
	EEPROM_Write_WithSize(arr_pin,&add2,pan_len);// PAN sent to EEPROM
	_delay_ms(100);
}
//********************************************************************************************************************************************

void CARD_USER_MODE(void)
{
		// Read pan and pin from eeprom
		EEPROM_Read_N(ad,str1,pan_len);
		EEPROM_Read_N(ad2,str2,pin_len);
		// Turn trigger on 
		DIO_WRITEPIN(pinb0,LOW);
		uint8_t index = null;
		DIO_WRITEPIN(SS, LOW);
		
        // send data via spi to atm 
		while (str1[index] != new_line)
		{
			SPI_SendReceive(str1[index]);
			index++;
			_delay_ms(900);
		}	
		index = null;
		while (str2[index] != new_line)
		{
			SPI_SendReceive(str2[index]);
			index++;
			_delay_ms(900);
		}
		SPI_SendReceive(new_line);

		DIO_WRITEPIN(SS, HIGH);
	
}
//********************************************************************************************************************************************	  
void app_init(){
	
	SPI_MasterInit(PRESCALER_16);
	DIO_INITPIN(pinb0,OUTPUT);
	DIO_WRITEPIN(pinb0,HIGH);
	LCD_INIT();
	USART_init();
	I2C_init(I2C_PRESCALER_16);
}
//********************************************************************************************************************************************
void app_start(){
	
	uint8_t mode_check[modes]={null} ;
	char *mode;
	EEPROM_Read_N(ad,&check,true);
	if (check == empty_data )
	{
		CARD_PROGRAMMING_MODE()	;
		CARD_USER_MODE();
	}
	else{
		do {
					 USART_Transmit_string ("Please press 1 for entering user mode and 2 for programming mode :");
					 mode= USART_receive_string(mode_check);
					 USART_transmit('\n');
					 if (*mode == mode_1)
					 {
						 CARD_USER_MODE();
						 
						 }else if(*mode == mode_2){
						 CARD_PROGRAMMING_MODE()	;
						 CARD_USER_MODE();
						 }
	
		} while (*mode != mode_1 && *mode != mode_2 );
			}	

}
//********************************************************************************************************************************************
