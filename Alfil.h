#pragma once
#include"Ficha.h"

class Alfil:public Ficha
{
public:
	void dibuja();
	bool movimiento(VPosicion* fin);

	friend class VMovimiento;
};
