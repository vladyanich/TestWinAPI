#ifndef __Thread_H__
#define __Thread_H__

#include "stdbool.h"

extern volatile int TIME;

extern volatile bool flagAltThread;

extern volatile int* globalArrayN[20];

extern volatile int gensCount;

extern int randSum;

int get_sum();

DWORD WINAPI ThreadFunc(void* data);

#endif