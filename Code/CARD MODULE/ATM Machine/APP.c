#include "APP.h"

/***********************************************************************************************************************
                                    GLOBAL VARIABLES 
*****************************************************************************************************************************/

/***********************************************************************************************************************
                                   FUNCTION IMPLMENTATION
****************************************************************************************************************************/
void app_Init(void)
{
// 	SPI_MasterInit(PRESCALER_16);
// 	 uint8_t str[] = "123456";
// 	 for (int i = 0; i < strlen(str); i++) {
// 		 SPI_SendReceive(str[i]);
// 	 }
// 	 SPI_SendReceive('\0');
// 	 _delay_ms(100);

SPI_MasterInit(PRESCALER_16);


    uint8_t message[] = " 1234";
    uint8_t index = 0;
	
DIO_WRITEPIN(SS, LOW);

    while (message[index] != '\0')
    {
	    SPI_SendReceive(message[index]);
	    index++;
	    _delay_ms(800);
    }
    SPI_SendReceive('\0');
	
DIO_WRITEPIN(SS, HIGH);

    while (1);
	
}
uint8_t data = 'A';
//uint8_t y[17] = {'1','2','3','4','5','6','7','8','9','1','2','3','4','5','6','7'};
	
void app_Start(void)
{
// 	DIO_WRITEPIN(SS,LOW);      
// 	SPI_SendReceive(data);    
// 	DIO_WRITEPIN(SS,HIGH);
// 	_delay_ms(100000);








	
	/*SPI_SendString(y);
	_delay_ms(100000);*/
	
	
	
	/*uint8_t y = 7;
	SPI_SendChar(y);
	_delay_ms(100000);*/
	

	
}
