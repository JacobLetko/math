#pragma once

#include "gameObject.h"

class Bullet : public GameObject
{
public:

	float alive;

	void update();
};