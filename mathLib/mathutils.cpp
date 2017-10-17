#include "mathutils.h"
#include <random>

unsigned min(unsigned x, unsigned y)
{
	// if x < y return x else return y
	return x < y ? x : y;
}

unsigned max(unsigned x, unsigned y)
{
	// if x > y return x else return y
	return x > y ? x : y;
}

int powerOf(int base, int exponent)
{
	int x = base;
	for (int i = 0; i < exponent; i++)
		x *= base;
	return x;
}

int rand(int range, int start)
{
	return rand() % range + start;
}
