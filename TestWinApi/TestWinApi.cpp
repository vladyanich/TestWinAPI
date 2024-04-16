#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <malloc.h>

#include <tchar.h>
#include <strsafe.h>

#define OPTION_GEN_COUNT 1
#define OPTION_GEN_ADD 2
#define OPTION_GEN_SETUP_N 3
#define OPTION_GEN_TIMER_SET 4
#define OPTION_GEN_SUM 5
#define EXIT_PROGRAM 6
#define MAX_START_GEN 3 
#define BUF_SIZE 10



typedef struct Generator 
{
	int N;
	struct Generator* next;
} Generator_t;

Generator_t *push_node(Generator_t* topNode, int newData)  
{
	Generator_t *ptr = (Generator_t*)malloc(sizeof(Generator_t));
	if (ptr != NULL)
	{
		ptr->N = newData;
		ptr->next = topNode;
		return ptr;
	}
}
void show_all_gens(const Generator_t *topNode)
{
	int count = 1;
	const Generator_t* currentNode = topNode;
	while (currentNode != NULL)
	{
		printf("\n%d. N = %d",count, currentNode->N);
		currentNode = currentNode->next;
		count++;
	}
}

int show_generators_count(const Generator_t* topNode)  
{
	int count = 1;
	const Generator_t* currentNode = topNode;
	while (currentNode != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode != NULL)
		{
			count++;
		}
	}
	return count;
}
const Generator_t* get_nth_generator(const Generator_t *topNode, int n)
{
	int count = 1;
	const Generator_t* currentNode = topNode;
	while (count <= n)
	{
		currentNode = currentNode->next;
		count++;
	}
	return currentNode;
}


/*Generator_t *push_node(Generator_t *topNode, int newNumber,  int newMaxRange)
{
	Generator_t *ptr = (Generator_t*)malloc(sizeof(Generator_t));
	ptr->number = newNumber;
	ptr->maxRange = newMaxRange;
	ptr->randData = rand() % newMaxRange;
	ptr->next = topNode;
	return ptr;
}

void show_generators_count(const Generator_t* topNode)  //показать список 
{
	int countGen = 0;
	const Generator_t* currentNode = topNode;
	while (currentNode != NULL)
	{
		printf("\"%s\"", currentNode->number);
		currentNode = currentNode->next;
		countGen++;
	}
	printf("Generators count %d", countGen);
}
*/
int main()
{
	Generator_t *topNode = NULL;

	setlocale(LC_ALL, "Russian");

	char buffer[BUF_SIZE];
	int number = 0;
	
	for (int i = 1; i <= MAX_START_GEN; i++)
	{
		topNode = push_node(topNode, i * 10);
	}

	/*for (int i = 0; i <= MAX_START_THREAD; i++)
	{
		pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(MYDATA));
		if (pDataArray[i] == NULL)
		{
			printf("\nОшибка выделения памяти");
		}
		pDataArray[i]->number = i;
		pDataArray[i]->maxRange = i * 10;
		pDataArray[i]->randData = rand() % 10;

		hThreadArray[i] = CreateThread(NULL, 0, MyThreadFunction, pDataArray[i], 0, &dwThreadIdArray[i]);

	}

	WaitForMultipleObjects(MAX_START_THREAD, hThreadArray, TRUE, INFINITE);

	// Close all thread handles and free memory allocations.

	for (int i = 0; i < MAX_START_THREAD; i++)
	{
		CloseHandle(hThreadArray[i]);
		if (pDataArray[i] != NULL)
		{
			HeapFree(GetProcessHeap(), 0, pDataArray[i]);
			pDataArray[i] = NULL;    // Ensure address is not reused.
		}
	}

	*/
	while (number != EXIT_PROGRAM)
	{
		printf("\n1. Количество генераторов\n");
		printf("2. Добавить генератор\n");
		printf("3. Задать N на конкртеном генераторе\n");
		printf("4. Показать все генераторы и их N\n");  //printf("4. Задать период опроса генераторов\n");
		printf("5. Узнать сумму значений, выданных всеми генератораим\n");
		printf("6. Выход\n");

		fgets(buffer, sizeof(buffer), stdin);
		number = atoi(buffer);

		switch (number)
		{
		case OPTION_GEN_COUNT:
			{
			printf("Generators count: %d", show_generators_count(topNode));
			show_all_gens(topNode);
			}
			break;
		case OPTION_GEN_ADD:
			{
				printf("\nЗадайте N = ");
				fgets(buffer, BUF_SIZE, stdin);
				number = atoi(buffer);
				topNode = push_node(topNode, number);
			}
			break;
		case OPTION_GEN_SETUP_N:
			{
			int r = rand() % 30;
			printf("rand num = %d", r);
			}
			break;
		case OPTION_GEN_TIMER_SET:
			{
				
			}
			break;
		case OPTION_GEN_SUM:
			{
		
			}
			break;
		}
	}



	return 0;
}
