#include "APP.h"

/***********************************************************************************************************************
                                    GLOBAL VARIABLES 
*****************************************************************************************************************************/

/***********************************************************************************************************************
                                   FUNCTION IMPLMENTATION
****************************************************************************************************************************/
uint8_t y[17] = "1234";
	
void app_Init(void)
{
	LCD_INIT();
	SPI_SlaveInit(PRESCALER_16);	

	uint8_t message[]={};
	uint8_t index = 0;

	while (1)
	{
		if (SPI_RecievePeriodicChecking(&message[index]))
		{
			if (message[index] == '\0')
			{
				break;
			}
			index++;
		}
	}
	
	LCD_GoTo(1,0);
	LCD_Write_String(message);
	while (1);
	

	
// 	LCD_INIT();
// 	DIO_INITPIN(pinc0, OUTPUT);
// 	DIO_INITPIN(pinc1, OUTPUT);
// 	DIO_INITPIN(pinc2, OUTPUT);
// 	DIO_INITPIN(pinc3, OUTPUT);
// 	DIO_INITPIN(pinc4, OUTPUT);
// 	DIO_INITPIN(pinc5, OUTPUT);
// 	DIO_INITPIN(pinc6, OUTPUT);
// 	DIO_INITPIN(pinc7, OUTPUT);


// 	 while (1) {
// 		 if (receive_index > 0 && received_str[receive_index-1] == '\0') {
// 			 received_str[receive_index-1] = '\0'; // Remove null terminator
// 			 break;
// 		 }
// 	 }


}


uint8_t received_data;

void app_Start(void)
{		
// 
//  if (SPI_RecievePeriodicChecking(&received_data))  
//  {
// 	LCD_GoTo(1,0);
// 	LCD_Write_Charecter(received_data);
//  }



		/*SPI_ReceiveString(X,16);
		LCD_GoTo(1,0);
		LCD_Write_String(X);
		DIO_port_write(pinc0, X[11]);
		_delay_ms(100000); */
				

		/*uint8_t X = SPI_ReceiveChar();
		LCD_GoTo(1,0);
		LCD_Write_Number(X);*/
	

}

