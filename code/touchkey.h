#ifndef __TOUCHKEY_H__
#define __TOUCHKEY_H__
#include "cms8s6990.h"

void HDKEY_Config(void);

#define HDP25KEY      1 
#define HDP26KEY      2

struct _KEY_
{
   uint8_t P25KEY : 1;
   uint8_t P26KEY: 1;


};

extern struct _KEY_  hdkey;



#endif 