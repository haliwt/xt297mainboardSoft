#include "demo_buzzer.h"
//#include "key.h"
//#include "myflash.h"
//#include "led.h"

//#include "output.h"
#include "demo_uart.h"






extern  uint8_t ReceOverflg;


unsigned char bufRxd[4]; //接收字节缓冲区


uint8_t cntRxd ;

/******************************************************************************
 ** \brief	 INT0 interrupt service function
 **			
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void INT0_IRQHandler(void)  interrupt INT0_VECTOR
{

}
/******************************************************************************
 ** \brief	 Timer 0 interrupt service function
 **
 ** \param [in]  none   100us PM2.5
 **
 ** \return none
******************************************************************************/
void Timer0_IRQHandler(void)  interrupt TMR0_VECTOR 
{
    
	

}
/******************************************************************************
 ** \brief	 INT0 interrupt service function
 **			
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void INT1_IRQHandler(void)  interrupt INT1_VECTOR
{
	;
}
/******************************************************************************
 ** \brief	 Timer 1 interrupt service function
 **
 ** \param [in]  none  100us timer
 **
 ** \return none
******************************************************************************/
void Timer1_IRQHandler(void)  interrupt TMR1_VECTOR 
{
	
       
	       

	
    
}
/******************************************************************************
 ** \brief	 UART 0 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void UART0_IRQHandler(void)  interrupt UART0_VECTOR 
{
	#if 1
	static uint8_t  vair=0;
 

    if(UART_GetSendIntFlag(UART0))
	{
		UART_ClearSendIntFlag(UART0);	
	}
	if(UART_GetReceiveIntFlag(UART0))
	{   
        UART_ClearReceiveIntFlag(UART0);
      //  UART_SendBuff(UART0,UART_GetBuff(UART0));
         if (cntRxd < 4){
             if(cntRxd ==0){ bufRxd[0] = UART_GetBuff(UART0);
			     if(bufRxd[0]== 0xAA)
                 	cntRxd++;
				 else cntRxd =0;
             }
			 else {
                 bufRxd[cntRxd] = UART_GetBuff(UART0);
                 cntRxd ++;
				if( bufRxd[3]= BCC())
				  ReceOverflg = 1;
				else {
					ReceOverflg =0;
					cntRxd=0;
				}
				   
             }
			if(cntRxd ==4)cntRxd=0;
			
        }
		
		
		if(ReceOverflg ==1)
		{
		   ReceOverflg =0;
		  
			  usartdat.usart_1 = bufRxd[1] ;
			  usartdat.usart_2 = bufRxd[2] ;
				
              
				UART_SendBuff(UART0,usartdat.usart_1);
				//UART_SendBuff(UART0,usartdat.usart_2);
			
			}
	}
       #endif 
}
    
 

/******************************************************************************
 ** \brief	 Timer 2 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer2_IRQHandler(void)  interrupt TMR2_VECTOR 
{
	 if(TMR2_GetOverflowIntFlag())
	{

        
     TMR2_ConfigTimerPeriod((65536 - 78900)); //= 20.00ms
        
		TMR2_ClearOverflowIntFlag();
        
	}	
}
/******************************************************************************
 ** \brief	 UART 1 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void UART1_IRQHandler(void)  interrupt UART1_VECTOR 
{
	;
}
/******************************************************************************
 ** \brief	 GPIO 0 interrupt service function
 **	
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P0EI_IRQHandler(void)  interrupt P0EI_VECTOR 
{
	
}
/******************************************************************************
 ** \brief	 GPIO 1 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P1EI_IRQHandler(void)  interrupt P1EI_VECTOR 
{
	
	
    
	
}
/******************************************************************************
 ** \brief	 GPIO 2 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P2EI_IRQHandler(void)  interrupt P2EI_VECTOR 
{

}
/******************************************************************************
 ** \brief	 GPIO 3 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void P3EI_IRQHandler(void)  interrupt P3EI_VECTOR 
{
	;
}

/******************************************************************************
 ** \brief	 LVD interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void LVD_IRQHandler(void)  interrupt LVD_VECTOR 
{

}
/******************************************************************************
 ** \brief	 LSE interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void LSE_IRQHandler(void)  interrupt LSE_VECTOR 
{

}

/********************************************************************************
 ** \brief	 ACMP interrupt service function
 **			
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void ACMP_IRQHandler(void)  interrupt ACMP_VECTOR 
{

}
/******************************************************************************
 ** \brief	 Timer 3 interrupt service function
 **
 ** \param [in]  none  100us timer3 
 **
 ** \return none
******************************************************************************/
void Timer3_IRQHandler(void)  interrupt TMR3_VECTOR 
{
 
}
/******************************************************************************
 ** \brief	 Timer 4 interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
******************************************************************************/
void Timer4_IRQHandler(void)  interrupt TMR4_VECTOR 
{

}
/******************************************************************************
 ** \brief	 EPWM interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void EPWM_IRQHandler(void)  interrupt EPWM_VECTOR
{

}
/******************************************************************************
 ** \brief	 ADC interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void ADC_IRQHandler(void)  interrupt ADC_VECTOR 
{

}
/******************************************************************************
 ** \brief	 WDT interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void WDT_IRQHandler(void)  interrupt WDT_VECTOR 
{

}
/******************************************************************************
 ** \brief	I2C interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void I2C_IRQHandler(void)  interrupt I2C_VECTOR 
{
	;
}
/******************************************************************************
 ** \brief	SPI interrupt service function
 **
 ** \param [in]  none   
 **
 ** \return none
 ******************************************************************************/
void SPI_IRQHandler(void)  interrupt SPI_VECTOR 
{
	;
}















