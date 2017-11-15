#include "GameObject.h"
#include "sfwdraw.h"
#include <iostream>
void Player::update()
{
	if (sfw::getKey('A') && transform.position.x > 0)
	{ 
		transform.position.x -= 5;
	}
		
	if (sfw::getKey('D') && transform.position.x < 800)
	{
		transform.position.x += 5;
	}
}

void Brick::update()
{
	if (life == 0)
		enabled = false;
}

bool doCollision(Ball &ball, const Wall &wall)
{
	Collision hit = collides(ball.transform, ball.collider,
		wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(ball.transform.position, ball.rigidbody.velocity, hit);
		return true;
	}
	return false;
}

void doCollision(Player &player, Ball &ball)
{
	Collision hit = collides(player.transform, player.collider,
		ball.transform, ball.collider);

	if (hit.penetrationDepth > 0)
	{
		dynamic_resolution(player.transform.position,
			ball.rigidbody.velocity * -1,
			player.rigidbody.mass,
			ball.transform.position,
			ball.rigidbody.velocity,
			ball.rigidbody.mass,
			hit);
	}
	
}

bool doCollisioin(Ball & ball, Brick & brick)
{
	Collision hit = collides(ball.transform, ball.collider,
		brick.transform, brick.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(ball.transform.position, ball.rigidbody.velocity, hit);
		return true;
	}

	return false;
}
