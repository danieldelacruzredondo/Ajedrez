#pragma once
#include"VPosicion.h"

class Rey
{
	VPosicion pos;
	bool color;
	Rey rey;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
