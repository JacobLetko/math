#include <iostream>
#include <ctime>

#include "sfwdraw.h"
#include "mathutils.h"
#include "vec2.h"
#include "mat3.h"
#include "transform.h"

#include "player.h"

int main()
{
	sfw::initContext();

	sfw::setBackgroundColor(BLACK);
	
	srand(time(NULL()));
	
	Player p1;
	void p1Setup(Player p1);
	{
		p1.pos = { 200, 300 };
		p1.rad = 30;
		p1.up = 'W';
		p1.down = 'S';
		p1.left = 'A';
		p1.right = 'D';
		p1.sprint = 'J';
		p1.teleport = 'K';
		p1.teleportTimer = 0;

		p1.sprite = sfw::loadTextureMap("../resources/spaceShip.png");
		p1.transform.dimension = vec2{ 48, 48 };
		p1.transform.position = vec2{ 400,300 };
		p1.collider.box.extents = { .5,.5 };
	}

	/*
	Transform myTransform;
	myTransform.position = vec2{ 400, 300 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = 0;

	Transform mybaby;
	mybaby.position = vec2{ 15, 15 };
	mybaby.dimension = vec2{ 1,1 };
	mybaby.angle = 0;
	mybaby.e_parent = &myTransform;
	*/

	Wall wall;

	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		float dt = sfw::getDeltaTime();

		/*
		myTransform.angle += sfw::getDeltaTime() * 360;
		//myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		mybaby.angle += sfw::getDeltaTime() * -360;

		DrawMatrix(myTransform.getGlobalTransform(), 40);
		DrawMatrix(mybaby.getGlobalTransform(), 30);
		*/

		p1.controller.poll(p1.rigidbody, p1.transform);
		p1.rigidbody.integrate(p1.transform, dt);
		p1.sprite.draw(p1.transform);

		doCollision(p1, wall);

		drawAABB(p1.collider.getGlobalBox(p1.transform), MAGENTA);
	}

	sfw::termContext();
}