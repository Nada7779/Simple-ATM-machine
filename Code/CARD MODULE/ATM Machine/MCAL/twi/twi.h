

#ifndef TWI_H_
#define TWI_H_

/*************************************************/
//					INCLUDES
/**************************************************/
#include "../MEMORYMAP.h"
#include "../../Service/STD_TYPES.h"
#include "../../Service/UTILES.h"
#include <math.h>

/*************************************************/
//					MACROS
/**************************************************/
//#define  F_CPU			8000000U
#define  SCL_CK			1000000U
#define	 BITRATE(TWSR)	((8000000U /SCL_CK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))


/*****************************************************
				Enums
********************************************************/
typedef enum{
	WRITE,
	READ
	
	}R_W;

typedef enum{
	ACK,
	NACK
	
}ACKOLEDGMENT;

typedef enum {
	I2C_PRESCALER_1 ,
	I2C_PRESCALER_4,
	I2C_PRESCALER_16,
	I2C_PRESCALER_64
	}I2C_PRESCALER;


/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/

void I2C_init(I2C_PRESCALER prescaler);
uint8_t I2C_start();
uint8_t I2C_addressEvent(uint8_t a_address ,R_W r_w );
uint8_t I2C_sendData(uint8_t *data);
uint8_t I2C_receiveData(uint8_t *data, ACKOLEDGMENT ack);
uint8_t I2C_dataEvent(uint8_t *data ,uint8_t s_r , uint8_t ack );
void I2C_stop();
uint8_t I2c_Restart();
void EEPROM_Write (uint8_t *data, uint8_t* _addres);
void EEPROM_Read (uint8_t *data) ;




#endif /* TWI_H_ */