#ifndef __Gens_Range_H__
#define __Gens_Range_H__

#include "stdbool.h"
#include "windows.h"

extern CRITICAL_SECTION criticalSection;

typedef struct Generator
{
	int N;
	struct Generator* next;
} Generator_t;

bool generator_create(Generator_t** topGenerator, int newData);

int generators_count(const Generator_t* topNode);

void generator_setup_n(Generator_t* topNode, int number, int value);

#endif 