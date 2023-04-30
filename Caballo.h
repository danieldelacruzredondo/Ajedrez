#pragma once
#include"VPosicion.h"

class Caballo
{
	VPosicion pos;
	bool color;
	Caballo caballo;
public:
	void dibuja();
	void setpos(VPosicion _pos);
	void setcolor(bool _color);
	VPosicion getpos();
        bool movimiento(VPosicion* fin);
	
	friend class VMovimiento;
};
