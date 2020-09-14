
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



uint8_t windLevelHighest ;
uint8_t flashflg=0;
struct usarts  usartdat;

#define MOTOR_RUN    0
#define AC_MOTOR_RUN    1
#define TOUCHKEY   1
uint8_t ReceOverflg;

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
    LED_GPIO_Init();
    UART0_Config();

	while(1)
	{
        	
			disp =usartdat.usart_1; //usartdat.usart_1;
			
		
			#if 1
			if((disp >> 7) == 1){
				d3=1;
			   LEDDisplay_TimerTim(d3,d2,d1);
               

			}
			else{
				d3=0;

				LEDDisplay_TimerTim(d3,d2,d1);
			}
            
			if((disp >> 4) == 1){
				 d2=1;
				 LEDDisplay_TimerTim(d3,d2,d1);
               
			}
			else{
				 d2=0;
				 LEDDisplay_TimerTim(d3,d2,d1);
                     
			}
            
            
			if((disp & 0x01) == 1){
				 d1=1;
				 LEDDisplay_TimerTim(d3,d2,d1);
                
			}
			else{
				 d1=0;
				 LEDDisplay_TimerTim(d3,d2,d1);
               

			}  

		
		

		

	 	
	}
}


	





  





















