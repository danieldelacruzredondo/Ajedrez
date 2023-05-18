#pragma once
#include"Ficha.h"
#include "ListaFichas.h"

class Peon:public Ficha
{
public:
	void dibuja();
	bool movimiento(VPosicion fin);

	friend class VMovimiento;
};
