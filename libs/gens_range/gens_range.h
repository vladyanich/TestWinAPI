#ifndef __Gens_Range_H__
#define __Gens_Range_H__


#include "stdbool.h"
typedef struct Generator
{
	int N;
	struct Generator* next;
} Generator_t;

bool generator_add(Generator_t* topNode, int newData);

int generators_count(const Generator_t* topNode);

void generator_setup_n(Generator_t* topNode, int number, int value);

#endif 