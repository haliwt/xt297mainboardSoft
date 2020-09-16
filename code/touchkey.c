#include "touchkey.h"

void delay_ms(uint16_t t)
{
	 uint16_t i=0,j;  
    for(i=0;i<t;i++) {
		
		for(j=0;j<100;j++){
		  _nop_(); 
		  _nop_(); 
		  _nop_(); 
		  _nop_(); 
		  _nop_(); 
		  _nop_(); 
		  _nop_(); 
		  _nop_();
           _nop_(); 
		  _nop_();
		}			
		  		
		  
} 

}
void HDKEY_Config(void)
{

	/*
	(1)设置P23 IO功能
	*/
	GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_GPIO);		//设置P25为GPIO模式 DATA
	GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_5);			//设置为输入模式
	GPIO_ENABLE_RD(P2RD, GPIO_PIN_5);				//开启下拉


	GPIO_SET_MUX_MODE(P26CFG, GPIO_MUX_GPIO);		//设置P26为GPIO模式 CONTROL
	GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_6);			//设置为输入模式
	GPIO_ENABLE_RD(P2RD, GPIO_PIN_6);				//开启下拉
	/*
	(2)设置中断方式
	*/
	//GPIO_SET_INT_MODE(P26EICFG, GPIO_INT_RISING);	//设置为下降沿中断模式
	GPIO_EnableInt(GPIO2, GPIO_PIN_6_MSK);			//开启P26中断

//	GPIO_SET_INT_MODE(P25EICFG, GPIO_INT_RISING);	//设置为下降沿中断模式
//	GPIO_EnableInt(GPIO2, GPIO_PIN_5_MSK);			//开启P25中断
	/*
	(3)设置中断优先级
	*/
//	IRQ_SET_PRIORITY(IRQ_P2, IRQ_PRIORITY_LOW);
	/*
	(4)开启总中断
	*/	
//	IRQ_ALL_ENABLE();



}

