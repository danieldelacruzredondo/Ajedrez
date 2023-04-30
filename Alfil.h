#pragma once
#include"VPosicion.h"

class Alfil
{
	VPosicion pos;
	bool color;
	Alfil alfil;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
