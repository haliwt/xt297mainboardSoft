
#include "cms8s6990.h"
#include "demo_buzzer.h"
#include "touchkey.h"
#include "cnrelay.h"


uint32_t Systemclock = 24000000;
struct _KEY_  hdkey;




int main(void)
{		
    CONT_Motor_Init();
	HDKEY_Config();

	while(1)
	{	

		if(hdkey.P25KEY == 1){
			hdkey.P25KEY =0;
			BUZZER_Config();
			


		}
		if(hdkey.P26KEY ==1){
			hdkey.P26KEY = 0;

		    BUZ_DisableBuzzer();	


		}
		
	}		
}






















