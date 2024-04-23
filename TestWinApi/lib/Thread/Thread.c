#include "Windows.h"
//#include "iostream"
#include "Thread.h"

volatile int TIME = 3000;

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