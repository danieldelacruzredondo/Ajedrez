#pragma once
#include"Ficha.h"

class Caballo:public Ficha
{
	
public:
	void dibuja();
	bool movimiento(VPosicion fin);

	friend class VMovimiento;
};
