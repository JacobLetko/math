#include "gameObject.h"
#include "sfwdraw.h"

GameObject::GameObject()
{
	pos = { 0,0 };
	dimen = { 0,0 };
	angle = 0;
	enabled = false;
}

mat3 GameObject::getLocalTransform()
{
	return translate(pos) * scale(dimen) * rotate(angle);
}

mat3 GameObject::getGlobalTransform()
{
	if (e_parent != nullptr)
		return e_parent->getGlobalTransform() * getLocalTransform();
	else
		return getLocalTransform();
}

void DrawMatrix(const mat3 & t, float drawing_scale, bool enabled)
{
	if (enabled == true)
	{
		vec2 pos = t[2].xy;
		vec2 right_ep = pos + t[0].xy * drawing_scale;
		vec2 up_ep = pos + t[1].xy * drawing_scale;

		sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
		sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

		sfw::drawCircle(pos.x, pos.y, drawing_scale / 4, 12, WHITE);
	}
}
