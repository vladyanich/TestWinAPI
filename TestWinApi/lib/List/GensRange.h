#ifndef __Gens_Range_H__
#define __Gens_Range_H__

extern volatile int* globalArrayN[20];
extern volatile int gensCount;

typedef struct Generator
{
	int N;
	struct Generator* next;
} Generator_t;

Generator_t* push_node(Generator_t* topNode, int newData);

void show_all_gens(const Generator_t* topNode);

int generators_count(const Generator_t* topNode);

void setup_n_generator(Generator_t* topNode, int number, int value);

void set_global_generators_parametrs(const Generator_t* topNode);

#endif 