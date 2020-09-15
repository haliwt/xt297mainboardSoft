
#include "cms8s6990.h"
#include "demo_buzzer.h"
#include "touchkey.h"
#include "cnrelay.h"
#include "lamp.h"
#include "limit.h"
#include "ac_relay.h"
#include "capture.h"

#define MOTOR_RUN    1
#define AC_MOTOR_RUN    0

uint32_t Systemclock = 24000000;

 extern uint8_t Number;

uint8_t ReceOverflg;

int main(void)
{		
   static uint8_t lampflg,dirflg,ACmotor=0;
   
   uint8_t order =0,event =0;
	CONT_Motor_Init();
	HDKEY_Config();
	LimitSwitch_One_Init(); //中断
	LAMP_Init();
	AC_Relay_Init();
	HDKEY_Config();
    TMR2_Config();
	

	while(1)
	{	
       event =0;   
	if(PC_26 ==1){
	
	if(Number == 2  && Number !=1 && Number !=3 && Number !=5 && event ==0) {
			  
			event =1;
			Number =0;
			   BUZZER_Config();
				delay_ms(300);
				BUZ_DisableBuzzer();
	       dirflg= dirflg ^ 0x01;
      
		   if(dirflg ==1 ){ //up move
			   
			   CONMOTOR_1 =1;
			   CONMOTOR_2=0; 
			}
		   else { //down move
		        CONMOTOR_1 =0;  //N15  控制电机旋转方向
				CONMOTOR_2 =1;  //N16    ----电机向下移动
				
		   }
		 
	      }
	 
	if(Number ==3  && Number !=1 && Number !=2 && Number !=5 && event ==0)//wind_key 风机按键
	 {
	            event =1;
				Number =0;
			   ACmotor =ACmotor ^ 0x01;
		       BUZZER_Config();
			  delay_ms(300);
			  BUZ_DisableBuzzer();
		     if(ACmotor ==0){
		       //交流流风机
		     
				AC_P15 = 0;
				AC_P13=0;
				AC_P04 =0;
				AC_P13=0;
			   }
			 else {
			   	 AC_P15=1; //Turn On ---AC POWER ON
			     AC_P14=1; //red line
			    AC_P04=0; //black line 低速 中速档位
		        AC_P13 = 1;//0--中风  1-小风

				
				
			 }
	  
	  }
	  if(Number == 5 && Number !=1 && Number !=3 && Number !=2 && event ==0) //Timer _key
	  {
	        event=1;
		    Number =0;
		    BUZZER_Config();
				delay_ms(300);
				BUZ_DisableBuzzer();
	  
	  }
	
	   if(Number == 1 && Number !=2 && Number !=3 && Number !=5 && event ==0){  
		    
		       event =1;
			   Number =0;
			   BUZZER_Config();
				delay_ms(300);
				BUZ_DisableBuzzer();
				lampflg = lampflg ^0x01;
				if(lampflg ==1)
				    LAMP = 1;
				else LAMP = 0;
				
				 
		}
	   }
	   else{

            if(Number <=3){ //风速一档
				Number =0;
				BUZZER_Config();
				delay_ms(300);
				BUZ_DisableBuzzer();
				AC_P15=1; //Turn On ---AC POWER ON
			     AC_P14=1; //red line
			    AC_P04=0; //black line 低速 中速档位
		        AC_P13 = 1;//0--中风  1-小风
			
			}
			if(Number > 3 && Number < 56){//风速二档
				Number=0;
				BUZZER_Config();
				delay_ms(300);
				BUZ_DisableBuzzer();

				AC_P15 =1; //AC Power On
				 AC_P14=1; //红色线 红色是高速
				    AC_P04 = 0; //黑色线   //红色和黑色限不能同时 道通
			     AC_P13 =0;
				//  AC_P15 = 1; //风速 中
				//AC_P13=0;
				//AC_P04 =0;
				//AC_P13=0;

			}
			if(Number >=56 ){//风速三档
				Number =0;
	            AC_P15 =1; //AC Power On
					AC_P14=0; //红色线 红色是高速
						AC_P04 = 1; //黑色线   //红色和黑色限不能同时 道通
			     AC_P13 =0;
				

			}

		}  
		  
	}

}
	





















