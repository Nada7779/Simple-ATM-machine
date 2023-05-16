
#ifndef APP_H_
#define APP_H_
/*****************************************************************
					Includes
*****************************************************************/
#include "../MCAL/dio/DIO.h"
#include "../MCAL/Timers/timer.h"
#include "../MCAL/twi/twi.h"
#include "../HAL/eeprom/eeprom.h"
#include "../HAL/keypad/keypad.h"
#include "../HAL/lcd/LCD.h"
#include "../MCAL/spi/spi.h"
#include <util/delay.h>
/*****************************************************************
					Defines
*****************************************************************/
#define  ad             0x00
#define  ad2            0x10
#define  pan_num        17
#define  pan_len        16
#define  pan_len_min1   15
#define  pin_num        5
#define  null           0
#define  null_ch       '0'
#define  true_char     '1'
#define  true          1
#define  zero_asci     48
#define  nine_asci     57
#define  mode_1        '1'
#define  mode_2        '2'
#define  pin_len        4
#define  pin_len_min1   3
#define  pin_len_plus3  7
#define  new_line       '\n'
#define  modes           3
#define  empty_data      0xff

/*************************************************************
						PROTOTYPES
**************************************************************/
void CARD_PROGRAMMING_MODE(void);
void CARD_USER_MODE(void);
void app_init();
void app_start() ;
#endif /* APP_H_ */