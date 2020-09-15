#ifndef __TOUCHKEY_H__
#define __TOUCHKEY_H__
#include "cms8s6990.h"

void HDKEY_Config(void);

#define PD_25      P25 //DATA.
#define PC_26      P26 //Contorl  RB3

#define HDP25KEY_PRES     1
#define HDP26KEY_PRES      2



extern uint8_t exeOrder;

extern uint8_t TimerStart;

void delay_ms(uint16_t t);
uint8_t KEY_HDScan(void);


#endif 