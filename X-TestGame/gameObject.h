#pragma once

#include "vec2.h"

class GameObject
{
public:
	vec2 pos;

	float speed;

	float rad;

	void update();
	void draw();
};