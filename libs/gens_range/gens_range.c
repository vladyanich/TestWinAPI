
#include "gens_range.h"
#include "Windows.h"

volatile int resultGensCount = 0;

volatile int generatorsRandomSumValue = 0;

CRITICAL_SECTION criticalSection;

void gens_range_init_critical_section()
{
	InitializeCriticalSection(&criticalSection);
}

bool generator_create(Generator_t** topGenerator, int newData)
{
	Generator_t* temp = (Generator_t*)malloc(sizeof(Generator_t));
	
	if (temp != NULL)
	{
		temp->N = newData;
		temp->next = *topGenerator;
		EnterCriticalSection(&criticalSection);
		*topGenerator = temp;
		LeaveCriticalSection(&criticalSection);

		resultGensCount++;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int generators_count(const Generator_t* topGenerator)
{	
	return resultGensCount;
}

void generator_setup_n(Generator_t* topGenerator, int number, int newN)
{
	int count = 0;
	EnterCriticalSection(&criticalSection);
	while (count < number && topGenerator->next)
	{
		topGenerator = topGenerator->next;
		count++;
	}
	topGenerator->N = newN;
	LeaveCriticalSection(&criticalSection);
}

volatile int threadRandomSumValue = 0;

int generators_get_sum(const Generator_t* topGenerator)
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