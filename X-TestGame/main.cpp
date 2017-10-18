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
	myTransform.position = vec2{ 300, 400 };
	myTransform.dimension = vec2{ 1,1 };

	while (sfw::stepContext())
	{
		myTransform.angle += sfw::getDeltaTime();
		drawMatrix(myTransform.getLocalTransform(), 40);
	}

	sfw::termContext();
}