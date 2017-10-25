#pragma once

#include "vec2.h"
#include "mat3.h"

class GameObject
{
public:
	vec2 pos;
	vec2 dimen;
	float angle;
	bool enabled;
	GameObject *e_parent;

	int length;
	int width;
	int rad;
	int speed;

	GameObject();

	mat3 getLocalTransform();
	mat3 getGlobalTransform();
};

void DrawMatrix(const mat3 &t, float drawing_scale, bool enabled);