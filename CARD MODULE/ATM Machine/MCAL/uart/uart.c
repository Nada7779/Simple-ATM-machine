/*
 * uart.h
 *
 * Created: 5/1/2023 10:34:00 AM
 *  Author: Nada
 */ 

#include "uart.h"

void USART_init(void)
{
	// calculate baud rate
	uint16 UBRR;
	#if sync_mode_selector == ASYNCH
	#if speed_mode_selector == normal_speed
	UBRR= (Fosc/16/baud)-1;
	#elif  speed_mode_selector == double_speed
	UBRR = (Fosc/8/baud)-1;
	#endif
	#elif sync_mode_selector == SYNCH
	UBRR = (Fosc/2/baud)-1; 
	#endif
	// set baud rate
	UBRRH = (uint8_t)(UBRR>>8); // high nibble bits
	UBRRL = (uint8_t) UBRR; // low nibble bits
	//enable UART  receiver.
	set_bit(UCSRB,RXEN); 
	//enable UART  transmitter .
	set_bit(UCSRB,TXEN);
	// set URSEL to write on UCSRC 
	set_bit(UCSRC,URSEL);
	// set speed
	#if speed_mode_selector==normal_speed
	clear_bit(UCSRA,U2X);
	#elif speed_mode_selector==double_speed
	set_bit(UCSRA,U2X);
	#endif
	// set synchronous or asynchronous
	#if  sync_mode_selector==SYNCH
	set_bit(UCSRC,UMSEL);
	#elif sync_mode_selector==ASYNCH
	clear_bit(UCSRC,UMSEL);
	#endif
	 // set parity mode
	 #if parity_mode_selector==NO_PARITY
	 clear_bit(UCSRC,UPM0);
	 clear_bit(UCSRC,UPM1);
	 #elif parity_mode_selector==EVEN_PARITY
	 clear_bit(UCSRC,UPM0);
	 set_bit(UCSRC,UPM1);
	 #elif parity_mode_selector==ODD_PARITY
	 set_bit(UCSRC,UPM0);
	 set_bit(UCSRC,UPM1);
	 #endif
	 // set Stop bits
	 #if number_stopBits_selector==ONE_STOP_BIT
	 clear_bit(UCSRC,USBS);
	 #elif number_stopBits_selector==TWO_STOP_BIT
	 set_bit(UCSRC,USBS);
	 #endif
	 // set data bits 
	 #if number_dataBits_selector==_5_DATA_BITS  
	 clear_bit(UCSRC,UCSZ0);
	 clear_bit(UCSRC,UCSZ1);
	 clear_bit(UCSRB,UCSZ2);
	 #elif number_dataBits_selector==_6_DATA_BITS  
	 set_bit(UCSRC,UCSZ0);
	 clear_bit(UCSRC,UCSZ1);
	 clear_bit(UCSRB,UCSZ2);
	 #elif number_dataBits_selector==_7_DATA_BITS  
	 clear_bit(UCSRC,UCSZ0);
	 set_bit(UCSRC,UCSZ1);
	 clear_bit(UCSRB,UCSZ2);
	 #elif number_dataBits_selector==_8_DATA_BITS  
	 set_bit(UCSRC,UCSZ0);
	 set_bit(UCSRC,UCSZ1);
	 clear_bit(UCSRB,UCSZ2);
	 #elif number_dataBits_selector==_9_DATA_BITS  
	 set_bit(UCSRC,UCSZ0);
	 set_bit(UCSRC,UCSZ1);
	 set_bit(UCSRB,UCSZ2);
	 #endif
}
//***************************************************************************************************************
// Data Transmission Sending Frames with 5 to 8 Data Bit
void USART_transmit( uint8_t data )
{
	// Wait for empty transmit buffer
	while(! (UCSRA & (1 << UDRE)));
	;
	// Put data into buffer, sends the data
	UDR = data;
}
//**************************************************************************************************************
// Receiving Frames with 5 to 8 Data Bits
uint8_t USART_receive( void )
{
	// Wait for data to be received
	while ( !(UCSRA & (1<<RXC)) )
	;
	// Get and return received data from buffer
	return UDR;
}
//**********************************************************************************************************
void USART_Transmit_string (char * str)
{
	uint8_t i =0 ;
	while(str[i]!=0)
	{ USART_transmit(str[i]); i++;}
	
}
//***********************************************************************************************************
char * USART_receive_string (uint8_t *string)  //Receive a character until carriage return or newline
{

	uint8_t  i=0,char_input=0;
	

	do

	{

		*(string+i)= USART_receive();

		char_input = *(string+i);

		i++;

	}while((char_input!='\n') && (char_input!='\r'));
	
	i++;
	*(string+i) = '\0';
		int u=0;
		while ((*(string+u)) !=0) u++;
		*(string+(u-1))=0;
	return string;

}
//***********************************************************************************************************