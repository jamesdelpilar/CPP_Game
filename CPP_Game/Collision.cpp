#include "Collision.h"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
	if ((rectA.x + rectA.w >= rectB.x &&  //right
		rectB.x + rectB.w >= rectA.x &&  //left
		rectA.y + rectA.h >= rectB.y &&  //bottom
		rectB.y + rectB.h >= rectA.y) == true)    //top
	{
		return true;
	}
	return false;
}
