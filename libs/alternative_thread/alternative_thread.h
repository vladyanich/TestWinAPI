#ifndef __Thread_H__
#define __Thread_H__

#include "stdbool.h"
#include "gens_range/gens_range.h"

extern volatile int sleepDelay;

extern volatile int GeneratorsRandomSumValue;

extern CRITICAL_SECTION criticalSection;

DWORD WINAPI thread_task_handler(const Generator_t* topNode);

#endif