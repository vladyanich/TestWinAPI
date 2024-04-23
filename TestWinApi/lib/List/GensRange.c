
#include "GensRange.h"
#include "Windows.h"

Generator_t* push_node(Generator_t* topNode, int newData)
{
	Generator_t* ptr = (Generator_t*)malloc(sizeof(Generator_t));
	if (ptr != NULL)
	{
		ptr->N = newData;
		ptr->next = topNode;
		return ptr;
	}
	else
	{
		printf("Can't create pointer");
	}
}

void show_all_gens(const Generator_t* topNode)
{
	int count = 1;
	const Generator_t* currentNode = topNode;
	while (currentNode != NULL)
	{
		printf("\n%d. N = %d", count, currentNode->N);
		currentNode = currentNode->next;
		count++;
	}
}

int generators_count(const Generator_t* topNode)
{
	int count = 0;
	const Generator_t* currentNode = topNode;
	while (currentNode != NULL)
	{
		if (currentNode != NULL)
		{
			count++;
			currentNode = currentNode->next;
		}
	}
	return count;
}

void setup_n_generator(Generator_t* topNode, int number, int value)
{
	int i = 0;
	Generator_t* currentNode = topNode;
	while (i < number && currentNode->next)
	{
		currentNode = currentNode->next;
		i++;
	}
	currentNode->N = value;
}

void set_global_generators_parametrs(const Generator_t* topNode) //установить параметры в volatile переменные
{
	const Generator_t* currentNode = topNode;
	int nodeCount = 0;
	int array[20];
	while (currentNode != NULL)
	{
		if (currentNode != NULL)
		{
			array[nodeCount] = currentNode->N;
			nodeCount++;
			currentNode = currentNode->next;
		}
	}
	memcpy(globalArrayN, array, 60);
	gensCount = nodeCount;
}
