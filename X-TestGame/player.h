#pragma once

#include "vec2.h"
#include "gameObject.h"

class Player : public GameObject
{
public:

	char up;
	char down;
	char left;
	char right;
	char sprint;
	char teleport;

	int teleportTimer;

	virtual void update();
};