

#include "count0.h"


/******************************************************************************
** \brief	 TMR0_Config
** \param [in] 
**            	
** \return  none
** \note  
******************************************************************************/
void TMR0_Count0(void)
{
	/*
	(1)设置Timer的运行模式
	*/
	TMR_ConfigRunMode(TMR0, TMR_MODE_COUNT,TMR_TIM_AUTO_8BIT);			//监测T0功能脚的下降沿
	//GPIO_SET_PS_MODE(PS_T0, GPIO_P23);
	//GPIO_ENABLE_UP(P2UP, GPIO_PIN_3);
	
	GPIO_SET_PS_MODE(PS_T0, GPIO_P25); //RB4---靠近电源线
	GPIO_ENABLE_UP(P2UP, GPIO_PIN_5);
			
	/*
	(2)设置Timer周期
	*/	
	TMR_ConfigTimerPeriod(TMR0, 256-1, 256-1); 				// 计数5次溢出
		
	/*
	(3)开启中断
	*/
	TMR_EnableOverflowInt(TMR0);

	/*
	(4)设置Timer中断优先级
	*/	
	IRQ_SET_PRIORITY(IRQ_TMR0,IRQ_PRIORITY_LOW);
	IRQ_ALL_ENABLE();	

	/*
	(5)开启Timer
	*/
	TMR_Start(TMR0);
}




























