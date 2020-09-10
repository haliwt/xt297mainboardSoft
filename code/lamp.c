#include "lamp.h"

void LAMP_Init(void)
{
    GPIO_SET_MUX_MODE(P16CFG, GPIO_MUX_GPIO);		// move motor
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_6);			//???????
	P16 = 0 ;      

}