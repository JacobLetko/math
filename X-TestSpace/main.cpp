#include <iostream>
#include <cassert>

#include "mathutils.h"
#include "vec2.h"
#include "vec3.h"

int main()
{
	/*
			|\    /|   /\   ___|___  |    |
			| \  / |  /__\     |     |----|
			|  \/  | /    \    |     |    |
	*/

	//min
	{
		min(1, 2);
		min(.1, .2);
		min(1.1, 2.2);
	}
	//max
	{
		max(1, 2);
		max(.1, .2);
		max(1.1, 2.2);
	}
	//power of
	{
		powerOf(2, 2);
	}
	//rand
	{
		rand(10, 1);
	}




	/*
	              _____    ____
		 \      / |       /    
		  \    /  |___   /     
		   \  /   |      \     
		    \/    |____   \____
	*/

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