#include "Windows.h"
#include "alternative_thread.h"
#include "gens_range/gens_range.h"

volatile int sleepDelay = 3000;

DWORD WINAPI thread_task_handler(const Generator_t* topNode)
{
	while (true)
	{ 
		EnterCriticalSection(&criticalSection);
		generatorsRandomSumValue = generators_get_sum(topNode);
		LeaveCriticalSection(&criticalSection);
		Sleep(sleepDelay);
	}
	return 0;
}