#ifndef __Thread_H__
#define __Thread_H__

#include "stdbool.h"
#include "../lib/List/gensRange.h"

extern volatile int sleepDelay;

extern volatile int thread_random_sum_value;

int thread_get_sum(const Generator_t* topNode);

DWORD WINAPI thread_task_handler(const Generator_t* topNode);

#endif