#pragma once

#include "gameObject.h"

class Tank : public GameObject
{
public:

	char up;
	char down;
	char tRight;
	char tLeft;
	char boost;
	char shoot;

	void update();
};