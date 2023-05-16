/*
 * hspi.c
 *
 * Created: 05-May-23 6:13:13 PM
 *  Author: Zerconium
 */ 


#include "spi.h"




static void (*SPI_Fptr)(void)=NULL;


void SPI_MasterInit(en_SPI_Prescaler prescaler)
{
	/* Set MOSI , SCK and SS as output, MISO as input */
	DIO_INITPIN(MOSI,OUTPUT);
	DIO_INITPIN(SCK,OUTPUT);
	DIO_INITPIN(SS,OUTPUT);
	DIO_INITPIN(MISO,INPLUP);
	
	/* set SS pin to high */
	DIO_WRITEPIN(SS,HIGH);
	
	/* Enable SPI, Master */
	set_bit(SPCR,SPE);
	set_bit(SPCR,MSTR);
	
	/* 2x speed OFF , flag reset*/

	
	switch (prescaler)
	{
		case PRESCALER_2:
		clear_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_4:
		clear_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_8:
		set_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_16:
		set_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_32:
		clear_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_64:
		clear_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_128:
		set_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
	}
}


void SPI_SlaveInit (en_SPI_Prescaler prescaler)
{
	/* Set MOSI , SCK and SS as input, MISO as output */
	DIO_INITPIN(MOSI,INPLUP);
	DIO_INITPIN(SCK,INPLUP);
	DIO_INITPIN(SS,INPLUP);
	DIO_INITPIN(MISO,OUTPUT);
	
	/* set SS pin to high */
	DIO_WRITEPIN(SS,HIGH);
	
	/* Enable SPI */
	set_bit(SPCR,SPE);
	
	/* 2x speed OFF , flag reset */
	SPSR &= 0x00 ;
	
	switch (prescaler)
	{
		case PRESCALER_2:
		clear_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_4:
		clear_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_8:
		set_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_16:
		set_bit(SPCR,SPR0);
		clear_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_32:
		clear_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		set_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_64:
		clear_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
		
		case PRESCALER_128:
		set_bit(SPCR,SPR0);
		set_bit(SPCR,SPR1);
		clear_bit(SPSR,SPI2X);
		break;
	}
}


uint8_t SPI_SendReceive(uint8_t data)
{
	SPDR=data;
	while(!read_bit(SPSR,SPIF));
	return  SPDR;
	
}



uint8_t SPI_RecievePeriodicChecking(uint8_t * pdata)
{
	if (read_bit(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}


void SPI_SendNoBlock(uint8_t data)
{
	SPDR = data;
}



uint8_t SPI_ReceiveNoBlock(void)
{
	return  SPDR;
}


void SPI_InterruptEnable(void)
{
	set_bit(SPCR,SPIE);
}


void SPI_InterruptDisable(void)
{
	clear_bit(SPCR,SPIE);
}


void SPI_SetCallBack(void (*fptr_local)(void))
{
	SPI_Fptr=fptr_local;
}


ISR(SPI_STC_vect)
{
	if (SPI_Fptr != NULL)
	{
		SPI_Fptr();
	}
}