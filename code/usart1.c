#include "usart1.h"

/******************************************************************************
 ** \brief	 UART0_Config
 ** \param [in] 
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void UART0_Config(void)
{
		//'??BRT???UARTg????????????????
	 uint16_t  BRTValue = 0;
	 uint32_t  BaudRateVlue = 9600;
	 
	 /*
	 (1)????UARTx??????g?
	 */
	 UART_ConfigRunMode(UART0,UART_MOD_ASY_8BIT, UART_BAUD_BRT);
	 UART_EnableReceive(UART0);
	 /*
	 (2)????UARTx???????
	 */
	 UART_ConfigBRTClk(BRT_CLK_DIV_1);	
	
	 UART_EnableDoubleFrequency(UART0); 							/*??????'??????SMOD =1*/
	
  #ifdef USE_FORMULA			//'?ù??????????l????(?????Systemclock???(main.c))??USE_FORMULA ?? ???Option->C51->Preporcessor Symbols->Define?????
	 BRTValue = UART_ConfigBaudRate(UART0, BaudRateVlue) ;
  #else 
	//BRTValue = 65380; 				//'???????????????l????(BRT?½?)
  BRTValue = 65484;           //WT.EDIT 

  #endif
 
	 UART_ConfigBRTPeriod(BRTValue);						/*????????*/
	 UART_EnableBRT();										/*'??????*/
	 /*
	 (3)????IO??
	 */
	// GPIO_SET_MUX_MODE(P23CFG,GPIO_MUX_TXD0);			/*TXD0*/
	// GPIO_SET_MUX_MODE(P22CFG,GPIO_MUX_RXD0);	 		/*RXD0*/
	 GPIO_SET_MUX_MODE(P25CFG,GPIO_MUX_TXD0);			/*TXD0*/
	  GPIO_SET_MUX_MODE(P26CFG,GPIO_MUX_RXD0);	 		/*RXD0*/     
	 
	 /*
	 (4)????UART???
	 */
	 UART_EnableInt(UART0);
	 IRQ_SET_PRIORITY(IRQ_UART0,IRQ_PRIORITY_HIGH);
	 IRQ_ALL_ENABLE();
	 
}



/*************************************************************************
 	*
	*Function Name: uint8_t BCC(uint8_t *sbytes,uint8_t width)
	*Function : BCC checksum code
	*Input Ref: 
	*Output Ref:No
	*
******************************************************************************/
uint8_t BCC(void)
{
     uint8_t sbytes[1],tembyte;
	 sbytes[0]=0xAA;


      tembyte =  sbytes[0]^ bufRxd[0]^bufRxd[1];
    
    return tembyte;

}


