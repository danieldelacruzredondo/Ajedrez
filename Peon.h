#pragma once
#include"Ficha.h"

class Peon:public Ficha
{
public:
	void dibuja();
	void setpos(VPosicion _pos) { pos = _pos; }
	void setcolor(bool _color) { color = _color; }
	VPosicion getpos() { return pos; }
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
