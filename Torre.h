#pragma once
#include"Ficha.h"

class Torre: public Ficha
{
public:
	void dibuja();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
