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


volatile int TIME = 3000;

volatile int gensCount = 0;

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

void setup_n_generator(const Generator_t *topNode, int number, int value)
{
	int i = 0;
	const Generator_t* currentNode = topNode;
	while (i < number && currentNode->next)
	{
		currentNode = currentNode->next;
		i++;
	}
}

int get_sum(const Generator_t *topNode)  // расчет по входу из односвязного списка  
{
	int sum = 0;
	int randomNum = 0; //test
	const Generator_t* currentNode = topNode;
	while (currentNode != NULL)
	{
		if (currentNode != NULL)
		{
			randomNum = currentNode->N;  //test
			randomNum = rand() % currentNode->N;
			sum += randomNum;
			printf("\nRandom number = %d", randomNum); //test
		}
		currentNode = currentNode->next;
	}
	printf("\nsumRand = %d\n", sum); //test
	return sum;
}


int get_N_gens_in_array(const Generator_t *topNode)
{
	const Generator_t *currentNode = topNode;
	int i = 0;
	int array[20];
	while (currentNode != NULL)
	{
		if(currentNode != NULL)
		{ 
			array[i] = currentNode->N;
			i++;
		}
	}
	return array[20];
}

DWORD WINAPI ThreadFunc(LPVOID data)
{
	int randSum = 0;
	//randSum = get_sum(gensCount);
	while (true)
	{
		//memcpy(string, i, 10);
		//temp[i] = string[i];
		//MessageBoxA(0, (LPCSTR)temp, "Some Title", MB_ICONERROR | MB_OK);
		//i++;

		printf("\nRandom = %d\n", randSum);
		printf("\n1. Generators count\n");
		printf("2. Add generator\n");
		printf("3. Set N on generator\n");
		printf("4. Set time of calculation\n");
		printf("5. Show sum generators\n");
		printf("6. Exit\n");
		Sleep(TIME);
		system("cls");
	}
	return 0;
}

int main()
{
	Generator_t *topNode = NULL;

	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	setlocale(LC_ALL, "Russian");

	char buffer[BUF_SIZE];
	int number = 0;
	int arrayN[20];

	for (int i = 1; i <= MAX_START_GEN; i++)
	{
		topNode = push_node(topNode, i * 10);
	}

	while (number != EXIT_PROGRAM)
	{
	
		gensCount = generators_count(topNode);

		fgets(buffer, sizeof(buffer), stdin);
		number = atoi(buffer);
		
		//arrayN[20] = get_N_gens_in_array(topNode);

		switch (number)
		{
		case OPTION_GEN_COUNT:
			{
			printf("Generators count: %d", gensCount);
			//show_all_gens(topNode);
			}
			break;
		case OPTION_GEN_ADD:
			{
				printf("\nSet value N = ");
				fgets(buffer, BUF_SIZE, stdin);
				number = atoi(buffer);
				topNode = push_node(topNode, number);
			}
			break;
		case OPTION_GEN_SETUP_N:
			{
			for (int i = 0; i <= 20; i++)
				{
				printf("\narrayN[%d] = %d", i, arrayN[i]);
				}
			}
			break;
		case OPTION_GEN_TIMER_SET:
			{
				fgets(buffer, sizeof(buffer), stdin);
				TIME = atoi(buffer);
				//show_all_gens(topNode); //test 
			}
			break;
		case OPTION_GEN_SUM:
			{
				//get_sum(gensCount);
				get_sum(topNode);//test
			}
			break;
		}
	}
	return 0;
}
