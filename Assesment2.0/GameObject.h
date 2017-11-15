#pragma once
#include "vec2.h"
#include "Transform.h"
#include "rigidBody.h"
#include "Collider.h"
#include "Sprite.h"

class GameObject
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
	bool enabled;
};

class Player : public GameObject
{
public:

	void update();
};

class Wall : public GameObject{};

class Ball : public GameObject {};

class Brick : public GameObject 
{
public:
	void update();
	int life; 
	Sprite s1;
	Sprite s2;
	Sprite s3;
};

bool doCollision(Ball &ball, const Wall &wall);
void doCollision(Player &player, Ball &ball);
bool doCollisioin(Ball &ball, Brick &brick);