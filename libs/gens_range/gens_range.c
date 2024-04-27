
#include "gens_range.h"
#include "Windows.h"

bool generator_create(Generator_t** topGenerator, int newData)
{
	Generator_t* temp = (Generator_t*)malloc(sizeof(Generator_t));
	
	if (temp != NULL)
	{
		EnterCriticalSection(&criticalSection);
		temp->N = newData;
		temp->next = *topGenerator;
		*topGenerator = temp;
		LeaveCriticalSection(&criticalSection);

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int generators_count(const Generator_t* topGenerator)
{
	int count = 0;
	while(topGenerator)
	{
		EnterCriticalSection(&criticalSection);
		printf("\n[%d]Gen N = %d", count, topGenerator->N);
		topGenerator = topGenerator->next;
		count++;
		LeaveCriticalSection(&criticalSection);
	}
	return count;
}

void generator_setup_n(Generator_t* topGenerator, int number, int newN) // ne rabotaet
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