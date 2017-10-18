#pragma once
#include "vec2.h"
#include "mat3.h"

class Trnsform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;

	Trnsform();

	mat3 getLocalTransform() const;
};

void drawMatrix(const mat3 &t, float drawing_scale);