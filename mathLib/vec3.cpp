#include "vec3.h"
#include "mathutils.h"

#include <cmath>
#include <cfloat>

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}
float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
/*
	for (int i = 0; i < 3; ++i)
		result.v[i] = lhs.v[i] + rhs.v[i];
*/
	return result;
}
vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - lhs.y;
	result.z = lhs.z - rhs.z;

	return result;
}
vec3 operator*(const vec3 & lhs, float rhs)
{
	vec3 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	result.z = lhs.z * rhs;

	return result;
}
vec3 operator*(float lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = rhs.x * lhs;
	result.y = rhs.y * lhs;
	result.z = rhs.z * lhs;

	return result;
}
vec3 operator/(const vec3 & lhs, float & rhs)
{
	vec3 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;
	result.z = lhs.z / rhs;

	return result;
}
vec3 operator-(const vec3 & lhs)
{
	return vec3{lhs.x * -1, lhs.y * -1, lhs.z * -1};
}

vec3 operator+=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}
vec3 operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}
vec3 operator*=(vec3 & lhs, float rhs)
{
	lhs = lhs * rhs;
	return lhs;
}
vec3 operator/=(vec3 & lhs, float rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

bool operator==(const vec3 lhs, const vec3 & rhs)
{
	if(abs(lhs.x - rhs.x < EPSILON) &&
		abs(lhs.y - rhs.y < EPSILON) &&
		abs(lhs.z - rhs.z < EPSILON))
	{
		return true;
	}
	return false;
}
bool operator!=(const vec3 lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x < EPSILON) &&
		abs(lhs.y - rhs.y < EPSILON) &&
		abs(lhs.z - rhs.z < EPSILON))
	{
		return false;
	}
	return true;
}

float mag(const vec3 & v)
{
	float asqr = v.x * v.x;
	float bsqr = v.y * v.y;
	float csqr = v.z * v.z;

	return sqrtf(asqr + bsqr + csqr);
}
vec3 norm(const vec3 & v)
{
	vec3 temp = v;
	float len = mag(v);

	temp /= len;

	return temp;
}
vec3 &normalize(vec3 & v)
{
	v = norm(v);

	return v;
}
float dot(const vec3 & a, const vec3 & b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
float dist(const vec3 & a, const vec3 & b)
{
	return mag(a - b);
}
/*
vec3 perp(const vec3 & v)
{
	return vec3{};
}
vec3 lerp(const vec3 & s, const vec3 & e, float a)
{
	return s + a * (e - s);
}
*/
vec3 min(const vec3 & a, const vec3 & b)
{
	return{fmin(a.x, b.x), fmin(a.y, b.y), fmin(a.z, b.z)};
}
vec3 max(const vec3 & a, const vec3 & b)
{
	return{ fmax(a.x, b.x), fmax(a.y, b.y), fmax(a.z, b.z)};
}
vec3 clamp(const vec3 & a, const vec3 & mini, const vec3 & maxi)
{
	vec3 temp;

	temp = max(a, mini);
	temp = min(a, maxi);

	return temp;
}