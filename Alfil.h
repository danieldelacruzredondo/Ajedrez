#pragma once
#include"VPosicion.h"

class Alfil
{
	VPosicion pos;
	bool color;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();

	friend class VMovimiento;
};
