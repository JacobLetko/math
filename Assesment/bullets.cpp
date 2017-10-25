#include "bullets.h"
#include "vec2.h"
#include "vec3.h"
#include "sfwdraw.h"

void Bullet::update()
{
	vec2 movment = { 0,0 };
	mat3 ang;
	if (alive > 0)
		alive--;

	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		enabled = true;
		alive = 5;
		ang = getGlobalTransform();
		movment += ang[1].xy;
	}
}
