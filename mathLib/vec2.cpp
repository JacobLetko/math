#include <cmath>
#include <cfloat>

#include "vec2.h"
#include "mathutils.h"


float vec2::operator[](unsigned idx)
{
	return v[idx];
}
float vec2::operator[](unsigned idx) const
{
	return v[idx];
}


vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs.x + rhs.x, lhs.y + rhs.y };
}
vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}
vec2 operator*(const vec2 &lhs, float rhs)
{	
	return { lhs.x * rhs, lhs.y * rhs };
}
vec2 operator*(float lhs, const vec2 &rhs)
{
	return{ lhs * rhs.x, lhs * rhs.y };
}
vec2 operator/(const vec2 & lhs, const vec2 &rhs)
{
	return { lhs.x / rhs.x, lhs.y / rhs.y };
}
vec2 operator-(const vec2 & rhs)
{
	return { rhs.x * -1, rhs.y * -1 };
}


vec2 & operator+=(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs + rhs };
}
vec2 & operator-=(const vec2 & lhs, const vec2 & rhs)
{
	return { lhs - rhs };
}
vec2 & operator*=(const vec2 & lhs, float rhs)
{
	return { lhs * rhs };
}
vec2 & operator/=(const vec2 & lhs, float rhs)
{
	vec2 temp;
	temp.x = lhs.x / rhs;
	temp.y = lhs.y / rhs;
	
	return temp;
}



bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	// this isn't quite right, but game engines tend
	// to do something fairly close to this process
	//
	// floating-point math is weird! check this out!
	// http://floating-point-gui.de/errors/comparison/

	const int qty = (sizeof(lhs.v) / sizeof(lhs.v[0]));
	for (int i = 0; i < qty; ++i)
	{
		// is the discrepancy within acceptable limits?
		if (std::abs(lhs.v[i] - rhs.v[i]) < FLT_EPSILON)
		{
			return false;
		}
	}

	return true;
}
bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	const int qty = (sizeof(lhs.v) / sizeof(lhs.v[0]));

	for (int i = 0; i < qty; i++)
	{
		if (std::abs(lhs.v[i] - rhs.v[i]) < FLT_EPSILON)
		{
			return true;
		}
	}
	return false;
}

float mag(const vec2 & v)
{
	float asqr = v.x * v.x;
	float bsqr = v.y * v.y;

	return sqrtf(asqr + bsqr);
}
vec2 norm(const vec2 & v)
{
	vec2 temp = v;
	float len = mag(v);

	temp /= len;

	return temp;
}
vec2 normalize(vec2 & v)
{
	v = norm(v);

	return v;
}
float dot(const vec2 & a, const vec2 & b)
{
	return a.x * b.x + a.y * b.y;
}
float dist(const vec2 & a, const vec2 & b)
{
	return mag(b - a);
}
vec2 perp(const vec2 & v)
{
	return vec2{ v.y, -v.x };
}
vec2 lerp(const vec2 & s, const vec2 & e, float a)
{
	return s + a * (e - s);
}
vec2 min(const vec2 & a, const vec2 & b)
{
	return{min(a.x, b.x) , min(a.y, b.y)};
}
vec2 max(const vec2 & a, const vec2 & b)
{
	return{ max(a.x, b.x) , max(a.y, b.y) };
}


