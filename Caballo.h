#pragma once
#include"Ficha.h"
#include "ListaFichas.h"

class Caballo:public Ficha
{
	
public:
	void dibuja();
	bool mueve(VPosicion fin);

};
