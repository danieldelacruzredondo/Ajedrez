#pragma once
#include"Ficha.h"

class Reina : public Ficha
{
public:
	void dibuja();
	bool mueve(VPosicion fin);

	friend class VMovimiento;
};
