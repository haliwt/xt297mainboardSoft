#ifndef __USART1_H__
#define __USART1_H__

#include "cms8s6990.h"


typedef struct usarts
{
    uint8_t usart_1;    //
    
    uint8_t usart_2 ;
    uint8_t usart_3;
	uint8_t usart_4;
   
 } ;

extern struct usarts  usartdat;

extern unsigned char bufRxd[4]; //???????



void UART0_Config(void);
uint8_t BCC(void);




#endif 