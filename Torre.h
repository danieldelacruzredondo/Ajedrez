#pragma once
#include"VPosicion.h"

class Torre
{
	VPosicion pos;
	bool color;
	Torre torre;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
