#pragma once
#include"VPosicion.h"

class Reina
{
	VPosicion pos;
	bool color;
	Reina reina;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();
        bool movimiento(VPosicion* fin);
	
	friend class VMovimiento;
};
