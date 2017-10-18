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
	}

	Trnsform myTransform;
	myTransform.position = vec2{ 400, 300 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = 0;

	Trnsform mybaby;
	mybaby.position = vec2{ 15, 15 };
	mybaby.dimension = vec2{ 1,1 };
	mybaby.angle = 0;
	mybaby.e_parent = &myTransform;

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		myTransform.angle += sfw::getDeltaTime() * 360;
		//myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

		mybaby.angle += sfw::getDeltaTime() * -360;

		drawMatrix(myTransform.getGlobalTransform(), 40);
		drawMatrix(mybaby.getGlobalTransform(), 30);
	}

	sfw::termContext();
}