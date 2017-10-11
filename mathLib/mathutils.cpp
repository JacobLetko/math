#include "mathutils.h"

int min(int x, int y)
{
	// if x < y return x else return y
	return x < y ? x : y;
}

int max(int x, int y)
{
	// if x > y return x else return y
	return x > y ? x : y;
}

int exponent(int base, int exponent)
{
	int x = base;
	for (int i = 0; i < exponent; i++)
		x *= base;
	return x;
}
