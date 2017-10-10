#include <iostream>
#include <math.h>


double pi = 2 * acos(0.0);

int square(int x)
{
	return x * x;
}

int Double(int x)
{
	return x * 2;
}

int cube(int x)
{
	return x * x * x;
}

float degToRad(int x)
{
	return x / 180 * pi;
}

float quadratic(int x)
{
	return 2 * x + x + 2;
}

float Quadratic(int b, int a, int c)
{
	return (-b + sqrt((b*b) - (4 * a*c)) )/ 2 * a;
}

float linearBlend(int x, int y, int z)
{
	return x + z*(y - x);
}

float distance(int x, int y, int x1, int y1)
{
	return sqrt(square(x - x1) + square(y - y1));
}

int main()
{
	return 0;
}