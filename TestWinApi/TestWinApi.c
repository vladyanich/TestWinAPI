#include "Windows.h"
#include "stdlib.h"
#include "stdio.h" 
#include "string.h"
#include "malloc.h"
#include "lib/List/GensRange.h"
#include "lib/Thread/Thread.h"


#define _CRT_SECURE_NO_WARNINGS

#define OPTION_GEN_COUNT 1
#define OPTION_GEN_ADD 2
#define OPTION_GEN_SETUP_N 3
#define OPTION_GEN_TIMER_SET 4
#define OPTION_GEN_SUM 5
#define EXIT_PROGRAM 6
#define MAX_START_GEN 3 
#define BUF_SIZE 10

//volatile int TIME = 3000;
volatile bool flagAltThread = TRUE;

volatile int* globalArrayN[20];
volatile int gensCount = 0;

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