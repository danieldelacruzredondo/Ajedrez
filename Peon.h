#pragma once
#include"Ficha.h"

class Peon:public Ficha
{
public:
	void dibuja();
	bool movimiento(VPosicion fin);

	friend class VMovimiento;
};
