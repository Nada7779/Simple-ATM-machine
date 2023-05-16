#include "twi.h"

/**DESCRIPTION:-
 This Function is used To Initialize the Communication With a Certain BitRate*/
void I2C_init(I2C_PRESCALER prescaler){
	
	TWSR = 0x00 ;												//To Make Sure No Previous scaler Is Set
	
	switch (prescaler){											//To Choose Between Different Set Of scalers 
		case I2C_PRESCALER_1 :
		clear_bit(TWSR,TWPS0);
		clear_bit(TWSR,TWPS1);
		break;
		
		case I2C_PRESCALER_4 :
		set_bit(TWSR,TWPS0);
		clear_bit(TWSR,TWPS1);
		break;
		
		case I2C_PRESCALER_16 :
		clear_bit(TWSR,TWPS0);
		set_bit(TWSR,TWPS1);
		break;
		
		
		case I2C_PRESCALER_64 :
		set_bit(TWSR,TWPS0);
		set_bit(TWSR,TWPS1);
		break;
		
		default:
		break;
	}
	
	
	TWBR  = BITRATE(TWSR);								//To Select The Division Factor For The BitRate Generator Which Generates The Master CLK
	
}
/*************************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Enables The Communication And Send The Starting Bit*/
uint8_t I2C_start(){
	
	set_bit(TWCR,TWINT);  // clear flag
	set_bit(TWCR,TWSTA);  // enable start condition
	set_bit(TWCR,TWEN);   // enable i2c
	while(read_bit(TWCR,TWINT) != 1);  // wait for flag to set
	
	if((TWSR & 0xf8) == START_SENT){   // check start condition status
		return EVENT_OK ;
		
	}else {
		
		return START_NOT_SENT ;
	}
	
}
/*******************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Set The Slave Address For Communications And Send The Event Type Of The Master Either R/W*/

uint8_t I2C_addressEvent(uint8_t a_address ,R_W r_w ){
	switch(r_w){
		
		case WRITE : 
		TWDR = a_address + WRITE ;				 //SET ADDRESS + WRITE
		
		set_bit(TWCR,TWINT);					 // clear flag
		set_bit(TWCR,TWEN);						// enable i2c
		while(read_bit(TWCR,TWINT) != 1);		// wait for flag to set
		
		if((TWSR & 0xf8) == AD_W_SENT_ACK){	// check status of sending address that we want to write in and ack received
			return AD_W_SENT_ACK_OK ;
		}
		else if ((TWSR & 0xf8) == AD_W_SENT_NACK){
			return AD_W_SENT_NACK_OK ;
		}
		else {
			
			return AD_W_SENT_FAILED ;
		}
		
		break; // END OF WRITE CASE
		
		
		
		case READ :
		TWDR = a_address + READ ; //SET ADDRESS + read
		
		set_bit(TWCR,TWINT);  // clear flag
		set_bit(TWCR,TWEN);   // enable i2c
		while(read_bit(TWCR,TWINT) != 1);  // wait for flag to set
		
		if((TWSR & 0xf8) == AD_R_SENT_ACK){   // // check status of sending address that we want to read from and ack received
			return AD_R_SENT_ACK_OK ;
		}
		else if ((TWSR & 0xf8) == AD_R_SENT_NACK){
			return AD_R_SENT_NACK_OK ;
		}
		else {
				
			return AD_R_SENT_FAILED ;
		}
			
		
		break;// END OF READ CASE
		
	}

	
}
/********************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Initialize Data Transfer */
uint8_t I2C_sendData(uint8_t *data ){
		
		TWDR = *data ;								//Write Data On Data Register
		set_bit(TWCR,TWINT);						// clear flag
		set_bit(TWCR,TWEN);							// enable i2c
		while(read_bit(TWCR,TWINT) != 1);			// wait for flag to set
		
		if((TWSR & 0xf8) == DATA_SENT_ACK){		  // check status of sending data  and ack received
			return DATA_SENT_ACK_OK ;
		}
		else if ((TWSR & 0xf8) == DATA_SENT_NACK){
			return DATA_SENT_NACK_OK ;
		}
		else {
			
			return DATA_SENT_FAILED ;
		}
	
}
/******************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Write The Stop Bit For The Communication*/
void I2C_stop(){
	clear_bit(TWCR,TWSTA);		 // clear start
	set_bit(TWCR,TWINT);		 // clear flag
	set_bit(TWCR,TWSTO);		// enable stop condition
	set_bit(TWCR,TWEN);			// enable i2c
	while(read_bit(TWCR,TWSTO) != 0);  // wait for flag to set
	
}
/******************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Receive Data From a Slave To Master*/
uint8_t I2C_receiveData(uint8_t *data, ACKOLEDGMENT ack){
	
	switch(ack){ 
		case ACK :
		set_bit(TWCR,TWEA); 
		break;
		
		case NACK :
		clear_bit(TWCR,TWEA);
		break;
		
	}
	
	set_bit(TWCR,TWINT);  // clear flag
	set_bit(TWCR,TWEN);   // enable i2c
	while(read_bit(TWCR,TWINT) != 1);  // wait for flag to set
	*data = TWDR ;
	if((TWSR & 0xf8) == DATA_RECIEVE_ACK){    // check status of receiving data and ack received
		return DATA_RECIEVE_ACK_OK ;
	}
	else if ((TWSR & 0xf8) == DATA_RECIEVE_NACK){
		return DATA_RECIEVE_NACK_OK ;
	}
	else {
		
		return DATA_RECIEVE_FAILED ;
	}
	

}
/******************************************************************************************************************************************/
/**DESCRIPTION:-
 This Function is used To Send a Repeated Start In Case Of Sending More Data to The Same Slave Or to another Slave*/
uint8_t I2c_Restart(){
	
		//set_bit(TWCR,TWINT);								// clear flag
		//set_bit(TWCR,TWSTA);								// enable start condition
		//set_bit(TWCR,TWEN);									// enable i2c
		TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
		while(read_bit(TWCR,TWINT) != 1);					 // wait for flag to set
		
		if((TWSR & 0xf8) == RESTART_SENT){					// check start condition status
			return RESTART_SENT;
			
		}else {
			
			return START_NOT_SENT ;
		}
		
}