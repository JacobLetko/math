#include <iostream>

#include "sfwdraw.h"

#include "GameObject.h"

int main()
{
	sfw::initContext();

	sfw::setBackgroundColor(BLACK);

	Ball ball;
	Player player;
	Wall top;
	Wall left;
	Wall right;

	void ballsetup();
	{
		
		ball.transform.position = { 375, 200 };

		ball.sprite = sfw::loadTextureMap("../Resources/Ball.jpg");

		ball.transform.dimension = vec2{ 10, 10 };
		ball.collider.box.extents = { .5, .5 };
	}

	void wallSetup();
	{
		top.transform.position = { 0, 550 };
		top.transform.dimension = vec2{ 5000, 5 };
		top.collider.box.extents = { .5,.5 };

		left.transform.position = {0 , 0};
		left.transform.dimension = vec2{5, 5000};
		left.collider.box.extents = { .5, .5 };

		right.transform.position = {800, 10};
		right.transform.dimension = vec2{5, 5000};
		right.collider.box.extents = { .5, .5 };
	}

	void playerSetup();
	{
		player.transform.position = { 375, 50 };
		
		player.sprite = sfw::loadTextureMap("../Resources/Player.jpg");
		player.transform.dimension = vec2{ 100, 10 };
		player.collider.box.extents = { .5,.5 };

	}

	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		float dt = sfw::getDeltaTime();

		player.update();

		ball.rigidbody.integrate(ball.transform, dt);
		drawAABB(ball.collider.getGlobalBox(ball.transform), MAGENTA);

		player.rigidbody.integrate(player.transform, dt);
		drawAABB(player.collider.getGlobalBox(player.transform), GREEN);

		top.rigidbody.integrate(top.transform, dt);
		drawAABB(top.collider.getGlobalBox(top.transform), WHITE);

		left.rigidbody.integrate(left.transform, dt);
		drawAABB(left.collider.getGlobalBox(left.transform), WHITE);

		right.rigidbody.integrate(right.transform, dt);
		drawAABB(right.collider.getGlobalBox(right.transform), WHITE);

		doCollision(player, ball);
		doCollision(ball, top);
		doCollision(ball, left);
		doCollision(ball, right);
	}

	sfw::termContext();
}