#pragma once
#include"Ficha.h"
#include "ListaFichas.h"

class Alfil :public Ficha
{
public:
	void dibuja();
	bool mueve(VPosicion fin);

	friend class VMovimiento;
};
