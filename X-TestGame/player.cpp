#include "player.h"
#include "sfwdraw.h"
#include "vec2.h"
#include "mathutils.h"

void Player::update()
{
	vec2 movment = { 0,0 };
	speed = 1;

	if (sfw::getKey(up))
		movment.y += 1;

	if (sfw::getKey(down))
		movment.y -= 1;

	if (sfw::getKey(left))
		movment.x -= 1;

	if (sfw::getKey(right))
		movment.x += 1;

	if (sfw::getKey(sprint))
		speed = 10;
	
	if (sfw::getKey(teleport) && teleportTimer == 0)
	{
		pos.x = rand(600, 10);
		pos.y = rand(600, 10);
		teleportTimer = 10;
	}

	movment *= speed;
	pos += movment;

	if (teleportTimer > 0) 
	{
		teleportTimer--;
	}
}
