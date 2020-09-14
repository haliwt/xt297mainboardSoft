
#include "cms8s6990.h"

#include "demo_buzzer.h"
#include "touchkey.h"
#include "cnrelay.h"
#include "lamp.h"
#include "limit.h"
#include "ac_relay.h"
#include "led.h"
#include "key.h"
#include "demo_uart.h"



uint32_t Systemclock = 24000000;

Telec Telecom;

uint8_t windLevelHighest ;
uint8_t flashflg=0;
struct usarts  usartdat;

#define MOTOR_RUN    0
#define AC_MOTOR_RUN    1
#define TOUCHKEY   1


/*******************************************************
	*
	*Function Name: int main(void)
	*
	*
	*
*******************************************************/
int main(void)
{		
   
    uint8_t d1,d2,d3,disp;
    TMR1_Config();
	TMR0_Config();
    LED_GPIO_Init();
    UART0_Config();

	while(1)
	{
        	
			disp =usartdat.usart_1; //usartdat.usart_1;
			d1 = disp % 10;
			d2=  (disp / 10 ) % 10;
			d3=  (disp / 100 ) % 10;
			
			LEDDisplay_TimerTim(d3,d2,d1);
	        LEDDisplay_GreenColorRing();
			delay_20us(20000);
			

		

	 	
	}
}

	





  





















