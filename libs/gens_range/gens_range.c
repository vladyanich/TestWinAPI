
#include "gens_range.h"
#include "Windows.h"

bool generator_create(Generator_t** topGenerator, int newData)
{
	Generator_t* temp = (Generator_t*)malloc(sizeof(Generator_t));

	if (temp != NULL)
	{
	
		temp->N = newData;
		temp->next = *topGenerator;
		*topGenerator = temp;

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
		count++;
		topGenerator = topGenerator->next;
	}

	return count;
}

void generator_setup_n(Generator_t* topGenerator, int number, int newN) // ne rabotaet
{
	int i = 0;
	Generator_t *temp = NULL;
	while (i < number && topGenerator->next)
	{
		topGenerator = topGenerator->next;
		i++;
	}
	temp = (Generator_t*)malloc(sizeof(Generator_t));
	temp->N = newN;
	if (topGenerator->next)
	{
		temp->next = NULL;
	}
	topGenerator->next = temp;
}