#include <iostream>

#include "sfwdraw.h"
#include "mathutils.h"

int main()
{
	sfw::initContext();

	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{

	}

	sfw::termContext();
}