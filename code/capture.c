#include "capture.h"

void TMR2_Config(void)
{
	/*
	(1)??Timer?????
	*/
	TMR2_ConfigRunMode(TMR2_MODE_TIMING, TMR2_LOAD_DISBALE);
	TMR2_EnableCapture(TMR2_CC0, TMR2_CAP_EDGE_FALLING);
	TMR2_EnableCapture(TMR2_CC1, TMR2_CAP_EDGE_FALLING);	
	TMR2_EnableCapture(TMR2_CC2, TMR2_CAP_EDGE_FALLING);	
	TMR2_EnableCapture(TMR2_CC3, TMR2_CAP_EDGE_FALLING);	
		
	/*
	(2)??Timer ????
	*/
	TMR2_ConfigTimerClk( TMR2_CLK_DIV_12);						/*Fsys = 24Mhz,Ftimer = 2Mhz,Ttmr=0.5us*/
	/*
	(3)??Timer??
	*/	
	TMR2_ConfigTimerPeriod((65536 - 20000)); 			//10ms
	// TMR2_ConfigTimerPeriod((65536 - 40000)); 			//20ms	
	/*
	(5)????
	*/
	TMR2_EnableOverflowInt();
	TMR2_EnableCaptureInt(TMR2_CC0);
	TMR2_EnableCaptureInt(TMR2_CC1);	
	TMR2_EnableCaptureInt(TMR2_CC2);	
	TMR2_EnableCaptureInt(TMR2_CC3);	
	
	/*
	(6)??Timer?????
	*/	
	IRQ_SET_PRIORITY(IRQ_TMR2,IRQ_PRIORITY_LOW);
	
	TMR2_AllIntEnable();
	IRQ_ALL_ENABLE();	
	
	/*
	(7)??Timer??
	*/	
    #if 0
	GPIO_SET_MUX_MODE(P00CFG, GPIO_MUX_GPIO);
	GPIO_SET_PS_MODE(PS_CAP0, GPIO_P00);				/*????0??*/
	GPIO_ENABLE_RD(P0RD, GPIO_PIN_0);					/*???*/	
	
	GPIO_SET_MUX_MODE(P01CFG, GPIO_MUX_GPIO);
	GPIO_SET_PS_MODE(PS_CAP1, GPIO_P01);				/*????0??*/
	GPIO_ENABLE_RD(P0RD, GPIO_PIN_1);					/*???*/		
	
	GPIO_SET_MUX_MODE(P02CFG, GPIO_MUX_GPIO);
	GPIO_SET_PS_MODE(PS_CAP2, GPIO_P02);				/*????0??*/
	GPIO_ENABLE_RD(P0RD, GPIO_PIN_2);					/*???*/		
	
	GPIO_SET_MUX_MODE(P03CFG, GPIO_MUX_GPIO);
	GPIO_SET_PS_MODE(PS_CAP3, GPIO_P03);				/*????0??*/
	GPIO_ENABLE_RD(P0RD, GPIO_PIN_3);					/*???*/
    #endif 
    
    GPIO_SET_MUX_MODE(P30CFG, GPIO_MUX_GPIO);
	GPIO_SET_PS_MODE(PS_CAP0, GPIO_P30);				/*????0??*/
	GPIO_ENABLE_RD(P3RD, GPIO_PIN_0);					/*???*/
	
	/*

	(8)??Timer
	*/
	TMR2_Start();

}




