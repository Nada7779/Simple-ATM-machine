#include "eeprom.h"
#include <util/delay.h>

/**DESCRIPTION:-
 This Function is used To Write Data On External EEPROM Using I2C Communication*/
void EEPROM_Write (uint8_t *data, uint8_t *_address){
	
	uint8_t LV_Index_I=0,LV_Length=0;
	while (data[LV_Length])											//Calculate The Length Of the Data String
	{
		LV_Length++;
	}

	if(I2C_start()==EVENT_OK){										//Send a Starting Bit and Wait For ACK
		if(I2C_addressEvent(0xA0,WRITE)==AD_W_SENT_ACK_OK){			//Send an Initializer "0b1010" Specified In the Data Sheet  and an Event Type "R/W" and Wait For ACK
			if(I2C_sendData(_address)== DATA_SENT_ACK_OK){			//Send an Address In the EEPROM  To Start Writing In It
					for (LV_Index_I=0;LV_Index_I<LV_Length;){		//To Send The Whole Data String 
				if(I2C_sendData(&data[LV_Index_I])== DATA_SENT_ACK_OK){		//Send Data Byte By Byte and Wait For AcK Each Time 
						
					  LV_Index_I++;
					}
				}
				
			}
		}
	}

	I2C_stop();															//End Of Communication
	
}
/******************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Read Data On External EEPROM Using I2C Communication*/
void EEPROM_Read ( uint8_t *data) {

	if(I2C_start()==EVENT_OK){															//Send a Starting Bit and Wait For ACK
		if(I2C_addressEvent(0xA0,READ)==AD_R_SENT_ACK_OK){								//Send an Initializer "0b1010" Specified In the Data Sheet  and an Event Type "R/W" and Wait For ACK
			if(I2C_receiveData(data,NACK)== DATA_RECIEVE_NACK_OK){						//Send an Address In the EEPROM  To Start Reading From It		
				I2C_stop();
			}
			
		}
	}
	
}
/**********************************************************************************************************************************************/
void EEPROM_Read_String(uint8_t * a_STR){
	uint8_t LV_Index_I=0;

	for (LV_Index_I=0;LV_Index_I<16;LV_Index_I++)
	{
		EEPROM_Read(&a_STR[LV_Index_I]);
		
	
	}

}

void EEPROM_Read_String_With_size(uint8_t * a_STR, uint8_t a_Length){
	uint8_t LV_Index_I=0;

	for (LV_Index_I=0;LV_Index_I<a_Length;LV_Index_I++)
	{
		EEPROM_Read(&a_STR[LV_Index_I]);
		
		
	}

}

/******************************************/

void EEPROM_Write_WithSize (uint8_t *data, uint8_t *_address,uint8_t LV_Length){
	
	uint8_t LV_Index_I=0;	
	
	if(I2C_start()==EVENT_OK){										//Send a Starting Bit and Wait For ACK
		if(I2C_addressEvent(0xa0,WRITE)==AD_W_SENT_ACK_OK){			//Send an Initializer "0b1010" Specified In the Data Sheet  and an Event Type "R/W" and Wait For ACK
			if(I2C_sendData(_address)== DATA_SENT_ACK_OK){			//Send an Address In the EEPROM  To Start Writing In It
				for (LV_Index_I=0;LV_Index_I<LV_Length;){		//To Send The Whole Data String
					if(I2C_sendData(&data[LV_Index_I])== DATA_SENT_ACK_OK){		//Send Data Byte By Byte and Wait For AcK Each Time
						
						LV_Index_I++;
					}
				}
				
			}
		}
	}
	
	I2C_stop();															//End Of Communication
	
}
//**************************************************************************************************************************************************
// Functions for EEPROM READ
//***************************************************************************************************************************************************
// I2C start function 
	 void TWI_Start(void)						
	 {
		 TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);					/* Enable TWI, generate start condition and clear interrupt flag */
		 while ((TWCR & (1<<TWINT)) == 0);							/* Wait until TWI finish starting*/
	 }
//*****************************************************************************************************************************************************
// I2C write function 
	  void TWI_Write(char data)								
	  {
		  TWDR = data;											/* Copy data in TWI data register */
		  TWCR = (1<<TWEN)|(1<<TWINT);							/* Enable TWI and clear interrupt flag */
		  while ((TWCR & (1<<TWINT)) == 0);							/* Wait until TWI finish writing */
	  }
//******************************************************************************************************************************************************
// EEPROM READ function address and size required
	void EEPROM_Read_N ( char _address, char * data,char lenght){
	// READ elements of size lenght	
	for (int i = 0; i<lenght; i++){
	
	TWI_Start();
	TWI_Write(0xA0);             // EEPROM write address
	TWI_Write(_address);		// Address in EEPROM to start reading from
	TWI_Start();
	TWI_Write(0xA1);            // EEPROM read address
	
	if(I2C_receiveData(&data[i],NACK)== DATA_RECIEVE_NACK_OK){	//Send Data Byte By Byte and Wait For AcK Each Time
		
		I2C_stop();
	}
	_address++; // ADDRESS to read the next element in EEPROM
	}
}
//***********************************************************************************************************************************************