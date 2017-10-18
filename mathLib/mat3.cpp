#include "mat3.h"
#include "vec3.h"

#include <cmath>

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}
const vec3 & mat3::operator[](unsigned idx) const
{
	return c[idx];
}

mat3 mat3::identity()
{
	return mat3{ 1,0,0,
				 0,1,0,
				 0,0,1 };
}
mat3 mat3::zero()
{
	return mat3{ 0, 0, 0,
				 0, 0, 0,
				 0, 0,0 };
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 temp;

	for (int i = 0; i < 9; ++i)
		temp.m[i] = A.m[i] + B.m[i];

	return temp;
}
mat3 operator-(const mat3 & A, const mat3 & B)
{
	mat3 temp;

	for (int i = 0; i < 9; ++i)
		temp.m[i] = A.m[i] - B.m[i];

	return temp;
}
mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 temp;
	
	mat3 At = transpose(A);

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; ++x)
			temp[y][x] = dot(At[x], B[y]);

	return temp;
}
vec3 operator*(const mat3 & A, const vec3 & V)
{
	mat3 temp = transpose(A);

	return vec3{ dot(temp[0], V),
				 dot(temp[1], V),
				 dot(temp[2], V) };
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return A[0] == B[0] &&
		   A[1] == B[1] &&
		   A[2] == B[2];
}

mat3 transpose(const mat3 & A)
{
	mat3 temp;
	for (int i = 0; i < 3; ++i)
		for (int k = 0; k < 3; ++k)
			temp[i][k] = A[k][i];
	
	return temp;
}

float determinant(const mat3 & A)
{
	return dot(A[0], cross(A[1], A[2]));
}

mat3 inverse(const mat3 & A)
{
	float di = 1 / determinant(A);

	return transpose(mat3{
		cross(A[1], A[2]) * di,
		cross(A[2], A[0]) * di,
		cross(A[0], A[1]) * di });
}

mat3 translate(const vec2 & t)
{
	mat3 temp = mat3::identity();

	temp[2].xy = t;

	return temp;
}
mat3 scale(const vec2 & s)
{
	return mat3{ s.x, 0,0,
				 0,s.y,0,
				 0,0,1 };
}
mat3 rotate(float deg)
{
	float rad = deg * 0.0174533;
	return mat3{ cos(rad), sin(rad), 0,
				 -sin(rad), cos(rad), 0,
				 0, 0, 1 };
}
