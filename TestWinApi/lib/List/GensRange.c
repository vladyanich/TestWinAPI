
#include "gensRange.h"
#include "Windows.h"

Generator_t* generator_add(Generator_t* topGenerator, int newData)
{
	Generator_t* ptr = (Generator_t*)malloc(sizeof(Generator_t));
	if (ptr != NULL)
	{
		ptr->N = newData;
		ptr->next = topGenerator;
		return ptr;
	}
	else
	{
		printf("Can't create pointer");
	}
}

int generators_count(const Generator_t* topGenerator)
{
	int count = 0;
	const Generator_t* currentGenerator = topGenerator;
	while (currentGenerator != NULL)
	{
		if (currentGenerator != NULL)
		{
			count++;
			currentGenerator = currentGenerator->next;
		}
	}
	return count;
}

void generator_setup_n(Generator_t* topGenerator, int number, int value)
{
	int i = 0;
	Generator_t* currentGenerator = topGenerator;
	while (i < number && currentGenerator->next)
	{
		currentGenerator = currentGenerator->next;
		i++;
	}
	currentGenerator->N = value;
}