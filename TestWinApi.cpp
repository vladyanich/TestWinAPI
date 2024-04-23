#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <malloc.h>
extern "C" 
{
	#include "lib/List/GensRange.h"
	#include "lib/Thread/Thread.h"
}

#define OPTION_GEN_COUNT 1
#define OPTION_GEN_ADD 2
#define OPTION_GEN_SETUP_N 3
#define OPTION_GEN_TIMER_SET 4
#define OPTION_GEN_SUM 5
#define EXIT_PROGRAM 6
#define MAX_START_GEN 3 
#define BUF_SIZE 10

volatile int TIME = 3000;
volatile bool flagAltThread = TRUE;
/*
volatile int* globalArrayN[20];
volatile int gensCount = 0;

typedef struct Generator
{
	int N;
	struct Generator* next;
} Generator_t;

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

int get_sum()
{
	int tempArray[20];
	int sum = 0;
	memcpy(tempArray, globalArrayN, 20);
	for (int i = 0; i < gensCount; i++)
	{
		sum += rand() % tempArray[i];
	}
	return sum;
}
/*
DWORD WINAPI ThreadFunc(void* data)
{
	int randSum = 0;

	while (true)
	{
		if (flagAltThread)
		{
			system("cls");
			randSum = get_sum();
			for (int i = 0; i < gensCount; i++)  //test
			{
				printf("arr[%d] = %d  ", i, globalArrayN[i]);
			}
			printf("\nGenerators count: %d\n", gensCount);//test
			printf("\nRandom = %d\n", randSum);
			printf("\n1. Generators count\n");
			printf("2. Add generator\n");
			printf("3. Set N on generator\n");// not work
			printf("4. Set time of calculation\n");
			printf("5. Show sum generators\n");
			printf("6. Exit\n");
			Sleep(TIME);
		}
		else
		{
			Sleep(1000);
		}
	}
	return 0;
}
*/
int main()
{
	Generator_t* topNode = NULL;
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	char buffer[BUF_SIZE];
	int number = 0;
	int nValue = 0;

	for (int i = 1; i <= MAX_START_GEN; i++)
	{
		topNode = push_node(topNode, i * 10);
	}

	set_global_generators_parametrs(topNode);

	while (number != EXIT_PROGRAM)
	{
		gensCount = generators_count(topNode);

		fgets(buffer, sizeof(buffer), stdin);
		number = atoi(buffer);

		switch (number)
		{
		case OPTION_GEN_COUNT:
		{
			printf("\nGenerators count: %d", gensCount);
			//show_all_gens(topNode);  //test
			//printf("\nCurrent thread: %d", GetCurrentThreadId()); //test
		}
		break;
		case OPTION_GEN_ADD:
		{
			flagAltThread = FALSE;

			printf("\nSet value N = ");
			fgets(buffer, BUF_SIZE, stdin);
			number = atoi(buffer);
			topNode = push_node(topNode, number);
			
			set_global_generators_parametrs(topNode);
			
			flagAltThread = TRUE;
		}
		break;
		case OPTION_GEN_SETUP_N:
		{
			flagAltThread = FALSE;
			
			printf("\nSet the generator number:");
			fgets(buffer, sizeof(buffer), stdin);
			number = atoi(buffer);

			printf("\nEnter value of N:");
			fgets(buffer, sizeof(buffer), stdin);
			nValue = atoi(buffer);

			setup_n_generator(topNode, number, nValue);
			set_global_generators_parametrs(topNode);
			
			flagAltThread = TRUE;
		}
		break;
		case OPTION_GEN_TIMER_SET:
		{
			flagAltThread = FALSE;
			
			printf("\nSet new timer: ");
			fgets(buffer, sizeof(buffer), stdin);
			TIME = atoi(buffer);
			
			flagAltThread = TRUE;
		}
		break;
		case OPTION_GEN_SUM:
		{
			printf("Sum = %d\n", get_sum());

		}
		break;
		}
	}
	return 0;
}