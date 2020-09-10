
#include "cms8s6990.h"
#include "demo_buzzer.h"
#include "touchkey.h"
#include "cnrelay.h"
#include "lamp.h"
#include "limit.h"


uint32_t Systemclock = 24000000;
struct _KEY_  hdkey;




int main(void)
{		
    uint8_t keyflg=0,dirflg=0;
	CONT_Motor_Init();
	HDKEY_Config();
	LimitSwitch_One_Init(); //中断
	LAMP_Init();

	while(1)
	{	
       keyflg = KEY_HDScan(0);
	   switch(keyflg){
		   
		   case 1 :
			 
			BUZZER_Config();
		    delay_ms(500);
		    BUZ_DisableBuzzer();
			
		    dirflg= dirflg ^ 0x01;

		   if(dirflg ==1){ //up move
			   CONMOTOR_1 =1;
			   CONMOTOR_2=0; 
		   }
		   else{ //down move
			if(LIMIT_ONE == 0){ //限位开关，ONE
				CONMOTOR_1 =0;
		        CONMOTOR_2 =0;
				LAMP = 0;
			}
			else 
		    {
				CONMOTOR_1 =0;  //N15  控制电机旋转方向
				CONMOTOR_2 =1;  //N16    ----电机向下移动
				LAMP = 1;
		    }
		   }
		
			
		    
			break;

		   case 2:
		    
	        BUZZER_Config();
		    delay_ms(500);
		    BUZ_DisableBuzzer();
			CONMOTOR_1 =0;
		    CONMOTOR_2 =0; //电机向上移动
			LAMP = 0;

		   break;
		
	}		
}
}
	





















