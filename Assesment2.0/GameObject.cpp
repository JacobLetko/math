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

bool doCollision(Player &player, const Wall &wall)
{
	auto hit = collides(player.transform, player.collider,
		wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit);
		return true;
	}
	return false;
}

bool doCollision(Ball &ball, const Wall &wall)
{
	auto hit = collides(ball.transform, ball.collider,
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

void doCollisioin(Ball & ball, Brick & brick)
{
	auto hit = collides(ball.transform, ball.collider,
		brick.transform, brick.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(ball.transform.position, ball.rigidbody.velocity, hit);
		brick.life--;
		if (brick.life == 0)
			brick.enabled = false;
	}
}
