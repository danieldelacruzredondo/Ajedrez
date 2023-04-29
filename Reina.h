#pragma once
#include"VPosicion.h"

class Reina
{
	VPosicion pos;
	bool color;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
};
