#include "Windows.h"
#include "alternative_thread.h"
#include "gens_range/gens_range.h"

volatile int sleepDelay = 3000;

volatile int thread_random_sum_value = 0;

int thread_get_sum(const Generator_t* topGenerator)
{
	int sum = 0;
	const Generator_t* currentGenerator = topGenerator;
	while (currentGenerator != NULL)
	{
		if (currentGenerator != NULL)
		{
			sum += rand() % currentGenerator->N;
			currentGenerator = currentGenerator->next;
		}
	}
	return sum;
}

DWORD WINAPI thread_task_handler(const Generator_t* topNode)
{
	while (true)
	{ 
		EnterCriticalSection(&criticalSection);
		thread_random_sum_value = thread_get_sum(topNode);
		LeaveCriticalSection(&criticalSection);
		Sleep(sleepDelay);
	}
	return 0;
}