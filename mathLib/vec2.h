#pragma once

union vec2
{
	// accsess by array
	float v[2];

	// accsess by individual
	struct 
	{
		float x, y;
	};

	// subscript
	float operator[](unsigned idx);
	float operator[](unsigned idx) const;

	/*
		has only two floats for memory

		unions are only as big as the largest variable in the union
	*/

};

// arithmic components
vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &rhs);

// compund assignment operators
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator/=(vec2 &lhs, float rhs);

// logical operator
bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float mag(const vec2 &v);
vec2 norm(const vec2 &v);
vec2 normalize(vec2 &v);
float dot(const vec2 &a, const vec2 &b);
float dist(const vec2 &a, const vec2 &b);
vec2 perp(const vec2 &v);
vec2 lerp(const vec2 &s, const vec2 &e, float a);
vec2 min(const vec2 &a, const vec2 &b);
vec2 max(const vec2 &a, const vec2 &b);