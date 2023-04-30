#pragma once
#include"VPosicion.h"

class Caballo
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
