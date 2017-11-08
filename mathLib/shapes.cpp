#include "shapes.h"
#include "sfwdraw.h"
#include <cmath>

// transform:
//	position, rotation, scale

/*
[sx   0   0]
[0   sy   0]
[0    0   1]
*/
circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = mag(M[0].xy);
	scale.y = mag(M[1].xy);

	 ret.radius *= fmaxf(scale.x, scale.y);

	 return ret;
}


// AABB Transformation
/*
	cmath
*/
AABB operator*(const mat3 &M, const AABB &B)
{
	AABB retval;

	vec2 TR = B.position + B.extents;
	vec2 BL = B.position - B.extents;
	vec2 TL = { BL.x, TR.y };
	vec2 BR = { TR.x, BL.y };

	TR = (M * vec3{ TR.x, TR.y, 1 }).xy;
	BL = (M * vec3{ BL.x, BL.y, 1 }).xy;
	TL = (M * vec3{ TL.x, TL.y, 1 }).xy;
	BR = (M * vec3{ BR.x, BR.y,1 }).xy;

	vec2 MinCorner = min(TR, min(BL, min(TL, BR)));
	vec2 MaxCorner = max(TR, max(BL, max(TL, BR)));

	retval.position = (MaxCorner + MinCorner) / 2.0f;
	retval.extents  = (MaxCorner - MinCorner) / 2.0f;

	return retval;
}

void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}


void DrawVecLine(const vec2 &a, const vec2 &b, int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void drawAABB(const AABB & box, int color)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, TL, color);
	DrawVecLine(TL, BL, color);
	DrawVecLine(BL, BR, color);
	DrawVecLine(BR, TR, color);
}

