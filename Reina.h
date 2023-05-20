#pragma once
#include "Ficha.h"
#include "ListaFichas.h"

class Reina : public Ficha
{
public:
	void dibuja();
	bool mueve(VPosicion fin);

};
