#ifndef __TOUCHKEY_H__
#define __TOUCHKEY_H__
#include "cms8s6990.h"

void HDKEY_Config(void);

#define HDP25KEY      P25 
#define HDP26KEY      P26

#define HDP25KEY_PRES     1
#define HDP26KEY_PRES      2

struct _KEY_
{
   uint8_t P25KEY : 1;
   uint8_t P26KEY: 1;


};

extern struct _KEY_  hdkey;

void delay_ms(uint16_t t);
uint8_t KEY_HDScan(uint8_t mode);


#endif 