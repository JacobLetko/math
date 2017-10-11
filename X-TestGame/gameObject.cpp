#include "gameObject.h"
#include "sfwdraw.h"

void GameObject::update()
{
}

void GameObject::draw()
{
	sfw::drawCircle(pos.x, pos.y, rad);
}
