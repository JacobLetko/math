#include "mat3.h"

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

const vec3 & mat3::operator[](unsigned idx) const
{
	return c[idx];
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 transpose(const mat3 & A)
{
	return mat3();
}

float determinant(const mat3 & A)
{
	return 0.0f;
}

mat3 inverse(const mat3 & A)
{
	return mat3();
}
