#pragma once
#include"VPosicion.h"
#include"Reina.h"
#include"Rey.h"
#include"Alfil.h"
#include"Caballo.h"
#include"Torre.h"

class Tablero
{
public:

	Reina reina;
	Rey rey;
	Alfil alfil11,alfil12,alfil21,alfil22;
	Caballo caballo11, caballo12, caballo21, caballo22;
	Torre torre11, torre12, torre21, torre22;

	float x_ojo = 0;
	float y_ojo = 0;
	float z_ojo = 0;
	int r, g, b;
	Tablero();
	void pintar();
	void inicializar();
};

