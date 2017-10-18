#pragma once

#include "vec3.h"
#include "vec2.h"

union mat3
{
	float m[9];
	float mm[3][3]; // col[y] row[x]

	vec3 c[3];

	vec3 &operator[](unsigned idx);
	const vec3 &operator[](unsigned idx) const;

	static mat3 identity();
	static mat3 zero();
};

mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, const mat3 &B); // combine transformation
vec3 operator*(const mat3 &A, const vec3 &V); // apply transformation

bool operator==(const mat3 &A, const mat3 &B);

mat3 transpose(const mat3 &A); // flips rows and colums

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

mat3 translate(const vec2 &t);
mat3 scale(const vec2 &s);
mat3 rotate(float deg);