/*
 * hspi.h
 *
 * Created: 05-May-23 6:13:21 PM
 *  Author: Zerconium
 */ 


#ifndef HSPI_H_
#define HSPI_H_

#include "../dio/DIO.h"


/*****************************************************************************************************************************************************************
*																		Macros																					 *
******************************************************************************************************************************************************************/
//SPCR bits
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

//SPSR bits
#define SPIF	7
#define WCOL	6
#define SPI2X	0

#define SS		 pinb4
#define MOSI	 pinb5
#define MISO	 pinb6
#define SCK		 pinb7
/*****************************************************************************************************************************************************************
*																		Enums																					 *
******************************************************************************************************************************************************************/
typedef enum {
	PRESCALER_2,
	PRESCALER_4,
	PRESCALER_8,
	PRESCALER_16,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128
} en_SPI_Prescaler;



void SPI_MasterInit(en_SPI_Prescaler prescaler);
void SPI_SlaveInit(en_SPI_Prescaler prescaler);
uint8_t SPI_SendReceive(uint8_t data);
uint8_t SPI_RecievePeriodicChecking(uint8_t * pdata);
void SPI_SendNoBlock(uint8_t data);
uint8_t SPI_ReceiveNoBlock(void);

void SPI_InterruptEnable(void);
void SPI_InterruptDisable(void);
void SPI_SetCallBack(void (*fptr_local)(void));




#endif /* HSPI_H_ */