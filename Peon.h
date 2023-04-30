#pragma once
#include"VPosicion.h"

class Peon
{
	VPosicion pos;
	bool color;
	Peon peon;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
