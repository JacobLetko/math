#include <iostream>
#include <cassert>

#include "vec2.h"

int main()
{
	//addition
	{
		vec2 a = { 1,2 };
		vec2 b = { 4,8 };

		//assert((a + b) == (vec2{5, 10}));
	}
	//subtraction
	{
		vec2 a = { 1,2 };
		vec2 b = { 4,8 };

		//assert((a - b) == (vec2{3,6}));
	}
	//multipplication
	{
		vec2 a = { 1,2 };
		vec2 b = { 4,8 };

		//assert((a * b) == (vec2{4, 16}));
	}
	//division
	{
		vec2 a = { 1,2 };
		vec2 b = { 4,8 };

		//assert((a / b) == (vec2{ 4,4 }));
	}
	//negative
	{
		vec2 a = { 1,2 };

		//assert((-a) == (vec2{ -1,-2 }));
	}


	while (true);
	return 0;
}