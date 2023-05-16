
#ifndef app_H_
#define app_H_



/*****************************************************************************************************************************************************************
*									Includes																				 *
******************************************************************************************************************************************************************/
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/exi_interrupt/EXI_INTERRUPT.h"
#include "../HAL/lcd/LCD.h"
#include "../HAL/keypad/keypad.h"
#include "../MCAL/timers/timer.h"
#include "../HAL/buzzer/buzzer.h"
#include "Server.h"
#include "../MCAL/spi/spi.h"

/*****************************************************************************************************************************************************************
*									defines																			 *
******************************************************************************************************************************************************************/

#define  DELAY_VALUE 1000
#define  BUTTON_PIN  pinb2
#define  MAX_Value	5000.0
#define PAN_Size	17
#define PIN_Size	5
#define SPI_REC_Size	21
#define Line_1			1
#define Line_2			2
#define Cell_0			0
#define Cell_1			1
#define Cell_3			3
#define Cell_4			4
#define Cell_5			5
#define Cell_6			6
#define Cell_15			15
#define Cell_7			7
#define Null			'\0'
#define BELL_Size	8
#define	True		1
#define False		0
#define MAX_PIN_Trial	3
typedef enum {
	
	WELCOME_STAGE = 1 ,
	INSERTION_STAGE ,
	RECIEVE_STAGE,
	PIN_ENTRY_STAGE ,
	PIN_CHECK_STAGE,
	TRANSACTION_ENTRY_STAGE ,
	ACCOUNT_CHECK_STAGE ,	
	
	}STAGES;
/*****************************************************************************************************************************************************************
*									Functions prototypes																			 *
******************************************************************************************************************************************************************/
extern uint8_t enter_zeroFlag ,state ;

void set_sage(void);
void welcome(void);
void insertion(void);
void PIN_Entery (void);
void PIN_Check (void);
void transaction_Entry(void);
void account_checks(void);
void app_Start(void);
void app_Init(void);
void RECIEVE_data(void);

#endif








