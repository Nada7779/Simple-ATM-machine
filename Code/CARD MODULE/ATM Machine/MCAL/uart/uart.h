/*
 * uart.h
 *
 * Created: 5/1/2023 10:33:46 AM
 *  Author: Nada
 */ 


#ifndef UART_H_
#define UART_H_

// Includes
#include "uart_config.h"
#include "../../Service/STD_TYPES.h"
#include "../MEMORYMAP.h"

// speed modes
#define  normal_speed     0
#define  double_speed     1
#define  total_speed      2
// parity modes
#define NO_PARITY    0
#define EVEN_PARITY  1
#define ODD_PARITY   2
// sync modes
#define  SYNCH  0
#define  ASYNCH 1
// number of stop bits
#define  ONE_STOP_BIT   1
#define  TWO_STOP_BIT   2
// number of data bits
#define  _5_DATA_BITS    5
#define  _6_DATA_BITS    6
#define  _7_DATA_BITS    7
#define  _8_DATA_BITS    8
#define  _9_DATA_BITS    9
// CPU frequency
#define   _4_MHZ         0
#define   _8_MHZ         1
#define  _16_MHZ         2
#define  TOTAL_CPU_F     3
// baud rate
#define  BAUD_2400       0
#define  BAUD_4800       1
#define  BAUD_9600       2
#define  BAUD_14400      3
#define  BAUD_19200      4
#define  BAUD_28800      5
#define  TOTAL_BAUD_RATE 6
// USART registers
#define UDR   *((volatile uint8_t*)0x2C)
#define UCSRA *((volatile uint8_t*)0x2B)
#define UCSRB *((volatile uint8_t*)0x2A)
#define UCSRC *((volatile uint8_t*)0x40)
#define UBRRL *((volatile uint8_t*)0x29)
#define UBRRH *((volatile uint8_t*)0x40)
// register bits config
#define  RXEN  4
#define  TXEN  3
#define  URSEL 7
#define  UCSZ0 1
#define  UDRE  5
#define  RXC   7
#define  UCSZ1 2
#define  U2X   1
#define  UMSEL 6
#define  UPM0  4
#define  UPM1  5
#define  USBS  3
#define  UCSZ2 2
// bits config
#define set_bit(reg,bit)            reg=(reg|(1<<bit))
#define clear_bit(reg,bit)           reg=(reg&(~(1<<bit)))
#define read_bit(reg,bit)              ((reg>>bit)&1)
#define toggel_bit(reg,bit)              reg=reg^(1<<bit)
// Functions prototypes
void USART_init(void);
void USART_transmit(uint8_t data);
uint8_t USART_receive(void);
void USART_Transmit_string (char * str);
char * USART_receive_string (uint8_t *string) ;



#endif /* UART_H_ */

