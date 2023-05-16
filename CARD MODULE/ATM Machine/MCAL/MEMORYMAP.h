
#ifndef memorymap_H_
#define memorymap_H_
#include "../SERVICE/std_types.h"

/********************************************DIO MAPING************************	********/
#define DDRA (*(volatile uint8_t*)0x3A)
#define DDRB (*(volatile  uint8_t*)0x37)
#define DDRC (*(volatile uint8_t*)0x34)
#define DDRD (*(volatile uint8_t*)0x31)


#define PINA (*(volatile uint8_t*)0x39)
#define PINB (*(volatile uint8_t*)0x36)
#define PINC (*(volatile uint8_t*)0x33)
#define PIND (*(volatile uint8_t*)0x30)


#define PORTA (*(volatile uint8_t*)0x3B)
#define PORTB (*(volatile uint8_t*)0x38)
#define PORTC (*(volatile uint8_t*)0x35)
#define PORTD (*(volatile uint8_t*)0x32)

/******************************EXT INTERRUPT MAPPING**************************************/

#define MCUCSR  (*(volatile uint8_t*)0X54)
#define MCUCR  (*(volatile uint8_t*)0X55)
#define GICR  (*(volatile uint8_t*)0X5B)
/*************interrupt registers pin macro*/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6
#define INT0 6
#define INT1 7
#define INT2 5
/****data sheet attributes to enable context switching and to enable global interrupt*/
#define INT0_vect	 __vector_1
#define INT1_vect	 __vector_2
#define INT2_vect	 __vector_3
#define TIMER2_OVF	 __vector_5

#define sei() __asm__ __volatile__("sei" ::: "memory")
#define cli() __asm__ __volatile__("cli" ::: "memory")

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



/*****************************************TIMER MAPING*************************************/
/***************************** TIMER_0 ******************************/
#define TCNT0   (*(volatile uint8_t*)0x52)
#define TCCR0   (*(volatile uint8_t*)0x53)
#define TIMSK   (*(volatile uint8_t*)0x59)
#define GIFR    (*(volatile uint8_t*)0x5A)
#define TIFR    (*(volatile uint8_t*)0x58)
#define OCR0    (*(volatile uint8_t*)0x5C)
/**TCCR0**/
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
/*************/

/***TIMSK**/
#define TOIE0 0
#define OCIE0 1
/**************/

/**GIFR**/


/*********/

/**TIFR**/
#define TOV0 0
#define OCF0 1
/**************/

/***************************** TIMER_2 ******************************/
#define TCCR2   (*(volatile uint8_t*)0x45)
#define TCNT2   (*(volatile uint8_t*)0x44)


/**TCCR2**/
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7
      
/**TIFR**/
#define TOV2 6

/***** TIMSK***/
#define TOIE2 6

/*************************************ADC MAPPING**************************************/

#define ADMUX     *((volatile uint8_t*)0x27)
#define ADCSRA    *((volatile uint8_t*)0x26)
#define ADCL      *((volatile uint8_t*)0x24)
#define ADCH      *((volatile uint8_t*)0x25)
#define ADCLH     *((volatile unsigned short int*)0x24) // use this when we use right method to read high and low bits
#define SFIOR     *((volatile uint8_t*)0x50)


/*************************************************************/
//						I2C REGISTERS
/*************************************************************/
#define TWBR	 *((volatile uint8_t *)0x20)
#define TWCR	 *((volatile uint8_t *)0x56)
#define TWSR	 *((volatile uint8_t *)0x21)
#define TWDR	 *((volatile uint8_t *)0x23)
#define TWAR	 *((volatile uint8_t *)0x22)


/********************************************
				Bit Defines
*********************************************/
/* MASTER MODE */
#define  START_SENT				0x08
#define  RESTART_SENT			0x10
#define	 AD_W_SENT_ACK			0x18
#define	 AD_W_SENT_NACK			0x20
#define	 DATA_SENT_ACK			0x28
#define  DATA_SENT_NACK			0x30
#define	 AD_R_SENT_ACK			0x40
#define  AD_R_SENT_NACK			0x48
#define	 DATA_RECIEVE_ACK		0x50
#define	 DATA_RECIEVE_NACK		0x58

/* RETURNS  */
#define	 EVENT_OK				 0
#define  START_NOT_SENT			 1 
#define  AD_W_SENT_ACK_OK		 2
#define  AD_W_SENT_NACK_OK		 3
#define  AD_W_SENT_FAILED		 5
#define  AD_R_SENT_ACK_OK	 	 6
#define  AD_R_SENT_NACK_OK		 7
#define	 AD_R_SENT_FAILED		 8
#define	 DATA_SENT_ACK_OK		 9
#define  DATA_SENT_NACK_OK		 10
#define	 DATA_SENT_FAILED		 11
#define  DATA_RECIEVE_ACK_OK	 12
#define	 DATA_RECIEVE_NACK_OK	 13
#define	 DATA_RECIEVE_FAILED	 14


/* TWSR */
#define	TWPS0				 0
#define TWPS1				 1

/* TWCR */
#define  TWIE				 0
#define  TWEN				 2
#define  TWWC				 3
#define  TWSTO				 4
#define	 TWSTA				 5
#define  TWEA				 6
#define  TWINT				 7




// USART
#define UDR *((volatile uint8_t*)0x2C)
#define UCSRA *((volatile uint8_t*)0x2B)
#define UCSRB *((volatile uint8_t*)0x2A)
#define UCSRC *((volatile uint8_t*)0x40)
#define UBRRL *((volatile uint8_t*)0x29)
#define UBRRH *((volatile uint8_t*)0x40)

// SPI
#define SPDR *((volatile uint8_t*)0x2F)
#define SPSR *((volatile uint8_t*)0x2E)
#define SPCR *((volatile uint8_t*)0x2D)



#endif /* memorymap_H_ */