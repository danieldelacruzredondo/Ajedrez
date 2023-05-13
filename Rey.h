#pragma once
#include"Ficha.h"

class Rey: public Ficha
{
public:
	void dibuja();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
