#include "cnrelay.h"


void CONT_Motor_Init(void)
{

    GPIO_SET_MUX_MODE(P31CFG, GPIO_MUX_GPIO);		// move motor
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_1);			//???????
	P31 = 0 ;
	
	GPIO_SET_MUX_MODE(P32CFG, GPIO_MUX_GPIO);		//move motor 
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_2);			//???????
	P32 = 0;
}