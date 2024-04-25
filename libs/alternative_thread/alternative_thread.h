#ifndef __Thread_H__
#define __Thread_H__

#include "stdbool.h"
#include "gens_range/gens_range.h"

extern volatile int sleepDelay;

extern volatile int thread_random_sum_value;

extern CRITICAL_SECTION criticalSection;

int thread_get_sum(const Generator_t* topNode);

DWORD WINAPI thread_task_handler(const Generator_t* topNode);

#endif