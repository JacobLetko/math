#pragma once

#include "vec2.h"
#include "gameObject.h"
#include "transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

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

	Transform   transform;
	Rigidbody   rigidbody;
	Collider    collider;
	Controller  controller;
	Sprite		sprite;

	virtual void update();
};

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

bool doCollision(Player &Player, const Wall &wall);