#include <iostream>

#include "sfwdraw.h"
#include "mathutils.h"
#include "mat3.h"
#include "vec2.h"
#include "vec3.h"

#include "gameObject.h"
#include "tank.h"
#include "bullets.h"

int main()
{
	sfw::initContext();

	sfw::setBackgroundColor(BLACK);

	Tank p1;
	void p1setup(); {
		p1.up = 'W';
		p1.down = 'S';
		p1.tLeft = 'A';
		p1.tRight = 'D';
		p1.boost = KEY_LEFT_SHIFT;
		p1.shoot = KEY_SPACE;
		p1.enabled = true;
		p1.speed = 5;
		p1.pos = vec2{ 200, 200 };
		p1.dimen = vec2{ 1, 1 };
	}

	Bullet one;
	one.pos = vec2{ 10, 10 };
	one.dimen = vec2{ 1, 1 };
	one.alive = 0;
	one.e_parent = &p1;

	while (sfw::stepContext())
	{
		p1.update();
		one.update();

		DrawMatrix(p1.getGlobalTransform(), 40, p1.enabled);
	}

	sfw::termContext();
}