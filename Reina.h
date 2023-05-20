#pragma once
#include"Ficha.h"

class Rey : public Ficha
{
public:
	void dibuja();
	bool mueve(VPosicion fin);

	friend class VMovimiento;
};
