
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
struct _KEY_  hdkey;
 extern uint8_t Number;

uint8_t ReceOverflg;

int main(void)
{		
   static uint8_t lampflg,dirflg,ud,run=0;
   static uint16_t count;
   uint8_t order =0;
	CONT_Motor_Init();
	HDKEY_Config();
	LimitSwitch_One_Init(); //中断
	LAMP_Init();
	AC_Relay_Init();
	HDKEY_Config();
    TMR2_Config();
	

	while(1)
	{	
          
		  
	
	if(Number / 2 == 1 && Number !=0 && Number !=1 && Number !=3 && Number !=5) {
			  
			Number =0;
			   BUZZER_Config();
				delay_ms(400);
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
	   if(Number / 1== 1 && Number !=0 && Number !=2 && Number !=3 && Number !=5){  
		    
		       Number =0;
			   BUZZER_Config();
				delay_ms(400);
				BUZ_DisableBuzzer();
				lampflg = lampflg ^0x01;
				if(lampflg ==1)
				  LAMP = 1;
				else LAMP = 0;
				
				 
		}
		if(Number / 3 ==1  && Number !=0 && Number !=1 && Number !=2 && Number !=5)//wind_key 风机按键
	  {
	           TimerStart =1;
		        Number =0;
		        BUZZER_Config();
				delay_ms(400);
				BUZ_DisableBuzzer();
	  
	  }
	  if(Number / 5 ==1  && Number !=0 && Number !=1 && Number !=3 && Number !=2) //Timer _key
	  {
	        TimerStart =1;
		    Number =0;
		    BUZZER_Config();
				delay_ms(400);
				BUZ_DisableBuzzer();
	  
	  }
	
	
	#endif 	
			  
		  
	
        
			 
		 #if 0
	   #if AC_MOTOR_RUN
		    	
			  AC_P15=1; //Turn On ---AC POWER ON
				AC_P14=1; //red line
					 AC_P04=0; //black line 
		    AC_P13 = 1;
		   
		   #endif 
		    
			
		    
	        BUZZER_Config();
		    delay_ms(500);
		    BUZ_DisableBuzzer();
			CONMOTOR_1 =0;
		    CONMOTOR_2 =0; //电机向上移动
			LAMP = 0;
			
			AC_P15 =0; //AC Power OF
					AC_P14=0; //红色线 
						AC_P04 = 1; //黑色线   //红色和黑色限不能同时 道通
			AC_P13 =0;
		   #endif

		  #endif 
		
			
	}

}
	





















