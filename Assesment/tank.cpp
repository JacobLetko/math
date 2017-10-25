#include "tank.h"
#include "vec2.h"
#include "vec3.h"
#include "sfwdraw.h"

void Tank::update()
{
	vec2 movment = { 0,0 };
	mat3 ang;

	if (sfw::getKey(up))
	{
		ang = getGlobalTransform();
		movment += ang[1].xy;
	}
	if (sfw::getKey(down))
	{
		ang = getGlobalTransform();
		movment -= ang[1].xy;
	}
	if (sfw::getKey(tLeft))
		angle++;
	if (sfw::getKey(tRight))
		angle--;

	if (sfw::getKey(shoot))
		pos += movment * speed;
	else
		pos += movment;

}
