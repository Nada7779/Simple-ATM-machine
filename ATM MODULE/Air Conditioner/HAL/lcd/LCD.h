

#ifndef LCD_H_
#define LCD_H_

#include "../../SERVICE/STD_TYPES.h"
#include "../../MCAL/dio/DIO.h"
//#define  F_CPU   8000000UL
#include <util/delay.h>

#define _4_bit_mode		0
#define _8_bit_mode		1
/************************* config**************************************************/
#define LCD_Mode      _4_bit_mode

#define  LCD_PORT      PA

#define	  D4		   pina4
#define	  D5		   pina5
#define	  D6		   pina6
#define	  D7		   pina7

#define   RS           pina1
#define   RW           pina2
#define   EN           pina3

/*********************************************************************************/

void LCD_WRITE_COMMAND(uint8_t a_COMMAND);
void LCD_WRITE_DATA(uint8_t a_DATA);

void LCD_INIT(void);
void LCD_Write_String(uint8_t*a_String);
void LCD_Write_Number(uint32_t a_number);
void LCD_Clear(void);
void LCD_GoTo(uint8_t a_line,uint8_t a_cell);
void LCD_Write_Charecter(uint8_t a_char);
void LCD_Create_Charecter(uint8_t*a_Pattern,uint8_t a_Adress);


#endif /* LCD_H_ */