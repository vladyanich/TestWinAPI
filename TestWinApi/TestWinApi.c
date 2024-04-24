#include "Windows.h"
#include "stdlib.h"
#include "stdio.h" 
#include "string.h"
#include "malloc.h"
#include "lib/List/gensRange.h"
#include "lib/Thread/Thread.h"

#define MAIN_OPTION_GEN_COUNT 1
#define MAIN_OPTION_GEN_ADD 2
#define MAIN_OPTION_GEN_SETUP_N 3
#define MAIN_OPTION_GEN_TIMER_SET 4
#define MAIN_OPTION_GEN_SUM 5
#define MAIN_EXIT_PROGRAM 6
#define MAIN_MAX_START_GEN 3 
#define MAIN_BUF_SIZE 10

int main()
{
	Generator_t* topGenerator = NULL;

	char buffer[MAIN_BUF_SIZE];
	int number = 0;
	int nValue = 0;
	int sum = 0;

	for (int i = 1; i <= MAIN_MAX_START_GEN; i++)
	{
		topGenerator = generator_add(topGenerator, i * 10);
	}

	HANDLE thread = CreateThread(NULL, 0, thread_task_handler, topGenerator, 0, NULL);

	while (number != MAIN_EXIT_PROGRAM)
	{

		system("cls");
		printf("\n1. Generators count\n");
		printf("2. Add generator\n");
		printf("3. Set N on generator\n");
		printf("4. Set time of calculation\n");
		printf("5. Show sum generators\n");
		printf("6. Exit\n");

		fgets(buffer, sizeof(buffer), stdin);
		number = atoi(buffer);

		switch (number)
		{
			case MAIN_OPTION_GEN_COUNT:
			{
				printf("\nGenerators count: %d", generators_count(topGenerator));
			}
			break;
			case MAIN_OPTION_GEN_ADD:
			{
				printf("\nSet value N = ");
				fgets(buffer, MAIN_BUF_SIZE, stdin);
				number = atoi(buffer);
				topGenerator = generator_add(topGenerator, number);
			}
			break;
			case MAIN_OPTION_GEN_SETUP_N:
			{
				printf("\nSet the generator number:");
				fgets(buffer, sizeof(buffer), stdin);
				number = atoi(buffer);
				printf("\nEnter value of N:");
				fgets(buffer, sizeof(buffer), stdin);
				nValue = atoi(buffer);
				generator_setup_n(topGenerator, number, nValue);
			}
			break;
			case MAIN_OPTION_GEN_TIMER_SET:
			{
				printf("\nSet new timer: ");
				fgets(buffer, sizeof(buffer), stdin);
				sleepDelay = atoi(buffer);
			}
			break;
			case MAIN_OPTION_GEN_SUM:
			{
				printf("\nRand sum = %d", thread_random_sum_value);
			}
			break;
			
		}
		Sleep(1000);
	}
	return 0;
}