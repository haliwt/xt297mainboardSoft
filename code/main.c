
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
uint8_t windTurnOn ;

int main(void)
{		
   static uint8_t lampflg,dirflg,ACmotor=0;
   static uint16_t count ;
   uint8_t event =0;
	CONT_Motor_Init();
	HDKEY_Config();
	LimitSwitch_One_Init(); //中断
	LAMP_Init();
	AC_Relay_Init();
	HDKEY_Config();
    TMR2_Config();
	

	while(1)
	{	
          
	if(Number < 5){	  
	
	if(Number / 2 == 1 && Number !=0 && Number !=1 && Number !=3 && Number !=4) {
			  
			Number =0;
			   BUZZER_Config();
				delay_ms(200);
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
	   if(Number / 1== 1 && Number !=0 && Number !=2 && Number !=3 && Number !=4){  
		    
		       Number =0;
			   BUZZER_Config();
				delay_ms(200);
				BUZ_DisableBuzzer();
				lampflg = lampflg ^0x01;
				if(lampflg ==1){
				  LAMP = 1;
				  delay_ms(5000);
				}
				else {
					LAMP = 0;
					 delay_ms(5000);
				}
				
				 
		}
	if(Number / 3 ==1  && Number !=0 && Number !=1 && Number !=2 && Number !=4)//wind_key 风机按键
	 {
	            ACmotor =ACmotor ^ 0x01;
		        Number =0;
		        BUZZER_Config();
				delay_ms(200);
				BUZ_DisableBuzzer();
			 if(ReceOverflg==1)LAMP =1;
			 else LAMP =0;
		     if(ACmotor ==1){
		      //交流流风机
				windTurnOn =0;
		        AC_P15=1; //Turn On ---AC POWER ON
				AC_P14=1; //red line
			    AC_P04=0; //black line 低速
		        AC_P13 = 1;
			 }
			 else {
                 windTurnOn =1;
			    AC_P15 = 0;
				AC_P13=0;
				AC_P04 =0;
				AC_P13=0;
			 }
	  
	  }
	  if(Number / 4 ==1  && Number !=0 && Number !=1 && Number !=3 && Number !=2) //Timer _key
	  {
	        TimerStart =1;
		    Number =0;
			 if(ReceOverflg==1)LAMP =1;
			 else LAMP =0;
		    BUZZER_Config();
				delay_ms(200);
				BUZ_DisableBuzzer();
	  
	  }
	
	   if(Number == 1 && Number !=2 && Number !=3 && Number !=5 && event ==0){  //LAMP
		    
		       event =1;
			   Number =0;
			   BUZZER_Config();
				delay_ms(300);
				BUZ_DisableBuzzer();
				lampflg = lampflg ^0x01;
				if(lampflg ==1){
				    LAMP = 1;
					delay_ms(6000);
					ReceOverflg=1;
				}
				else {
					LAMP = 0;
					delay_ms(6000);
					ReceOverflg=0;
				}
			}
	   
	     }
		if(windTurnOn ==1){
			count ++ ;
			if(ReceOverflg==1)LAMP =1;
			else LAMP =0;
			if(count > 10000){
				count =0;
			if(Number > 4){
				/**wind level setup*/
				if(Number == 5 && Number !=6){ //风速一档
					Number =0;
					BUZZER_Config();
					delay_ms(200);
					BUZ_DisableBuzzer();
					if(ReceOverflg==1)LAMP =1;
			        else LAMP =0;
					AC_P15=1; //Turn On ---AC POWER ON
					AC_P14=1; //red line
					AC_P04=0; //black line 低速 中速档位
					AC_P13 = 1;//0--中风  1-小风
				
				}
				if(Number == 6 && Number !=5){//风速二档
					Number=0;
					BUZZER_Config();
					delay_ms(200);
					BUZ_DisableBuzzer();
					if(ReceOverflg==1)LAMP =1;
			        else LAMP =0;

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
	}

}
	





















