#include "ac_relay.h"

void AC_Relay_Init(void)
{
   
    GPIO_SET_MUX_MODE(P15CFG, GPIO_MUX_GPIO);		// AC control relay //P7
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_5);			//???????
	P15 = 0 ;
	
	GPIO_SET_MUX_MODE(P14CFG, GPIO_MUX_GPIO);		//move motor   //P8
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_4);			//???????
	P14 = 0;

	GPIO_SET_MUX_MODE(P13CFG, GPIO_MUX_GPIO);		//move motor   //P9
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_3);			//???????
	P13 = 0;

	GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_GPIO);		//move motor   //P10
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_4);			//???????
	P04 = 0;


}