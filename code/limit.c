#include "limit.h"





void LimitSwitch_One_Init(void)
{
    /*
	(1)设置P23 IO功能
	*/
	GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_GPIO);		//设置P25为GPIO模式
	GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_3);			//设置为输入模式
	GPIO_ENABLE_UP(P2UP, GPIO_PIN_3);				//开启下拉

	/*
	(2)设置中断方式
	*/
	//GPIO_SET_INT_MODE(P23EICFG, GPIO_INT_RISING);	//设置为下降沿中断模式
	//GPIO_EnableInt(GPIO2, GPIO_PIN_3_MSK);			//开启P26中断

	
	/*
	(3)设置中断优先级
	*/
	//IRQ_SET_PRIORITY(IRQ_P2, IRQ_PRIORITY_LOW);
	/*
	(4)开启总中断
	*/	
	//IRQ_ALL_ENABLE();



}