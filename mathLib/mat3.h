#pragma once

#include "vec3.h"

union mat3
{
	float m[9];
	float mm[3][3]; // col[y] row[x]

	vec3 c[3];

	vec3 &operator[](unsigned idx);
	const vec3 &operator[](unsigned idx) const;
};

mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, const mat3 &B); // combine transformation
mat3 operator*(const mat3 &A, const mat3 &V); // apply transformation

mat3 transpose(const mat3 &A); // flips rows and colums

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);