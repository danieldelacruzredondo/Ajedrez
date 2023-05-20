#include"VPosicion.h"

bool VPosicion::operator==(VPosicion b)
{
	if (b.x == x && b.y == y)return true;
	else return false;
}

bool VPosicion::operator!=(VPosicion b)
{
	if (b.x != x || b.y != y)return true;
	else return false;
}
