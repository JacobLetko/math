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
	Brick bricks[15];

	void ballsetup();
	{
		
		ball.transform.position = { 375, 200 };

		ball.sprite = sfw::loadTextureMap("Resources/Ball.png");

		ball.transform.dimension = vec2{ 10, 10 };
		ball.collider.box.extents = { .5, .5 };
		ball.rigidbody.force = { -10 , -100 };
		ball.rigidbody.drag = 0;
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
		
		player.sprite = sfw::loadTextureMap("Resources/Player.png");

		player.transform.dimension = vec2{ 50, 10 };
		player.collider.box.extents = { .5,.5 };

	}

	void brickSetup();
	{
		float BlockMoveX = 60;
		float BlockMoveY = 400;

		for (int i = 0; i < 15; i++)
		{
			bricks[i].transform.position = { BlockMoveX, BlockMoveY };
			bricks[i].transform.dimension = vec2{ 25,10 };
			bricks[i].collider.box.extents = { .5,.5 };
			bricks[i].enabled = true;
			bricks[i].life = 3;

			bricks[i].s1 = sfw::loadTextureMap("Resources/Block_1.png");
			bricks[i].s2 = sfw::loadTextureMap("Resources/Block_2.png");
			bricks[i].s3 = sfw::loadTextureMap("Resources/Block_3.png");
			BlockMoveX += 45;
		}
	}

	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		float dt = sfw::getDeltaTime();

		ball.rigidbody.integrate(ball.transform, dt);
		drawAABB(ball.collider.getGlobalBox(ball.transform), MAGENTA);
		ball.sprite.draw(ball.transform);

		player.update();
		player.rigidbody.integrate(player.transform, dt);
		drawAABB(player.collider.getGlobalBox(player.transform), GREEN);
		player.sprite.draw(player.transform);
		
		drawAABB(top.collider.getGlobalBox(top.transform), WHITE);
		drawAABB(left.collider.getGlobalBox(left.transform), WHITE);
		drawAABB(right.collider.getGlobalBox(right.transform), WHITE);

		for (int i = 0; i < 15; i++)
		{
			if (bricks[i].enabled == true)
			{
				drawAABB(bricks[i].collider.getGlobalBox(bricks[i].transform), YELLOW);
				
				if (bricks[i].life == 1)
					bricks[i].s1.draw(bricks[i].transform);
				if (bricks[i].life == 2)
					bricks[i].s2.draw(bricks[i].transform);
				if (bricks[i].life == 3)
					bricks[i].s3.draw(bricks[i].transform);
				
				bool die = doCollisioin(ball, bricks[i]);
				if (die == true)
					bricks[i].life -= 1;
				bricks[i].update();
			}
			
		}

		doCollision(player, ball);
		doCollision(ball, top);
		doCollision(ball, left);
		doCollision(ball, right);

		if (sfw::getKey('R') && ball.transform.position.y < 50)
			ball.transform.position = { 200, 200 };
		
	}

	sfw::termContext();
}