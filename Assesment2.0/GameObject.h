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
};

class Player : public GameObject
{
public:
	void update();
};

class Wall : public GameObject{};

class Ball : public GameObject {};

bool doCollision(Player &player, const Wall &wall);
bool doCollision(Ball &ball, const Wall &wall);
bool doCollision(Player &player, Ball &ball);