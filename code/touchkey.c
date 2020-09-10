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
	GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_GPIO);		//设置P25为GPIO模式
	GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_5);			//设置为输入模式
	GPIO_ENABLE_UP(P2UP, GPIO_PIN_5);				//开启下拉


	GPIO_SET_MUX_MODE(P26CFG, GPIO_MUX_GPIO);		//设置P26为GPIO模式
	GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_6);			//设置为输入模式
	GPIO_ENABLE_UP(P2UP, GPIO_PIN_6);				//开启下拉
	/*
	(2)设置中断方式
	*/
	//GPIO_SET_INT_MODE(P26EICFG, GPIO_INT_RISING);	//设置为下降沿中断模式
	//GPIO_EnableInt(GPIO2, GPIO_PIN_6_MSK);			//开启P26中断

	//GPIO_SET_INT_MODE(P25EICFG, GPIO_INT_RISING);	//设置为下降沿中断模式
	//GPIO_EnableInt(GPIO2, GPIO_PIN_5_MSK);			//开启P25中断
	/*
	(3)设置中断优先级
	*/
	//IRQ_SET_PRIORITY(IRQ_P2, IRQ_PRIORITY_LOW);
	/*
	(4)开启总中断
	*/	
	//IRQ_ALL_ENABLE();



}

uint8_t KEY_HDScan(uint8_t mode)
{
    
	static uint8_t key_up=1;     //°´¼üËÉ¿ª±êÖ¾
    if(mode==1)key_up=1;    // 支持连续按键
    if(key_up&&(HDP25KEY==0 || HDP26KEY==0))
    {
       
        key_up =0 ;
		delay_ms(20);
	
	 if(HDP25KEY==0)            return HDP25KEY_PRES;
       else if(HDP26KEY==0)    return HDP26KEY_PRES;
      
		
    }else if(HDP25KEY==1&&HDP26KEY==1)key_up=1;
    return 0;   //没有按键按下
}