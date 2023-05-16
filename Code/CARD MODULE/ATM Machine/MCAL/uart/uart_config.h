/*
 * uart_config.h
 *
 * Created: 5/1/2023 10:34:27 AM
 *  Author: Nada
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


//*******************************************************************************************************
 /* configure speed modes
 // speed modes
  normal_speed     
  double_speed     
  total_speed      
*/
#define speed_mode_selector    normal_speed

 /* configure parity modes
 // parity modes
 NO_PARITY    
 EVEN_PARITY  
 ODD_PARITY   
*/
#define parity_mode_selector  NO_PARITY   

 /* configure sync modes
 // sync modes
 SYNCH  
 ASYNCH 
*/
#define sync_mode_selector    ASYNCH 

 /* configure number of stop bits 
 // number of stop bits
 ONE_STOP_BIT   
 TWO_STOP_BIT   
*/
#define number_stopBits_selector   ONE_STOP_BIT   

 /* configure number of data bits
  // number of data bits
  _5_DATA_BITS    
  _6_DATA_BITS    
  _7_DATA_BITS    
  _8_DATA_BITS    
  _9_DATA_BITS    
*/
#define number_dataBits_selector _8_DATA_BITS    

/* configure CPU frequency
  // CPU frequency
   _4_MHZ         
   _8_MHZ         
   _16_MHZ        
  TOTAL_CPU_F     
*/
#define cpu_freq_selector  _8_MHZ 

/* configure Baud rate
  // Baud rate
  BAUD_2400       
  BAUD_4800       
  BAUD_9600       
  BAUD_14400      
  BAUD_19200      
  BAUD_28800      
  TOTAL_BAUD_RATE  
*/
#define baud_rate_selector   BAUD_9600  
// Data to calculate UBRR
/* configure Baud 
  // Baud 
  2400       
  4800       
  9600       
  14400      
  19200      
  28800        
*/
#define baud  9600
/* configure CPU frequency
  // Fosc
   4000000       
   8000000         
   16000000             
*/
#define Fosc  8000000


//***************************************************************************************************************


#endif /* UART_LCFG_H_ */
 


