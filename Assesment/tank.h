#pragma once

#include "gameObject.h"

class Tank : GameObject
{
public:

	char up;
	char down;
	char left;
	char right;

	void update();
};